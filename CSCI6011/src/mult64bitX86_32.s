	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.globl	_store_prod             ## -- Begin function store_prod
	.p2align	4, 0x90
_store_prod:                            ## @store_prod
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	.cfi_offset %esi, -20
	.cfi_offset %edi, -16
	.cfi_offset %ebx, -12
	movl	16(%ebp), %eax
	movl	20(%ebp), %ecx
	movl	12(%ebp), %edx
	movl	8(%ebp), %esi
	movl	12(%ebp), %edi
	movl	%edi, %ebx
	sarl	$31, %ebx
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	movl	16(%ebp), %eax
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	movl	20(%ebp), %eax
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%edi, %eax
	movl	%ecx, -28(%ebp)         ## 4-byte Spill
	movl	-24(%ebp), %ecx         ## 4-byte Reload
	imull	%ecx, %eax
	movl	%eax, -32(%ebp)         ## 4-byte Spill
	movl	%edi, %eax
	movl	-20(%ebp), %ecx         ## 4-byte Reload
	movl	%edx, -36(%ebp)         ## 4-byte Spill
	mull	%ecx
	movl	-32(%ebp), %edi         ## 4-byte Reload
	addl	%edi, %edx
	imull	%ecx, %ebx
	addl	%ebx, %edx
	movl	8(%ebp), %edi
	movl	%eax, (%edi)
	movl	%edx, 4(%edi)
	movl	%esi, -40(%ebp)         ## 4-byte Spill
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset %ebp, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register %ebp
	subl	$56, %esp
	movl	$10, %eax
	movl	$0, -4(%ebp)
	movl	$0, -12(%ebp)
	movl	$10, -16(%ebp)
	movl	$0, -20(%ebp)
	movl	$5, -24(%ebp)
	movl	-8(%ebp), %ecx
	movl	%esp, %edx
	movl	%ecx, (%edx)
	movl	$0, 12(%edx)
	movl	$5, 8(%edx)
	movl	$10, 4(%edx)
	movl	%eax, -28(%ebp)         ## 4-byte Spill
	calll	_store_prod
	xorl	%eax, %eax
	addl	$56, %esp
	popl	%ebp
	retl
	.cfi_endproc
                                        ## -- End function

.subsections_via_symbols
