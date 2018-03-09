#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
bool CreateStack(Stack *stack, int size) {
	if (size <= 0)
		return false;
	stack->head = NULL;
	stack->top = -1;
	stack->maxTop = size - 1;
	return true;
}
bool IsEmpty(Stack *stack) {
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
bool Push(Stack *stack, double x) {
	if (IsFull(stack))
		return false;
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->values = x;
	newNode->next = stack->head;
	stack->head = newNode;
	stack->top++;
	return true;
}
bool Pop(Stack *stack, double *x) {
	if (IsEmpty(stack))
		return false;
	Node *temp = stack->head;
	stack->head = temp->next;
	free(temp);
	stack->top--;
	return true;
}
void DisplayStack(Stack *stack) {
	printf("Top --> ");
	if (IsEmpty(stack)) {
		printf("|---------------|\n");
		return;
	}
	printf("%-7s%-9g|\n", "|", stack->head->values);
	Node *next = stack->head->next;
	for (int i = stack->top - 1; i > -1; i--) {
		printf("%8s%-7s%-9g|\n", "", "|", next->values);
		next = next->next;
	}
	printf("%9s---------------|\n", "|");
}
void DestroyStack(Stack *stack) {
	free(stack->head);
}