#include "T6.h"

#define ARRAY_LENGTH 100000 //Length of random array
#define RANDOM_RANGE 1000000 //Range of random number

void InsertSort(int *A, int n) {/*The main process of merge sort*/
	int key = A[0];//Key indicate the element which is finding position to insert
	int pos;//Record the current position of key
	for (int i = 0; i < n - 1; i++) {
		if (A[i + 1] < A[i]) {
			key = A[i + 1];
			pos = i;
			while (pos >= 0 && A[pos] > key) {//Find the correct position of key
				A[pos + 1] = A[pos];
				pos--;
			}
			A[pos + 1] = key;//Insert the key to correct place
		}
	}
}

void MergeSort(int *A, int *B, int left, int right) {/*The main process of merge sort*/
	if (left == right)//When the part of array only have one element, do not sort
		return;
	if (right - left == 1) {//Sort the part of array when the part of array only have two elements
		if (A[left] > A[right]) {//Switch the position of two numbers if it is not the right order
			int tmp = A[left];
			A[left] = A[right];
			A[right] = tmp;
		}
		return;
	}
	int center = (right + left) / 2;
	MergeSort(A, B, left, center);
	MergeSort(A, B, center + 1, right);
	Merging(A, B, left, center, right);//Merge left and right part of sorted array
}

void Merging(int *A, int *B, int left, int center, int right) {/*Merge two sorted arrays*/
	int size = sizeof(A) / sizeof(int);//The size of A
	int i1 = left, i2 = center + 1, i3 = left;
	/* 
	** i1 record the position of left part
	** i2 record the position of right part
	** i3 record the position of B
	*/
	while (i1 <= center && i2 <= right) {//Compare elements in two arrays
		if (A[i1] < A[i2]) {
			B[i3++] = A[i1++];
		}
		else {
			B[i3++] = A[i2++];
		}
	}
	//Put the rest elements into result array when one array have used up
	while (i1 <= center) {
		B[i3++] = A[i1++];
	}
	while (i2 <= right) {
		B[i3++] = A[i2++];
	}
	Copy(A, B, left, right);//Copy the result from temp array to origin array
}

void Copy(int *A, int *B, int left, int right) {/*Copy the sorted array from B to A*/
	for (int i = left; i <= right; i++) {
		A[i] = B[i];
	}
}

int main() {
	srand(time(NULL));
	int *A1 = (int *)malloc(sizeof(int) * ARRAY_LENGTH);//The array to store random numbers
	int *A2 = (int *)malloc(sizeof(int) * ARRAY_LENGTH);//The array to store a copy of random numbers
	int *B = (int *)malloc(sizeof(int) * ARRAY_LENGTH);//The array to temporarily store result for merge sort
	for (int i = 0; i < ARRAY_LENGTH; i++) {//Generate random numbers
		A1[i] = (rand() * 30) % RANDOM_RANGE;//(RAND_MAX * 30) is approximate to 10^6
	}
	Copy(A2, A1, 0, ARRAY_LENGTH - 1);//A copy of random number array
	/*Test of Insert Sort*/
	int Istart = clock();//The start time of Insert Sort
	InsertSort(A1, ARRAY_LENGTH);
	int Iend = clock();//The end time of Insert Sort
	/*Test of Merge Sort*/
	int Mstart = clock();//The start time of Merge Sort
	MergeSort(A2, B, 0, ARRAY_LENGTH - 1);
	int Mend = clock();//The end time of Merge Sort
	printf("The time cost of Insert Sort is: %dms\n", Iend - Istart);
	printf("The time cost of Merge Sort is: %dms\n", Mend - Mstart);
	free(A1);
	free(A2);
	free(B);
	return 0;
}