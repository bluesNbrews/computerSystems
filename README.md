# Table of Contents

- [CSCI 6011(Computer Systems - simple C programs)](#csci-6011-computer-systems---simple-c-programs)
  * [arrayDiff.c](#arraydiffc)
  * [binomialCoeff.c](#binomialcoeffc)
  * [binRepInt.c](#binrepintc)
  
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
