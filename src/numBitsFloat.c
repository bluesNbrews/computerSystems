//Author: Steven Williams
//CSCI 6011
//Write C code to count the set of bits in a floating point number.

#include <stdio.h>

unsigned int countSetBitsChar(char n) 
{ 
    unsigned int count = 0; 
    while (n) 
    {
      //printf("%c\n", n);
      //n = n & (n-1)
      //Bitwise operator & 
      n &= (n-1); 
      //printf("%c\n", n);
      //Increase the count
      count++; 
    } 
    return count; 
} 

// Returns set bits in binary representation of float x in the driver program.
unsigned int countSetBitsFloat(float x) 
{ 
    // Count number of chars (or bytes) in binary representation of float. 
    // Float size of 4 divided by char size of 1 equals 4.
    unsigned int n = sizeof(float)/sizeof(char); 
	//printf("%d\n", n);
  
    //Typecast the pointer of float x to char pointer type.
    //This is pointing to the first value in x. 
    char *ptr = (char *)&x;   
  
  	//Counter for the number of bits.
    int counter = 0;   
    //Iterate through the size of 4.
    for (int i = 0; i < n; i++) 
    { 
         counter += countSetBitsChar(*ptr); 
         ptr++; 
    } 
    return counter; 
}

//Driver program to test the functions. 
int main(){
	//The inital float along with the num count for the bits in that float.
	float x = 0.15625;
	unsigned int numOfSetBitsFloat = 0;

	numOfSetBitsFloat = countSetBitsFloat(x);

	//Print the total num count of bits.
	printf ("%s%f%s%u%s\n", "The binary version of the float ", x, " has ", numOfSetBitsFloat, " set bits."); 
	return 0;
}



