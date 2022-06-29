section .data
    string1 db 'Enter a number: ', 10
	string1len equ $-string1
    string2 db 'Enter a word: ', 10
	string2len equ $-string2
	string3 db 'The number is: ',
	string3len equ $-string3
    string4 db 'The word is: ',
	string4len equ $-string4
	newline db ' ',10
	newlinelen equ $-newline

section .bss
    num resb 5
    string resb 9
	
section .text
global _start

%macro write_message 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

_start:
	write_message string1, string1len

    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 5
    int 80h

    write_message newline,newlinelen
    write_message string2, string2len

    mov eax, 3
    mov ebx, 2
    mov ecx, string
    mov edx, 9
    int 80h

    write_message newline,newlinelen
    write_message string3, string3len
    write_message num, 5
    write_message string4, string4len
    write_message string, 9
    write_message newline,newlinelen

	mov eax,1
    mov ebx,0
    int 80h