//Author: Steven Williams
//CSCI 6011

/*Write source code to enter any number by the user to count the number of trailing zeros in the given number by using the 
bitwise operator. A bitwise operator is used to track the trailing zeros in any given number. The first set bit position is 
equal to the number of the trailing zeros in the binary number.*/

#include <stdio.h>

int main(){
	//
	int num, i;
	int count = 0;
	int sizeInt = sizeof(int) * 8;
	//printf("%d", sizeInt);

	//Get number from user
	printf("Enter any number: ");
	scanf("%d", &num);
	//printf("%d", num);

	//Iterate over each bit of the number 
	for(i = 0; i < sizeInt; i++){
		//If the least signicant bit of a bit shift to the right is 1, then break
		//In essence, how many bit shifts to the right does it take to get the right most 1 in binary 
		//form of the number to reach the 2^0 position (least sig bit position in little endian).
		//printf("The iteration is currently at :%d\n", i);
		if((num >> i ) & 1){
			//printf("%d\n", num >> i);
			//printf("%d\n\n", (num >> i) & 1);
			break;
		}
		count++;
	}

	//Print the amount of trailing zeros
	printf("The amount of trailing zeros for %d is %d.\n", num, count);
	
	return 0;
}