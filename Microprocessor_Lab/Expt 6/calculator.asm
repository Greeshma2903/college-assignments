section .data
    read1 db "Enter numbers: ", 10
    numlen1 equ $-read1

    nl db "", 10
    nllen equ $-nl

    printSum db "The sum ", 9
    Slen equ $-printSum
    
    printDiff db "The difference ", 9
    Dlen equ $-printDiff

    printProd db "The product ", 9
    Plen equ $-printProd

    printQuo db "The quotient ", 9
    Qlen equ $-printQuo

section .bss
    num1 resb 9
    num2 resb 9
    sum resb 9
    diff resb 9
    prod resb 9
    quo resb 9 
    remind resb 9
    
section .text 
    global _start

_start: 
    mov eax, 4
    mov ebx, 1
    mov ecx, read1
    mov edx, numlen1
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

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h

    ; addition
    call Addition

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h

    ; subtraction
    call Subtraction

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h

    ; multiplication
    call Multiply

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h

    ; division
    call Divide

    ; exit
    mov eax, 1
    mov ebx, 0
    int 80h
Addition: 
    mov eax, [num1]
    mov ebx, [num2]
    sub eax, '0'
    sub ebx, '0'
    add eax, ebx
    add eax, '0'
    mov [sum], eax

        ; print sum
    mov eax, 4
    mov ebx, 1
    mov ecx, printSum
    mov edx, Slen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, 9
    int 80h

    ret

Subtraction:
    mov eax, [num1]
    mov ebx, [num2]
    sub eax, '0'
    sub ebx, '0'
    sub eax, ebx
    add eax, '0'
    mov [diff], eax

        ; print difference
    mov eax, 4
    mov ebx, 1
    mov ecx, printDiff
    mov edx, Dlen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, diff
    mov edx, 9
    int 80h

    ret

Multiply:
    mov al, [num1]
    mov bl, [num2]
    sub al, '0'
    sub bl, '0'
    mul bl
    add al, '0'
    mov [prod], al

        ; print product
    mov eax, 4
    mov ebx, 1
    mov ecx, printProd
    mov edx, Plen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, prod
    mov edx, 9
    int 80h

    ret

Divide:
    mov al, [num1]
    mov bl, [num2]
    sub al, '0'
    sub bl, '0'
    div bl
    add al, '0'
    mov [quo], al

        ; print quotient
    mov eax, 4
    mov ebx, 1
    mov ecx, printQuo
    mov edx, Qlen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, quo
    mov edx, 9
    int 80h

    ret