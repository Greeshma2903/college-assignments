; @Greeshma - 201105030
section .data
	string1 db 'Enter the number 1: ', 10
	string1len equ $-string1
    string2 db 'Enter the number 2: ', 10
	string2len equ $-string2
    string3 db 'The sum of number 1 & 2: ', 10
	string3len equ $-string3
    string4 db 'The difference of number 1 and 2: ', 10
	string4len equ $-string4
    string5 db 'The product of number 1 & 2: ', 10
	string5len equ $-string5
    string6 db 'The division of number 1 & 2: ', 10
	string6len equ $-string6
    string7 db 'The remainder is: ', 10
	string7len equ $-string7
    newline db '', 10
    newlinelen equ $-newline

section .bss
    num1 resb 5
    num2 resb 5
    sum resb 5
    diff resb 5
    prod resb 5
    quo resb 5
    rem resb 5

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

%macro addition 3
    mov eax, [%1]
    sub eax, '0'
	mov ebx, [%2]
    sub ebx, '0'
    add eax, ebx
    add eax, '0'
	mov [%3], eax
%endmacro

%macro subtraction 3
    mov eax, [%1]
    sub eax, '0'
	mov ebx, [%2]
    sub ebx, '0'
    sub eax, ebx
    add eax, '0'
	mov [%3], eax
%endmacro

%macro multiplication 3
    mov al, [%1]
    sub al, '0'
	mov bl, [%2]
    sub bl, '0'
    MUL bl
    add al, '0'
	mov [%3], al
%endmacro

%macro division 4
    mov al, [%1]
    sub al, '0'
	mov bl, [%2]
    sub bl, '0'
    DIV bl
    add al, '0'
    add ah, '0'
	mov [%3], al
    mov [%4], ah
%endmacro

section .text
global _start

_start:
	write_string_number string1, string1len
	read_number num1

    write_string_number string2, string2len
	read_number num2
    write_string_number newline, newlinelen

    ; PRINT SUM
    write_string_number string3, string3len
    addition num1, num2, sum
    write_string_number sum, 5
    write_string_number newline, newlinelen

    write_string_number newline, newlinelen

    ; PRINT DIFFERENCE
    write_string_number string4, string4len
    subtraction num1, num2, diff
    write_string_number diff, 5
    write_string_number newline, newlinelen

    write_string_number newline, newlinelen

    ; PRINT PRODUCT
    write_string_number string5, string5len
    multiplication num1, num2, prod
    write_string_number prod, 5
    write_string_number newline, newlinelen

    write_string_number newline, newlinelen

    ; PRINT QUOTIENT
    write_string_number string6, string6len
    division num1, num2, quo, rem
    write_string_number quo, 5
    write_string_number newline, newlinelen
    write_string_number string7, string7len
    write_string_number rem, 5

    write_string_number newline, newlinelen

    mov eax,1
    mov ebx,0
    int 80h