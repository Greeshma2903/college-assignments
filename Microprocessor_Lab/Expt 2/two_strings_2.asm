; @greeshma - 201105030
section .data
	hello db 'hello world', 10
	hellolen equ $-hello
	line1 db 'greeshma', 10
	linelen equ $-line1
section .text
	global _start
_start:
	MOV eax, 4
	MOV ebx, 1
	MOV ecx, hello
	MOV edx, hellolen
	int 80h
	MOV eax, 4
	MOV ebx, 1
	MOV ecx, line1
	MOV edx, linelen
	int 80h
	MOV eax, 1
	MOV ebx, 0
	int 80h
