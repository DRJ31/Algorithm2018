#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 50//The longest string the program could receive
void reverseR(int length, char *str){
    if (length <= 1)//When the length of string is less than 1, stop without execute it
        return;
    //Swap the first letter of string and the last letter of string
    char tmp = *str;
    *str = *(str + length -1);
    *(str + length -1) = tmp;
    //Recursive reverse
    reverseR(length - 2, str + 1);
}
int main(){
    char str[MAXLENGTH];
    puts("Please input the string: ");//Remind users to input string to reverse
    fgets(str, MAXLENGTH, stdin);//Get string from user
    reverseR(strlen(str), str);
    puts(str);//Output the string
    return 0;
}