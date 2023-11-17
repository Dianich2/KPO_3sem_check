.586
.MODEL FLAT, STDCALL
includelib kernel32.lib

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD

.STACK 4096

.CONST

.DATA
MB_OK	EQU		0
STR1	DB	"Моя первая программа"
STR2	DB	"Привет, всем!"
HW		DD	?	

.CODE

main PROC 
START :
		PUSH MB_OK 
		PUSH OFFSET STR1
		PUSH OFFSET STR2
		PUSH HW
		call MessageBoxA
	push -1
	call ExitProcess
main ENDP

end main