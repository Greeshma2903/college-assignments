section .data
    read db "Enter a number: "
    readlen equ $-read

    msg db "The Diffeerence: "
    len equ $-msg
section .bss
    num1 resb 9
    num2 resb 9
    sum resb 9

section .text
    global _start

_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, read
    mov edx, readlen
    int 80h

     ; READ NUMBER 1
    mov eax, 3
    mov ebx, 2
    mov ecx, num1
    mov edx, 9
    int 80h

    ; READ NUMBER 2
    mov eax, 3
    mov ebx, 2
    mov ecx, num2
    mov edx, 9
    int 80h

    mov esi, 2
    mov ecx, 3
    clc         ;sets the carry flag to zero

add_loop:
    mov al, [num1 + esi]
    sbb al, [num2 + esi]  
    aaa
    pushf
    or al, 30h
    popf

    mov [sum + esi], al
    dec esi
    loop add_loop

    ; print the sum
    mov eax, 4
    mov ebx, 1
    mov ecx, msg
    mov edx, len
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, 9
    int 80h

    ; exits
    mov eax, 1
    mov ebx, 0
    int 80h