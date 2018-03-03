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
    if (index == 0){//Replace the node head when index = 0
        *phead = insert;
        insert->next = next;
        return *phead;
    }
    for (int i = 1; i < index; i++){//Go to Node to insert
        next = next->next;
    }
    insert->next = next->next;//Insert to the Node
    next->next = insert;
    return *phead;
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
    Node *next = present->next;
    if (present->data == x){//Check whether the head will be replaced
        *phead = next;
        free(present);
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
    printf("%g", head->data);//Print the first data
    head = head->next;
    while(head != NULL){
        printf("->%g", head->data);//Print the rest data
        head = head->next;
    }
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