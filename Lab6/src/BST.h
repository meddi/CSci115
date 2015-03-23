/*
 * BST.h
 *
 *  Created on: Mar 19, 2015
 *      Author: mehdi
 */
class BST
{
private:
	struct node
	{
		int key;
		node* left;
		node* right;
	};

	node* root;

	node* createLeaf(int key);

	void insertPrivate(int key, node* ptr);

	void printInOrderPrivate(node* ptr, int k1, int k2);

	void printPrivate(node *ptr);

	int findSmallestPrivate(node* ptr);

	int count;

public:
	BST();

	void insert(int key);

	void printInOrder(int key1, int key2);

	void print();

	int findSmallest();
};
