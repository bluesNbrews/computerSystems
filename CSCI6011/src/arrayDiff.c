/* Author: Steven Williams
** Simple program to find the largest number for each element of two arrays. 
** For example, array1[0] is compared to array2[0] to find the larger number. 
** Runs in linear time - O(n)
*/

#include<stdio.h>
#include<stdlib.h>

double* arrayFunc(double *arr1, double *arr2){

	//Allocate memory for the larger number array
	double *arr3 = (double *)malloc(2 * sizeof(double));

	//Compare each element of array 1 to array 2 and store the larger number in array 3
	for(int i = 0; i < 2; i++){
			if(arr1[i] < arr2[i])
				arr3[i] = arr2[i];	
	}

	//Return new array with larger number
	return arr3;

}

int main(void){
	
	//Allocate memory for array 1, array 2 and array 3 (larger number)
	double *arr1 = (double *)malloc(2 * sizeof(double));
	double *arr2 = (double *)malloc(2 * sizeof(double));
	double *arrLargerNumber;

	//Populate array 1 and array 2 from user input
	printf("Enter two pairs of numbers (e.g. 23 2 2 4): \n");
	for(int i = 0; i < 2; i++){
		scanf("%lf%lf", &arr1[i], &arr2[i]);
	}

	//Compare two arrays and return array with larger numbers
	arrLargerNumber = arrayFunc(arr1,arr2);

	//Print array with larger numbers
	for(int i = 0; i < 2; i++){
		printf("New Array: %.2f\n", arrLargerNumber[i]);
	}

	return 0;
}