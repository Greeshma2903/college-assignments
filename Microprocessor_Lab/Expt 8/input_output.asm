%macro write_string_number 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read_number_string 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1 
    mov edx, %2
    int 80h
%endmacro
section .data
    read db "Enter the array: "
    readlen equ $-read

    msg db "The array values are: "
    len equ $-msg

arr dw 24

section .text
    global _start

_start:
    write_string_number read, readlen
    read_number_string arr, 24

    write_string_number msg, len
    write_string_number arr, 24

    mov eax, 1
    mov ebx, 0
    int 80h