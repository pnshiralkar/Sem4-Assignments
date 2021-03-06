; Write alp to find and display length of string


.model small
.stack 100h
.data
	menu db 10, 13, 10, 13, '1. Calculate Length', 10, 13, '2. Display reverse', 10, 13, '3. Check palindrome', 10, 13, '4. Exit' , 10, 13, '    Your Response : ', '$'
	msg1 db 10, 13, 10, 13, 'Enter String : $'
	msg2 db 10, 13, 10, 13, 'String is : $'
	msg3 db 10, 13, 10, 13, 'Length : $'
	msg4 db 10, 13, 10, 13, 'Reverse : $'
	msg5 db 10, 13, 10, 13, 'The given string is a palindrome$'
	msg6 db 10, 13, 10, 13, 'The given string is not a palindrome$'
	menures db ?
	res db 80 dup(?)
	newline db 10, 13, '$'
	len dw 00h
	
	
.code
;	---Init data seg---
	mov ax, @data
	mov ds, ax
	
;	---print enter str---
	mov dx, offset msg1
	mov ah, 09h
	int 21h
	lea si, res
	mov ah, 01h
	
;	---inp str char by char---
	loop1:
	int 21h
	cmp al, 13
	je loop1end
	mov [si], al
	inc si
	inc len
	
	jmp loop1
	
	
	loop1end:
;	---Append '$' to end---
	mov al, '$'
	mov [si], al
	
;	---Print string is : ---
	mov dx, offset msg2
	mov ah, 09h
	int 21h
	
;	---Print the string---
	mov dx, offset res
	mov ah, 09h
	int 21h
	
;	------ Menu driven ------
	menuloop:
	mov dx, offset menu
	mov ah, 09h
	int 21h
	
	mov ah, 01h
	int 21h
	cmp al, 31h
	je callen
	cmp al, 32h
	je rev
	cmp al, 33h
	je cpal
	jmp progend
	
	
	
	callen:
	call callenp
	
	
	rev:
	call revp
	
	cpal:
	call palp
	
	progend:
	
;	---Terminate program---
	mov ah, 04ch
	int 21h
	
	
	revp proc near
		;	---Print reverse :---
		mov dx, offset msg4
		mov ah, 09h
		int 21h
		
		
		;	---Print reverse string---
		lea di, res
		add di, len
		sub di, 1
		mov dx, [di]
		mov ah, 02h
		mov cx, len
		loop2:
		mov dx, [di]
		int 21h
		dec di
		dec cx
		jnz loop2
		
		jmp menuloop
		ret
	endp revp
	
	
	palp proc near	
	;	---Check Palindrome---
		lea si, res
		lea di, res
		add di, len
		sub di, 1
		mov cx, len
		
		loop3:
		mov al, [si]
		mov ah, [di]
		cmp al, ah
		jne notpal
		inc si
		dec di
		dec cx
		jnz loop3
			
		xor ax, ax
	;	--- Print str is pal ---
		mov dx, offset msg5
		mov ah, 09h
		int 21h
		
		jmp palend
		
		notpal:	
	;	--- Print str not pal ---
		mov dx, offset msg6
		mov ah, 09h
		int 21h
		
		palend:
		jmp menuloop
		ret
	endp palp
	
	
	callenp proc near
	;	---Print length is---
		mov dx, offset msg3
		mov ah, 09h
		int 21h
		
	;	---Print length---
		xor dx,dx
		mov dx, len
		add dx, 30h
		mov ah, 02h
		int 21h
		jmp menuloop
		ret
	endp callenp
end
