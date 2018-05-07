//
// Author: Renjie Deng
// Date: May 7th, 2018
// AVL Tree
//

#include "AVL.h"
#include "stdlib.h"
#include "stdio.h"

Node* insertNode(Node **proot, int x){
	Node *newNode;
	if ((*proot) == NULL)
		return createNode(&(*proot), x);
	if ((*proot)->key == x)
		return NULL;
    if ((*proot)->key > x) {
        newNode = insertNode(&(*proot)->left, x);
        if ((*proot)->height == (*proot)->left->height)
            (*proot)->height++;
    }
    else {
        newNode = insertNode(&(*proot)->right, x);
        if ((*proot)->height == (*proot)->right->height)
            (*proot)->height++;
    }
    //Balance the tree
    switch (isBalance(*proot)) {
        case 1:
            rightRotate(*proot);
            break;
        case 2:
            leftRotate(*proot);
            break;
        case 3:
            leftRotate((*proot)->left);
            rightRotate(*proot);
            break;
        case 4:
            rightRotate((*proot)->right);
            leftRotate(*proot);
            break;
        default:
            break;
    }
    return newNode;
}

Node* deleteNode(Node **proot, int x){
    Node *matchNode;
	if (*proot == NULL)
        return NULL;
    if ((*proot)->key > x)
        matchNode = deleteNode(&(*proot)->left, x);
    else if ((*proot)->key < x)
        matchNode = deleteNode(&(*proot)->right, x);
    else
        matchNode = deleteRoot(&(*proot));
    //Update height
    if (*proot != NULL) {
        if ((*proot)->left == NULL && (*proot)->right == NULL)
            (*proot)->height = 0;
        else if ((*proot)->left == NULL)
            (*proot)->height = (*proot)->right->height + 1;
        else if ((*proot)->right == NULL)
            (*proot)->height = (*proot)->left->height + 1;
        else
            (*proot)->height = (*proot)->left->height > (*proot)->right->height ? (*proot)->left->height + 1 : (*proot)->right->height + 1;
        //Balance the tree
        switch (isBalance(*proot)) {
            case 1:
                rightRotate(*proot);
                break;
            case 2:
                leftRotate(*proot);
                break;
            case 3:
                leftRotate((*proot)->left);
                rightRotate(*proot);
                break;
            case 4:
                rightRotate((*proot)->right);
                leftRotate(*proot);
                break;
            default:
                break;
        }
    }
    return matchNode;
}

Node* deleteRoot(Node **proot) {
    Node *currentNode = *proot;
    if ((*proot)->left == NULL) {
        *proot = (*proot)->right;
        return currentNode;
    }
    if ((*proot)->right == NULL) {
        *proot = (*proot)->left;
        return currentNode;
    }
    Node *minNode = deleteMin(&(*proot)->right);
    minNode->left = (*proot)->left;
    minNode->right = (*proot)->right;
    *proot = minNode;
    return currentNode;
}

Node *deleteMin(Node **proot) {
    Node *minNode;
    if ((*proot)->left == NULL) {
        minNode = (*proot);
        *proot = (*proot)->right;
        return minNode;
    }
    minNode = deleteMin(&(*proot)->left);
    //Update height
    if ((*proot)->right != NULL) {
        if ((*proot)->left != NULL)
            (*proot)->height = (*proot)->left->height > (*proot)->right->height ? (*proot)->left->height + 1 : (*proot)->right->height + 1;
        else
            (*proot)->height = (*proot)->right->height + 1;
    }
    else {
        if ((*proot)->left != NULL)
            (*proot)->height = (*proot)->left->height + 1;
        else
            (*proot)->height = 0;
    }
    //Balance the tree
    switch (isBalance(*proot)) {
        case 1:
            rightRotate(*proot);
            break;
        case 2:
            leftRotate(*proot);
            break;
        case 3:
            leftRotate((*proot)->left);
            rightRotate(*proot);
            break;
        case 4:
            rightRotate((*proot)->right);
            leftRotate(*proot);
            break;
        default:
            break;
    }
    return minNode;
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

<<<<<<< HEAD
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
=======
Node* createNode(Node **proot, int x) {
	*proot = (Node *)malloc(sizeof(Node));
	(*proot)->left = NULL;
	(*proot)->right = NULL;
	(*proot)->key = x;
	(*proot)->height = 0;
	return *proot;
}


void leftRotate(Node *root) {
    Node *newHead = root->right;
    Node *oldHead;
    createNode(&oldHead, root->key);
    oldHead->left = root->left;
    if (oldHead->left == NULL)
        oldHead->height = 0;
    else
        oldHead->height = root->height - 2;
    oldHead->right = newHead->left;
    root->left = oldHead;
    root->right = newHead->right;
    root->key = newHead->key;
    root->height = root->left->height + 1;
    if (root->right != NULL)
        root->right->height = root->height - 1;
    free(newHead);
}

void rightRotate(Node *root) {
    Node *newHead = root->left;
    Node *oldHead;
    createNode(&oldHead, root->key);
    oldHead->right = root->right;
    if (oldHead->right == NULL)
        oldHead->height = 0;
    else
        oldHead->height = root->height - 2;
    oldHead->left = newHead->right;
    root->right = oldHead;
    root->left = newHead->left;
    root->key = newHead->key;
    root->height = root->right->height + 1;
    if (root->left != NULL)
        root->left->height = root->height - 1;
    free(newHead);
}

int isBalance(Node *root) {
    if (root->height == 2 && root->right == NULL) {
        if (root->left->left == NULL)
            return 3;
        return 1;
    }
    if (root->height == 2 && root->left == NULL) {
        if (root->right->right == NULL)
            return 4;
        return 2;
    }
    if (root->left != NULL && root->height - root->left->height == 3) {
        if (root->right->right->height > root->right->left->height)
            return 2;
        return 4;
    }
    if (root->right != NULL && root->height - root->right->height == 3) {
        if (root->left->left->height > root->left->right->height)
            return 1;
        return 3;
    }
    return 0;
}
>>>>>>> fda663aefc8f2569ab94ce3291f99dccfb6c1ef4
