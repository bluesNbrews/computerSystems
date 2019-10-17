//Author: Steven Williams
//Create C source code from the assembly code below.

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

/*
	pushl %ebp              // stores the stack frame on the stack
	movl %esp, %ebp         // takes the current stack pointer and uses it as the frame for  the called function
	subl $24, %esp          // creates 24 bytes on the stack 
	movl $10, -4(%ebp)      // value 10 (local variable) stored in 4 bytes above ESB (vertically speaking) 
	movl $20, -8(%ebp)      // value 20 (local variable) stored in 8 bytes above ESB (vertically speaking)
	movl -8(%ebp), %eax     // move value 20 into register eax
	movl %eax, 4(%esp)      // move value 20 into 4 bytes below stack pointer (vertically speaking)
	movl -4(%ebp), %eax     // move value 10 into register eax
	movl %eax, (%esp)       // move value 10 into stack pointer
	movl $LC0, (%esp)       // LC0 is a label that references some value, maybe the add function below
	call _printf            // print statement
	movl $0, %eax           // return 0

_add:
	pushl %ebp              // stores the stack frame of the calling function on the stack
	movl %esp, %ebp         // takes the current stack pointer and uses it as the frame for the called function
	movl 12(%ebp), %eax     // another parameter passed in to eax
	addl 8(%ebp), %eax      // add 20 (passed in as parameter) with eax
	popl %ebp               // restore original value
	ret                     // return value
*/

int add_ints(int x, int y){
	
	return x + y;

}

int main(){

	int x = 10;
	int y = 20;

	printf("%d\n", add_ints(x, y));

	return 0;
}