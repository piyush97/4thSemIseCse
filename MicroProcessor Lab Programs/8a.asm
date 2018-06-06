assume cs:code
code segment
start:
        mov ah,2ch              ;get system time
        int 21h
        
        mov al,ch               ; mov hours to al
        call hex_bcd            ;convert hours from hex to bcd
        call disp               ;display
        
        mov dl,':'              ; put the colon in dl register
        
        mov ah,2                ;get system time again
        int 21h
                
        mov al,cl               ;move minutes to al now
        call hex_bcd
        call disp

        mov ah,4ch
        int 21h

     disp proc
        push cx                 
        mov ah,00h
        
        mov cx,4
        shl ax,1
        shl ax,1
        shl ax,1
        shl ax,1

        shr al,1
        shr al,1
        shr al,1
        shr al,1
        
        add ax,3030h
        push ax
        
        mov dl,ah
        mov ah,2
        int 21h
        
        pop ax
        
        mov dl,al
        mov ah,2
        int 21h
        
        pop cx
        ret
        disp endp

      hex_bcd proc
      push cx
      mov cl,al
      mov ch,0
      mov al,0

   next:
        add al,1
        daa
        loop next
        pop cx
        ret
        hex_bcd endp

  code ends
  end start
