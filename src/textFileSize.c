//Author: Steven Williams
//CSCI 6011
//Practice Set 5 Problem 2
//Compute the size (in bytes) of a given file.

#include<stdio.h>

long int findSize(char file[])
{
	//Read file (set pointer)
	FILE *myFile = fopen(file, "r");

	//If read doesn't work, set error and alert user
	if (myFile == NULL){
		printf("File not found\n");
		return -1;
	}

	//Set the file position of the stream to the given offset
	fseek(myFile, 0L, SEEK_END);

	//Return the file position of the stream
	long int size = ftell(myFile);

	//Close the file
	fclose(myFile);

	//Return the size
	return size;
}

int main(void){

	//Place the file contents of test.txt into a char array
	char file[] = { "test.txt" };
	
	//Use function findSize to get the size of the file above
	long int size = findSize(file);

	//As long as file is found, print the size of file
	if (size != -1)
		printf("Size of the file is %ld bytes.\n", size);
	
	return 0;
}