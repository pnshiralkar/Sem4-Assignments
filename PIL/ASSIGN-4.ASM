print macro m
mov dx,offset m
mov ah,09h
int 21h
endm

.model small
.data
menu db ,13,10, "Menu: "
     db ,13,10, "1.Enter the strings "
     db ,13,10, "2.Check the equality "
     db ,13,10, "3.Concatenation "
     db ,13,10, "4.Exit "
     db ,13,10, "Enter Your choice: $"

empty db 13,10,"  $"

str1 db 25,?,25 dup('$')
str2 db 25,?,25 dup('$')

len1 db ?
len2 db ?
mstring db ,13,10,"Enter the first String: $"
mstring1 db ,13,10,"Enter the second String: $"
mconcat db ,13,10,"Concatenated String: $"
mequal db ,13,10,"Strings are equal$"
mnotequal db ,13,10,"String are not equal$"
mlength1 db ,13,10,"Length of first String: $"
mlength2 db ,13,10,"Length of second string: $"

error db ,13,10,"Enter the valid choice!!$",13,10,"$"

.code   

start:
        mov ax,@data
        mov ds,ax

        again:
        print menu
        call accept
        mov bl,al

        case1:
                cmp bl,"1"
                jne case2

                print empty
                print mstring
                call accept_string1
                print empty
                print mstring1
                call accept_string2
                mov cl,str1+1
                mov bl,cl
                print mlength1
                call display1
                print empty
                mov cl,str2+1
                mov bl,cl
                print mlength2
                call display1
                jmp again

        case2:
                cmp bl,"2"
                jne case3
                print empty
                lea si,str1
                lea di,str2
                mov bx,00

                mov bl,str1+1
                mov bh,str2+1

                cmp bl,bh
                jne l1

                add si,2
                add di,2

                l2: mov bl,byte ptr[si]
                    cmp byte ptr[di],bl
                    jne l1
                    inc si
                    inc di
                    cmp byte ptr[di],'$'
                    jne l2

                    lea dx,mequal
                    mov ah,09h
                    int 21h

                    jmp l5

               l1: lea dx,mnotequal
                   mov ah,09h
                   int 21h


               l5:
                  jmp again


        case3:
              cmp bl,"3"
              jne  case4
              print empty

              mov cl,str1+1
              mov si,offset str1
              next: inc si
                    dec cl
                    jnz next
                    inc si

                    inc si
                   
                    mov di,offset str2
                    inc di
                    inc di

                     mov cl,str2+1

              mov_next: mov al,[di]
                        mov [si],al
                        inc si
                        inc di
                        dec cl
                        jnz mov_next
                        print str1+1
                        print empty

              jmp again

        case4:
               cmp bl,"4"
               jne case5
               jmp exit
        case5:
               print error
               print empty
               jmp again
        exit:
                mov ah,4ch
                int 21h

        accept proc near
        mov ah,01h
        int 21h
        ret
        accept endp

        display1 proc near

        mov al,bl
        mov bl,al
        and al,0f0h
        mov cl,04
        rol al,cl

        cmp al,09
        jbe number
        add al,07h

        number: add al,30h
                mov dl,al
                mov ah,02h
                int 21h

                mov al,bl
                and al,00fh
                cmp al,09h
                jbe number2
                add al,07h

        number2: add al,30h
                 mov dl,al
                 mov ah,02h
                 int 21h

        ret
        display1 endp

        accept_string1 proc near

        mov ah,0ah
        mov dx, offset str1
        int 21h
        ret
        accept_string1 endp

       accept_string2 proc near

       mov ah,0ah
       mov dx,offset str2
       int 21h
       ret

       accept_string2 endp

end start
end








