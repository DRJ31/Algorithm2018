#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 50//The longest string the program could receive
void reverseR(int length, char *str){
    if (length <= 1)
        return;
    char tmp = *str;
    *str = *(str + length -1);
    *(str + length -1) = tmp;
    reverseR(length - 2, str + 1);
}
int main(){
    char str[MAXLENGTH];
    puts("Please input the string: ");
    fgets(str, MAXLENGTH, stdin);
    reverseR(strlen(str), str);
    puts(str);
    return 0;
}