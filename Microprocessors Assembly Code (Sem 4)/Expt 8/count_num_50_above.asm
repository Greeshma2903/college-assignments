; Count the num of numbers above 50 and below 50
section .data
    msg1 db 'Numbers above 50: ' 
    msg1len equ $-msg1
    msg2 db 'Numbers below 50: ' 
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
    arr: db 2,4,34,66,57

section .bss
    above resb 1
    below resb 1
    temp resb 5

section .text
    global _start
_start:
	call count
	write msg1,msg1len
	write above, 1
	write newline,n1
	write msg2,msg2len
	write below, 1
	write newline,n1

    ; exit
	mov eax ,1
	mov ebx ,0
	int 80h

; procedure
count:
	mov eax, 0
	mov [above],eax
	mov [below], eax
	mov ecx, 5
	mov esi, 0
	label:
        movzx edi, byte[arr+esi]
        mov [temp],edi 
        mov al,[temp]
        mov bl,50
        cmp al, bl
        jg l1

        ; if number below 50
        inc byte[below]
        jmp end
	l1:
        ; if number above 50
	    inc byte[above]
	end:
        inc esi
        loop label
        mov eax, [below]
        add eax, '0'
        mov [below], eax
        mov eax, [above]
        add eax, '0'
        mov [above], eax
ret