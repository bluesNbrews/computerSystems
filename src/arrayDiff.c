#include<stdio.h>
#include<stdlib.h>

double* arrayFunc(double *arr1, double *arr2){
	double temp[5];
	double *arr3;
	int sum = 0;
	int k = 0;

	for(int i = 0; i < 5; i++){
		for(int j = 0; j < 5; j++){
			if(arr1[i] == arr2[j]){
				j = 5;
			}
			if(arr1[i] != arr2[j] && j == 4){
				temp[i] = arr1[i];
				sum ++;
			}
		}
	}

	arr3 = (double *)malloc(sum * sizeof(double));

	for(int i = 0; i < 5; i++){
		if((int)temp[i] > 0){
			arr3[k] = temp[i];
			k++;
		}
	}

	for(int i = 0; i < 5; i++){
		printf("Array 1: %.2f\n", arr1[i]);
		printf("Array 2: %.2f\n", arr2[i]);
	}

	for(int i = 0; i < 5; i++){
		printf("Array Temp: %.2f\n", temp[i]);
	}

	printf("%d\n", sum);

	return arr3;
}

int main(void){
	
	
	int size = 5;
	double *arr1 = (double *)malloc(size * sizeof(double));
	double *arr2 = (double *)malloc(size * sizeof(double));
	double *arr3;

	printf("Enter a pair of numbers: \n");
	for(int i = 0; i < 5; i++){
		scanf("%lf%lf", &arr1[i], &arr2[i]);
	}

	arr3 = arrayFunc(arr1,arr2);

	for(int i = 0; i < 5; i++){
		printf("New Array: %.2f\n", arr3[i]);
	}

	return 0;
}