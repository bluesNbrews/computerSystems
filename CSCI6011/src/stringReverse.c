//Author: Steven Williams

#include <stdio.h>

int main(){
	
	//Declare variables
	char s[1000], r[1000];
	int begin, end, count = 0;

	//[]is the scanset character and ^\n specifies to take input 
	//until new line isn't encountered. %*c reads the newline character and the * 
	//indicates that the newline character is discarded. 
	//Long story short, it will take user input with spaces, where scanf normally stops at the space.
	printf("Input a string\n");
	scanf("%[^\n]%*c", s);

	//Keep track of the length of s and the end of s
	while(s[count] != '\0')
		count++;

	end = count - 1;

	//
	for(begin = 0; begin < count; begin++){
		r[begin] = s[end];
		end--;
	}

	r[begin] = '\0';

	printf("%s\n", r);

	return 0;
}