#include <stdio.h>
#include <stdlib.h>
void reverseR(int length, char *str){
    if (length <= 1)
        return;
    char tmp = *str;
    *str = *(str + length -1);
    *(str + length -1) = tmp;
    reverseR(length - 2, str + 1);
}
int main(){
    int length;
    char *str;
    printf("Please input the length of the string: ");
    scanf("%d", &length);
    getchar();
    str = (char *)malloc(sizeof(char) * (length + 1));
    puts("Please input the string: ");
    fgets(str, length + 1, stdin);
    reverseR(length, str);
    puts(str);
    return 0;
}