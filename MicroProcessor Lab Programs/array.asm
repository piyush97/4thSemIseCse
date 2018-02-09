assumr cs:code, ds:data
data segment
  array db 10h,20h,30h,40h,50h
data ends

code segment
start:
  mov ax,data
  mov ds,ax
  
  mov D1,0
  mov a1,array[d1]
  add a1,07h
  add di,05h
  
  mov array[d1],a1
  mov ah,4ch
  int 21h
  
  code ends
  end start
