; @Greeshma - 201105030
; SUM OF THREE NUMBERS
section .data
    askUser db "Enter the numbers:", 10
    askUserLen equ $-askUser
    print db "The Sum is: "
    printlen equ $-print
    nl db "", 10
    nllen equ $-nl
section .bss
    num1 resb 9
    num2 resb 9
    num3 resb 9
    sum resb 9
    inter resb 9
section .text
    global _start
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, askUser
    mov edx, askUserLen
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

        ; READ NUMBER 2
    mov eax, 3
    mov ebx, 2
    mov ecx, num3
    mov edx, 9
    int 80h

    ; ADDITION OF NUMBERS
    mov eax, [num1]
    sub eax, '0'
    mov ebx, [num2]
    sub ebx, '0' 
    add eax, ebx
    add eax, '0' 
    mov [sum], eax

    mov eax, [sum]
    sub eax, '0'
    mov ebx, [num3]
    sub ebx, '0' 
    add eax, ebx
    add eax, '0' 
    mov [sum], eax

    ; PRINT THE SUM
    mov eax, 4
    mov ebx, 1
    mov ecx, print
    mov edx, printlen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, 9
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, nl
    mov edx, nllen
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h
