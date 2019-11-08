/*
**Author: Mark Williams
** Simple matrix multiplication using device code (NVIDIA GPU). 
** Matrix size is 16*16, values are all 32 and the output is 256.
*/

#include <stdio.h>
#include <stdlib.h>

__global__ void MatrixMulKernel(float *Md, float *Nd, float *Pd, int Width){

	//2D Thread ID
	int tx = threadIdx.x;
	int ty = threadIdx.y;

	//Pvalue stores the Pd element that is computed by the thread
	float Pvalue = 0;

	for(int k = 0; k < Width; ++k){
		float Mdelement = Md[ty * Width + k];
		float Ndelement = Nd[k * Width + tx];
		Pvalue += Mdelement * Ndelement; 
	}

	//Write the matrix to device memory each thread writes one element
	Pd[ty * Width + tx] = Pvalue;
}

void MatrixMultiplication(float* M, float* N, float* P, int Width){

	//Pointers for each matrix (separate matrices for device computation)
	float *Md, *Nd, *Pd;

	//Size to be used for memory allocation
	int size = Width * Width * sizeof(float);

	//Transfer matrix M and N to device memory
	cudaMalloc((void**) &Md, size); 
	cudaMemcpy(Md, M, size, cudaMemcpyHostToDevice);
	cudaMalloc((void**) &Nd, size); 
	cudaMemcpy(Nd, N, size, cudaMemcpyHostToDevice);
	
	//Allocate matrix P on the device
	cudaMalloc((void**) &Pd, size); 

	//Setup the execution configuration
	dim3 dimBlock(Width, Width);
	dim3 dimGrid(1,1);

	//Launch the device computation threads
	MatrixMulKernel<<<dimGrid, dimBlock>>>(Md, Nd, Pd, Width);

	//Transfer P from device to host
	cudaMemcpy(P, Pd, size, cudaMemcpyDeviceToHost);

	//Free device matrices
	cudaFree(Md);
	cudaFree(Nd);
	cudaFree(Pd);
}


int main (){
	
	//Pointers for each matrix 
	float *M, *N, *P;
	
	//Use matrix width of 16, calculate size of memory for this width
	int Width = 16;
	int size = Width * Width * sizeof(float);
	int count = 0;

	//Allocate the memory
	M = (float*)malloc(size); 
	N = (float*)malloc(size);
	P = (float*)malloc(size);

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
