	MOV R7,  #04h
	MOV 20h, #0Ah
	MOV 21h, #07h
	MOV 22h, #09h
	MOV 23h, #07h

	CLR A
	MOV R0, #20h

VOLTA:	MOV R2, A
	MOV A, @R0
	MOV R1, A
	MOV A, R2
	ADD A, R1
	INC R0
	DJNZ R1, VOLTA

	MOV R2, #0
	MOV B, R7
	DIV AB
