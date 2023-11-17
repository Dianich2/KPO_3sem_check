.586
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
a		byte	3
b		byte	2
MB_OK	EQU		0
STR1	DB	"Моя первая программа",0
STR2	DB	"Результат сложения= ",0
HW		DD	?	

.CODE

main PROC 
START :
		mov al,a
		add al,b
		add al,30h
		mov STR2+19,al
		PUSH MB_OK 
		PUSH OFFSET STR1
		PUSH OFFSET STR2
		PUSH HW
		call MessageBoxA
	push -1
	call ExitProcess
main ENDP

end main