[org 0x100]

mov ax, 200h
mov bx, 150h

mov word [200], 25h
mov word [250], 15h

mov ax, [200]
mov cx, [250]

mov dx, [200]
mov bx, [250]
mov [200], bx
mov [250], dx

mov ax, [num]
mov bx, [num + 2]
mov cx, [num + 4]
mov dx, [num + 6]
mov si, [num + 8]
mov di, [num + 10]

mov ax, 0x4c00
int 21h

num: dw 2, 1, 0, 0, 1, 3
