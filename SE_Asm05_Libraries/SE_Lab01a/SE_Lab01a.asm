.586P
.MODEL FLAT, STDCALL
getmin		PROTO : DWORD, : DWORD
getmax		PROTO : DWORD, : DWORD
.STACK 4096

.CODE
getmin PROC parm1 : DWORD, parm2 : DWORD
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]
	loop_start:
		cmp eax, [esi]
		jle skip
		mov eax, [esi]
		skip:
		add esi, type parm1
	loop loop_start
	ret
getmin ENDP
getmax PROC parm1 : DWORD, parm2 : DWORD
START:
	mov ecx, parm2
	mov esi, parm1
	mov eax, [esi]
	loop_start:
		cmp eax, [esi]
		jge skip
		mov eax, [esi]
		skip:
		add esi, type parm1
	loop loop_start
	ret
getmax ENDP
end