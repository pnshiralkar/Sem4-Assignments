; Write alp to find and display length of string


.model small
.stack 100h
.data
	msg1 db 10, 13, 'Enter String : $'
	msg2 db 10, 13, 'String is : $'
	msg3 db 10, 13, 'Length : $'
	res db 80 dup(?)
	newline db 10, 13, '$'
	len dw 00h
.code
	mov ax, @data
	mov ds, ax
	
	mov dx, offset msg1
	mov ah, 09h
	int 21h
	lea si, res
	mov ah, 01h
	
	loop1:
	int 21h
	cmp al, 13
	je loop1end
	mov [si], al
	inc si
	inc len
	
	jmp loop1
	
	loop1end:
	mov al, '$'
	mov [si], al
	
	mov dx, offset msg2
	mov ah, 09h
	int 21h
	
	mov dx, offset res
	mov ah, 09h
	int 21h
	
	mov dx, offset msg3
	mov ah, 09h
	int 21h
	
	xor dx,dx
	mov dx, len
	add dx, 30h
	mov ah, 02h
	int 21h
	
	mov ah, 04ch
	int 21h
end
