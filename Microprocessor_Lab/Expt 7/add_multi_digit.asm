%macro write_string_number 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read_number_string 1
    mov eax, 3
    mov ebx, 2
    mov ecx, %1 
    mov edx, 9
    int 80h
%endmacro

section .data
    read db "Enter a number: "
    readlen equ $-read

    msg db "The Sum: "
    len equ $-msg
section .bss
    num1 resb 9
    num2 resb 9
    sum resb 9

section .text
    global _start

_start:
    write_string_number read, readlen

    read_number_string num1     ; READ NUMBER 1
    read_number_string num2     ; READ NUMBER 2

    mov esi, 2
    mov ecx, 3
    clc         ;sets the carry flag to zero

add_loop:
    mov al, [num1 + esi]
    adc al, [num2 + esi]  
    aaa
    pushf
    or al, 30h
    popf

    mov [sum + esi], al
    dec esi
    loop add_loop

    ; print the sum
    write_string_number msg, len
    write_string_number sum, 9

    ; exits
    mov eax, 1
    mov ebx, 0
    int 80h