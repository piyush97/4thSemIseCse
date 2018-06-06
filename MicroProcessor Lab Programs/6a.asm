assume cs:code
code segment
start:
        mov al,2        ;sets screen resolution to 24*80
        mov ah,0        ;clears screen 
        int 10h         

        mov ah,2
        mov dh,12d      ;12th line
        mov dl,40d      ;40th character
        int 10h         ;now cursor is at the center

        mov ah,9
        mov bl,8fh      ;8 : For setting color of background(can be 1,2,3..)
                        ;f : For setting color of text
                        ;8 when made 0 stops blinking
        mov al,'X'
        mov cl,01       ;01 for displaying once 
        int 10h             
      

        mov ah,7        ;For reading next command
        int 21h

        mov ah,4ch
        int 21h
code ends
end start
