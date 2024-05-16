.MODEL small
.STACK 100h

.DATA
    message1 DB 'Hi, You pressed a', 0
    message2 DB 'Hi, You pressed b', 0
    message3 DB 'Hi, You entered wrong credentials', 0
    newline DB 10, 13, '$'

.CODE
    ORG 100h

    ; Display message and wait for a keypress
    MOV AH, 0
    INT 16h

    ; Clear the screen
    MOV AH, 0   ; Function 0 - Clear the screen
    INT 10h

    ; Wait for the first keystroke
    MOV AH, 0   ; Function 0 - Read character from keyboard
    INT 16h     ; Wait for a keypress

    ; Store the first keypress in AL
    MOV BL, AL

    ; Display message and wait for a second keypress
    MOV AH, 0
    INT 16h

    ; Check the second keystroke
    CMP BL, 'a'
    JE key_a
    CMP BL, 'b'
    JE key_b

    ; Display the "wrong credentials" message
    MOV AH, 09h     ; Display string function
    LEA DX, message3
    INT 21h

    JMP terminate

key_a:
    ; Display the "Hi, You pressed a" message
    MOV AH, 09h     ; Display string function
    LEA DX, message1
    INT 21h

    JMP terminate

key_b:
    ; Display the "Hi, You pressed b" message
    MOV AH, 09h     ; Display string function
    LEA DX, message2
    INT 21h

terminate:
    ; Wait for a keypress to terminate the program
    MOV AH, 0
    INT 16h

    ; Exit to DOS
    MOV AH, 4Ch
    INT 21h

END