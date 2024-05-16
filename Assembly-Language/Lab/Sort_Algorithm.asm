[org 0x0100]

; Data
array db 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
len equ 10
key db 5
foundMsg db 'found',0
failMsg db 'failed',0

; Main program
mov cx, len
lea si, [array]
mov al, [key]
call search_key
cmp al, 0
jz print_fail
lea dx, [foundMsg]
jmp print_msg
print_fail:
lea dx, [failMsg]
print_msg:
call print_str
mov ax, 0x4c00
int 0x21

; subroutine to search key in array
search_key:
search_loop:
    cmp al, [si]
    je key_found
    inc si
    loop search_loop
    mov al, 0
    ret
key_found:
    mov al, 1
    ret

; subroutine to print string
print_str:
    next_char:
        lodsb
        test al, al
        je done
        mov ah, 0Eh
        int 0x10
        jmp next_char
    done:
    ret
