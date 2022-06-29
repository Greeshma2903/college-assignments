; @Greeshma - 201105030

section .data
    stars times 9 db '*'
    starslen equ $-stars
section .text
    global _start
_start:
    MOV eax, 4
    MOV ebx, 1
    MOV ecx, stars
    MOV edx, starslen
    int 80h
    MOV eax, 1
    MOV edx, 0
    int 80h
