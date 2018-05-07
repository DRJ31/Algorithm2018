//
// Author: Renjie Deng
// Date: April 28th, 2018
// AVL Tree
//

#include "AVL.h"
#include "stdlib.h"
#include "stdio.h"

Node* insertNode(Node **proot, int x){
	Node *newNode;
	if ((*proot) == NULL)
		return createNode(x);
	if ((*proot)->key == x)
		return NULL;
	if ((*proot)->key > x)
		newNode = insertNode(&(*proot)->left, x);
	else
		newNode = insertNode(&(*proot)->right, x);

}

Node* deleteNode(Node **proot, int x){
	Node *pnode = findNode(*proot, x); //Record the position of the node to delete
	if (pnode == NULL)
		return NULL;
	if (pnode->right == NULL)
		pnode = deleteMin(&(*proot));
	else
		pnode->key = deleteMin(&(*proot))->key;
	return pnode;
}

Node* findNode(Node *root, int x){
	if (root == NULL)
		return NULL;
	if (root->key > x)
		return findNode(root->left, x);
	if (root->key < x)
		return findNode(root->right, x);
	if (root->key == x)
		return root;
	return NULL;
}

void destroyTree(Node *root){
	Node *deleted;
	while (root != NULL) {
		deleted = deleteNode(&root, root->key);
		free(deleted);
	}
}

Node* createNode(int x) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->left = NULL;
	node->right = NULL;
	node->key = x;
	node->height = 0;
	return node;
}

Node* deleteMin(Node **proot) {
	if ((*proot)->right == NULL)
		return (*proot)->left;
	Node *deleted;//Record the smallest node
	if ((*proot)->right->left == NULL) {
		deleted = (*proot)->right;
		(*proot)->right = NULL;
		return deleted;
	}
	*proot = (*proot)->right;
	while ((*proot)->left->left != NULL)//Find the smallest node
		*proot = (*proot)->left;
	deleted = (*proot)->left;
	(*proot)->left = NULL;
	return deleted;
}