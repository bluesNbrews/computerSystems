/*
**Author: Mark Williams
** Simple matrix multiplication using host code (CPU). 
** Matrix size is 16*16, values are all 32 and the output is 256.
*/

#include <stdio.h>
#include <stdlib.h>

void MatrixMultiplication(float *M, float *N, float *P, int Width){
	
	//Multiply matrix m by mattrix n and store results in matrix p
	for (int i = 0; i < Width; ++i)
		for (int j = 0; j < Width; ++j){
			float sum = 0;
			for (int k = 0; k < Width; ++k){
				float a = M[i * Width + k];
				float b = N[k * Width + j];
				sum += a * b;
			}
			P[i * Width + j] = sum;
		}
}


int main (){
	
	//Pointers for each matrix 
	float *M, *N, *P;

	//Use matrix width of 16, calculate size of memory for this width
	int Width = 16;
	int count = 0;

	//Allocate the memory
	M = (float*)malloc((Width * Width) * sizeof(float)); 
	N = (float*)malloc((Width * Width) * sizeof(float));
	P = (float*)malloc((Width * Width) * sizeof(float));

	//Populate M and N with 1's and 2's, repsectively
	for(int i = 0; i < (Width * Width); i++){
		M[i] = 1.0;
		N[i] = 2.0;
	}

	//Pass the matrices and width size to multiplication function
	MatrixMultiplication(M, N, P, Width);

	//Print out the results
	for(int i = 0; i < (Width * Width); i++){
		count++;
		printf("%.0f ", P[i]);
		if(count % 16 == 0)
			printf("\n");
	}
	printf("Count is %d\n", count);

	//Deallocate memory
	free(M);
	free(N);
	free(P);

	return 0;
}