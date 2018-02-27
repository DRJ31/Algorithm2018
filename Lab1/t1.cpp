#include <stdio.h>
long int factR(int n){
    if (n > 1)
        return factR(n-1) * n;
    return 1;
}
int main(){
    int number;
    while(true){//Check if the input number is positive
        printf("Please input a positive number: ");        
        scanf("%d", &number);
        if (number <= 0){
            puts("A positive number is required!");
        }
        else{
            break;
        }
    }
    printf("The factorial of %d is %ld\n", number, factR(number));
    return 0;
}