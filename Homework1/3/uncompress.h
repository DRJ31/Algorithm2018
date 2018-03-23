#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *values;
	int top;
} Stack;

char *Uncompress(char *str);//Obtain the uncompressed string

char *ReverseString(char *str);//Reverse a string

bool IsNumber(char c);//Check if the character is a number

bool IsLetter(char c);//Check if the character is a letter

int TenPower(int n);//Get the n power of 10

void CreateStack(Stack *stack);//Create a new stack

bool IsEmpty(Stack *stack);//Check if the stack is empty

void Push(Stack *stack, char c);//Push character to stack

int Pop(Stack *stack);//Pop elements in stack when stack is not empty