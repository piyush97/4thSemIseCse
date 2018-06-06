;add r6, r5, #4   ;Add 4 to r5 and store it in r6
;ldr r5,=zero 	  ;load the address of memory location with the name zero onto the register r5 (Similar to LEA SI,zero)
;ldr r8, [r5]      ;Load the word whose address is pointed by r5 onto r8 (Similar to MOV a,[b])
;movgt r8, r9      ;MOV contents from r9 to r8  IF AND ONLY IF THE FIRST TERM IN PREVIOUS COMPARISION WAS GREATER THAN SECOND TERM
;str r8, [r5], #4  ;store the contents of r8 onto the memory location pointed by r5 and then post increment r5 by 4
;blt loop2         ;Branch if less than: Jump to loop2 if in the previous comparision the left term was letter than the right term                 





;Normal structure of bubble sort
;for (i=0;i<n;i++)
;    for(j=0;j<n;j++)
;		compare and if necessory swap

;Similary here,r0 is similar to n
;r10 is similar to i
;r11 is similar to j



mov r0, #9 		;There are 9 elements ,so we need to execute 9 times. So register will be used in comparion
mov r10, #0		;counter for outer loop (loop 1)	
mov r11, #0		
loop1:
      ldr r5, =arr  ;load the starting address of arr to r5 (r5 will point to the first element)
	  add r6, r5, #4 ;we add 4 to r5 and we get second element (This is because we are storing numbers in memory as words(32 bit in arm ie 4 byte))Therefore there will be a differnce of 4 between addresses

      mov r11, #0	;counter for inner loop (loop 2) It will be set to 0 before the beginning of inner loop
loop2:
      ldr r8, [r5]	;move the contents in memory pointed by r5 to r8
      ldr r9, [r6]	;move the contents in memory pointed by r6 to r9
	  
	  ;Next 6 lines we compare and if necessory swap.
      cmp r8, r9	;compare r8 and r9
	  
	  ;we swap r8 and r9 using r3 as temprorary register
      movgt r3, r8	;if r8 is greater than r9 we move r8 to r3
      movgt r8, r9	;if r8 is greater than r9 we move r9 to r8
      movgt r9, r3	;if r8 is greater than r9 we move r9 to r3
	  
	  ;now the address are swapped , we need to make the same change in memory
      str r8, [r5], #4		;We move r8 contents to memory pointed by r5(it was previously pointed by r6) (#4 signifies POST increment r5 by 4(This is done to move to next element for next iteration))
      str r9, [r6], #4		;We move r9 contents to memory pointed by r6(it was previously pointed by r5) (#4 signifies POST increment r6 by 4(This is done to move to next element for next iteration))
	  ;Thus swaping of contents in memory is achieved
	  
	  add r11, r11, #1 ;we increment r11(inner loop counter) by 1
      cmp r11, r0      ;we compare r11 and ro(contains 9).If r11 is less than r0,we contineu with the loop else we will exit the inner loop and move continue with outer loop (Similar to j<n)
      blt loop2			;if r11 is less than r0 continue with next iteration of inner loop
add r10, r10, #1		;we increment r10(outer loop counter) by 1
cmp r10, r0				;we compare r10 and r0,if r10 is less than r0(contains 9) we contineu else end the program (Similar to i<n)
blt loop1
.data

arr: .word 5,6,9,2,1,8,3,7,0              
