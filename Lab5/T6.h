#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertSort(int *A, int n);
/*
** A is an array of integers and n is the size of A
** Sort A using insertion sort
*/

void MergeSort(int *A, int *B, int left, int right);
/*
** Sort sub-array A using merge sort
** B is the array which temporarily store the sorted result of array A
*/

void Merging(int *A, int *B, int left, int center, int right);
/*Merge two sorted arrays*/
/*B is the array which temporarily store the sorted result of array A*/
/* I changed the prototype because I found that the time of merge sort
will increase a lot because we have to allocate space for the temporary 
array B every time we call the Merging function. If we take B as a parameter
of MergeSort and Merging, we can only allocate space for B just once.
Though the complexity of this function won't change, it really save a
lot of time.
*/

void Copy(int *A, int *B, int left, int right);
/*Copy the sorted array from B to A*/