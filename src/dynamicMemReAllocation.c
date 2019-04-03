//Author: Steven Williams
//CSCI 6011
//Practice set 4, Problem 1
#include<stdio.h>
#include<stdlib.h>

int* resize(int *ptr, int n, int j){
	ptr = (int *)realloc(ptr, 20 * sizeof(int));

	int k = 162;
	for(int i = n-1; i < j; i++){
		ptr[i] = k;
		k++;
	}
	return ptr;
}

void print(int *ptr){
	for(int i = 0; i < 20; i++)
		printf("%d\n", *(ptr + i));
}

int main(void){
	
	int n = 12;
	int j = 20;
	int k = 150;

	int *ptr = (int *)malloc(n * sizeof(int));

	for(int i = 0; i < n; i++)
	{
		ptr[i] = k;
		k++;
	}

	print(ptr);
 
	ptr = resize(ptr, n, j);

	print(ptr);

	return 0;
}