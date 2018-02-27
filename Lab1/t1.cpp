#include <stdio.h>
long int factR(int n){//Recursive function to calculate the factorial of a number
    if (n > 1)
        return factR(n-1) * n;
    return 1;
}
int main(){
    int number;
    while(true){//Check if the input number is positive
        printf("Please input a positive number: ");        
        scanf("%d", &number);//Scan the number you want to get factorial
        if (number <= 0){
            puts("A positive number is required!");//Remind user to input a positive number
        }
        else{
            break;
        }
    }
    printf("The factorial of %d is %ld\n", number, factR(number));//Output the result of factorial
    return 0;
}