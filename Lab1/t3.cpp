#include <stdio.h>
int compare(int x, int y, bool judge){//When judge is true, return bigger number, else return smaller number
    if (judge)
        return x >= y ? x : y;
    return x <= y ? x : y;
}
int GCD(int x, int y){//Recursive function of finding biggest divisor
    if (compare(x, y, false) == 0)//Return value of bigger number if the smaller number is 0
        return compare(x, y, true);
    return GCD(compare(x, y, false), compare(x, y, true) % compare(x, y, false));//Continue to find GCD if the remainder is not 0
    
}
int main(){
    int x, y;
    while(true){//Check the input of number x
        printf("Enter number x: ");
        scanf("%d", &x);//Scan number x
        if (x >= 0)
            break;
        puts("Please input a natural number!");//Remind user not to input a non-natural number
    }
    while(true){//Check the input of number y
        printf("Enter number y: ");
        scanf("%d", &y);//Scan number y
        if (y >= 0)
            break;
        puts("Please input a natural number!");//Remind user not to input a non-natural number
    }
    printf("The greatest common divisor of %d and %d is %d.\n", x, y, GCD(x, y));//Output the greatest common divisor of 2 numbers
    return 0;
}