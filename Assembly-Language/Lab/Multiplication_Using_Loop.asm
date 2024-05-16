[org 0x100];

mov ax, [num1]
mov cx, [num2]
sub cx, 1
mov bx, 0
l1 :
	add ax, [num1]
       sub cx, 1
	jnz l1

mov [product], ax
  
mov ax,0x4c00
int 21h
num1 : dw 6
num2: dw 5
product: dw 0