.model small
.stack 100h
.data
        string db 'hello$'
        msg db 13,10,'Size: $'
.code
        mov ax,@data
        mov ds,ax

        lea dx,string
        mov ah,09h
        int 21h

        lea dx,msg
        mov ah,09h
        int 21h

        add si,0
        mov ax,00

        l2: cmp string[si],'$'
            je l1
            inc si
            add al,1
            jmp l2

        l1:add al,30h

            mov dl,al
            mov ah,02h
            int 21h

            mov ah,4ch
            int 21h

end


        







            
