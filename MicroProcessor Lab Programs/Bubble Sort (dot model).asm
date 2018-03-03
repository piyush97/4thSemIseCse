.model small
.data
Arr db 5,1,8,7,4,3 ;array to be sorted
Len equ $-arr ;to find the length of array
.code
Mov ax,@data
Mov ds,ax ; initializing the data segment
mov ch,len-1 ;ch holds number of passes
again:mov cl,ch ;cl holds number of comparisons
mov si,offset arr ;point si to the first element of array
repeat:mov al,[si] inc si
cmp al,[si]
jbe next
xchg al,[si] ;Exchange the content of two locations
mov [si-1],al
next: dec cl
jnz repeat
dec ch
jnz again
int 3
end
