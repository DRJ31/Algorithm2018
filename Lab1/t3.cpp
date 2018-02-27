#include <stdio.h>
int compare(int x, int y, bool judge){//When judge is true, return bigger number, else return smaller number
    if (judge)
        return x >= y ? x : y;
    return x <= y ? x : y;
}
int GCD(int x, int y){
    if (compare(x, y, false) == 0)
        return compare(x, y, true);
    return GCD(compare(x, y, false), compare(x, y, true) % compare(x, y, false));
    
}
int main(){
    int x, y;
    while(true){//Check the input of number x
        printf("Enter number x: ");
        scanf("%d", &x);
        if (x >= 0)
            break;
        puts("Please input a natural number!");
    }
    while(true){//Check the input of number y
        printf("Enter number y: ");
        scanf("%d", &y);
        if (y >= 0)
            break;
        puts("Please input a natural number!");
    }
    printf("The greatest common divisor of %d and %d is %d.\n", x, y, GCD(x, y));
    return 0;
}