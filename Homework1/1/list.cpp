#include "list.h"

int DeleteNodes(Node **phead, double x) {//Delete all the nodes which have value x
	if (*phead == NULL)
		return 0;
	int count = 0;//Count the occurence of x
	Node *present = *phead;//Represent current node
	while (present->next != NULL) {
		if (present->next->data == x) {
			Node *tmp = present->next;//Temporarily record next node of list
			present->next = tmp->next;
			free(tmp);
			count++;
			continue;
		}
		present = present->next;
	}
	present = *phead;//Switch present to first node
	if (present->data == x) {//Check if the first element of list equals to x
		*phead = present->next;
		free(present);
		count++;
	}
	return count;
}

void RemoveDuplicants(Node **phead) {//Remove duplicant elements in a linked list
	Node *present = *phead;//Represent current node
	while (present != NULL && present->next != NULL) {
		if (present->data == present->next->data) {
			DeleteNodes(phead, present->data);
			present = *phead;
			continue;
		}
		present = present->next;
	}
}

void CreateList(Node *phead, int len) {//Create a list which have $len elements 
	Node *present = phead;//Record the present node
	Node *next;//Record next node of linked list
	for (int i = 0; i < len; i++) {
		scanf("%lf", &present->data);
		if (i == len - 1)
			break;
		present->next = (Node *)malloc(sizeof(Node));
		present = present->next;
	}
	present->next = NULL;
}

void PrintList(Node *phead) {//Print out the linked list
	if (phead == NULL) {
		puts("Null");
		return;
	}
	printf("%g", phead->data);
	while (phead->next != NULL) {
		phead = phead->next;
		printf("->%g", phead->data);
	}
	puts("");//Wrap
}

void ListFromArr(Node *phead, double *arr, int size) {//Create a list from array
	Node *present = phead;//Record the current node
	for (int i = 0; i < size; i++) {
		present->data = arr[i];
		if (i == size - 1)
			break;
		present->next = (Node *)malloc(sizeof(Node));
		present = present->next;
	}
	present->next = NULL;
}

void DestroyList(Node *phead) {//Destroy a list
	if (phead == NULL)
		return;
	Node *next = phead->next;
	while (next != NULL) {
		free(phead);
		phead = next;
		next = phead->next;
	}
	free(phead);
}