#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

bool CreateQueue(Queue *queue, int size) {//Create a new queue
	if (size <= 0)//Check if the size is valid
		return false;
	queue->values = (double *)malloc(sizeof(double) * size);//Alloc space for queue
	queue->front = 0;
	queue->rear = -1;
	queue->counter = 0;
	queue->maxSize = size;
	return true;
}

bool IsEmpty(Queue *queue) {//Check if the queue is empty
	return queue->counter == 0;
}

bool IsFull(Queue *queue) {//Check if the queue is full
	return queue->counter >= queue->maxSize;
}

bool Enqueue(Queue *queue, double x) {//Add element into the queue
	if (IsFull(queue))//If the queue is full, stop adding elements into it
		return false;
	queue->rear = (queue->rear + 1) % queue->maxSize;//Find the position of queue's tail
	queue->values[queue->rear] = x;
	queue->counter++;
	return true;
}

bool Dequeue(Queue *queue, double *x) {//Delete the first element in the queue
	if (IsEmpty(queue))//If the queue is empty, stop deleting elements in it
		return false;
	queue->front = (queue->front + 1) % queue->maxSize;//Find the position of queue's front
	if (queue->front == 0)
		*x = queue->values[queue->maxSize - 1];
	else
		*x = queue->values[queue->front - 1];
	queue->counter--;
	return true;
}

void DisplayQueue(Queue *queue) {//Display the queue
	if (IsEmpty(queue)){
		puts("The queue is empty.");
		return;
	}
	printf("front -->%8g\n", queue->values[queue->front]);
	if (queue->front > queue->rear) {
		for (int i = queue->front + 1; i < queue->maxSize; i++) {
			printf("%17g\n", queue->values[i]);
		}
		for (int i = 0; i < queue->rear; i++) {
			printf("%17g\n", queue->values[i]);
		}
	}
	else {
		for (int i = queue->front + 1; i < queue->rear; i++) {
			printf("%17g\n", queue->values[i]);
		}
	}
	printf("%17g%17s\n", queue->values[queue->rear], "<-- rear");
}

void DestroyQueue(Queue *queue) {
	free(queue->values);
}