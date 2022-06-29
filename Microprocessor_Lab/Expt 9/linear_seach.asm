section .data
	prompt db "Enter number of elements",10
	plen equ $-prompt
	prompt2 db "Enter elements",10
	p2len equ $-prompt2
	prompt3 db "Elements are:",10
	p3len equ $-prompt3
	prompt4 db "Enter element to search:",10
	p4len equ $-prompt4
	prompt5 db "Found at index: "
	p5len equ $-prompt5
	prompt6 db "Not found: "
	p6len equ $-prompt6	
	newline db 10
	space db ' '
	
section .bss
	n resb 4
	num resb 4
	arr resb 10
	index resb 4
	trash resb 1

%macro SYS_WRITE 2
	mov eax,4
	mov ebx,1
	mov ecx,%1
	mov edx,%2
	int 80h
%endmacro
	
%macro SYS_READ 2
	mov eax,3
	mov ebx,2
	mov ecx,%1
	mov edx,%2
	int 80h
	mov eax,3
	mov ebx,2
	mov ecx,trash
	mov edx,1
	int 80h
%endmacro
	
section .text
global _start

_start:
	SYS_WRITE prompt,plen
	SYS_READ n,1
	sub [n],byte '0'

	SYS_WRITE prompt2,p2len
	mov eax,arr
	mov edx,[n]
	call input
	
	SYS_WRITE prompt3,p3len	
	mov eax,arr
	mov edx,[n]	
	call display

	SYS_WRITE prompt4,p4len
	SYS_READ num,1

	mov eax,arr
	mov edx,[n]
	mov edi,[num]
	call linear_search
	
	mov eax,1
	mov ebx,0
	int 80h

input:
	;; eax should contain address of array
	;; edx should contain size of array
	mov ecx,0
repeat_input:	
	cmp ecx,edx
	jge after_input

	mov esi,eax
	add esi,ecx
	pushad
	SYS_READ esi,1
	popad
	
	inc ecx
	jmp repeat_input
after_input:
	
	ret


display:
	;; eax should contain address of array
	;; edx should contain size of array
	mov ecx,0
repeat_display:	
	cmp ecx,edx
	jge after_display

	mov esi,eax
	add esi,ecx

	pushad
	SYS_WRITE esi,1
	SYS_WRITE space,1
	popad
	
	inc ecx
	jmp repeat_display
after_display:
	mov eax,4
	mov ebx,1
	mov ecx,newline
	mov edx,1
	int 80h
	
	ret

linear_search:
;; eax should contain address of array
;; edx should contain size of array
;; edi should contain number to search
	and edi,000fh
	mov ecx,0
repeat_search:	
	cmp ecx,edx
	jge after_search

	mov esi,eax
	add esi,ecx
	mov ebx,[esi]
	and ebx,000fh
	cmp ebx,edi
	jne not_match
;;matched
	add ecx,'0'
	mov [index],ecx
	pushad
	SYS_WRITE prompt5,p5len
	SYS_WRITE index,1
	popad
	ret
not_match:
	inc ecx
	jmp repeat_search
after_search:
	SYS_WRITE prompt6,p6len
	ret
	
