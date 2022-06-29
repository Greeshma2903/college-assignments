section .data
	string1 db 'Enter the number: ', 10
	string1len equ $-string1
    string2 db 'The number is: ',
	string2len equ $-string2
	newline db ' ',10
	newlinelen equ $-newline

section .bss
    num resb 5
section .text
global _start

%macro write_string_number 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read_number 1
    mov eax, 3
    mov ebx, 2
    mov ecx, %1
    mov edx, 5
    int 80h
%endmacro

_start:
	write_string_number string1, string1len

    read_number num

    write_string_number newline, newlinelen

    write_string_number string2, string2len

    write_string_number num, 5

	mov eax,1
    mov ebx,0
    int 80h