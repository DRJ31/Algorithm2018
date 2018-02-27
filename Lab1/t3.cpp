#include <stdio.h>
int compare(int x, int y, bool judge){
    if (judge){
        if (x >= y)
            return x;
        return y;
    }
    if (x <= y)
        return x;
    return y;
}
int GCD(int x, int y){
    if (compare(x, y, false) == 0)
        return compare(x, y, true);
    if (x == y)
        return x;
    int remainder = compare(x, y, true) % compare(x, y, false);
    if (remainder == 0)
        return compare(x, y, false);
    return GCD(compare(x, y, false), remainder);
    
}
int main(){
    int x, y;
    while(true){
        printf("Enter number x: ");
        scanf("%d", &x);
        if (x >= 0)
            break;
        puts("Please input a natural number!");
    }
    while(true){
        printf("Enter number y: ");
        scanf("%d", &y);
        if (y >= 0)
            break;
        puts("Please input a natural number!");
    }
    printf("The greatest common divisor of %d and %d is %d.\n", x, y, GCD(x, y));
    return 0;
}