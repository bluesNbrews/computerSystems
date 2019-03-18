//Author: Steven Williams
//CSCI 6011
//Write source code to binary represent a floating point number.

#include<stdio.h>

void binary(int n, int i)
{
	printf("This is the binary function.");
    int k;
    printf(" The parameters of n are: %d and the size is: %d\n", n, i);
    for (i--; i >= 0; i--)
    {
    	k = n >> i;
      	if (k & 1)
        	printf("1");
        else
        	printf("0");
    }
}

typedef union
{
	float f;
    struct
    {
            unsigned int mantissa : 23;
            unsigned int exponent : 8;
            unsigned int sign : 1;
    } field;
} myfloat;

int main()
{
    myfloat var;

    printf("myfloat var is currently: %d%d%d\n", var.field.sign, var.field.exponent, var.field.mantissa);
    
    printf("Enter any float number: ");
    scanf("%f", &var.f);

    printf("myfloat var is now: %d%d%d\n", var.field.sign, var.field.exponent, var.field.mantissa);
    
    printf("The 'sign' field of the float number is: %d \n", var.field.sign);
    printf("The 'exponent' field of the float number is: %d \n", var.field.exponent);
    printf("The 'mantissa' field of the float number is: %d \n", var.field.mantissa);

    binary(var.field.exponent, 8);
    printf(" \n");
    
    binary(var.field.mantissa, 23);
    printf("\n");
    
    return 0;
}