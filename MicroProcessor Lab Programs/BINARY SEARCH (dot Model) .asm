.MODEL SMALL

.STACK 100H

.DATA

        MATR1 DW 0001H,0002H,0003H,0004H,0005H,0006H,0007H,0008H,0009H,000AH

        SEARCH DW 0003H

        LOWER DW 0000H

        HIGHER DW 000AH

        MID DW 0000H

        TEMP DW 0000H

    CI DW 0000H

        MSG1 DB 'NUMBER FOUND','$'

        MSG2 DB 'NUMBER NOT FOUND','$'

.CODE

MAIN PROC FAR

        MOV AX,@DATA

        MOV DS,AX

        MOV BX,0002H

        LEA DI,MATR1

        LEA SI,MATR1+0014H

NEXT:   MOV AX,LOWER

        MOV DX,HIGHER

        CMP AX,DX

        JGE TERM2

        MOV AX,0

        MOV DX,0

        MOV AX,LOWER

        ADD AX,HIGHER

        DIV BX

        MOV SI,0000H

        MOV SI,AX

        ;MOV AL,SEARCH

    MOV CI,AX

    MUL BX

    MOV CX,AX

    MOV AX,CI

    MOV CI,CX

        CMP [SI+CI],SEARCH

        JGE AGAIN

        MOV HIGHER,AX

        JMP NEXT

AGAIN:  MOV SI,0000H

        MOV SI,AX

        MOV DX,AX

    MOV CI,AX

    MUL BX

    MOV CX,AX

    MOV AX,CI

    MOV CI,CX

    MOV AX,0

        CMP [SI+CI],SEARCH

        JE TERM

        MOV LOWER,DX

        JMP NEXT

TERM:   LEA DX,MSG1

        MOV AH,09H

        INT 21H

        MOV AH,4CH

        INT 21H

TERM2:  LEA DX,MSG2

        MOV AH,09H

        INT 21H

        MOV AH,4CH

        INT 21H

MAIN ENDP

END
