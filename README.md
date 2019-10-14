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
  * [stringReverse.c](#stringreversec)
  
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

### stringReverse.c

Write a program to reverse the order of a string.




