#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void QuickSort(int *A, int left, int right);

void HeapSort(int *A, int n);

void Insert(int *A, int number, int *size);//Insert element into heap

void DelMax(int *A, int *size);

void Pivot(int *A, int left, int right);//Put the pivot to the end of array

void Switch(int *a, int *b);//Switch the value of a and b