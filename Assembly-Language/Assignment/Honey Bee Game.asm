[org 0x0100]
jmp start
h1 : db '     ___'
l1 : dw 8
h2 : db ' ___/   \___'
l2 : dw 12
h3 : db '/   \___/   \'
l3 : dw 13
h4 : db '\___/   \___/'
l4 : dw 13
h5 : db '/   \___/   \'
l5 : dw 13
h6 : db '\___/   \___/'
l6 : dw 13
h7 : db '    \___/'
l7 : dw 9

hline1 : db '___________'
ll1 : dw 11
hline2 : db '____________________'
ll2 : dw 20
hline3 : db '_______'
ll3 : dw 7
hline4 : db '____'
ll4 : dw 4
hline5 : db '___________________'
ll5 : dw 19
hline6 : db '_____________'
ll6 : dw 13
hline7 : db '___'
ll7 : dw 3
hline8 : db '______________'
ll8 : dw 14
hline9 : db '______________________'
ll9 : dw 22
bee : db '-(|):'
beelength : dw 5
beeindex : dw 3208
max_rownum : dw 78
tickcount: dw 0
bee2 : db ':(|)-'
bee2length : dw 5
gamename : db 'HONEYBEE MAZE ADVENTURE'
namelength : dw 23
instructions : db 'INSTRUCTIONS'
ilen : dw 12
inst1 : db '> Press Esc to exit'
len1 : dw 19
inst2 : db '> Press Space to start the game'
len2 : dw 31
inst3 : db '> Use arrow keys to move the bee'
len3 : dw 32
inst4 : db '> Try to avoid the obstacles'
len4 : dw 28
inst5 : db '> The bee should reach the honeycomb'
len5 : dw 36
loading : db 'Loading ...'
len6 : dw 11
congrats : db 'CONGRATULATIONS!!!'
clen : dw 18
win : db  'YOU WIN'
wlen : dw 7
score : db 'Your Score Is : '
slen : dw 16
baseline_score : dw 1000
bonus : dw 100
score_reduction : dw 10
total_score : dw 0
flag : dw 0
bonus_win : db 'YOU WON WITH 100 BONUS POINTS :)'
bwlen : dw 29
gameover : db '-------GAMEOVER-------'
glen : dw 22
crossborder : db 'you tried to cross the border:('
blen : dw 31

clr_scr:
mov ax,0xb800
mov es,ax
mov di,0
nextchar1:
mov word [es:di],0x6020  ;0110 0000 
add di,2
cmp di,4000
jne nextchar1
ret



border:
mov ax,0xb800
mov es,ax
mov ax,di
mov di,ax
push dx
mov dx,0

upperborder:
mov word[es:di],0x602D
add di,2
inc dx
cmp dx,76   
jne upperborder

mov dx,0
rightborder:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,22
jne rightborder

sub di,162
mov dx,0
bottomborder:
mov word[es:di], 0x602D
sub di,2
inc dx
cmp dx,76
jne bottomborder


mov dx,0
leftborder:
mov word[es:di],0x607C
sub di,160
inc dx
cmp dx,22
jne leftborder
pop dx
call honeycomb
ret


printstr: 
 push bp 
 mov bp, sp 
 push es 
 push ax 
 push cx 
 push si 
 push di 
 mov ax, 0xb800 
 mov es, ax ; point es to video base 
 mov si, [bp+6] ; point si to string 
 mov cx, [bp+4] ; load length of string in cx 
 mov ah, 0x60 ; normal attribute fixed in al 
nextchar: mov al, [si] ; load next char of string 
 mov [es:di], ax ; show this char on screen 
 add di, 2 ; move to next screen location 
 add si, 1 ; move to next char in string 
 loop nextchar ; repeat the operation cx times 
 pop di 
 pop si 
 pop cx 
 pop ax 
 pop es 
 pop bp 
 ret 4

printstr2:
push bp
mov bp, sp
push es
push ax
push cx
push si
push di
mov ax, 0xb800
mov es, ax
mov si, [bp+6]
mov cx, [bp+4]
mov ah, 0x07
nextchar2: mov al, [si]
mov [es:di], ax
add di, 2
add si, 1
loop nextchar2
pop di
pop si
pop cx
pop ax

pop es
pop bp
ret 4

printnum:	
		push bp
		mov bp, sp
		push es
		push ax
		push bx
		push cx
		push dx
		push di

		mov ax, 0xb800
		mov es, ax
		mov ax, [bp+4]
		mov bx, 10
		mov cx, 0

nextdigit:	
		mov dx, 0
		div bx
		add dl, 0x30
		push dx
		inc cx
		cmp ax, 0
		jnz nextdigit

		;mov di, 140

nextpos:	
		pop dx
		mov dh, 0x07
		mov [es:di], dx
		add di, 2
		loop nextpos

		pop di
		pop dx
		pop cx
		pop bx
		pop ax
		pop es
		pop bp
		ret 2


honeycomb: 
mov ax,h1
push ax
push word[l1]
mov di,608
call printstr
mov ax,h2
push ax
push word[l2]
add di,160
call printstr
mov ax,h3
push ax
push word[l3]
add di,160
call printstr
mov ax,h4
push ax
push word[l4]
add di,160
call printstr
mov ax,h5
push ax
push word[l5]
add di,160
call printstr
mov ax,h6
push ax
push word[l6]
add di,160
call printstr
mov ax,h7
push ax
push word[l7]
add di,160
call printstr
pop dx
ret


maze:
mov di,360
mov ax,0xb800
mov es,ax
mov ax,di
mov di,ax
push dx
mov dx,0
VLINE1:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE1
mov ax,hline1
push ax
push word[ll1]
mov di,490
call printstr
mov ax,hline2
push ax
push word[ll2]
mov di,530
call printstr
mov dx,0
add di,40
VLINE2:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,2
jne VLINE2
mov dx,0
mov di,418
VLINE3:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,6
jne VLINE3
mov dx,0
mov di,756
VLINE4:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE4
mov di,648
mov dx,0
VLINE5:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,9
jne VLINE5
mov ax,hline3
push ax
push word[ll3]
mov di,826
call printstr
mov di,688
mov dx,0
VLINE6:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE6
mov di,724
mov dx,0
VLINE7:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,2
jne VLINE7
mov ax,hline4
push ax
push word[ll4]
mov di,908
call printstr
mov ax,hline5
push ax
push word[ll5]
mov di,1130
call printstr
mov di,1016
mov dx,0
VLINE8:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE8
mov ax,hline3
push ax
push word[ll3]
mov di,864
call printstr
mov di,1038
mov dx,0
VLINE9:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE9
mov ax,hline6
push ax
push word[ll6]
mov di,1520
call printstr
mov di,1546
mov dx,0
VLINE10:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE10
mov di,1530
mov dx,0
VLINE11:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE11
mov ax,hline3
push ax
push word[ll3]
mov di,1178
call printstr
mov di,1136
mov dx,0
VLINE12:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,2
jne VLINE12
mov ax,hline7
push ax
push word[ll7]
mov di,1930
call printstr
mov di,2096
mov dx,0
VLINE13:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,5
jne VLINE13
mov ax,hline6
push ax
push word[ll6]
mov di,2738
call printstr
mov di,2924
mov dx,0
VLINE14:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,2
jne VLINE14
mov ax,hline1
push ax
push word[ll1]
add di,148
call printstr
add di,22
mov dx,0
VLINE15:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,6
jne VLINE15
mov ax,hline8
push ax
push word[ll8]
sub di,28
call printstr
mov dx,0
VLINE16:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,5
jne VLINE16
mov ax,hline4
push ax
push word[ll4]
sub di,8
call printstr
mov dx,0
VLINE17:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,1
jne VLINE17
mov ax,hline5
push ax
push word[ll5]
call printstr
mov ax,hline8
push ax
push word[ll8]
mov di,3048
call printstr
mov dx,0
VLINE18:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,5
jne VLINE18
mov di,3424
mov dx,0
VLINE19:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,8
jne VLINE19
mov ax,hline8
push ax
push word[ll8]
sub di,28
call printstr
mov dx,0
VLINE20:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE20
mov ax,hline8
push ax
push word[ll8]
add di,322
call printstr
mov ax,hline7
push ax
push word[ll7]
add di,28
call printstr
mov dx,0
add di,6
VLINE21:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE21
mov ax,hline3
push ax
push word[ll3]
mov di,3434
call printstr
mov dx,0
mov di,3288
VLINE22:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE22
mov ax,hline3
push ax
push word[ll3]
mov di,3458
call printstr
mov dx,0
mov di,3312
VLINE24:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,2
jne VLINE24
sub di,486
mov ax,hline3
push ax
push word[ll3]
call printstr
add di,174
mov dx,0
VLINE25:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE25	
mov di,2954
mov dx,0
VLINE26:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE26
add di,2	
mov ax,hline6
push ax
push word[ll6]
call printstr
add di,26
mov dx,0
VLINE27:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,5
jne VLINE27
add di,298
mov ax,hline1
push ax
push word[ll1]
call printstr
add di,644
mov dx,0
VLINE28:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,3
jne VLINE28
sub di,158
mov ax,hline9
push ax
push word[ll9]
call printstr
add di,204
mov dx,0
VLINE29:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,4
jne VLINE29
add di,12
sub di,160
mov ax,hline3
push ax
push word[ll3]
call printstr
sub di,320
sub di,10
mov ax,hline3
push ax
push word[ll3]
call printstr
sub di,160
sub di,36
mov dx,0
VLINE30:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,2
jne VLINE30
sub di,480
add di,16
mov dx,0
VLINE31:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,6
jne VLINE31
add di,2
mov ax,hline1
push ax
push word[ll1]
call printstr
add di,960
add di,8
mov dx,0
VLINE32:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,3
jne VLINE32
add di,2
mov ax,hline1
push ax
push word[ll1]
call printstr
add di,22
mov dx,0
VLINE33:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,4
jne VLINE33
add di,800
sub di,6
mov dx,0
VLINE34:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,3
jne VLINE34
sub di,158
mov ax,hline4
push ax
push word[ll4]
call printstr
pop dx
ret

honeybee:
add di,2
mov ax,bee
push ax
push word[beelength]
call printstr
ret

honeybee2:
add di,2
mov ax,bee2
push ax
push word[bee2length]
call printstr
ret


clear_bee:
mov ax,0xb800
mov es,ax
mov si,0
nextchar3:
mov word [es:di],0x6020  ;0110 0000 
add di,2
add si,1
cmp si,9	
jne nextchar3
ret



delay:
	push cx
	mov cx,20
	d1:
	push cx
	mov cx,50930
	d2:
	dec cx
	jne d2
	pop cx
	loop d1
	pop cx
	ret


delay2:
	push cx
	mov cx,40
	d3:
	push cx
	mov cx,50930
	d4:
	dec cx
	jne d4
	pop cx
	loop d3
	pop cx
	ret


interface:

call clr_scr
mov di,324
call border
call maze
call Timer
ret


Timer:
	push dx
	mov dx,[tickcount]
	add dx,1
	mov word [tickcount],dx
	mov di, 140
	push dx
	call printnum
	pop dx
	ret	

start_screen:
call clr_scr
mov di, 700
mov ax, gamename
push ax
push word [namelength]
call printstr
mov di, 540
mov ax, hline9
push ax
push word [ll9]
call printstr
mov di, 1160
mov ax, hline9
push ax
push word [ll9]
call printstr
add di,44
mov ax, hline9
push ax
push word [ll9]
call printstr
add di,146
mov ax, instructions
push ax
push word [ilen]
call printstr
mov di,3400
mov ax, hline9
push ax
push word [ll9]
call printstr
add di,44
mov ax, hline9
push ax
push word [ll9]
call printstr
sub di,44
mov dx,0
straightline2:
mov word[es:di], 0x607C
sub di,160
inc dx
cmp dx,14
jne straightline2
mov di, 1406
mov dx,0
straightline1:
mov word[es:di], 0x607C
add di,160
inc dx
cmp dx,14
jne straightline1
mov di,1644
mov ax, inst1
push ax
push word [len1]
call printstr
add di,320
mov ax, inst2
push ax
push word [len2]
call printstr
add di,320
mov ax, inst3
push ax
push word [len3]
call printstr
add di,320
mov ax, inst4
push ax
push word [len4]
call printstr
add di,320
mov ax, inst5
push ax
push word [len5]
call printstr
ret


loading_screen:
mov di,3750
mov ax,loading
push ax
push word[len6]
call printstr
ret

score_calculator:
mov ax, [baseline_score]
mov bx, [tickcount]
mov cx, [score_reduction]
imul bx,cx
sub ax,bx
mov dx,63
cmp bx,dx
jbe add_bonus
add_bonus:
mov word[flag],1
add ax,[bonus]
skip_bonus:
mov [total_score],ax
ret


score_screen:
call clr_scr
mov di, 1020
mov ax, congrats
push ax
push word [clen]
call printstr

print_score:
mov di, 1660
mov ax, score
push ax
push word [slen]
call printstr2
call score_calculator
push dx
mov dx,[total_score]
add di, 32
push dx
call printnum
pop dx

cmp word[flag],1
jne no_bonus
win_with_bonus
mov di, 1332
mov ax, bonus_win
push ax
push word [bwlen]
call printstr
jmp last
no_bonus:
mov di, 1348
mov ax, win
push ax
push word [wlen]
call printstr
last:
ret


game_over:
call clr_scr
mov di, 1338
mov ax, gameover
push ax
push word [glen]
call printstr

add di,320
sub di,6
mov ax, crossborder
push ax
push word [blen]
call printstr
ret
;//////////////////////////////////////////////////////////////////////////////////////
start:
call start_screen
mov ax, 0
int 16h
cmp al, 0x1b       ;Check for Escape key
je end_of_maze1
mov ax, 0
int 16h
cmp al, 0x20
jne end_of_maze1
start_again:
call loading_screen
call delay2
call interface
call Timer
mov di,[beeindex]
call honeybee
mov bx, 0      ; bx will hold the bee's position in the maze (initially set to 0)
;///////press space to start game and esc to end game

move_bee: 
    
    mov ax, 0
    int 16h
    cmp al, 0x1B       ; Check for Escape key
    je end_of_maze1     
    in al, 0x60
    cmp al, 0x4D
    je forward_loop
    cmp al, 0x50
    je downward_loop
    cmp al, 0x4B
    je backward_loop1
    cmp al, 0x48
    je upward_loop
    
    jmp move_bee      ; If none of the movement keys are pressed, continue the loop

end_of_maze1:
jmp end_of_maze
forward_loop:
    
    call clear_bee
    call interface
    add word[beeindex],6
    mov di,[beeindex]
    cmp word[es:di],0x607C
    je game_over
    call honeybee
    call delay
    ; Move the bee forward
    mov dx, 1   ; Move one position forward
    add bx, dx  ; Update the bee's position
    cmp word[beeindex],608
    je score_screen
    jmp move_bee

backward_loop1:
jmp backward_loop
upward_loop:
    
call clear_bee
    call interface
    sub word[beeindex],160
    mov di,[beeindex]
    cmp word[es:di],0x602D
    je game_over
call honeybee
    call delay
    ; Move the bee downward
    sub dx, 160   ; Move one position forward
    add bx, dx  ; Update the bee's position
    cmp word[beeindex],1586
    je score_screen
    jmp move_bee

downward_loop:
    
call clear_bee
    call interface
    add word[beeindex],160
    mov di,[beeindex]
    cmp word[es:di],0x602D
    je game_over
    mov di,[beeindex]
call honeybee
    call delay
    ; Move the bee downward
    add dx, 160   ; Move one position forward
    add bx, dx  ; Update the bee's position
    jmp move_bee


backward_loop:
   
call clear_bee
    call interface
    sub word[beeindex],6
    mov di,[beeindex]
    cmp word[es:di],0x607C
    je game_over
    mov di,[beeindex]
    call honeybee2
    call delay
    ; Move the bee backward
    sub dx, 1   ; Move one position forward
    add bx, dx  ; Update the bee's position
    jmp move_bee


end_of_maze:
    mov ax, 0x4c00
    int 0x21

