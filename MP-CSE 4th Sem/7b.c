#include <stdio.h>
#include "NUC1xx.h"
#include "Driver\DrvSYS.h"
#include "Driver\DrvGPIO.h"
#include "NUC1xx-LB_002\LCD_Driver.h"

int main(void)
{
	UNLOCKREG();
	DrvSYS_Open(48000000);
	LOCKREG(); 

	Initial_panel(); 
	clr_all_panel();
	
	print_lcd(0, "Welcome to MSRIT   ");   	  	 	  		
}
