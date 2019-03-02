//Author: Steven Williams
//CSCI 6011
//Each one of our computers is connected to a network with an identifier
//to recognize other computer addresses that is known as Internet Protocol (IP)
//address. An IPv4 has 4 octets having decimal value between 0-255 and depend
//on the value in the first octet. The IP addresses are divided into five classes 
//as shown below

//Class A    1    to  126 
//Class B    128  to  191
//Class C    192  to  223
//Class D    224  to  239
//Class E    240  to  254

#include<stdio.h>

int main(){
	
	//Variables for loop, each octet of the IP address, and the first octet of the
	//IP address 
	int i;
	unsigned char a,b,c,d;
	int A;

	//Get IP Address from the user
	printf("Enter an IP address: \n");
	scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
	
	//printf("%hhu.%hhu.%hhu.%hhu\n", a, b, c, d);
	
	//Convert the first octet of the IP address as an unsigned char to char
	A = (int)a;
	//printf("%d\n", A);
	
	//Find the class of IP address based on the first octet
	switch(a) {
		case  1 ... 126:
			printf("Your IP address is Class A.\n");
			break;
		case  128 ... 191:
			printf("Your IP address is Class B.\n");
			break;
		case  192 ... 223:
			printf("Your IP address is Class C.\n");
			break;
		case  224 ... 239:
			printf("Your IP address is Class D.\n");
			break;
		case  240 ... 254:
			printf("Your IP address is Class E.\n");
			break;
		default:
			printf("Out of range!\n");
	}

	return 0;
}