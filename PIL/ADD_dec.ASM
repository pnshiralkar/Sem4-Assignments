.model small
.stack 100h
.data
        a db 9
        b db 2
.code
	mov ax, @data
	mov ds, ax
	
	xor ax, ax
	
	mov al, 08h
	mov bx, ax
	mov al, 02h
	add ax, bx ; ax += bx
	mov bx, 0Ah
	
	xor dx, dx
	
	div bx
	
	add al, 30h
	add dl, 30h
	mov bl, dl
	
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov ah, 04ch
	int 21h
end
