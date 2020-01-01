.model small
.stack 100h
.data
        abc db 'Hello World!', 10, '$'
        pict db 'PICT, Pune', 13, 10, '$'
        a db 3
        b db 2
.code
	mov ax, @data
	mov ds, ax
	
	mov ah, 09h
        mov dx, offset abc
	int 21h
	
	mov ah, 09h
        mov dx, offset pict
	int 21h
	
	mov al, a
	mov bl, b
	add al, bl
	add al, 30h
	mov dl, al
	mov ah, 02h
	int 21h
	
	mov dl, 41h
	mov ah, 02h
	int 21h
	
	
	mov ah, 04ch
	int 21h
end
