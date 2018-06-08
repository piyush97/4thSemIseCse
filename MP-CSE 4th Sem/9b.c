#include <stdio.h> 
#include "NUC1xx.h" 
#include "DrvSYS.h" 
#include "DrvGPIO.h" 
#include "scankey.h" 
#include "NUC1xx-LB_002\LCD_Driver.h" 
 
int main (void) 
{ int8_t number; 
char TEXT0[16]="Smpl_LCD_Keypad"; 
char TEXT1[16]="Keypad:        "; 
UNLOCKREG();  
DrvSYS_Open(48000000); 
LOCKREG(); 
Initial_panel(); 
clr_all_panel(); 
OpenKeyPad(); 
print_lcd(0,TEXT0); 
DrvGPIO_Open(E_GPB, 11, E_IO_OUTPUT); 
DrvGPIO_Open(E_GPC, 12, E_IO_OUTPUT);  
DrvGPIO_SetBit(E_GPC, 12); 
 while(1) 
 {   number = Scankey(); 
 sprintf(TEXT1+8,"%d",number); 
 print_lcd(1, TEXT1); 
 DrvSYS_Delay(5000); 
 if(number==3)
 { DrvGPIO_ClrBit(E_GPB,11); 
 DrvSYS_Delay(1000); 
 DrvGPIO_SetBit(E_GPB,11); 
 DrvSYS_Delay(1000); 
 } 
 else if(number==2)
 { DrvGPIO_ClrBit(E_GPC, 12);        
 DrvSYS_Delay(3000000);        
 DrvGPIO_SetBit(E_GPC, 12);        
 DrvSYS_Delay(3000000); 
 } 
 }
 } 
