
[org 0x0100]

Data
    message1 db 'Hi, You pressed a', 0
    message2 db 'Hi, You pressed b', 0
    message3 db 'Hi, You entered wrong credentials', 0
    newline db 10, 13, '$'

Code
    org 100h

    mov ax, 0
    int 16h

    mov ax, 0
    int 10h

    mov ax, 0
    int 16h

    mov bl, al

    mov ax, 0
    int 16h

    cmp bl, 'a'
    je keyA
    cmp bl, 'b'
    je keyB

    mov ah, 09h
    lea dx, message3
    int 21h

    jmp terminate

keyA:
    mov ah, 09h
    lea dx, message1
    int 21h

    jmp terminate

keyB:
    mov ah, 09h
    lea dx, message2
    int 21h

End:
    mov ah, 0
    int 16h

    mov ah, 4Ch
    int 21h