[org 0x0100]

jmp start
multiplicand: dq 1300
multiplier: dd 500
result: dq 0
start:
    mov cx, 32             
    mov dx, [multiplier]   
    xor si, si            
    xor di, di            
checkbit:
    shr dx, 1              
    jnc skip                
    mov ax, [multiplicand] 
    add si, ax            
    mov ax, [multiplicand+4] 
    adc di, ax            
skip:
    shl dword [multiplicand], 1    
    rcl dword [multiplicand+4], 1  
    dec cx                 
    jnz checkbit            
    mov dword [result], si 
    mov dword [result+4], di 

    mov ax, 0x4c00          
    int 21h