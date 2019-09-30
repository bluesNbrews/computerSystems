//Author: Steven Williams

/*
Write source code in C to convert a binary number to hexadecimal number.
Use the problem solution below to help you create the C code. 
1) Select you input. 
2) Divide the binary number into groups of 4 bits, each group of 4 bits,
multiply each bit with the power of 2 and add them consecutively. 
3) Combine the result of all groups to get the output. 
 */

#include <stdio.h>
#include <math.h>

void byteSum(char binNum[], char hexNum[])
{
	//The logic is separated to the first 4 bits and the second 4 bits. 
	//Two sums, two counters, and hex values to compare to.
	int sumNibble1 = 0;
	int sumNibble2 = 0;
	int counter1 = 3;
	int counter2 = 7;
	char hexDict[] = {
		'0', '1', '2', '3', 
		'4', '5', '6', '7', 
		'8', '9', 'A', 'B',
		'C', 'D', 'E', 'F'
	};

	//For loop is to iterate through the user input array which is the binary number.
	//OK, going left to right. If the value of the ith position is 1, then add the value to the total.
	//For example: if the first value is 1, then add 8 (2^3). The counter is the power and it is decremented each iteration. 
	//If the next value is 1, then add 4 (2^2). There are two if statements to account for the two sets of 4 bits (1 byte, the binary number). 
	for(int i = 0; i < 8; i++){
		if(binNum[i] == '1' && i < 4){
			sumNibble1 += pow(2, counter1);	
		}	
		counter1--;	
		if(binNum[i] == '1' && i >= 4){
			sumNibble2 += pow(2, counter2);
		}
		counter2--;
	}

	//Iterate through the hex values and assign accordingly. 
	//For example: if the sum is 11, assign the values A (11th position in the array), and so on. 
	for(int i = 0; i < sizeof(hexDict); i++){
		if (sumNibble1 == i + 1){
			hexNum[0] = hexDict[i + 1];
		}
		if (sumNibble2 == i + 1){
			hexNum[1] = hexDict[i + 1];
		}
	}	
}

int main()
{
	//Two arrays, the first for the binary number from user input.
	//The second is to store the final hex values (two total). 
	char binNum[8];
	char hexNum[2];

	//Binary number from user input
	printf("Enter the binary number: \n");
	for(int f = 0; f < 8; f++)
	{
		scanf("%c", &binNum[f]);
	}

	//Call the byteSum function to convert the binary number to hex values.
	byteSum(binNum, hexNum);

	//Showing the binary number converted to the hex values.
	printf("%s", "Your binary number of ");
	
	for(int i = 0; i < sizeof(binNum); i++)
	{
		printf("%c", binNum[i]);
	}
	printf("%s", " equals to ");

	for(int i = 0; i < sizeof(hexNum); i++)
	{
		printf("%c", hexNum[i]);
	}
	printf("%s\n", " in hexadecimal.");

	return 0;
}