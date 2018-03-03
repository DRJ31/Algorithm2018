package com.algorithm.labtwo;
import java.util.Scanner;

public class ListNode {
    //Function DestroyList can't be implemented in Java
    public boolean IsEmpty(Node head){//Check if the LinkedList is empty
        return head == null;
    }
    public Node CreateList(){//Create LinkedList from input
        Scanner scan = new Scanner(System.in);
        int length;
        while(true){
            System.out.print("Enter the length of linked list: ");
            length = scan.nextInt();
            if (length > 0)
                break;
            System.out.println("Please enter a positive number!");
        }
        System.out.println("Enter linked list: ");
        Node head = new Node();
        Node present = head;
        for (int i = 0; i < length - 1; i++){
            present.data = scan.nextDouble();
            present.next = new Node();
            present = present.next;
        }
        present.data = scan.nextDouble();
        present.next = null;
        scan.close();
        return head;
    }
    public Node InsertNode(Node phead, int index, double x){//Insert number x to LinkedList
        Node insert = new Node();
        insert.data = x;
        Node next = phead;
        if (index == 0){//Insert before the first Node
            phead = insert;
            insert.next = next;
            return phead;
        }
        for (int i = 1; i < index; i++)//Insert after n Nodes
            next = next.next;
        insert.next = next.next;
        next.next = insert;
        return phead;
    }
    public int FindNode(Node head, double x){//Find the position of first number x in LinkedList
        int pos = 1;//The first element is 1
        while(head != null){
            if (head.data == x)
                return pos;
            head = head.next;
            pos++;
        }
        return 0;//Return 0 when element cannot be find
    }
    public Node DeleteNode(Node phead, double x){//Delete first number x in LinkedList
        Node next = phead;
        if (phead.data == x){
            phead = phead.next;
            return phead;
        }
        while (next.next != null){
            if (next.next.data == x){
                Node tmp = next.next;
                next.next = tmp.next;
                return phead;
            }
            next = next.next;
        }
        System.out.println(x + " cannot be found in linked list.");
        return phead;
    }
    public void DisplayList(Node head){//Display elements in LinkedList
        System.out.print(head.data);
        head = head.next;
        while (head != null){
            System.out.print("->" + head.data);
            head = head.next;
        }
    }
}