//Author: Steven Williams
//Create a program that takes two command line arguments that corresponds to the dimensions
//(rows and columns) of a 2D array of doubles. Allocate memory to create the array and assign 
//random values to its elements so that the sum of the elements in each row is equal to 1.

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int main(){

	//Use input for 2D array size
	int x;
	int y;
	//Loop variables
	int i, j;
	//Min and max for random num generation
	int lower = 0;
	int upper = 1000;

	//Sum of all values
	double sum;
	double diff;
	double total = 0.0;

	//Current time for random num generation
	srand(time(0));

	//Get user input for array
	printf("Enter the size of the 2D array. Ex 3 3\n");
	scanf("%d %d", &x, &y);

	//Allocate memory for 2D array
	double *myArray = (double *)malloc(x * y * sizeof(double));

	//Generate random values for each array element such that each row has a sum of 1.0
	for(i = 0; i < x; i++){
		
		for(j = 0; j < y; j++){
			
			//Generate random number less than 1.0 and assign to array element
			int num = (rand() % (upper - lower + 1)) + lower;
	    	double num2 = (double)num / 1000;
	    	*(myArray + i * y + j) = num2;
			
			//Lower the upper limit of the random numbers being generated and keep track of sum for the row
			upper = upper - num;
			sum = sum + num2;

			//For the last element in the row, add the remaining value (if necessary) to make row total 1.0
			if(j+1==y){
				
				if(sum != 1.0){
					diff = 1.0 - sum;
					*(myArray + i * y + j) += diff;
				}
				
				//Row over, reset the upper limit for random number generation and running total for the row
				upper = 1000;
				sum = 0;
			}
		}
		printf("\n");
	}

	//Display the array
	for(i = 0; i < x; i++){
		
		printf("Row %d", i +1);
		
		for(j = 0; j < y; j++){
			printf(" | %.3f ", *(myArray + i * y + j));
			total += *(myArray + i * y + j);
		}
		
		printf("| Row total value : %.3f\n\n", total);
		total = 0.0;
	}

	return 0;
}