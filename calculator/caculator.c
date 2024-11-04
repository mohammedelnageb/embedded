/*
 * caculator.c
 *
 *  Created on: Feb 14, 2024
 *      Author: Moham
 */
#include "lcd.h"
#include "keypad.h"
#include <stdio.h>
#include <util/delay.h> /* For the delay functions */
#define SIZE 10
unsigned char x;
unsigned char y[SIZE]={0};
unsigned char z=0;
unsigned char operation[SIZE] ={0};
unsigned char sum;
#define DELAY 500
int main(void)
{
	 LCD_init();

	while(1)
	{



	 x= KEYPAD_getPressedKey();

	 if(x>=0&&x<=9)
	 {
		 LCD_intgerToString(x);
         y[z]=10*y[z]+x;

	 }
	 else if(x=='=')
	 {
			LCD_displayCharacter(x);
			 sum =y[0];

 			for(int i=1;i<=z;i++)
 			{
		 switch (operation[i-1])
		 		 {
		 		 case '+':
		 			sum=y[i]+sum;

		 			 break;
		 		 case '*':
		 			 sum=y[i]*sum;
		 			 break;

		 		 case '/':
		 	 		 sum=sum/y[i];

		 			 break;

		 		 case '-':
		 	 		 sum=sum-y[i];


		 			 break;

		 		 }

 			}
 			LCD_intgerToString(sum);

	 }
	 else if(x==13)
	 {
		 LCD_clearScreen();
			for(int i=0;i<z;i++)
			{
				operation[i]=0;
				y[i]=0;
			}
	 }
	 else
	 {
		operation[z]= x;
				LCD_displayCharacter(x);

             z++;
		  	_delay_ms(DELAY); /* Press time */

		 	}

	  	_delay_ms(DELAY); /* Press time */

	 }



	}






/*while(1)
		 	{

		 	 x= KEYPAD_getPressedKey();

		 	 if(x>0&&x<9)
		 	 {
		 		 LCD_intgerToString(x);
		          z=10*z+x;
		 	 }
		 	 else if(x=='=')
		 	 {
		 		 LCD_displayCharacter(x);
				  	_delay_ms(DELAY);

             break;

		 	 }
		 	 */
