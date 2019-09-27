// Author: Steven Williams
// CSCI 6011
/*
Write a C program to count number of 1's in the binary representation of an integer.
Loop through all bits in an integer, find if a bit is set and if it has incremented
the set bit count.

Algorithm Steps:
1) Take user input for an integer value
2) Iterate through the binary form of the integer and count the number of ones.
3) Return the number of ones. 
4) Print the number of 1's.
*/

#include <stdio.h>

int intToBinary(int userInt){

	//The temporary number is essentially a remainder to iterate through the binary version of the integer (1 byte, 0-255). See below.
	//The total binary 1's variable is a counter for the 1's .
	//OK, so the test array is used to subtract the user integer from each array number (8 numbers total, one for each bit. For ex: 2^7 = 128, 2^6 = 64, ..., 2^0 = 1).   
	//If the integer is greater than the ith number, it can be subtracted and the counter can be incremented to show that a 1 exists in that position of the byte.  
	//The remainder will be used as the loop iterates through the bit values for each position in binary.
	int tempNum = userInt;
	int totalBin = 0;
	int testArray[] = {
		128, 64, 32, 16, 8, 4, 2, 1
	};
	for(int i = 0; i < 8; i++){
		if(tempNum >= testArray[i]){
			tempNum = tempNum - testArray[i];
			totalBin += 1;
			//printf("%d\n", totalBin);
		}
		else
			continue;
		
	}	
	return totalBin;
}

int main(){
	
	//Variables for user input and for the total number of 1's in the binary form of the integer, respectfully.
	int userInt = 0;
	int totalOnes = 0;
	
	//Take user input for an integer
	printf("%s\n", "Please enter an integer (0-255).");
	scanf("%d", &userInt);

	//Call the function to count the number of 1's and store in the respective variable.
	//See intToBinary function above.
	totalOnes = intToBinary(userInt);

	//Print the total number of 1's.
	printf("%s%d%s\n", "The number of 1's the binary form of your integer is ", totalOnes, ".");
	
	return 0;
}