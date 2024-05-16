[org 0x100];
mov si,0
miv di,0
l1:
mov ax,[digits+si]
cmp ax,-1
je end
add di,2

l2:
mov bx,[digits+di]
cmp bx,-1
je next
cmp ax,bx
je end
add di,2
jmp l2

next;
add si,2
mov di,si
jmp l1

end:
mov bx,1

mov ax,0x4c00
int 21h

digits: dw 1,1,2,1,1,-1