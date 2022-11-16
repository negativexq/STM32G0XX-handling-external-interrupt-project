/*
* main.c
*
* Author:
* Ömer Faruk Koc 
*
*/
#include "stm32g0xx.h"
//#include "stdlib.h"
//#include "stdio.h"
//#include "math.h"
//#include "string.h"
#include "bsp.h"

int main(void) {

IWDG->KR = 0xCCCCU; // WDG Timer
IWDG->KR = 0x5555U;
IWDG->PR = 6;
IWDG->RLR = 4800;

Keypad_Enable();



 while(1) {
	 display2();
 }
 return 0;
}
