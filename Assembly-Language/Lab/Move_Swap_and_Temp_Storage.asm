[org 0x0100];
mov ax,200h
mov bx,150h
mov [0x200],25h
mov [0x250],15h

mov bx,[0x200]
mov ax,bx

mov cx,[0x250]

mov bx,[ax]
mov dx,[cx]

mov ax,[dx]
mov cx,[bx]


mov si,0
mov di,0
mov ax,[num1+si]
mov [temp+di],ax

add si,2
add di,2

mov ax,[num1+si]
mov [temp+di],ax

add si,2
add di,2

mov ax,[num1+si]
mov [temp+di],ax

add si,2
add di,2

mov ax,[num1+si]
mov [temp+di],ax

add si,2
add di,2

mov ax,[num1+si]
mov [temp+di],ax

add si,2
add di,2

mov ax,[num1+si]
mov [temp+di],ax

num : dw 2,1,0,0,1,3
num1 : dw 0,0,1,1,2,3
temp : dw 0,0,0,0,0,0

