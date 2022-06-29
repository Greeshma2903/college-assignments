section .data 
    read db "Enter a number: "
    readlen equ $-read

    write db "The factorial is: "
    writelen equ $-write

    newline db '', 10
    nl equ $-newline

section .bss
    num resb 9
    inter resb 9
    prod resb 9
    fact resb 9
    count resb 9

section .text
    global _start
_start:
    ; read number
    mov eax, 4
    mov ebx, 1
    mov ecx, read
    mov edx, readlen
    int 80h

    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 9
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    ; Display statement
    mov eax, 4
    mov ebx, 1
    mov ecx, write
    mov edx, writelen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    ; assign 1 to PROD
    mov eax, '1'
    mov [prod], eax

    ; assign 'num' to 'inter'
    mov eax, [num]
    mov [inter], eax

    ; assign 'num' to 'count'
    mov eax, [num]
    mov [count], eax

    ; Procedure call
    call Factorial
    jmp L3
L3:
    ; print Factorial
    mov eax, 4
    mov ebx, 1
    mov ecx, prod
    mov edx, 5
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h
    
    ; exit
    mov eax, 1
    mov ebx, 0
    int 80h

Factorial:
    jmp L1
    L1:
            ; Mulitply 
        mov al, [prod]
        sub al, '0'
        mov bl, [inter]
        sub bl, '0'
        mul bl
        add al, '0'
        mov [prod], al

            ; decrement 'inter'
        mov eax, [inter]
        dec eax
        mov [inter], eax

        jmp L2

    L2:
            ; Compare to run loop
        mov al, [inter]
        mov bl, '1'
        cmp al, bl
        jge L1
    ret 





