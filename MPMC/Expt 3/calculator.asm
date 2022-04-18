section .data
    read db "Enter number: ", 10
    readLen equ $-read
    printSum db "Sum: ", 10
    printDiff db "Diff: ", 10
    printProd db "Product : ", 10
    printQuo db "Quotient: ", 10

	newLineMsg db 0xA, 0xD			; --- for new line
	newLineLen equ $-newLineMsg
section .bss
    num1 resb 9
    num2 resb 9
    sum resb 9
    diff resb 9
    prod resb 9
    quo resb 9

section .text
    global _start:

_start:
    ; ------- READ VALUES
    mov eax, 4
    mov ebx, 1
    mov ecx, read
    mov edx, readLen
    int 80h

    mov eax, 3
	mov ebx, 2
	mov ecx, num1
	mov edx, 9
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, num2
	mov edx, 9
	int 80h

; --------- SUM
    mov eax, [num1]
    mov ebx, [num2]
    sub eax, '0'
    sub ebx, '0'
    add eax, ebx
    add eax, '0'
    mov [sum], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, printSum
    mov edx, 5
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, sum
    mov edx, 9
    int 80h

; --------- DIFF
    mov eax, [num1]
    mov ebx, [num2]
    sub eax, '0'
    sub ebx, '0'
    sub eax, ebx
    add eax, '0'
    mov [diff], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, printDiff
    mov edx, 6
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, diff
    mov edx, 9
    int 80h

; --------- MUL
    mov al, [num1]
    mov bl, [num2]
    sub al, '0'
    sub bl, '0'
    mul bl
    add al, '0'
    mov [prod], al

    mov eax, 4
    mov ebx, 1
    mov ecx, printProd
    mov edx, 9
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, prod
    mov edx, 9
    int 80h

; --------- DIVISION
    mov al, [num1]
    sub al, '0'
    mov bl, [num2]
    sub bl, '0'
    div bl
    add al, '0'
    mov [quo], al

    mov eax, 4
    mov ebx, 1
    mov ecx, printQuo
    mov edx, 12
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, quo
    mov edx, 9
    int 80h

; ------ EXIT
    mov eax, 1
    mov ebx, 0
    int 80h