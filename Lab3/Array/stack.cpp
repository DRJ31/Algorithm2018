#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/*
** This version of stack use array to represent a stack
*/
bool CreateStack(Stack *stack, int size) {
	if (size <= 0)//Stop creating stack if size is invalid
		return false;
	stack->values = (double *)malloc(sizeof(double) * size);//Alloc memory for stack
	stack->top = -1;
	stack->maxTop = size - 1;
	return true;
}
bool IsEmpty(Stack *stack) {//Check if the stack is empty
	return stack->top <= -1;
}
bool IsFull(Stack *stack) {//Check if the stack is full
	return stack->top >= stack->maxTop;
}
bool Top(Stack *stack, double *x) {//Fetch the data in the top of stack
	if (IsEmpty(stack))//Check if stack is empty
		return false;
	*x = stack->values[stack->top];
	return true;
}
bool Push(Stack *stack, double x) {//Push data to stack
	if (IsFull(stack))//Stop pushing data if stack is full
		return false;
	stack->values[++stack->top] = x;
	return true;
}
bool Pop(Stack *stack, double *x) {//Pop data in stack
	if (IsEmpty(stack))//If stack is empty, pop operation will not be executed
		return false;
	*x = stack->values[--stack->top];
	return true;
}
void DisplayStack(Stack *stack) {
	printf("Top --> ");//Print the top of stack
	if (IsEmpty(stack)) {
		printf("|---------------|\n");//Print the last line if stack is empty
		return;
	}
	printf("%-7s%-9g|\n", "|", stack->values[stack->top]);//Print the top of stack
	for (int i = stack->top - 1; i > -1; i--) {
		printf("%8s%-7s%-9g|\n", "", "|", stack->values[i]);//Print elements in stack
	}
	printf("%9s---------------|\n", "|");//Print the last line after printing elements in stack
}
void DestroyStack(Stack *stack) {//Free memory of stack
	free(stack->values);
}
