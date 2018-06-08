	PRESERVE8
	THUMB
	AREA |.text|,CODE,READONLY
	EXPORT __main
__main
	MOV R0,#5
	PUSH {R0}
	POP {R1}
stop	B	stop
	END
	
