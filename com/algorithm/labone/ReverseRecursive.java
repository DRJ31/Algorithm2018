package com.algorithm.labone;
import java.util.Scanner;

public class ReverseRecursive {
    public String recursive(String str){
        if (str.length() == 0)
            return "";
        if (str.length() == 1)
            return str;
        return recursive(str.substring(1)) + str.charAt(0);
    }
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        ReverseRecursive reverse = new ReverseRecursive();
        System.out.println("Enter a string: ");
        String str = scan.nextLine();
        str = reverse.recursive(str);
        System.out.println(str);
    }
}