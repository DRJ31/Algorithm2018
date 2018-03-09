#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
bool CreateStack(Stack *stack, int size) {
	if (size <= 0)
		return false;
	stack->values = (double *)malloc(sizeof(double) * size);
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
	*x = stack->values[stack->top];
	return true;
}
bool Push(Stack *stack, double x) {
	if (IsFull(stack))
		return false;
	stack->values[++stack->top] = x;
	return true;
}
bool Pop(Stack *stack, double *x) {
	if (IsEmpty(stack))
		return false;
	*x = stack->values[--stack->top];
	return true;
}
void DisplayStack(Stack *stack) {
	printf("Top --> ");
	if (IsEmpty(stack)) {
		printf("|---------------|\n");
		return;
	}
	printf("%-7s%-9g|\n", "|", stack->values[stack->top]);
	for (int i = stack->top - 1; i > -1; i--) {
		printf("%8s%-7s%-9g|\n", "", "|", stack->values[i]);
	}
	printf("%9s---------------|\n", "|");
}
void DestroyStack(Stack *stack) {
	free(stack->values);
}