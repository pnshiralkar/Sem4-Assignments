.model small
.stack 100h
.data
        arr db 10 dup(?)
        newline db 10, 13, '$'
        space db ' $'
        nums db 10, 13, 'Enter number of elements : $'
        inp db 10, 13, 'Enter number : $'
        outl db 10, 13, 'Addition of numbers is : $'
.code
	mov ax, @data
	mov ds, ax
	
	mov dx, offset nums
	mov ah, 09h
	int 21h
	
	mov ah, 01h
	int 21h
	
	mov cl, al
	sub cl, 30h
	mov bl, cl
	mov si, 0
	
	loop1:
	mov ah, 09h
	mov dx, offset inp
	int 21h
	mov ah, 01h
	int 21h
	mov arr[si], al
	inc si
	dec cx
	jnz loop1
	
	
	mov ah, 09h
	mov dx, offset outl
	int 21h
	
	mov cl, bl
	mov si, 0
	
	xor dx, dx
	
	loop2:
	add dl, [si]
	sub dl, 30h
	inc si
	dec cx
	jnz loop2
	
	add dl, 30h
	mov ah, 02h
	int 21h
	
	
	mov ah, 04ch
	int 21h
end
