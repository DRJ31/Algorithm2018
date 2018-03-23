#include "uncompress.h"

int main(void) {
	char str[][20] = { "", "abc", "a11[c]d", "3[a]2[bc]", "3[a2[c]]", "2[abb3[cd]]ef" };
	for (int i = 0; i < 6; i++) {
		printf("\n##### Testing #####\n");
		printf("Origin string: %s\n", str[i]);
		printf("Extracted string: %s\n", Uncompress(str[i]));
	}
	return 0;
}