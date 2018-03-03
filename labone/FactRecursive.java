package labone;
import java.util.Scanner;

public class FactRecursive {
    long recursive(int n){
        if (n > 1)
            return recursive(n - 1) * n;
        return 1;
    }
    public static void main(String[] args){
        int number;
        FactRecursive fact = new FactRecursive();
        Scanner scan = new Scanner(System.in);
        while (true){
            System.out.print("Enter a positive number: ");
            number = scan.nextInt();
            if (number > 0)
                break;
            System.out.println("Please input a positive number!");
        }
        scan.close();
        System.out.printf("The factorial of %d is %d\n", number, fact.recursive(number));
    }
}