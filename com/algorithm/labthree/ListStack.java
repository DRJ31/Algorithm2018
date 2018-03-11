package com.algorithm.labthree;
public class ListStack extends Stack {
    Node head;
    public void createStack(int size){
        this.head = null;
        this.top = -1;
        this.maxTop = size - 1;
    }
    public boolean isEmpty(){
        return this.head == null;
    }
    public boolean isFull(){
        return this.top >= this.maxTop;
    }
    public double getTopValue(){
        return head.data;
    }
    public boolean push(double x){
        if (this.isFull())
            return false;
        Node newHead = new Node();
        newHead.data = x;
        newHead.next = this.head;
        this.head = newHead;
        this.top++;
        return true;
    }
    public boolean pop(){
        if (this.isEmpty())
            return false;
        this.top--;
        this.head = this.head.next;
        return true;
    }
    public void displayStack(){
        System.out.print("Top --> ");
        if (this.isEmpty()){
            System.out.print("|---------------|");
            return;
        }
        System.out.printf("%-7s%-9s|\n", "|", this.head.data);
        Node next = this.head.next;
        while (next != null){
            System.out.printf("%8s%-7s%-9s|\n", "", "|", next.data);
            next = next.next;
        }
        System.out.printf("%9s---------------|\n", "|");
    }
}