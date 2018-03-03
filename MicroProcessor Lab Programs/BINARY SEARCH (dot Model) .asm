.model small
.data
a dw 1234h,5678h,6252h,7617h,8213h ;numbers in ascending order
n equ 5
key dw 1234h ;keytobesearched
msg1 db 10,13,"Key is found$"
msg2 db 10,13,"Key is not found$"
.code
Mov ax,@data
Mov ds,ax ;Initialize thedatasegment
Mov ax,key
mov cx,0
mov dx,n-1
loop1:cmp cx,dx ja
notfound
mov bx,cx
add bx,dx
shr bx,1
mov si,bx
add si,si ;to point to the actual mid
cmp ax,a[si] je
found
ja above
mov dx,bx ;high=mid-1
dec dx
jmp loop1
above:mov cx,bx ;low=mid+1
inc cx
jmp loop1
found:lea dx,msg1
jmp print notfound:lea
dx,msg2 print: mov ah,09h
int 21h
mov ah,4ch int
21h
end
