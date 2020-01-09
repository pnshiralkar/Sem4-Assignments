.model small
.stack 100h
.data
        string db 'hello$'
        msg1 db 13,10,'Entered String is a Palindrome$'
        msg2 db 13,10,'Entered String is not a palindrome$'
        reverse db 20 dup(?)
        length dw 00
.code

        mov ax,@data
        mov ds,ax

        lea dx,string
        mov ah,09h
        int 21h

        add si,0
        mov ax,00

        l2: cmp string[si],'$'
            je l1
            inc si
            add al,1
            jmp l2

        l1: mov cl,al

        add cl,1
        dec si
        mov dl,0
        loop1: mov al,string[si]
               mov reverse[dl],al
               dec si
               inc dl
               jnz loop1

        loop2: cmp 

            

