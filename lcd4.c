// File Name: lcd interface on 8051
// Author: R.venkatesan
// lcd 16X2 4bit method 
 // lcd pin connection port1 -data pin (D4-D7)
 // control pin lcd conection  RS=P1^0, R/W=P1^1, E=P1^2
 

# include <reg51.h>
# include <stdio.h>
# include "lcd4bit.h"  // lcd library 
/* if want change the lcd pin connection open lcd file library change the pin as per your aspect 
 And also remain you change busy flag= bf(used name in lcdlibrary ) also for inlcd pin data  lcd file libary  */
 void main()
 {
  port(); // pulldown the all pin in micro controller
	lcd_initial(); // lcd basic initialization cammand line 
	 while(1)
	 {
	   lcd_com(0x01);  // lcd cammand dispaly frist line
		 lcd_string(" lcd 4bit method "); // write your own word in double quotes
		 
		 lcd_com (0xc0);  // lcd cammand dispaly second line
		 lcd_string("design by RV ");  // write your own word in double quotes
		 
		  delay(100); // delay for seen the lcd lines display
	 }
		 
 }
	 