;@Greeshma
section .data
	askUser db "Enter the length of a rectangle: ", 10
	askUserLen equ $-askUser
	askUserBreadth db "Enter the breadth of a rectangle: ", 10
	askBreadthLen equ $-askUserBreadth

	displayArea db "The area is : ", 9
	displayAreaLen equ $-displayArea
	displayPeri db "The perimeter is: ", 9
	displayPeriLen equ $-displayPeri

	newLineMsg db 0xA, 0xD			; --- for new line
	newLineLen equ $-newLineMsg

section .bss
    length resb 9
    breadth resb 9
    inter resb 9
    area resb 9
    perimeter resb 9
section .text
    global _start
_start:
; -------- Read Values from User
    mov eax, 4
	mov ebx, 1
	mov ecx, askUser
	mov edx, askUserLen
	int 80h

    mov eax, 3
	mov ebx, 2
	mov ecx, length
	mov edx, 9
	int 80h

    mov eax, 4
	mov ebx, 1
	mov ecx, askUserBreadth
	mov edx, askBreadthLen
	int 80h

    mov eax, 3
	mov ebx, 2
	mov ecx, breadth
	mov edx, 9
	int 80h

; ---------- Calculate area of rectangle
    mov al, [length]
    sub al, '0'
    mov bl, [breadth]
    sub bl, '0'
    mul bl
    add al, '0'
    mov [area], al

    ; --- display area
    mov eax, 4
	mov ebx, 1
	mov ecx, displayArea
	mov edx, displayAreaLen
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, area
	mov edx, 9
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 80h

; -------- Calculate rectangle perimeter
    mov eax, [length]
    sub eax, '0'
    mov ebx, [breadth]
    sub ebx, '0'
    add eax, ebx
    add eax, '0'
    mov [inter], eax

    mov al, [inter]
    sub al, '0'
    mov bl, '2'
    sub bl, '0'
    mul bl
    add al, '0'
    mov [perimeter], al

    ; --- display perimeter
    mov eax, 4
	mov ebx, 1
	mov ecx, displayPeri
	mov edx, displayPeriLen
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, perimeter
	mov edx, 9
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, newLineMsg
	mov edx, newLineLen
	int 80h

; ------- Exit program
    mov eax, 1
    mov ebx, 0
    int 80h