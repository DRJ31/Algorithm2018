/*
** Quick Sort and Heap Sort
** In this program, the "right" variable refer to index of last number
** Author: Renjie Deng Apr 10th, 2018
*/
#include "T8.h"
#define ARRAYLENGTH 100000 //The length of unsorted array
#define NUMBERRANGE 1000000 //The range of random number

int main() {
	srand(time(NULL));
	int *arr1 = (int *)malloc(sizeof(int) * ARRAYLENGTH);//Array to check QuickSort Speed
	int *arr2 = (int *)malloc(sizeof(int) * ARRAYLENGTH);//Array to check HeapSort Speed
	puts("Running: Generate random numbers");
	for (int i = 0; i < ARRAYLENGTH; i++) {
		arr1[i] = (rand() * 30) % NUMBERRANGE;//Generate random number between 1-1000000
		arr2[i] = arr1[i];//Copy the number from arr1 to arr2 to make sure the two array is the same
	}
	puts("Finished: Generate random numbers\n");
	//Quick Sort
	puts("Running: QuickSort");
	double quickStart = clock();//start time of quick sort
	QuickSort(arr1, 0, ARRAYLENGTH - 1);
	double quickEnd = clock();//end time of quick sort
	printf("finish quicksort in %gms\n\n", quickEnd - quickStart);
	//Heap Sort
	puts("Running: HeapSort");
	double heapStart = clock();//Start time of heap sort
	HeapSort(arr2, ARRAYLENGTH);
	double heapEnd = clock();//End time of heap sort
	printf("Finish HeapSort in %gms\n", heapEnd - heapStart);
	return 0;
}

void QuickSort(int *A, int left, int right) {
	if (left == right) //If the partition only have one number, return
		return;
	if (left + 1 == right) {//If the partition only have 2 numbers, swap them if they not in correct order
		if (A[left] > A[right]) {
			int temp = A[left];
			A[left] = A[right];
			A[right] = temp;
		}
		return;
	}
	Pivot(A, left, right);//Set Pivot
	int i = left + 1, j = right - 1, pivot = A[right];
	while (true) {
		while (A[i] < pivot)
			i++;
		while (A[j] > pivot)
			j--;
		if (i < j) {
			if (A[i] == pivot && A[j] == pivot)
				break;
			Switch(&A[i], &A[j]);
		}
		else
			break;
	}
	Switch(&A[i], &A[right]);//Switch pivot and the first element which is bigger than pivot
	QuickSort(A, left, i - 1);
	QuickSort(A, i + 1, right);
}

void Pivot(int *A, int left, int right) {//Put the pivot to the end of array
	if (A[left] > A[(left + right) / 2])
		Switch(&A[left], &A[(left + right) / 2]);
	if (A[right] < A[left])
		Switch(&A[left], &A[right]);
	if (A[(left + right) / 2] < A[right])
		Switch(&A[(left + right) / 2], &A[right]);
}

void Switch(int *a, int *b) {//Switch the value of a and b
	int temp = *a;
	*a = *b;
	*b = temp;
}

void HeapSort(int *A, int n) {
	int size = 0;
	for (int i = 0; i < n; i++) {
		Insert(A, A[i], &size);
	}
	for (int i = 0; i < n; i++) {
		DelMax(A, &size);
	}
}

void Insert(int *A, int number, int *size) {//Insert element into heap
	int pos = *size;//The current position of number
	(*size)++;
	int parent;//Record the parent node of pos
	while (pos > 0) {
		parent = pos % 2 == 0 ? (pos - 2) / 2 : (pos - 1) / 2;
		if (A[parent] >= number)
			break;
		A[pos] = A[parent];
		pos = parent;
	}
	A[pos] = number;
}

void DelMax(int *A, int *size) {
	int small = A[--(*size)];
	A[*size] = A[0];//Put the max number at the bottom of tree
	int pos = 0;//Record the position of small number
	int children;//Record the children node swapped with current position
	while (pos < *size) {
		if (pos * 2 + 2 >= *size) {//Stop buble down when it reach the edge of array
			if (pos * 2 + 1 >= *size)
				break;
			if (A[pos * 2 + 1] > small) {
				A[pos] = A[pos * 2 + 1];
				pos = pos * 2 + 1;
			}
			break;
		}
		//Stop bubble down when it is bigger than its children
		if (small >= A[pos * 2 + 1] && small >= A[pos * 2 + 2])
			break;
		children = A[pos * 2 + 1] < A[pos * 2 + 2] ? pos * 2 + 2 : pos * 2 + 1;
		A[pos] = A[children];
		pos = children;
	}
	A[pos] = small;
}