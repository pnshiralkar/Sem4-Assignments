; Write alp to find and display length of string


.model small
.stack 100h
.data
	menu db 10, 13, '1. Hex to BCD', 10, 13, '2. BCD to Hex', 10, 13, '3. Exit', 10, 13, '    Your Response : ', '$'
	res db ?
	newline db 10, 13, '$'
	
	hx db 'hex to bcd$'
	dc db 'bcd to hex$'
.code
	mov ax, @data
	mov ds, ax
	
	
	loop1:
	mov res, 0
	
	mov dx, offset menu
	mov ah, 09h
	int 21h
	
	mov ah, 01h
	int 21h
	mov res, al
	
	cmp res, 31h
	je h2b
	cmp res, 32h
	je b2h
	cmp res, 33h
	je loopend
	
	h2b:
	; logic
	mov dx, offset hx
	mov ah, 09h
	int 21h
	jmp loop1
	
	b2h:
	; logic
	mov dx, offset dc
	mov ah, 09h
	int 21h
	jmp loop1
	
	loopend:
	
	mov ah, 04ch
	int 21h
end
