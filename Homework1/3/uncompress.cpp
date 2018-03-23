#include "uncompress.h"

char *Uncompress(char *str) {//Obtain the compressed string
	//Stack main process the string and return result, temp temporarily store the characters to process
	Stack main, temp;
	CreateStack(&main);
	CreateStack(&temp);
	int times = 0;//Record number that the string will repeat
	if (str == NULL)
		return NULL;
	while (*str != '\0') {
		Push(&main, *str);
		if (main.values[main.top] == ']') {//Pop values in the stack until meet number
			while (!IsNumber(main.values[main.top])) {
				char pop = Pop(&main);//Record character which have been pop
				if (IsLetter(pop)) {//Record string which will be repeat
					Push(&temp, pop);
				}
			}
			int len = 0;//The length of number
			while (IsNumber(main.values[main.top])) {//Calculate how many tims to repeat
				times += (Pop(&main) - '0') * TenPower(len);
				len++;
			}
			for (int i = 0; i < times; i++) {//Connect the repeat string to main string
				strcat(main.values, ReverseString(temp.values));
				main.top += strlen(temp.values);
			}
			times = 0;
			while (!IsEmpty(&temp)) {//Clear temp stack
				Pop(&temp);
			}
		}
		*str++;
	}
	return main.values;
}

char *ReverseString(char *str) {//Reverse a string
	char *newString = (char *)malloc(sizeof(char) * (strlen(str) + 1));
	for (int i = strlen(str) - 1; i >= 0; i--) {
		newString[strlen(str) - i - 1] = str[i];
	}
	newString[strlen(str)] = '\0';
	return newString;
}

bool IsNumber(char c) {//Check if the character is a number
	return c >= '0' && c <= '9';
}

bool IsLetter(char c) {//Check if the character is a letter
	return c >= 'a' && c <= 'z';
}

int TenPower(int n) {//Get the n power of 10
	if (n <= 0)
		return 1;
	return 10 * TenPower(n - 1);
}

void CreateStack(Stack *stack) {//Create a new stack
	stack->values = (char *)malloc(sizeof(char) * 10000);//Alloc memory for stack
	stack->values[0] = '\0';
	stack->top = -1;
}

bool IsEmpty(Stack *stack) {//Check if the stack is empty
	return stack->top <= -1;
}

void Push(Stack *stack, char c) {//Push character to stack
	stack->values[++stack->top] = c;
	stack->values[stack->top + 1] = '\0';
}

int Pop(Stack *stack) {//Pop elements in stack when stack is not empty
	if (IsEmpty(stack))
		return 0;
	stack->top--;
	char popChar = stack->values[stack->top + 1];//The char which have been pop
	stack->values[stack->top + 1] = '\0';
	return popChar;//Return the element which have popped
}