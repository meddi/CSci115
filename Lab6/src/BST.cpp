/*
 * BST.cpp
 *
 *  Created on: Mar 22, 2015
 *      Author: mehdi
 */
#include <iostream>
#include <cstdlib>
#include "BST.h"

using namespace std;

BST::BST() { root = NULL; count = 0; }

BST::node* BST::createLeaf(int key)
{
	node* newNode = new node;
	newNode->key = key;
	newNode->left = newNode->right = NULL;
	return newNode;
}

//
void BST::insert(int key)
{
	insertPrivate(key, root);
}

//
void BST::insertPrivate(int key, node* ptr)
{
	if (root == NULL)
		root = createLeaf(key);

	else if (key < ptr->key)
	{
		if (ptr->left != NULL)
			insertPrivate(key, ptr->left);
		else
			ptr->left = createLeaf(key);
	}
	else if (key > ptr->key)
	{
		if (ptr->right != NULL)
			insertPrivate(key, ptr->right);
		else
			ptr->right = createLeaf(key);
	}
	else
		cout << "The key " << key << " Has already been added!" << endl;
}

//
void BST::printInOrder(int key1, int key2)
{
	printInOrderPrivate(root, key1, key2);
}

//
void BST::printInOrderPrivate(node* ptr, int key1, int key2)
{
	/* This function will check if the eithr of given keys
	 * are tree themselves.
	 * 1. first key is a subtree, second key is a leaf
	 * 2. first key is a leaf, second key is a subtree
	 * 3. both keys are subtrees
	 * 4. both keys are leaves
	 * The logic recursively goes down the tree and find the
	 * specified key range passed from driver.cpp file
	 * */
	if (ptr == NULL)
		return;

	if (ptr->key < key1)
		printInOrderPrivate(ptr->right, key1, key2);

	else if (ptr->key >= key1 && ptr->key <= key2)
	{
		printInOrderPrivate(ptr->left, key1, key2);
		cout << ptr->key << " ";
		printInOrderPrivate(ptr->right, key1, key2);
	}
	else
		printInOrderPrivate(ptr->right, key1, key2);

}

//
int BST::findSmallest()
{
	return findSmallestPrivate(root);
}

//
int BST::findSmallestPrivate(node* ptr)
{
	if (root == NULL)
	{
		cout << "The tree is empty!" << endl;
		return -1;
	}
	else
	{
		if (ptr->left != NULL)
			return findSmallestPrivate(ptr->left);
		else
			return ptr->key;
	}
}

void BST::print()
{
	printPrivate(root);
}

//
void BST::printPrivate(node *ptr)
{
	if (root != NULL)
	{
		if (ptr->left != NULL)
			printPrivate(ptr->left);
		cout << ptr->key << " ";
		if (ptr->right != NULL)
			printPrivate(ptr->right);
	}
	else
		cout << "The tree is empty!" << endl;
}












