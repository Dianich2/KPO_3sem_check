.586
.MODEL FLAT, STDCALL
includelib kernel32.lib
includelib msvcrt.lib
includelib "..\Debug\SE_Lab01a.lib"
getmin PROTO : DWORD, : DWORD
getmax PROTO : DWORD, : DWORD

ExitProcess PROTO: DWORD
MessageBoxA PROTO: DWORD, : DWORD, : DWORD, : DWORD
SetConsoleTitleA PROTO : DWORD
GetStdHandle PROTO :DWORD
WriteConsoleA PROTO :DWORD, :DWORD, :DWORD, :DWORD, :DWORD

.STACK 4096

.CONST

.DATA
Array		DWORD	 2, 3, 4, 5,1, -6, 8, 9, 10
TitleCon	DB		"console",0
Text		db		"getmin+getmax=",0
output		db		10 dup(0)
consolehandle dd	0h
max			DWORD	?

.CODE
int_to_char PROC uses eax ebx ecx edi esi,
					pstr		: dword, 
					intfield	: sdword 

	mov edi, pstr
	mov esi, 0
	mov eax, intfield												
	cdq
	test eax, eax													
	mov ebx, 10;
	idiv ebx														
	jns plus														
	neg eax
	neg edx
	mov cl, '-'														
	mov [edi], cl													
	inc edi															

plus:
	push dx															
	inc esi															
	test eax, eax													
	jz fin															
	cdq																
	idiv ebx  
	jmp plus														

fin:																
	mov ecx, esi

write:																
	pop bx															 
	add bl,'0'														
	mov [edi], bl													
	inc edi
	loop write														 
	ret
	
int_to_char ENDP
main PROC 
START :
	push offset TitleCon
	call SetConsoleTitleA

	push -11
	call GetStdHandle
	mov consolehandle,eax

	push 0
	push 0
	push sizeof Text
	push offset Text
	push consolehandle
	call WriteConsoleA

	INVOKE getmax, OFFSET Array, LENGTHOF Array
	mov max, eax
	INVOKE getmin, OFFSET Array, LENGTHOF Array
	add eax, max

	INVOKE int_to_char, OFFSET output, eax
	push 0
	push 0
	push sizeof output
	push offset output
	push consolehandle
	call WriteConsoleA
	push -1
	call ExitProcess
main ENDP

end main