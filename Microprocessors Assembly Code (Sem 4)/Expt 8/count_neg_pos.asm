%macro write_string_number 2
    mov eax, 4
    mov ebx, 1
    mov ecx, %1
    mov edx, %2
    int 80h
%endmacro

%macro read_number_string 2
    mov eax, 3
    mov ebx, 2
    mov ecx, %1 
    mov edx, %2
    int 80h
%endmacro

; ---->
section .data
    pos_msg db "Positive count:"
    pos_len equ $-pos_msg
    neg_msg db "Negative count:"
    neg_len equ $-neg_msg
    nl db '', 10
    nllen equ $-nl

    ; array declaration and initialization
    array dw 1, 2, -9, 11, -12, 4, 9, 2, -3
    arrCnt equ 9     ; static array size
    posCnt dw 0     ; number of positive numbers
    negCnt dw 0     ; no of negative numbers

section .bss
        dis_buffer resb 2
    
section .text
    global _start

_start:
    ; initializing array start address
    mov esi, array
    mov ecx, arrCnt
    UP: BT word[esi], 15
    JC NCXT
    inc byte[posCnt]
    JMP PSKIP

    NCXT: inc byte[negCnt]
    PSKIP:
        inc esi
        inc esi
        loop UP
    
    ; positive count message
    write_string_number pos_msg, pos_len
    mov bl, [posCnt]
    CALL Hex_ASCII

    ; print newline
    write_string_number nl, nllen

    ; negative count message
    write_string_number neg_msg, neg_len
    mov bl, [negCnt]
    CALL Hex_ASCII

    ; print newline
    write_string_number nl, nllen

    ; exit
    mov eax, 1
    mov ebx, 0
    int 80h


; HEX to ASCII procedure ----->
Hex_ASCII:
    mov ecx, 2
    mov edi, dis_buffer
    DUP: 
        rol bl, 04
        mov al, bl
        and al, 0fh
        cmp al, 09h
        jbe NEXT
        add al, 07h

    NEXT:
        add al, 30h
        mov [edi], al
        inc edi
        loop DUP

        ; display count
        write_string_number dis_buffer, 2
    ret



        