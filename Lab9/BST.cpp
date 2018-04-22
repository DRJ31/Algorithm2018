//
// Binary Search Tree
// Author: Renjie Deng
// Created on: April 22nd
//

#include "BST.h"
#include <stdlib.h>

Node* insertNode(Node **proot, int x){
    Node *current = *proot;//Record the current position of pointer
    if (current == NULL) {//Check if the first node is null
        *proot = (Node *)malloc(sizeof(Node));
        current = *proot;
        current->key = x;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
    while (current != NULL) {
        if (x == current->key)//Stop insert if same element exists
            break;
        //Find the position to insert
        if (x < current->key) {
            if (current->left != NULL) {
                current = current->left;
                continue;
            }
            current->left = (Node *)malloc(sizeof(Node));
            current->left->key = x;
            current->left->left = NULL;
            current->left->right = NULL;
            return current->left;
        }
        if (x > current->key) {
            if (current->right != NULL) {
                current = current->right;
                continue;
            }
            current->right = (Node *)malloc(sizeof(Node));
            current->right->key = x;
            current->right->left = NULL;
            current->right->right = NULL;
            return current->right;
        }
    }
    return NULL;
}

Node* deleteNode(Node **proot, int x){
    Node *deletedNode = findNode(*proot, x);//Confirm the existance of node to delete
    if (deletedNode != NULL) {//Check if node to delete exists
        Node *present = *proot;//Find the previous node of the deleted node
        if (x == present->key) {//When the root is the deleteNode
            if (present->right != NULL) {
                present = present->right;
                if (present->left != NULL) {
                    while (present->left->left != NULL)
                        present = present->left;
                    *proot = present->left;
                    present->left = NULL;
                    present = *proot;
                    present->left = deletedNode->left;
                    present->right = deletedNode->right;
                    return deletedNode;
                }
                *proot = present;
                present->left = deletedNode->left;
                return deletedNode;
            }
            *proot = present->left;
            return deletedNode;
        }
        while (true) {//Find the previous node of the deleteNode
            if (present->left != NULL && present->right != NULL) {
                if (present->left->key != x && present->right->key != x) {
                    present = x < present->key ? present->left : present->right;
                    continue;
                }
            }
            else if (present->left != NULL && present->right == NULL) {
                if (present->left->key != x) {
                    present = present->left;
                    continue;
                }
            }
            else if (present->left == NULL && present->right != NULL) {
                if (present->right->key != x) {
                    present = present->right;
                    continue;
                }
            }
            break;
        }
        Node *nextNode;//Record the next node which replace the position of deleted node
        //Replace the deletedNode with another node
        if (deletedNode->right != NULL) {
            nextNode = deletedNode->right;
            if (nextNode->left != NULL) {
                while (nextNode->left->left != NULL)
                    nextNode = nextNode->left;
                if (present->key > x) {
                    present->left = nextNode->left;
                    nextNode->left = NULL;
                    nextNode = present->left;
                    nextNode->left = deletedNode->left;
                    nextNode->right = deletedNode->right;
                    return deletedNode;
                }
                else {
                    present->right = nextNode->left;
                    nextNode->left = NULL;
                    nextNode = present->right;
                    nextNode->left = deletedNode->left;
                    nextNode->right = deletedNode->right;
                    return deletedNode;
                }
            }
            if (x < present->key)
                present->left = nextNode;
            else
                present->right = nextNode;
            nextNode->left = deletedNode->left;
            return deletedNode;
        }
        if (x < present->key)
            present->left = present->left->left;
        else
            present->right = present->right->left;
    }
    return deletedNode;
}

Node* findNode(Node *root, int x){
    Node *present = root; //Record present node
    while (present != NULL) {
        if (x < present->key) {
            present = present->left;
        }
        else if (x > present->key) {
            present = present->right;
        }
        else {
            return present;
        }
    }
    return NULL;
}

void destroyTree(Node *root){
    Node *deleted;//Record the deleted node
    while (root != NULL) {
        deleted = deleteNode(&root, root->key);
        free(deleted);
    }
}
