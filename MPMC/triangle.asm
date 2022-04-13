section .data
	askUser db "Enter the side of a triangle: ", 10
	askUserLen equ $-askUser
	askUserHeight db "Enter the height of a triangle: ", 10
	askHeightLen equ $-askUserHeight
	displayArea db "The area is : ", 10
	displayAreaLen equ $-displayArea
	displayPeri db "The perimeter is: ", 10
	displayPeriLen equ $-displayPeri
section .bss
	side1 resb 9
	side2 resb 9
	side3 resb 9
	height resb 9
	area resb 9
	inter resb 9
	perimeter resb 9
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
	mov ecx, side1
	mov edx, 9
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, side2
	mov edx, 9
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, side3
	mov edx, 9
	int 80h

	mov eax, 4
	mov ebx, 1
	mov ecx, askUserHeight
	mov edx, askHeightLen
	int 80h

	mov eax, 3
	mov ebx, 2
	mov ecx, height
	mov edx, 9
	int 80h

	mov eax, [side1]
	sub eax, '0'
	mov ebx, [height]
	sub ebx, '0'
	mul ebx
	add eax, '0' 	
	mov [inter], eax

	mov
	
	mov eax, [inter]
	sub eax, '0' 
	mov ebx, 2
	sub ebx, '0'
	div ebx
	add eax, '0'
	mov [area], eax

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

	mov eax, 1
	mov ebx, 0
	int 80h
	

	

	
