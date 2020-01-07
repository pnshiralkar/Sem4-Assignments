.model small
.stack 100h
.data
	hx db 'Addition in hex is : $'
	dc db 'Addition in decimal is : $'
	newline db 10, 13, '$'
	ansl db ?
	ansh db ?
.code
	mov ax, @data
	mov ds, ax
	
	mov ax, 215	
	mov bx, 125
	add ax, bx
	mov cx, ax ; temporarily store ax in cx
	mov ansl, al
	mov ansh, ah
	
	xor ax,ax
	
	mov dx, offset hx
	mov ah, 09h
	int 21h
	
	mov ax, cx ; restore cx in ax
	
	mov bx, 10h
	div bx
	mov cx, dx

	div bx
	mov bx, dx
	
	mov dx, ax
	add dx, 30h
	mov ah, 02h
	int 21h
	
	mov dx, bx
	add dx, 30h
	mov ah, 02h
	int 21h
	mov dx, cx
	add dx, 30h
	mov ah, 02h
	int 21h
	
	
;   ----Decimal----
	
	mov dx, offset newline
	mov ah, 09h
	int 21h
	
	mov dx, offset dc
	mov ah, 09h
	int 21h
	
	mov al, ansl
	mov ah, ansh

	mov bx, 0Ah
	xor dx, dx
	div bx
	
	mov cx, dx ; cx = units
	
	div bx     ; ax = hundreds
	mov bx, dx ; bx = tens
	
	mov dx, ax
	add dx, 30h
	mov ah, 02h
	int 21h
	
	mov dx, bx
	add dx, 30h
	mov ah, 02h
	int 21h
	
	mov dx, cx
	add dx, 30h
	mov ah, 02h
	int 21h
	
	mov ah, 04ch
	int 21h
end
