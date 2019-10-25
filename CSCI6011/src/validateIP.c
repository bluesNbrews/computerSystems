//Author: Steven Williams
//Create a program that checks the validity of user defined IP address.

#include<stdio.h>
#include<string.h>

//Function to convert string to int. I had to create my own because atoi() will not work on my architecture.
//Characters will show as valid input for this implementation
int myAtoi(char *str) 
{ 
	//Initialize result 
    int res = 0;
   
    //Iterate through all characters of input string and update result
    for (int i = 0; str[i] != '\0'; ++i){
        res = res*10 + str[i] - '0'; 
    }
   
    //Return result. 
    return res; 
} 

//If digit is valid, return 1. Otherwise, return 0.
int checkDigit(char *ptrIP) 
{ 
    while (*ptrIP) { 
        if (*ptrIP >= '0' && *ptrIP <= '9') 
            ++ptrIP; 
        else
            return 0; 
    } 
    return 1; 
} 

int checkIP(char ipAddress[]){
	
	//Delimit the IP by decimal point
	char *ptrIP = strtok(ipAddress, ".");
	//Variable for string converted to integer
	int strToInt;
	//Variable for number of decimal point
	int decimalPoints = -1;
	//Result fot the checks (result)
	int code;

	//If IP user input is empty, return error
	if (ptrIP == NULL) 
        return 0;

	//Check that the digits are valid. If not, return error
	code = checkDigit(ptrIP);
	if (code == 0)
		return 0;

	//Check that the octets are valid. If not, return error
	while(ptrIP != NULL){
		strToInt = myAtoi(ptrIP);
		
		if (strToInt >=0 && strToInt <=255){
			code = 1;
			decimalPoints++;
		}
		else 
			return 0;

		ptrIP = strtok(NULL, ".");
	}

	//Check that there are 4 octets. If not, return error
	if (decimalPoints != 3) 
        return 0; 

    //Return the result
	return code;
}

int main(){
	
	//Variables for user input
	char ipAddress[20];

	//Results of functions to check valid digits and the IP, respectively
	int result;

	//Get user input
	printf("Enter an IP address (ex: 200.32.2.5): \n");
	scanf("%s", ipAddress);

	//Check the digits and octets
	result = checkIP(ipAddress);

	//Print the result
	printf("The result of the IP check for digits and octets is (valid is 1, non-valid is 0): %d\n", result);


	return 0;

}