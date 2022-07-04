; @Greeshma - 201105030
section .data
    name db 'flat alc', 10
    namelen equ $-name
section .text
    global _start
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, name
    mov edx, namelen
    int 80h
    mov [name], dword 'tcfs'    ; this replaces the first word in the string with given string 'tcfs'
    mov eax, 4
    mov ebx, 1
    mov ecx, name               ; print string after replacement
    mov edx, namelen
    int 80h
    mov eax, 1
    mov ebx, 0
    int 80h