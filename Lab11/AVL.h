typedef struct Node 
{
  int key, height;
  Node *left, *right;
} Node;

Node* insertNode(Node **proot, int x);
/*
 function:
	inserts a new node to the tree
 input:
	proot - pointer to the pointer to the tree root
	x - the key of the new node
 output:
	returns a pointer to the newly inserted node 
	returns NULL if insertion is not successful
*/

Node* deleteNode(Node **proot, int x);
/*
 function:
	removes a node from the tree without freeing it
 input:
	proot - pointer to the pointer to the tree root
	x - the key of of the node to be deleted
 output:
	returns a pointer to the deleted node 
	returns NULL if no such node exists
*/

Node* findNode(Node *root, int x);
/*
 function:
	searches for a node in the tree
 input:
	root - pointer to the tree root
	x - the key of of the node to be searched
 output:
	returns a pointer to the found node 
	returns NULL if no such node exists
*/

void destroyTree(Node *root);
/*
 function:
	deletes all the nodes in the tree and frees the memory occupied by them
 input:
	root - pointer to the tree node
*/

void printTree(Node * root);
/*
 function:
	prints ascii tree for given Node structure
	this function is already implemented in printTree.cpp
 input:
	root - pointer to the tree node
*/

Node* createNode(Node **proot, int x);
/*
 function:
	create a new node
 input:
	x - the value of node
	height - the height of this node
*/

Node* deleteMin(Node **proot);
/*
 function:
	delete the smallest number in the right tree or the biggest in the left tree
 input:
	proot - the node you want to substitute with deleted node
*/

int isBalance(Node *root); //Check if the tree is balance and return type of unbalance

void leftRotate(Node *root);//Left rotate current tree

void rightRotate(Node *root);//Right rotate current tree

Node* deleteRoot(Node **proot);//Delete the selected root
