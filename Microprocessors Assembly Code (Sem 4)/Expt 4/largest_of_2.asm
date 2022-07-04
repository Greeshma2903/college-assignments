section .data
	string1 db 'Enter the number 1: ', 
	string1len equ $-string1
    string2 db 'Enter the number 2: ',
	string2len equ $-string2
    string3 db 'The largest number is: ', 
	string3len equ $-string3
    newline db '', 10
    newlinelen equ $-newline

section .bss
    num1 resb 5
    num2 resb 5

section .text
global _start

_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, string1
	mov edx, string1len
	int 80h
	
	mov eax, 3
	mov ebx, 2
	mov ecx, num1
	mov edx, 5
	int 80h
	
	mov eax, 4
	mov ebx, 1
	mov ecx, string2
	mov edx, string2len
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, string3
	mov edx, string3len
	int 80h

	mov eax, [num1]
	cmp eax, [num2]
	jg L1
	jl L2

	L1:
		mov eax, 4
		mov ebx, 1
		mov ecx, num1
		mov edx, 5
		int 80h

		jmp L3

	L2:
		mov eax, 4
		mov ebx, 1
		mov ecx, num2
		mov edx, 5
		int 80h

		jmp L3

	L3:
		mov eax, 1
		mov ebx, 0
		int 80h