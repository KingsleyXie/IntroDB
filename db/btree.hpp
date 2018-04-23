#include <bits/stdc++.h>

class BTreeNode
{
private:
	BTreeNode **children;
	int *keys, order, keynum;
	bool isLeaf;

public:
	BTreeNode(int order, bool isLeaf)
	{
		this->order = order;
		this->isLeaf = isLeaf;

		children = new BTreeNode *[2 * order];
		keys = new int[2 * order - 1];
		keynum = 0;
	}

	~BTreeNode() {}

	void insertNonFull(int key)
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

	void splitChild(int pos, BTreeNode *child)
	{
		BTreeNode *sibling = new BTreeNode(child->order, child->isLeaf);
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

	BTreeNode* search(int key)
	{
		int i = 0;
		while(i < keynum && key > keys[i]) i++;
		if (keys[i] == key) return this;
		if (isLeaf) return NULL;
		return children[i]->search(key);
	}

friend class BTree;
};

class BTree
{
private:
	BTreeNode *root;
	int order;

public:
	BTree(int order)
	{
		root = NULL;
		this->order = order;
	}

	~BTree() {}

	void insert(int key)
	{
		if (root == NULL)
		{
			root = new BTreeNode(order, true);
			root->keys[0] = key;
			root->keynum = 1;
		}
		else
		{
			if (root->keynum == 2 * order - 1)
			{
				BTreeNode *node = new BTreeNode(order, false);
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
	}

	BTreeNode* search(int key)
	{
		return root == NULL ? NULL : root->search(key);
	}
};
