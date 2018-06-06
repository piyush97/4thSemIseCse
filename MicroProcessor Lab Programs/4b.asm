assume cs:code, ds:data
data segment
         pa equ 20a0h
         pb equ 20a1h
         pc equ 20a2h
         cr equ 20a3h
data ends

code segment
    start:
           mov ax,data
           mov ds,ax

           mov dx,cr
           mov al,80h
           out dx,al

           mov cx,10h     ;degree of rotation
           mov al,22h     ; the quadrant

           mov dx,pa

    rot_clock:
               out dx,al
               rol al,1             ;anti-clockwise
               call delay
               loop rot_clock
               mov ah,4ch
               int 21h

    delay proc
              mov bx,000ffh
         l2:  mov di,02fffh
         l1:  dec di
              jnz l1
              dec bx
              jnz l2
              ret
          delay endp

code ends
end start
