#include "func.h"

bool ValidBrackets(char *str) {//Check if the bracket is valid
	if (str == NULL)//Check if the string is NULL
		return false;
	int size = strlen(str);//The length of string
	if (size % 2 != 0)
		return false;
	for (int i = 0; i < size / 2; i++) {//Check if the bracket is valid
		if (!CorrectBracket(str[i], str[size - 1 - i]))
			return false;
	}
	return true;
}

bool CorrectBracket(char left, char right) {//Check if the two brackets are a pair
	switch (left) {
		case '(':
			return right == ')';
			break;
		case '[':
			return right == ']';
			break;
		case '{':
			return right == '}';
			break;
		default:
			return false;
	}
}

void FunctionTest(char *str) {//Test if the program can get the right result
	printf("\n##### Testing #####\n");
	if (str == NULL)
		printf("Input: NULL\n");
	else
		printf("Input: \"%s\"\n", str);
	if (ValidBrackets(str))
		puts("True");
	else
		puts("False");
	printf("\n");
}