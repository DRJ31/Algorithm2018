#include "BST.h"
#include <stdlib.h>

Node* insertNode(Node **proot, int x){
    Node *current = *proot;//Record the current position of pointer
    if (current == NULL) {
        *proot = (Node *)malloc(sizeof(Node));
        current = *proot;
        current->key = x;
        current->left = NULL;
        current->right = NULL;
        return current;
    }
    while (current != NULL) {
        if (x == current->key)
            break;
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
    Node *deleteNode = findNode(*proot, x);
    if (deleteNode != NULL) {
        Node *present = *proot;//Find the previous node of the deleted node
        if (x == present->key) {//When the root is deleteNode
            if (present->right != NULL) {
                present = present->right;
                if (present->left != NULL) {
                    while (present->left->left != NULL)
                        present = present->left;
                    *proot = present->left;
                    present->left = NULL;
                    present = *proot;
                    present->left = deleteNode->left;
                    present->right = deleteNode->right;
                    return deleteNode;
                }
                *proot = present;
                present->left = deleteNode->left;
                return deleteNode;
            }
            *proot = present->left;
            return deleteNode;
        }
        while (present->left->key != x && present->right->key != x) {
            present = x < present->key ? present->left : present->right;
        }
        Node *nextNode;//Record the next node which replace the position of deleted node
        if (deleteNode->right != NULL) {
            nextNode = deleteNode->right;
            if (nextNode->left != NULL) {
                while (nextNode->left->left != NULL)
                    nextNode = nextNode->left;
                if (present->key > x) {
                    present->left = nextNode->left;
                    nextNode->left = NULL;
                    nextNode = present->left;
                    nextNode->left = deleteNode->left;
                    nextNode->right = deleteNode->right;
                    return deleteNode;
                }
                else {
                    present->right = nextNode->left;
                    nextNode->left = NULL;
                    nextNode = present->right;
                    nextNode->left = deleteNode->left;
                    nextNode->right = deleteNode->right;
                    return deleteNode;
                }
            }
            if (x < present->key)
                present->left = nextNode;
            else
                present->right = nextNode;
            nextNode->left = deleteNode->left;
            return deleteNode;
        }
        if (x < present->key)
            present->left = present->left->left;
        else
            present->right = present->right->left;
    }
    return deleteNode;
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
