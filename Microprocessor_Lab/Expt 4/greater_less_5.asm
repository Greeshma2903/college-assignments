section .data
	string1 db 'Enter the number: ', 
	string1len equ $-string1
    string2 db 'The number is greater than 5.',
	string2len equ $-string2
    string3 db 'The number is less than 5.', 
	string3len equ $-string3
	string4 db 'The number is equal to 5.', 
	string4len equ $-string4
    newline db '', 10
    newlinelen equ $-newline

section .bss
    num resb 5

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
	mov ecx, num
	mov edx, 5
	int 80h

    mov eax, 4
	mov ebx, 1
	mov ecx, newline
	mov edx, newlinelen
	int 80h
	
    mov al, [num]
	cmp al, '5'
	jg L1
	jl L2
	je L3
	
	L1:
		mov eax, 4
	    mov ebx, 1
	    mov ecx, string2
	    mov edx, string2len
	    int 80h

        mov eax, 4
	    mov ebx, 1
	    mov ecx, newline
	    mov edx, newlinelen
	    int 80h

		jmp L4

	L2:
		mov eax, 4
	    mov ebx, 1
	    mov ecx, string3
	    mov edx, string3len
	    int 80h

        mov eax, 4
	    mov ebx, 1
	    mov ecx, newline
	    mov edx, newlinelen
	    int 80h

		jmp L4

	L3:
		mov eax, 4
	    mov ebx, 1
	    mov ecx, string4
	    mov edx, string4len
	    int 80h

        mov eax, 4
	    mov ebx, 1
	    mov ecx, newline
	    mov edx, newlinelen
	    int 80h

		jmp L4

	L4:
		mov eax, 1
		mov ebx, 0
		int 80h