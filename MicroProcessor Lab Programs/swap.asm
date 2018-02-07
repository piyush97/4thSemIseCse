assume cs:code,ds:data
  data segment
    x db 20h
    y db 30h
  data ends
    code segment
      start:
        mov ax, data
        mov ds, ax
        mov al,x
        mov bl,y
        mov x,bl
        mov y,al
        
        mov ah,4ch
        int 21h
        
     code ends
   end start
