assume cs:code
code segment
start:
      mov cx, 100d
      mov bl, 00
      
      
next_digit:
          mov al,bl
          aam
          add ax,3030h

          mov dl,ah           ; output ah
          mov ah,2            ; output a character
          push ax             ; push and pop saves the value of al register
          int 21h
          pop ax

          mov dl,al           ; output al
          mov ah,2            ; output a character
          int 21h

          mov dl,0dh          ; display carraige return
          mov ah,2            ; output a character
          int 21h

          

          call delay
          inc bl
          loop next_digit
          
          mov ah,4ch
          int 21h
          
          
delay proc
        mov si, 0222h
     l1:mov di, 02ffh
     l2:dec di
        jnz l2
        dec si
        jnz l1
        ret
        
delay endp
code ends
end start
