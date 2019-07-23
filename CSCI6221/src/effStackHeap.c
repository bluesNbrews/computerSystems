/* Author: Steven Williams
** Class: CSCI 6221 Midterm Problem
** Purpose: Measure and compare the time it takes to create an array on both the stack and heap
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Allocate an array on the stack
void createArrayStack(){
	
	//Size of the array
	int stackArr[100];

	//Populate with integer value of 1
	for(int i = 0; i < 100; i++){
		stackArr[i] = 1;
	}
}

//Allocate an array on the heap
void createArrayHeap(){
	
	//Allocate array on the heap
	int *heapArr = malloc(100 * sizeof(double));

	//Populate with integer value of 1
	for(int i = 0; i < 100; i++){
		*(heapArr + i) = 1;
	}

	//Deallocate array from the heap
	free(heapArr);
}

int main(){
	
	//Measure and print time to allocate an array on the stack
	clock_t start1 = clock();
	createArrayStack();
	clock_t end1 = clock();
	double totalTime1 = ((double) (end1 - start1) / CLOCKS_PER_SEC);
	printf("Allocate int array[100] on the stack takes: %f\n", totalTime1);

	//Measure and print time to allocate an array on the heap
	clock_t start2 = clock();
	createArrayHeap();
	clock_t end2 = clock();
	double totalTime2 = ((double) (end2 - start2) / CLOCKS_PER_SEC);
	printf("Allocate int array[100] on the heap takes: %f\n", totalTime2);
	
	return 0;
}