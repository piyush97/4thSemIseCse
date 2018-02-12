assume cs:code,ds:data
data segment
   x db 12h
   y db 45h
data ends

code segment
  start:
       mov ax,data
       mov ds,ax

       mov ah,x
       mov bh,y
       add ah,bh

       shr ah,1
       shr ah,1

mov ah,4ch
Int 21h
  code ends
  end start
