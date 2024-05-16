[org 0x100];

mov al,[key]
mov dx,0
mov si,0
l1:
cmp si,-1
je end
cmp al,[arr1+si]
je end
inc si
jmp l1

mov si,-1

end:
mov dx,si


mov ax,0x4c00
int 21h

key : db 30
arr1 : db 1,15,-11,30,2,14,68,120,9,-1