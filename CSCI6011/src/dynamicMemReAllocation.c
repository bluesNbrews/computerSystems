//Author: Steven Williams
//Dynamically allocate memory for an array. 
//Change the size of the array and dynamically reallocate memory for new array aize and values.

#include<stdio.h>
#include<stdlib.h>

//Reallocate existing memory for array from 12 to 20 integers
//Continue to populate with 162-169 and return ptr for new array size of 20 int
int* resize(int *ptr, int n, int j){
	ptr = (int *)realloc(ptr, 20 * sizeof(int));

	//Init values (k) to populate array and increment
	//Iterate from size of old array to size of new array 
	int k = 161;
	for(int i = n-1; i < j; i++){
		ptr[i] = k;
		k++;
	}
	return ptr;
}

//Print function to iterate through the entire array size of 20 int
void print(int *ptr, int size){
	
	printf("Your array size is %d and the values are as follows: \n", size);
	for(int i = 0; i < size; i++)
		printf("%d\n", *(ptr + i));
}

int main(void){
	
	//N is old size of array, j is new size
	//Init values (k) to populate array and increment 
	int n = 12;
	int j = 20;
	int k = 150;

	//Allocate memory for initial array size of 12
	int *ptr = (int *)malloc(n * sizeof(int));

	//Populate the array of size 20 with ints 150-161
	for(int i = 0; i < n; i++)
	{
		ptr[i] = k;
		k++;
	}

	//Print initial array with size of 12 int
	print(ptr, n);
 
 	//Increment size of array by reallocating memory
	ptr = resize(ptr, n, j);

	//Print array with new size of 20 int
	print(ptr, j);

	//Free the allocated memory
	free(ptr);

	return 0;
}