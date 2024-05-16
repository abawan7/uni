[org 0x0100]

mov ax,0x1234
mov bx,0xABCD
mov si,0
mov cx,0
l1:
shr bx,1
jc l2
cmp bx,0
jne l1
jz l3
l2:
inc si
jmp l1
l3:
cmp si,0
jz end
mov dx,0000 0000 0000 0001b
l4:
xor ax,dx
shl dx,1
inc cx
cmp cx,si
jnz l4
end:

mov ax,0x4c00
int 21h