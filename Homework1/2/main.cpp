#include "func.h"

int main(void) {
	char str[][6] = { "{()}", "([)]", "{()}[", "" };
	for (int i = 0; i < 4; i++) {
		FunctionTest(str[i]);
	}
	FunctionTest(NULL);
	return 0;
}