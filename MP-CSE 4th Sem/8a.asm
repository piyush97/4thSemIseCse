	PRESERVE8
	THUMB
	AREA |.text|,CODE,READONLY
	EXPORT __main
__main
	MOVS R0,#3
	CMP R0,#3
	BHI default_case
	MOVS R2,#4
	MUL R0,R2,R0
	LDR R1,=BranchTable
	LDR R2,[R1,R0]
	BX R2
	ALIGN 4
BranchTable
	DCD Test0
	DCD Test1
	DCD Test2
	DCD Test3
default_case
	MOVS R0,#1
stop B stop 
Test0    
	MOVS R0,#2
stop1 B stop1
Test1     
	MOVS r0,#3
stop2 B stop2
Test2     
	MOVS R0,#4
stop3 B stop3
Test3   
	MOVS R0,#5
stop4 B stop4
	END
