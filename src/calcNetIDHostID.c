//Author: Steven Williams
//CSCI 6011
//Practice Set 6 Problem 1
//Write a program to show the class of a given IPv4 address, netword ID, and host ID.

//Class A    1    to  126 
//Class B    128  to  191
//Class C    192  to  223
//Class D    224  to  239
//Class E    240  to  254

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void append(char* s, char c){
    int len = strlen(s);
    s[len] = c;
    s[len+1] = '\0';
    printf("%s", s);
}

int main(){
	
	//Variables for loop, each octet of the IP address, and the first octet of the
	//IP address 
	unsigned char a,b,c,d;
	//int A;
	char zero = '0';
	char networkClass; 


	//Get IP Address from the user
	printf("Enter an IP address (ex: 253.1.0.224): \n");
	scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);	
	
	//Convert the first octet of the IP address as an unsigned char to char
	//A = (char)a;
	
	//Find the class of IP address based on the first octet
	switch(a) {
		case  1 ... 126:
			networkClass = 'A';
			break;
		case  128 ... 191:
			networkClass = 'B';
			break;
		case  192 ... 223:
			networkClass = 'C';
			break;
		case  224 ... 239:
			networkClass = 'D';
			break;
		case  240 ... 254:
			networkClass = 'E';
			break;
		default:
			printf("Out of range!\n");
	}

	printf("Your IP address is Class %c.\n", networkClass);

	return 0;

}