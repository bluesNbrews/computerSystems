// Author: Steven Williams
// Create a simple program that multiplies to long long data types. The goal is to see the assembly code for this simple operation. 

#include<stdio.h>

typedef long long longLong_t;

void store_prod(longLong_t *dest, longLong_t x, longLong_t y){
	*dest = x*y;
}

int main(){
	
	long long *dest;
	long long x,y;
	x = 10;
	y = 5;

	store_prod(dest, 10, 5);

	return 0;
}