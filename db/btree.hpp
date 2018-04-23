#include <bits/stdc++.h>

template <typename T>
class BTreeNode
{
public:
	BTreeNode<T> **children;
	T *keys;
	int order, keynum;
	bool isLeaf;

	BTreeNode(int order, bool isLeaf)
	{
		this->order = order;
		this->isLeaf = isLeaf;

		children = new BTreeNode<T> *[2 * order];
		keys = new T[2 * order - 1];
		keynum = 0;
	}

	~BTreeNode() {}

	void insertNonFull(T key)
	{
		int i = keynum - 1;
		if (isLeaf)
		{
			while(i >= 0 && keys[i] > key)
			{
				keys[i + 1] = keys[i];
				i--;
			}

			keys[i + 1] = key;
			keynum++;
		}
		else
		{
			while(i >= 0 && keys[i] > key) i--;
			if (children[i + 1]->keynum == 2 * order - 1)
			{
				splitChild(i + 1, children[i + 1]);
				if (keys[i + 1] < key) i++;
			}
			children[i + 1]->insertNonFull(key);
		}
	}

	void splitChild(int pos, BTreeNode<T> *child)
	{
		BTreeNode<T> *sibling = new BTreeNode<T>(child->order, child->isLeaf);
		sibling->keynum = order - 1;

		for (int i = 0; i < order - 1; ++i)
			sibling->keys[i] = child->keys[i + order];

		if (!child->isLeaf)
		{
			for (int i = 0; i < order; ++i)
				sibling->children[i] = child->children[i + order];
		}

		child->keynum = order - 1;

		for (int i = keynum; i >= pos + 1; i--)
			children[i + 1] = children[i];
		children[pos + 1] = sibling;

		for (int i = keynum - 1; i >= pos; i--)
			keys[i + 1] = keys[i];

		keys[pos] = child->keys[order - 1];
		keynum++;
	}

	void traverse()
	{
		for (int i = 0; i < keynum; ++i)
		{
			if (!isLeaf) children[i]->traverse();
			std::cout << keys[i] << " ";
		}

		if (!isLeaf) children[keynum]->traverse();
	}

	void dump(std::ostream& stream)
	{
		for (int i = 0; i < keynum; ++i)
		{
			if (!isLeaf) children[i]->dump(stream);
			keys[i].archive(stream);
		}

		if (!isLeaf) children[keynum]->dump(stream);
	}

	BTreeNode<T>* search(T key)
	{
		int i = 0;
		while(i < keynum && key > keys[i]) i++;
		if (keys[i] == key) return this;
		if (isLeaf) return NULL;
		return children[i]->search(key);
	}

	int findKey(T key)
	{
		int index = 0;
		while (index < keynum && keys[index] < key)
			index++;
		return index;
	}

	T getPred(int index)
	{
		BTreeNode<T> *curr = children[index];
		while (!curr->isLeaf)
			curr = curr->children[curr->keynum];

		return curr->keys[curr->keynum - 1];
	}

	T getSucc(int index)
	{
		BTreeNode<T> *curr = children[index + 1];
		while (!curr->isLeaf)
			curr = curr->children[0];
		return curr->keys[0];
	}

	void fill(int index)
	{
		if (index != 0
			&& children[index - 1]->keynum >= order)
		{
			borrowFromPrev(index);
		}
		else
		{
			if (index != keynum
				&& children[index + 1]->keynum >= order)
				borrowFromNext(index);
			else
			{
				if (index != keynum) merge(index);
				else merge(index - 1);
			}
		}
		return;
	}

	void borrowFromPrev(int index)
	{
		BTreeNode<T> *child = children[index];
		BTreeNode<T> *sibling = children[index - 1];

		for (int i = child->keynum - 1; i >= 0; --i)
			child->keys[i+1] = child->keys[i];

		if (!child->isLeaf)
		{
			for(int i = child->keynum; i >= 0; --i)
				child->children[i + 1] = child->children[i];
		}

		child->keys[0] = keys[index - 1];

		if (!isLeaf)
		{
			child->children[0] = sibling->children[sibling->keynum];
		}

		keys[index - 1] = sibling->keys[sibling->keynum - 1];

		child->keynum++;
		sibling->keynum--;
		return;
	}

	void borrowFromNext(int index)
	{
		BTreeNode<T> *child = children[index];
		BTreeNode<T> *sibling = children[index + 1];

		child->keys[(child->keynum)] = keys[index];
		if (!child->isLeaf)
		{
			child->children[(child->keynum) + 1] = sibling->children[0];
		}

		keys[index] = sibling->keys[0];

		for (int i = 1; i < sibling->keynum; ++i)
			sibling->keys[i - 1] = sibling->keys[i];

		if (!sibling->isLeaf)
		{
			for(int i = 1; i <= sibling->keynum; ++i)
				sibling->children[i - 1] = sibling->children[i];
		}

		child->keynum++;
		sibling->keynum--;
		return;
	}

	void merge(int index)
	{
		BTreeNode<T> *child = children[index];
		BTreeNode<T> *sibling = children[index + 1];

		child->keys[order - 1] = keys[index];

		for (int i = 0; i < sibling->keynum; ++i)
			child->keys[i + order] = sibling->keys[i];

		if (!child->isLeaf)
		{
			for(int i = 0; i <= sibling->keynum; ++i)
				child->children[i + order] = sibling->children[i];
		}

		for (int i = index + 1; i < keynum; ++i)
			keys[i - 1] = keys[i];

		for (int i = index + 2; i <= keynum; ++i)
			children[i - 1] = children[i];

		child->keynum += sibling->keynum + 1;
		keynum--;

		delete sibling;
		return;
	}

	void remove(T key)
	{
		int index = findKey(key);

		if (index < keynum && keys[index] == key)
		{
			if (isLeaf) removeFromLeaf(index);
			else removeFromNonLeaf(index);
		}
		else
		{
			if (isLeaf)
			{
				throw "Provided key is not in the tree!\n";
			}

			bool flag = (index == keynum);

			if (children[index]->keynum < order)
				fill(index);

			if (flag && index > keynum)
				children[index - 1]->remove(key);
			else
				children[index]->remove(key);
		}
		return;
	}

	void removeFromLeaf(int index)
	{
		for (int i = index + 1; i < keynum; ++i)
			keys[i - 1] = keys[i];
		keynum--;
		return;
	}

	void removeFromNonLeaf(int index)
	{
		T key = keys[index];
		if (children[index]->keynum >= order)
		{
			T pre = getPred(index);
			keys[index] = pre;
			children[index]->remove(pre);
		}
		else
		{
			if  (children[index + 1]->keynum >= order)
			{
				T succ = getSucc(index);
				keys[index] = succ;
				children[index + 1]->remove(succ);
			}
			else
			{
				merge(index);
				children[index]->remove(key);
			}
		}
	}
};

template <typename T>
class BTree
{
private:
	BTreeNode<T> *root;
	int order;

public:
	BTree(int order)
	{
		root = NULL;
		this->order = order;
	}

	~BTree() {}

	void insert(T key)
	{
		if (root == NULL)
		{
			root = new BTreeNode<T>(order, true);
			root->keys[0] = key;
			root->keynum = 1;
		}
		else
		{
			if (root->keynum == 2 * order - 1)
			{
				BTreeNode<T> *node = new BTreeNode<T>(order, false);
				node->children[0] = root;
				node->splitChild(0,  root);

				int i = 0;
				if (node->keys[0] < key) i++;
				node->children[i]->insertNonFull(key);

				root = node;
			}
			else
				root->insertNonFull(key);
		}
	}

	void traverse()
	{
		if (root != NULL) root->traverse();
		std::cout << "\n";
	}

	// Note: "dump" and "restore" functions are
	// specially wrote for B-Trees of "KVNode" Type
	void dump(std::ostream& stream)
	{
		stream << "[";

		if (root != NULL) root->dump(stream);

		stream.seekp(-1, std::ios_base::end);
		stream << "]";
	}

	void restore(std::istream& stream)
	{
		json data;
		stream >> data;

		for (int i = 0; i < data.size(); ++i)
		{
			json row = data[i];
			T nd(row["key"], row["value"]);
			insert(nd);
		}
	}

	BTreeNode<T>* search(T key)
	{
		return root == NULL ? NULL : root->search(key);
	}

	void remove(T key)
	{
		if (!root) throw "The tree is empty!\n";
		root->remove(key);

		if (root->keynum == 0)
		{
			BTreeNode<T> *t = root;

			if (root->isLeaf) root = NULL;
			else root = root->children[0];

			delete t;
		}
		return;
	}
};
