; @Greeshma - 201105030
section .data
    askUser db "Enter a number to print:", 10
    askUserLen equ $-askUser
    print db "The number you entered is: ", 10
    printlen equ $-print
section .bss
    num resb 9
section .text
    global _start
_start:
    mov eax, 4
    mov ebx, 1
    mov ecx, askUser
    mov edx, askUserLen
    int 80h
    
    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 9
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, print
    mov edx, printlen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, num
    mov edx, askUserLen
    int 80h

    mov eax, 1
    mov ebx, 0
    int 80h
