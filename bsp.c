/*
* bsp.c
*
* Author:
* Ömer Faruk Koc
*
* 
*
*/

#include "bsp.h"
#include "math.h"
static volatile int num1=20;
static volatile int num2=20;
static volatile int num3=20;
static volatile int num4=20;
//static volatile int fonk;
//static volatile int sum;
static volatile int digit;
static volatile int digit1;
static volatile int digit2;
static volatile int digit3;
static volatile int digit4;
void clearSSD(void);
void setSSD(int);
void set_Rows_keypad(void);
void clear_Rows_keypad(void);

void delay(volatile uint32_t s) {
 for(; s>0; s--);
}

void EXTI0_1_IRQHandler(void){ //interrupt from pb0

clear_Rows_keypad();
GPIOA->ODR ^= (1U << 8);

if ((GPIOB -> IDR >>0)& 1){

//D1_Digit();
//setSSD(15);
get_number(15);
}

GPIOA->ODR ^= (1U << 8);
GPIOB->ODR ^= (1U << 9);

if ((GPIOB -> IDR >>0)& 1){

//D1_Digit();
//setSSD(9);
get_number(9);
}

GPIOB->ODR ^= (1U << 9);
GPIOB->ODR ^= (1U << 5);

if ((GPIOB -> IDR >>0)& 1){
//D1_Digit();
//setSSD(6);
get_number(6);
}

GPIOB->ODR ^= (1U << 5);
GPIOB->ODR ^= (1U << 4);

if ((GPIOB -> IDR >>0)& 1){
//D1_Digit();
//setSSD(3);
get_number(3);
}

GPIOB->ODR ^= (1U << 4);
EXTI->RPR1 |= (1U << 0);
set_Rows_keypad();
}

void EXTI2_3_IRQHandler(void){ //interrupt from PB2
clear_Rows_keypad();
GPIOA->ODR ^= (1U << 8);

if((GPIOB->IDR >>2) &1){
//D1_Digit();
//setSSD(0);
get_number(0);
}
GPIOA->ODR ^= (1U << 8);
GPIOB->ODR ^= (1U << 9);

if((GPIOB->IDR >>2) &1){
//D1_Digit();
//setSSD(8);
get_number(8);
}
GPIOB->ODR ^= (1U << 9);
GPIOB->ODR ^= (1U << 5);

if((GPIOB->IDR >>2) &1){
//D1_Digit();
//setSSD(5);
get_number(5);
}
GPIOB->ODR ^= (1U << 5);
GPIOB->ODR ^= (1U << 4);
if((GPIOB->IDR >>2) &1){
//D1_Digit();
//setSSD(2);
get_number(2);
}
GPIOB->ODR ^= (1U << 4);
EXTI->RPR1 |= (1U << 2);
set_Rows_keypad();
}
void EXTI4_15_IRQHandler(void){ // interrupt PB8 and PA9
if((GPIOB->IDR >>8) &1){
clear_Rows_keypad();
GPIOA->ODR ^= (1U << 8);

if((GPIOB->IDR >>8) &1){
//D1_Digit();
//setSSD(14);
get_number(14);
}
GPIOA->ODR ^= (1U << 8);
GPIOB->ODR ^= (1U << 9);

if((GPIOB->IDR >>8) &1){
//D1_Digit();
//setSSD(7);
get_number(7);
}
GPIOB->ODR ^= (1U << 9);
GPIOB->ODR ^= (1U << 5);

if((GPIOB->IDR >>8) &1){
//D1_Digit();
//setSSD(4);
get_number(4);
}
GPIOB->ODR ^= (1U << 5);
GPIOB->ODR ^= (1U << 4);
if((GPIOB->IDR >>8) &1){

//D1_Digit();
//setSSD(1);
get_number(1);
}
GPIOB->ODR ^= (1U << 4);
EXTI->RPR1 |= (1U << 8);
set_Rows_keypad();
}
if((GPIOA->IDR >>9) &1){
clear_Rows_keypad();
GPIOA->ODR ^= (1U << 8);
if((GPIOA->IDR >>9) &1){

//D1_Digit();
//setSSD(13);
get_number(13);
}
GPIOA->ODR ^= (1U << 8);
GPIOB->ODR ^= (1U << 9);
if((GPIOA->IDR >>9) &1){

//D1_Digit();
//setSSD(12);
get_number(12);
}
GPIOB->ODR ^= (1U << 9);
GPIOB->ODR ^= (1U << 5);
if((GPIOA->IDR >>9) &1){

//D1_Digit();
//setSSD(11);
get_number(11);
}
GPIOB->ODR ^= (1U << 5);
GPIOB->ODR ^= (1U << 4);
if((GPIOA->IDR >>9) &1){

//D1_Digit();
//setSSD(10);
get_number(10);
}
GPIOB->ODR ^= (1U << 4);
EXTI->RPR1 |= (1U << 9);
set_Rows_keypad();
}
}
void Odr_For_Digits(void){
RCC->IOPENR |= (1U << 1);
GPIOB ->ODR |= (1U << 6); // D1 PB6
GPIOB ->ODR |= (1U << 7); // D2 PB7
GPIOB ->ODR |= (1U << 1); // D3 PB1
GPIOB ->ODR |= (1U << 3); // D4 PB3
}

void D1_Digit(void){
 GPIOB ->ODR |= (1U << 6);
 GPIOB ->ODR &= ~(1U << 7);
 GPIOB ->ODR &= ~(1U << 3);
 GPIOB ->ODR &= ~(1U << 1);
}

void D2_Digit(void){
 GPIOB ->ODR &= ~(1U << 6);
 GPIOB ->ODR |= (1U << 7);
 GPIOB ->ODR &= ~(1U << 3);
 GPIOB ->ODR &= ~(1U << 1);
}
void D3_Digit(void){
 GPIOB ->ODR &= ~(1U << 7);
 GPIOB ->ODR &= ~(1U << 6);
 GPIOB ->ODR |= (1U << 1);
 GPIOB ->ODR &= ~(1U << 3);
}
void D4_Digit(void){
 GPIOB ->ODR &= ~(1U << 7);
 GPIOB ->ODR &= ~(1U << 10);
 GPIOB ->ODR &= ~(1U << 1);
 GPIOB ->ODR |= (1U << 3);
}
void moders_for_digits(){
RCC->IOPENR |= (1U << 1);
GPIOB->MODER &= ~(3U << 2*1);
GPIOB->MODER |= (1U << 2*1);
GPIOB->MODER &= ~(3U << 2*3);
GPIOB->MODER |= (1U << 2*3);
GPIOB->MODER &= ~(3U << 2*6);
GPIOB->MODER |= (1U << 2*6);
GPIOB->MODER &= ~(3U << 2*7);
GPIOB->MODER |= (1U << 2*7);
}

/*void School_Id(){
moders_for_digits();
for(int i=0; i<4000; i++){
D1_Digit();
setSSD(1);
delay(500);
D2_Digit();
setSSD(7);
delay(500);
D3_Digit();
setSSD(6);
delay(500);
D4_Digit();
setSSD(6);
delay(500);
}
clearSSD();
}*/

void Keypad_Enable(void){
 // Enable GPIOA clock
 RCC->IOPENR |= (1U << 0);
// Enable GPIOB clock
 RCC->IOPENR |= (1U << 1);
 // Setup PA9, PB0, PB2, PB8 as input C
GPIOA->MODER &= ~(3U << 2*9);
GPIOA->PUPDR |= (2U << 2*9);
GPIOB->MODER &= ~(3U << 0);
GPIOB->PUPDR |= (2U << 0);
GPIOB->MODER &= ~(3U << 2*2);
GPIOB->PUPDR |= (2U << 2*2);
GPIOB->MODER &= ~(3U << 2*8);
GPIOB->PUPDR |= (2U << 2*8);
// Setup PA8, PB9, PB5, PB4 as output R
 GPIOA->MODER &= ~(3U << 2*8);
 GPIOA->MODER |= (1U << 2*8);
 GPIOB->MODER &= ~(3U << 2*9);
 GPIOB->MODER |= (1U << 2*9);
 GPIOB->MODER &= ~(3U << 2*5);
 GPIOB->MODER |= (1U << 2*5);
 GPIOB->MODER &= ~(3U << 2*4);
 GPIOB->MODER |= (1U << 2*4);
// Setup interrupts
 EXTI->EXTICR[2] |= (0U << 8*1); //pa9
 EXTI->EXTICR[0] |= (1U << 0); //pb0
 EXTI->EXTICR[0] |= (1U << 8*2); //pb2
 EXTI->EXTICR[2] |= (1U << 0); //pb8
// Rising edge
 EXTI->RTSR1 |= (1U << 9);
 EXTI->RTSR1 |= (1U << 0);
 EXTI->RTSR1 |= (1U << 2);
 EXTI->RTSR1 |= (1U << 8);
 // Mask register
  EXTI->IMR1 |= (1U << 9);
  EXTI->IMR1 |= (1U << 0);
  EXTI->IMR1 |= (1U << 2);
  EXTI->IMR1 |= (1U << 8);
 // Enable NVIC
  NVIC_SetPriority(EXTI0_1_IRQn, 0);
  NVIC_EnableIRQ(EXTI0_1_IRQn);
  NVIC_SetPriority(EXTI2_3_IRQn, 0);
  NVIC_EnableIRQ(EXTI2_3_IRQn);
  NVIC_SetPriority(EXTI4_15_IRQn, 0);
  NVIC_EnableIRQ(EXTI4_15_IRQn);
 // Pins for SSD
 GPIOA->MODER &= ~(3U << 2*0);
 GPIOA->MODER |= (1U << 2*0);
 GPIOA->MODER &= ~(3U << 2*1);
 GPIOA->MODER |= (1U << 2*1);
 GPIOA->MODER &= ~(3U << 2*4);
 GPIOA->MODER |= (1U << 2*4);
 GPIOA->MODER &= ~(3U << 2*5);
 GPIOA->MODER |= (1U << 2*5);
 GPIOA->MODER &= ~(3U << 2*6);
 GPIOA->MODER |= (1U << 2*6);
 GPIOA->MODER &= ~(3U << 2*11);
 GPIOA->MODER |= (1U << 2*11);
 GPIOA->MODER &= ~(3U << 2*12);
 GPIOA->MODER |= (1U << 2*12);
 GPIOA->MODER &= ~(3U << 2*7);
 GPIOA->MODER |= (1U << 2*7);
 GPIOB->MODER &= ~(3U << 2*1);
 GPIOB->PUPDR |= (2U << 2*1);
 GPIOB->MODER &= ~(3U << 2*7);
 GPIOB->PUPDR |= (2U << 2*7);
 GPIOB->MODER &= ~(3U << 2*6);
 GPIOB->PUPDR |= (2U << 2*6);
 GPIOB->MODER &= ~(3U << 2*3);
 GPIOB->PUPDR |= (2U << 2*3);
 GPIOA -> ODR |= (1U << 8);
 GPIOB -> ODR |= (1U << 9);
 GPIOB -> ODR |= (1U << 5);
 GPIOB -> ODR |= (1U << 4);
 clearSSD(); }

void clearSSD(void){
GPIOA -> ODR |= (1U << 0);
GPIOA -> ODR |= (1U << 1);
GPIOA -> ODR |= (1U << 4);
GPIOA -> ODR |= (1U << 5);
GPIOA -> ODR |= (1U << 12);
GPIOA -> ODR |= (1U << 11);
GPIOA -> ODR |= (1U << 6);
}

void setSSD(int x){
clearSSD();
switch(x){
case 0:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 12);
GPIOA -> ODR &= ~(1U << 11);
break;
case 1:
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
break;
case 2:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 12);
GPIOA -> ODR &= ~(1U << 6);
break;
case 3:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 6);
break;
case 4:
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 11);
GPIOA -> ODR &= ~(1U << 6);
break;
case 5:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 11);
GPIOA -> ODR &= ~(1U << 6);
break;
case 6:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 12);
GPIOA -> ODR &= ~(1U << 11);
GPIOA -> ODR &= ~(1U << 6);
break;
case 7:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
break;
case 8:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 12);
GPIOA -> ODR &= ~(1U << 11);
GPIOA -> ODR &= ~(1U << 6);
break;
case 9:
GPIOA -> ODR &= ~(1U << 0);
GPIOA -> ODR &= ~(1U << 1);
GPIOA -> ODR &= ~(1U << 4);
GPIOA -> ODR &= ~(1U << 5);
GPIOA -> ODR &= ~(1U << 11);
GPIOA -> ODR &= ~(1U << 6);
break;

case 20: // -
GPIOA -> ODR &= ~(1U << 6);
break;

}

}

void clear_Rows_keypad(void){
GPIOA -> ODR &= ~(1U << 8);
GPIOB -> ODR &= ~(1U << 9);
GPIOB -> ODR &= ~(1U << 5);
GPIOB -> ODR &= ~(1U << 4);
}

void set_Rows_keypad(void){
GPIOA -> ODR |= (1U << 8);
GPIOB -> ODR |= (1U << 9);
GPIOB -> ODR |= (1U << 5);
GPIOB -> ODR |= (1U << 4);
}


void display1(int num1,int num2,int num3,int num4){
	moders_for_digits();
	for(int i = 0; i < 100; i++){
	D1_Digit();
	setSSD(num1);
	delay(500);

	D2_Digit();
	setSSD(num2);
	delay(500);

    D3_Digit();
    setSSD(num3);
	delay(500);

	D4_Digit();
	setSSD(num4);
	delay(500);     }
	IWDG->KR = 0xAAAAU; // feed
}

void display2(void){
	moders_for_digits();
		for(int i = 0; i < 100; i++){
		D1_Digit();
		setSSD(num1);
		delay(500);

		D2_Digit();
		setSSD(num2);
		delay(500);

	    D3_Digit();
	    setSSD(num3);
		delay(500);

		D4_Digit();
		setSSD(num4);
		delay(500);     }
	}



int get_number(int a){
		delay(1500);

		 if((num1 == 20) && (num2 == 20) && (num3 == 20) && (num4 == 20)){
		    num1 = a;
		    display1(num1,num2,num3,num4);
		    delay(1500);


		    }
		    else if((num2 == 20) && (num3 == 20) && (num4 == 20)){
		    num2=num1;
		    num1 = a;
		    display1(num1,num2,num3,num4);
		    delay(1500);

		    }
		    else if( (num3 == 20) && (num4 == 20)){
		    num3=num2;
		    num2=num1;
		    num1 = a;
		    display1(num1,num2,num3,num4);
		    delay(1500);

		    }
		    else if(num4 == 20){
		    num4 = num3;
		    num3 = num2;
		    num2 = num1;
		    num1 = a;
		    display1(num1,num2,num3,num4);
		    delay(1500);

		    }
		    else {
		    num4 = num3;
		    num3 = num2;
		    num2 = num1;
		    num1 = a;
		    display1(num1,num2,num3,num4);
		    delay(1500);
}
	}




