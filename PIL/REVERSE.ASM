.model small
.stack 100h
.data
        string db 'hello$'
        msg db 13,10,'Reverse: $'
.code

        mov ax,@data
        mov ds,ax 

        lea dx,string
        mov ah,09h
        int 21h

        add si,0
        mov ax,00
        lea dx,msg
        mov ah,09h
        int 21h

        l2: cmp string[si],'$'
            je l1
            inc si
            add al,1
            jmp l2

        l1: mov cl,al
        
        add cl,1
        dec si

        loop1: mov dl,string[si]
               mov ah,02h
               int 21h
               dec si
               dec cl
               jnz loop1

        mov ah,4ch
        int 21h
 end
               
            



