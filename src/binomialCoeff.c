//Author: Steven Williams
//CSCI 6011
//Implement the binomial coeffecient formula in C (for nonnegative integers)
/*
	|n|	      n!    
	| |	= ----------
	|k|    k!(n-k)!
*/
#include<stdio.h>

//Method to calculate a factorial
int factorial(int f){
	//Set i to one less than parameter to decrement down to 0
	int i = f - 1;
	//Give sum the value of the number for factorial. It will then be multiplied
	//by the i abovee
	int sum = f;
	while(i){
		sum *= i;
		i--;
	}
	//printf("%d\n", sum);
	return sum;
}

int formula(int n, int k){
	int result = 0;
	//See formula above. Use factorial function to calculate
	result = factorial(n) / (factorial(k) * (factorial(n-k)));
	//Return factorial result of parameter
	return result;
}

int main(){
	int total = 0;
	int n = 0;
	int k = 0;

	//Use input for n and k of the formula
	printf("Please enter 'n' for the formula: \n");
	scanf("%d", &n);
	printf("Please enter 'k' for the formula: \n");
	scanf("%d", &k);
	
	//Calculate formula with the user variables above
	total = formula(n, k);

	//Print the total of the formula!
	printf("Your total is %d.\n", total);

	return 0;
}