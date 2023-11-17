.586
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
myBytes		BYTE	10h, 20h, 30h, 40h	
myWords		WORD	8Ah, 3BH, 44h, 5Fh, 99h
myDoubles	DWORD	1, 2, 3, 4, 5, 6
myPointer	DWORD	myDoubles

.CODE

main PROC 
START :
		mov IDI, OFFSET myWords
		mov	AX,[myWords+IDE]
		mov BX, myWords[0]
	push -1
	call ExitProcess
main ENDP

end main