; @Greeshma
section .data
	string1 db 'Enter the number: ', 
	string1len equ $-string1
    string2 db 'The number is an even number.',
	string2len equ $-string2
    string3 db 'The number is not an even number.', 
	string3len equ $-string3
    newline db '', 10
    newlinelen equ $-newline

section .bss
    num resb 5
    quo resb 5
    rem resb 5

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
    sub al, '0'
	mov bl, '2'
    sub bl, '0'
    DIV bl
    add al, '0'
    add ah, '0'
	mov [quo], al
    mov [rem], ah
	
    mov eax, [rem]
	cmp eax, '0'
	je L1
	jne L2

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

		jmp L3
    
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

		jmp L3

	L3:
		mov eax, 1
		mov ebx, 0
		int 80h
