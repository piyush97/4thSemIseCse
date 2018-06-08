	PRESERVE8
	THUMB
	AREA |.text|,CODE,READONLY
	EXPORT __main
func
	MOVS R1,#2
	MOVS R3,#9
	MULS R0,R1,R0
	ADDS R0,R0,R3
	BX lr
__main
	MOV R0,#4
	BL func
stop B stop
	END
