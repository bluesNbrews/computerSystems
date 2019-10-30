# Table of Contents

- [CSCI 6011(Computer Systems - simple C programs)](#csci-6011-computer-systems---simple-c-programs)
  * [arrayDiff.c](#arraydiffc)
  * [binomialCoeff.c](#binomialcoeffc)
  * [binRepInt.c](#binrepintc)
  * [binToHex.c](#bintohexc)
  * [calcNetIDHostID.c](#calcnetidhostidc)
  * [dynamicMemAllocation.c](#dynamicmemallocationc)
  * [dynamicMemReAllocation.c](#dynamicmemreallocationc)
  * [floatToBin.c](#floattobinc)
  * [ipAddr.c](#ipaddrc)
  * [linkedList.c](#linkedlistc)
  * [mult64bitX86_32.c](#mult64bitx86_32c)
  * [mult64bitX86_32.s](#mult64bitx86_32s)
  * [numSetBitsFloat.c](#numsetbitsfloatc)
  * [randNumArray.c](#randnumarrayc)
  * [rectCoord.c](#rectcoordc)
  * [reverseEngAssemb.c](#reverseengassembc)
  * [sizeCircLinkedList.c](#sizecirclinkedlistc)
  * [stringReverse.c](#stringreversec)
  * [structArrSort.c](#structarrsortc)
  * [textFileSize.c](#textfilesizec)
  * [trailZeroBin.c](#trailzerobinc)
  * [twosComp.c](#twoscompc)
  * [validateIP.c](#validateipc)
  * [varMemRep.c](#varmemrepc)
- [CSCI 6221 (Software Paradigms)](#csci-6221-software-paradigms)
  * [effStackHeap.c](#effstackheapc)
  * [objBinding.c](#objbindingc)
  
# Sample work @ George Washington University (using C/Assembly/CUDA/C++/GO)
  * Computer Systems (6011)
  * Computer Architecture (6461)
  * Software Paradigms (6221)
  * Design & Analysis of Algorithms (6212) 

## CSCI 6011 (Computer Systems - simple C programs)

### arrayDiff.c 

Simple program to find the largest number for each element of two arrays. For example, array1[0] is compared to array2[0] to find the larger number. Runs in linear time - O(n).

### binomialCoeff.c 

Implement the binomial coeffecient formula in C (for nonnegative integers). Runs in constant time - O(1).

	|n|	      n!    
	| |	= ----------
	|k|        k!(n-k)!

### binRepInt.c

Count number of 1's in the binary representation of an integer. Loop through all bits in an integer, find if a bit is set and if it has incremented the set bit count.

### binToHex.c

Convert a binary number to a hexadecimal number.

### calcNetIDHostID.c

Show the class, network ID, and host ID of a given IPv4 address. The class is based on the first octet as follows:

* Class A    1    to  126 
* Class B    128  to  191
* Class C    192  to  223
* Class D    224  to  239
* Class E    240  to  254

### dynamicMemAllocation.c

Find the sum of array elements. The array elements are populated from user input using dynamic memory allocation.

### dynamicMemReAllocation.c

Dynamically allocate memory for an array and populate with values. Change the size of the array and dynamically reallocate memory for new array aize and populate with values.

### floatToBin.c

Convert a floating point number to a binary number.

### ipAddr.c

Show the class based on IP address provided by the user. Similar to calcNetIDHostID.c.

### linkedList.c

Create a linked list using structures and memory allocation. Robust functionality includes find (O(n) time), print (O(n) time), insert at the head of the list (O(1) time), insert at a specified position in the list (O(1) time), delete a specified element (O(1) time), and modify values.

### mult64bitX86_32.c

Multiply two long long data types. The goal is to see the assembly code for this simple operation. 

### mult64bitX86_32.s

Assembly code for mult64bitX86_32.c. This code was generating using the GNU Compiler Collection (GCC).

### numSetBitsFloat.c

Count the set of bits in a floating point number. E.g. the number of 1's in a given binary number.

### randNumArray.c

Create a program that takes two command line arguments that corresponds to the dimensions (rows and columns) of a 2D array of doubles. Allocate memory to create the array and assign random values to its elements so that the sum of the elements in each row is equal to 1.

### rectCoord.c

Calculate the area based on two coordinates of a rectangle (on a graph). Use the x and y values to calculate the area. E.g. Area = Width * Length -> (y2 - y1) * (x2 - x1)

### reverseEngAssemb.c

Based on the following assembly code, write the corresponding C source code. 

	pushl %ebp              
	movl %esp, %ebp        
	subl $24, %esp          
	movl $10, -4(%ebp)      
	movl $20, -8(%ebp)      
	movl -8(%ebp), %eax     
	movl %eax, 4(%esp)     
	movl -4(%ebp), %eax     
	movl %eax, (%esp)       
	movl $LC0, (%esp)       
	call _printf            
	movl $0, %eax           

	_add:
	pushl %ebp              
	movl %esp, %ebp         
	movl 12(%ebp), %eax    
	addl 8(%ebp), %eax      
	popl %ebp               
	ret  

### sizeCircLinkedList.c

Define the size of a circular linked list (no NULL end pointer at end node, points back to the HEAD).

### stringReverse.c

Write a program to reverse the order of a string.

### structArrSort.c

For 20 students, sort by grade and display students with a grade higher than the average grade of all students. Worst case runtime is O(n^2).

### textFileSize.c

Compute the size (in bytes) of a given text file.

### trailZeroBin.c

Count the number of trailing zeros (binary) for a given number (decimal) by using the bitwise operator. E.g. 8 = 1000 (3 trailing zeros).

### twosComp.c

Convert a byte or two nibbles from user input to the one's complement and the two's complement for that input.

### validateIP.c

Check the validity of user defined IP address.

### varMemRep.c

Show the memory representation of the C variables such as int, float, and pointer.

## CSCI 6221 (Software Paradigms)

### effStackHeap.c

Measure and compare the time it takes to create an array on both the stack and heap.

### objBinding.c

Create a program that will test both static and dynamic object binding using another object.
