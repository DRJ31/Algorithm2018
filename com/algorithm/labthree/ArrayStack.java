package com.algorithm.labthree;
public class ArrayStack extends Stack{
    double[] values;
    public void createStack(int size){
        this.maxTop = size - 1;
        values = new double[this.maxTop];
        this.top = -1;
    }
    public boolean isEmpty(){
        return this.top <= -1;
    }
    public boolean isFull(){
        return this.top >= this.maxTop;
    }
    public double getTopValue(){
        return this.values[this.top];
    }
    public boolean push(double x){
        if (this.isFull())
            return false;
        this.values[++this.top] = x;
        return true;
    }
    public boolean pop(){
        if (this.isEmpty())
            return false;
        this.top--;
        return true;
    }
    public void displayStack(){
        System.out.print("Top --> ");
        if (this.isEmpty()){
            System.out.print("|---------------|");
            return;
        }
        System.out.printf("%-7s%-9s|\n", "|", this.values[this.top]);
        for (int i = this.top - 1; i > -1; i--) {
            System.out.printf("%8s%-7s%-9s|\n", "", "|", this.values[i]);
        }
        System.out.printf("%9s---------------|\n", "|");
    }
}