//Author: Steven Williams

//Write a program to show the class of a given IPv4 address, netword ID, and host ID.

//Class A    1    to  126 
//Class B    128  to  191
//Class C    192  to  223
//Class D    224  to  239
//Class E    240  to  254

#include<stdio.h>

int main(){
	
	//Variables for each octet of the IP address, and the IP address class
	unsigned char a,b,c,d;
	char networkClass; 


	//Get IP Address from the user
	printf("Enter an IP address (ex: 253.1.0.224): \n");
	scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);	
	
	//Find the class of IP address based on the first octet. Modify and print Network ID and Host ID based on the IP address class.
	switch(a) {
		case  1 ... 126:
			networkClass = 'A';
			printf("Your IP address is Class %c.\n", networkClass);
			printf("The Network ID is %d.%d.%d and Host ID is %d. ", a, b, c, d);
			break;
		case  128 ... 191:
			networkClass = 'B';
			printf("Your IP address is Class %c.\n", networkClass);
			printf("The Network ID is %d.%d and Host ID is %d.%d. ", a, b, c, d);
			break;
		case  192 ... 223:
			networkClass = 'C';
			printf("Your IP address is Class %c.\n", networkClass);
			printf("The Network ID is %d.%d.%d and Host ID is %d. ", a, b, c, d);
			break;
		case  224 ... 239:
			networkClass = 'D';
			printf("Your IP address is Class %c. This class is reserved for multicast purposes only.\n", networkClass);
			break;
		case  240 ... 254:
			networkClass = 'E';
			printf("Your IP address is Class %c. This class is reserved for experimental purposes only.\n", networkClass);
			break;
		default:
			printf("Out of range!\n");
	}

	return 0;

}