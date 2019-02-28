//Author: Steven Williams
//CSCI 6011
//Write a C program to enter a binary number from the user and to //find 2's complement of the binary number.
//First step is to transform x into a bit vector in the form of
//[0..01..1], find two's complement of a binary string.

//Algorithm
/*One's Complement:

1) Iterate array and flip the bits
	a) If '1', then change to '0'
	b) If '0', then change to '1'

Two's Complement:

Add 1 to One's complement

1) Start with least significant bit, if 0, then add 1
2) If least significant is 1 then add 1 and carry 1 to the next least significant bit.
3) If the next least significant bit position is 1, then repeat step 2 until the most significant bit is 0 

Psuedo:

add = 1

for ones complement:

while add = 1
	is curr pos 1?
		if yes, change to 0
	is curr pos 0?
		if yes, change to 1
		change add = 0

*/

#include<stdio.h>

void Comp(char *binNum, char binNumOnesComp[], char binNumTwosComp[]){

	//Flag and counter variable to calculate two's complement below
	int add = 1;
	int i;

	//For loop to calculate one's complement
	//Populate two's complement array as well in order to have all leading zeros
	for(int i = 7; i < sizeof(binNum); i--){
		if (binNum[i] == '0'){
			binNumOnesComp[i] = '1';	
			binNumTwosComp[i] = '1';
		}
		else{
			binNumOnesComp[i] = '0';
			binNumTwosComp[i] = '0';
		}
	}

	//Calculate two's complement and populate array
	//If two's array isn't set in for loop above, leading zeros will be truncated
	i = 7;
	while(add){
		if(binNumOnesComp[i] == '1'){
			binNumTwosComp[i] = '0';
		}
		else {
			binNumTwosComp[i] = '1';
			add = 0;
		}
		i--;
	}
}

int main(){
	
	//Counter variable and arrays for all binary numbers (user binary, one's complement, two's complement)
	int i;
	char binNum[8];
	char binNumOnesComp[8];
	char binNumTwosComp[8];

	//Get binary number from user
	printf("Enter the binary number: \n");
	for(i = 0; i < sizeof(binNum); i++){
		scanf("%c", &binNum[i]);
	}
	
	//Calculate one's complement and two's complement, see function above
	Comp(binNum, binNumOnesComp, binNumTwosComp);

	//Print one's complement
	printf("The one's complement of your binary number is: \n");
	for(i = 0; i < sizeof(binNumOnesComp); i++){
		printf("%c", binNumOnesComp[i]);
	}
	printf("\n");

	//Print two's complement
	printf("The two's complement of your binary number is: \n");
	for(i = 0; i < sizeof(binNumTwosComp); i++){
		printf("%c", binNumTwosComp[i]);
	}
	printf("\n");

	return 0;
}