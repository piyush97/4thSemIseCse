	PRESERVE8 
        THUMB       
        AREA    |.text|, CODE, READONLY
	
	EXPORT	__main			 

__main	
	MOVS	R0,#5
        MOVS	R1,#1
loop	
	MULS	R1,R0,R1
	SUBS	R0,R0,#1
	BNE loop
	NOP
	END
