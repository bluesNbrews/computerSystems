//Author: Steven Williams
//Write source code to convert a floating point number to a binary number.

#include<stdio.h>

//Change to binary with bitwise operation on floating point portion (mantissa or exponent) 
void binary(int n, int i)
{
    int k;
  
    for (i--; i >= 0; i--)
    {
    	k = n >> i;
      	if (k & 1)
        	printf("1");
        else
        	printf("0");
    }
}

//Breakup the floating point number to mantissa, exponent, and sign.
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

//COmment out print statements that help show the breakdown of the floating point number.
int main()
{
    myfloat var;

    printf("Enter any float number: ");
    scanf("%f", &var.f);

    //printf("The 'sign' field of the float number is: %d \n", var.field.sign);
    //printf("The 'exponent' field of the float number is: %d \n", var.field.exponent);
    //printf("The 'mantissa' field of the float number is: %d \n", var.field.mantissa);

    //printf("The exponent is: ");
    printf("The binary representation of %f is: ", var.f);
    binary(var.field.exponent, 8);
    //printf(" \n");
    
    //printf("The mantissa is: ");
    binary(var.field.mantissa, 23);
    printf("\n");
    
    return 0;
}