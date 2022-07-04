section .data
    string1 db "Enter size of fibo series: ", 10
    string1len equ $-string1
    string2 db "The series is: ", 10
    string2len equ $-string2
    newline db '', 10
    nl equ $-newline

    empty db "-"
    emptylen equ $-empty

section .bss
    num resb 5
    a resb 5
    b resb 5
    c resb 5
    inter resb 5
    count resb 5

section .text 
    global _start
_start: 
    mov eax, 4
    mov ebx, 1
    mov ecx, string1
    mov edx, string1len
    int 80h

    ; [num] stores the size of fibo
    mov eax, 3
    mov ebx, 2
    mov ecx, num
    mov edx, 5
    int 80h

    ; To print the series
    mov eax, 4
    mov ebx, 1
    mov ecx, string2
    mov edx, string2len
    int 80h

    ; Compare the size of Fibo entered
    mov al, [num]
    mov bl, '0'
    cmp al, bl 
    je Empty
    jg Compare

Empty:
    ; if (num == 0) print '-'
    mov eax, 4
    mov ebx, 1
    mov ecx, empty
    mov edx, emptylen
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    ; exit
    jmp C3

Compare:
    ; Compare if (num >= 1)
    mov al, [num]
    mov bl, '1'
    cmp al, bl 
    je PrintOnce
    jg PrintTwo

PrintOnce:
    ; if (num == 1)
    mov eax, '0'
    mov [a], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, a
    mov edx, 5
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    jmp C3

PrintTwo: 
    ; if (num >= 2)
    ; Initialize 'a' and 'b'
    mov eax, '0'
    mov [a], eax
    mov eax, '1'
    mov [b], eax

    mov eax, 4
    mov ebx, 1
    mov ecx, a
    mov edx, 5
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    mov eax, 4
    mov ebx, 1
    mov ecx, b
    mov edx, 5
    int 80h
    
    mov eax, 4
    mov ebx, 1
    mov ecx, newline
    mov edx, nl
    int 80h

    jmp C1

C1:
    ; Compare if (num > 2), and print rest series
    mov al, [num]
    mov bl, '2'
    cmp al, bl 
    je C3
    jg C2

C2:
    ; Initialize count
    mov eax, '2'
    mov [count], eax

    call fibo
    jmp C3

C3: 
    ; exit program
    mov eax, 1
    mov ebx, 0
    int 80h

fibo:
    jmp L1
    L1:
        ;--------- addition a, b, c
        mov eax, [a]
        sub eax, '0'
        mov ebx, [b]
        sub ebx, '0'
        add eax, ebx
        add eax, '0'
        mov [c], eax

        ; ------- print 'c'
        mov eax, 4
        mov ebx, 1
        mov ecx, c
        mov edx, 5
        int 80h

        mov eax, 4
        mov ebx, 1
        mov ecx, newline
        mov edx, nl
        int 80h

            ; ------- Move b to a
        mov eax, [b]
        mov [a], eax

            ; ------- Move c to a 
        mov eax, [c]
        mov [b], eax

            ; ------ Increment count
        mov eax, [count]
        inc eax
        mov [count], eax

        jmp L2

    L2:        
            ; ------ Compare count and num
        mov al, [count]
        mov bl, [num]
        cmp al, bl
        jl L1
    ret




    