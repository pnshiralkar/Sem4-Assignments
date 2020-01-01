.model small
.stack 100h
.data
        a db 9
        b db 2
.code
	mov ax, @data
	mov ds, ax
	
	mov ax, 9h ; ax = 9h
	mov bx, 2h ; bx = 2h
	add ax, bx ; ax += bx
	add ax, 30h ; add 30h to get char 0-9
	
	cmp ax, 39h ; compare ax and decimal 9
	jle no_add_7 ; if ax > dec. 9 then jump to no_add_7
	
	add ax, 07h ; if not jumped add 7 (to get A-F)
	no_add_7:
	
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov ah, 04ch
	int 21h
end
