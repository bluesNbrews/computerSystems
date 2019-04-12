//Author: Steven Williams
//CSCI 6011
//Practice Set 5 Problem 1
//Show the memory representation of the C variables such as int, float, and pointer.
//Using the address and the size of the variable, typecast the address as a character. 


#include<stdio.h>

typedef unsigned char *ptr;

//Take in the typecasted var and the length. Iterate through mem representation based on size(length) of the variable.
void printVar(ptr mem, int len){
	printf("The memory representation of your variable is: ");
	for(int i = 0; i < len; i++)
		printf("%.2x", mem[i]);
	printf("\n");
}

//Typecast the pointer to char and pass to print funciton along with size of int
void printInt(int x){
	printVar((ptr) &x, sizeof(int));
}

//Typecast the pointer to char and pass to print function along with size of float
void printFloat(float x){
	printVar((ptr) &x, sizeof(float));
}

//Typecast the pointer to char and pass to print function along with size of ptr
void printPointer(void *x){
	printVar((ptr) &x, sizeof(void *));
}

int main(void){
	
	//Declare variables 
	int myInt = 3;
	float myFloat = 3.0;
	int *p1 = &myInt;
	float *p2 = &myFloat;

	//Pass variables to show memory representation
	printInt(myInt);
	printFloat(myFloat);
	printPointer(p1);
	printPointer(p2);

	return 0;
}