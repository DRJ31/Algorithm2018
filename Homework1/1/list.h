#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	double data;
	struct node *next;
} Node;

int DeleteNodes(Node **phead, double x);//Delete all the nodes which have value x

void RemoveDuplicants(Node **phead);//Remove duplicant elements in a linked list

void CreateList(Node *phead, int len);//Create a list which have $len elements 

void PrintList(Node *phead);//Print out the linked list

void ListFromArr(Node *phead, double *arr, int size);//Create a list from array

void DestroyList(Node *phead);//Destroy a list