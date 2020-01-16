strprint macro str
	mov dx, offset str
	mov ah, 09h
	int 21h
endm

.model small
.stack 100h
.data
	menu db 10, 13, 10, 13, '1. Compare', 10, 13, '2. Concatenate', 10, 13, '3. Find No. of occurences', 10, 13, '4. Exit' , 10, 13, '    Your Response : ', '$'
	msg11 db 10, 13, 10, 13, 'Enter String 1 : $'
	msg12 db 10, 13, 10, 13, 'Enter String 2 : $'
	msg2 db 10, 13, 10, 13, 'String is : $'
	msg3 db 10, 13, 10, 13, 'Given strings are equal$'
	msg4 db 10, 13, 10, 13, 'Given strings are not equal$'
	msg5 db 10, 13, 10, 13, 'Concatenated string is : $'
	msg6 db 10, 13, 10, 13, 'The given string is not a palindrome$'
	msg7 db 10, 13, 10, 13, 'Occurences of string2 in string1 are : $'
	menures db ?
	res1 db 80 dup(?)
	res2 db 80 dup(?)
	newline db 10, 13, '$'
	len1 dw 00h
	len2 dw 00h
	occ dw 00h
	siw dw ?
	diw dw ?
.code
;	---Init data seg---
	mov ax, @data
	mov ds, ax
	
;	---print enter str---
	strprint msg11
	lea si, res1
	mov ah, 01h
	
;	---inp str char by char---
	loop11:
	int 21h
	cmp al, 13
	je loop11end
	mov [si], al
	inc si
	inc len1
	
	jmp loop11
	loop11end:
	
;	---Append '$' to end---
	mov al, '$'
	mov [si], al
	
;	---Print string is : ---
	strprint msg2
	
;	---Print the string---
	strprint res1
	
;	---print enter str---
	strprint msg12
	lea si, res2
	mov ah, 01h
	
;	---inp str char by char---
	loop12:
	int 21h
	cmp al, 13
	je loop1end
	mov [si], al
	inc si
	inc len2
	
	jmp loop12
	loop1end:
	
;	---Append '$' to end---
	mov al, '$'
	mov [si], al
	
;	---Print string is : ---
	strprint msg2
	
;	---Print the string---
	strprint res2
	
	
;	------ Menu driven ------
	menuloop:
	strprint menu
	
	mov ah, 01h
	int 21h
	cmp al, 31h
	je compstr
	cmp al, 32h
	je concat
	cmp al, 33h
	je occs
	jmp progend
	
	
	compstr:
	mov ax, len1
	mov bx, len2
	cmp ax, bx
	jne strne
	lea si, res1
	lea di, res2
	mov cx, len1
	loopcs:
	mov al, [si]
	mov ah, [di]
	cmp al, ah
	jne strne
	inc si
	inc di
	dec cx
	jnz loopcs
	
	strprint msg3
	jmp menuloop
	
	strne:
	strprint msg4
	jmp menuloop
	
;	---Concat---
	concat:
	lea si, res2
	lea di, res1
	add di, len1
	mov cx, len2
	loopcc:
	mov al, [si]
	mov [di], al
	inc si
	inc di
	dec cx
	jnz loopcc
	
	mov al, '$'
	mov [di], al
	
	mov ax, len1
	add ax, len2
	mov len1, ax
	
	strprint msg5
	
	strprint res1
	
	jmp menuloop
	
;	---Occurences--	
	
	occs:
	lea si, res1
	lea di, res2
	mov cx, len1
	mov occ, 00h
	
	ocl1:
		mov siw, si
		mov diw, di
		mov bx, len2
		ocl2:
			mov al, [si]
			mov ah, [di]
			cmp al, ah
			jne noocc
			inc si
			inc di
			dec bx
			cmp bx, 00h
		jne ocl2
		mov bx, occ
		inc bx
		mov occ, bx
		
		noocc:
		mov si, siw
		mov di, diw
		inc si
		dec cx
	jnz ocl1
	
	strprint msg7
	
	mov dx, occ
	add dx, 30h
	mov ah, 02h
	int 21h
	
	jmp menuloop
	
	progend:
	
;	---Terminate program---
	mov ah, 04ch
	int 21h
end
