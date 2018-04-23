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

	void traverse()
	{
		if (root != NULL) root->traverse();
	}

	BTreeNode* search(int key)
	{
		return root == NULL ? NULL : root->search(key);
	}
};
