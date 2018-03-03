package com.algorithm.labone;
import java.util.Scanner;

public class GCD {
    public int compare(int x, int y, boolean judge){//True return bigger, false smaller
        if (judge)
            return x >= y ? x : y;
        return x <= y ? x : y;
    }
    public int recursive(int x, int y){
        if (compare(x, y, false) == 0)
            return compare(x, y, true);
        return recursive(compare(x, y, false), compare(x, y, true) % compare(x, y, false));
    }
    public static void main(String[] args){
        int x, y;
        GCD gcd = new GCD();
        Scanner scan = new Scanner(System.in);
        while(true){
            System.out.print("Enter number x: ");
            x = scan.nextInt();
            if (x >= 0)
                break;
            System.out.println("Please input a natural number!");
        }
        while(true){
            System.out.print("Enter number y: ");
            y = scan.nextInt();
            if (y >= 0)
                break;
            System.out.println("Please input a natural number!");
        }
        scan.close();
        System.out.printf("The greatest common divisor of %d and %d is %d\n", x, y, gcd.recursive(x, y));
    }
}