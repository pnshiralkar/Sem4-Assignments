.model small
.stack 100h
.data
        msg db 'Numbers are : ', 13, 10, '$'
        newline db 13, 10, '$'

.code
	mov ax, @data
	mov ds, ax
	
	
	mov dx, offset msg
	mov ah, 09h
	int 21h
	
	mov cx, 10
	mov dl, 48
	mov ah, 02h
	
	loop1:
	int 21h
	inc dl
	dec cx
	jnz loop1
	
	mov ah, 04ch
	int 21h
end
