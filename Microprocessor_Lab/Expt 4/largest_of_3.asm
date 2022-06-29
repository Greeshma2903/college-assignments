section .data
	string1 db 'Enter the number 1: ', 
	string1len equ $-string1
    string2 db 'Enter the number 2: ',
	string2len equ $-string2
    string3 db 'Enter the number 3: ',
	string3len equ $-string3
    string4 db 'The largest number is: ', 
	string4len equ $-string4
    newline db '', 10
    newlinelen equ $-newline

section .bss
    num1 resb 5
    num2 resb 5
    num3 resb 5

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
	mov ecx, string3
	mov edx, string3len
	int 80h
	
	mov eax, 3
	mov ebx, 2
	mov ecx, num3
	mov edx, 5
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, string4
	mov edx, string4len
	int 80h

	mov eax, [num1]
	cmp eax, [num2]
	jg L1
	jl L2

	L1:
        mov eax, [num1]
	    cmp eax, [num3]
	    jg N1
	    jl N3

    L2:
		mov eax, [num2]
	    cmp eax, [num3]
	    jg N2
	    jl N3

		jmp L3

    N1:
        mov eax, 4
		mov ebx, 1
		mov ecx, num1
		mov edx, 5
		int 80h

		jmp L3
    
    N2:
        mov eax, 4
		mov ebx, 1
		mov ecx, num2
		mov edx, 5
		int 80h

		jmp L3

    N3:
        mov eax, 4
		mov ebx, 1
		mov ecx, num3
		mov edx, 5
		int 80h

		jmp L3
	
	L3:
		mov eax, 1
		mov ebx, 0
		int 80h