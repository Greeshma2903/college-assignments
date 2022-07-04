section .data
    msg db 'Enter 5 numbers in the array:' 
    msglen equ $-msg
    msg1 db 'Even numbers: ' 
    msg1len equ $-msg1
    msg2 db 'Odd numbers: ' 
    msg2len equ $-msg2
    newline db '',10
    n1 equ $-newline

%macro write 2
	mov eax,4
	mov ebx,1
	mov ecx, %1
	mov edx, %2
	int 80h
%endmacro
 
%macro read 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro

    global arr 
    arr: db 2,4,5,6,7
section .bss
    odd resb 1
    even resb 1
    temp resb 5

section .text
    global _start
_start:	
	call count
	write msg1,msg1len
	write even, 1
	write newline,n1
	write msg2,msg2len
	write odd, 1
	write newline,n1

	mov eax ,1
	mov ebx ,0
	int 80h

count:
	mov eax, 0
    ; set initial values of 'odd' and 'even' as 0
	mov [odd],eax
	mov [even], eax

    ; point pointer to 0'th position
	mov ecx, 5
	mov esi, 0
	label:
        movzx edi, byte[arr+esi]
        mov [temp],edi 
        mov al,[temp]
        mov bl,2
        div bl
        cmp ah,0
        je l1
        ; if number is odd
        inc byte[odd]
        jmp end
	l1:
        ; if number is even
	    inc byte[even]
	end:
        inc esi
        loop label
        mov eax, [odd]
        add eax, '0'
        mov [odd], eax
        mov eax, [even]
        add eax, '0'
        mov [even], eax
ret
