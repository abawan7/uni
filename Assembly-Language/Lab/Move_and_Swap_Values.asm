[org 0x100]

mov ax, 25h
mov bx, 10
mov cx, ax
mov ax, bx
mov bx, cx
mov word [0x270],1234h
mov bx, 0
l1 : mov ax, [num + bx]
	add bx, 2
	cmp bx, 6
	jne l1
  
mov ax,0x4c00
int 21h
num : dw 12,25,10