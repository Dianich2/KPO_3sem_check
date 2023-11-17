.586
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
myBytes		BYTE	10h, 20h, 30h , 40h	
myWords		WORD	8Ah, 3BH, 44h, 5Fh, 99h
myDoubles	DWORD	1, 2, 3, 4, 5, 6
myPointer	DWORD	myDoubles
array		DWORD	1, 2, 3, 4, 5, 6
sum			DWORD	0

.CODE

main PROC 
START :
		mov EDI, 2
		mov	AX, [myWords+EDI]
		mov BX, myWords[0]

		mov ESI, OFFSET array ;ссылка на первый эл
		mov ECX, LENGTHOF array 
		mov EAX, 0
		
sum_loop:
	add EAX, [ESI]
	cmp ESI, 0
	add ESI, type array
loop sum_loop
	jz EXIT_WITH_NULL
		mov EBX, 1
		jmp Exit
	EXIT_WITH_NULL:
		mov EBX, 0
	Exit:
	push -1
	call ExitProcess
main ENDP

end main