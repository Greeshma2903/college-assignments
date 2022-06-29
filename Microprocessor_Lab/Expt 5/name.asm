section .data
	string1 db 'Enter the name: ', 10
	string1len equ $-string1
	newline db ' ',10
	newlinelen equ $-newline

section .bss
    name resb 9
    count resb 9

section .text
global _start

%macro write_syscall 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read_name 1
    mov eax, 3
    mov ebx, 2
    mov ecx, %1
    mov edx, 9
    int 80h
%endmacro

_start:

	write_syscall string1, string1len

    read_name name

    write_syscall name, 9

    mov eax, '1'
    mov [count], eax
    write_syscall count, 9
    jmp L1

    L1:
        mov eax, [count] 
        cmp eax, '9'
        jl L2
        jg L3

    L2:
        write_syscall name, 9
        mov eax, [count] 
        inc eax
        mov [count], eax
        write_syscall count, 9
        jmp L1

    L3:
	    mov eax,1
        mov ebx,0
        int 80h