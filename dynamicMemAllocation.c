//Steven Williams
//CSCI 6011 
//C program to find sum of array elements using Dynamic Memory Allocation.

#include<stdio.h>
#include<stdlib.h>

int main()
{	
	int arraySize;	
	int *ptr;
	int sum = 0;	

	//Get user input for array size
	printf("What is the size of the array: ");
	scanf("%d", &arraySize);

	//Dynamically allocate memory for the array
	ptr = (int*)malloc(arraySize * sizeof(int));

	//Get user input for the array 
	for(int i = 0; i < arraySize; i++)
	{
		printf("What is element %02d: ", i + 1);
		scanf("%d", (ptr + i));
	}

	//Print the array
	printf("The array is as follows:\n");
	for(int i = 0; i < arraySize; i++)
	{
		printf("%d\n", *(ptr + i));
	}
	
	//Add all of the array elements
	for(int i = 0; i < arraySize; i++)
	{
		sum += *(ptr+i);
	}
	printf("The sum of all of the array elements is: %d\n", sum);
	
	//Free the memory!
	free(ptr);	
	
	return 0;
}