#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
** This version of stack use linked list to represent a stack
*/
bool CreateStack(Stack *stack, int size) {
	if (size <= 0)//Return false if the size is incorrect
		return false;
	stack->head = NULL;
	stack->top = -1;
	stack->maxTop = size - 1;
	return true;
}
bool IsEmpty(Stack *stack) {//Check if the stack doesn't have any data
	return stack->top <= -1;
}
bool IsFull(Stack *stack) {
	return stack->top >= stack->maxTop;
}
bool Top(Stack *stack, double *x) {
	if (IsEmpty(stack))
		return false;
	*x = stack->head->values;
	return true;
}
bool Push(Stack *stack, double x) {//The "push" operation of stack
	if (IsFull(stack))//If the stack is full, it will not push data into the stack
		return false;
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->values = x;
	newNode->next = stack->head;//Substitute the top value of linked list stack
	stack->head = newNode;
	stack->top++;
	return true;
}
bool Pop(Stack *stack, double *x) {//The "pop" operation of stack
	if (IsEmpty(stack))//If the stack is empty, the "pop" operation will not be executed
		return false;
	Node *temp = stack->head;
	stack->head = temp->next;
	free(temp);
	stack->top--;
	return true;
}
void DisplayStack(Stack *stack) {
	printf("Top --> ");
	if (IsEmpty(stack)) {//Print the last line if the stack is empty
		printf("|---------------|\n");
		return;
	}
	printf("%-7s%-9g|\n", "|", stack->head->values);//Print the top of stack
	Node *next = stack->head->next;
	for (int i = stack->top - 1; i > -1; i--) {//Print the rest elements of stack
		printf("%8s%-7s%-9g|\n", "", "|", next->values);
		next = next->next;
	}
	printf("%9s---------------|\n", "|");//Print the last line after printing elements in stack
}
void DestroyStack(Stack *stack) {//Free memory of stack after pop all the elements in stack
	free(stack->head);
}
