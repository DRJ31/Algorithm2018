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
** 
*/

void Merging(int *A, int *B, int left, int center, int right);
/*Merge two sorted arrays*/
/*B is the array which temporarily store the sorted result of array A*/

void Copy(int *A, int *B, int left, int right);
/*Copy the sorted array from B to A*/

unsigned long TenPow(int n);
/*Return the value of 10^n*/