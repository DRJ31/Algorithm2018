#include <stdio.h>
#include <stdlib.h>
#include "list.h"
bool IsEmpty(Node *head){//Check if the ListNode is empty
    return head == NULL;
}
Node* InsertNode(Node **phead, int index, double x){
    Node *insert = (Node *)malloc(sizeof(Node));
    insert->data = x;
    Node *next = *phead;
    if (index < 0){//Check the input of user
        puts("Please input a positive position!");
        return *phead;
    }
    if (index == 0){//Replace the node head when index = 0
        *phead = insert;
        insert->next = next;
        return *phead;
    }
    for (int i = 1; i < index; i++){//Go to Node to insert
        if (next == NULL){
            printf("Index %d out of range!", index);
            return *phead;
        }
        next = next->next;
    }
    insert->next = next->next;//Insert to the Node
    next->next = insert;
    return insert;
}
int FindNode(Node* head, double x){
    int pos = 1;//Suppose the first position is 1
    while(head != NULL){
        if (head->data == x)
            return pos;
        head = head->next;
        pos++;
    }
    return 0;//Return 0 if cannot find the data
}
int DeleteNode(Node **phead, double x){
    int pos = 1;
    Node *present = *phead;
    if (IsEmpty(present))
        return 0;
    Node *next = present->next;
    if (present->data == x){//Check whether the head will be replaced
        *phead = next;
        free(present);
        return pos;
    }
    while(present->next != NULL){//Find the Node which will be deleted
        pos++;
        if (present->next->data == x){
            next = present->next;
            present->next = present->next->next;
            free(next);
            return pos;
        }
        present = present->next;
    }
    return 0;//If cannot find, return 0
}
void DisplayList(Node *head){
    if (IsEmpty(head)){
        printf("The list is empty.");
        return;
    }
    printf("%g", head->data);//Print the first data
    head = head->next;
    while(head != NULL){
        printf("->%g", head->data);//Print the rest data
        head = head->next;
    }
    printf("\n");
}
void DestroyList(Node *head){
    Node *next = head->next;//Record the next Node of Node which will be destroyed soon
    while (next != NULL){
        free(head);//Destroy Node
        head = next;
        next = head->next;
    }
    free(head);//Destroy last Node
}
int main() 
{ 
	Node *head = 0;
	for(int i=0; i<5; i++)
		InsertNode(&head, i, i);
	DisplayList(head);
	for(int i=0; i<5; i++)
		InsertNode(&head, 0, i);
	DisplayList(head);
	for(int i=0; i<7; i+=2){
		int idx = FindNode(head, i);
		if(idx>0)
			printf("%d is at position %d.\n", i, idx);
		else
			printf("%d is not in the list.\n", i);
	}
	DeleteNode(&head, 0);
	DisplayList(head);
	DestroyList(head);
}  