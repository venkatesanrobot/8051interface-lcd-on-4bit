# include <reg51.h>
# define LCD
# define lcd P1
 sbit rs=P1^0;
 sbit rw=P1^1;
 sbit en=P1^2;
 
void delay(unsigned int itime)
{
unsigned int i,j;
for(i=0;i<itime;i++)
for(j=0;j<1275;j++);
}
  void lcd_com(char ll)
 {

    lcd= (ll&0xf0); 
	  rw=0; rs=0;
	  en=1;en=0;
	 
	  lcd= ((ll<<4)&0xf0);
	 rw=0; rs=0;
	  en=1;en=0;
	delay(3);
	
 }
void port()
{
  P0=0x00;
	P1=0x00;
	P2=0x00;
	P3=0x00;
}
 void lcd_initial()
 { 
	 delay(10);
	 lcd_com(0x02);
	 lcd_com(0x28);
	 lcd_com(0x0E);
	 lcd_com(0x06);
	 lcd_com(0x01);
	 delay(10);
 }

 void lcd_data(char lll)
 {
	 lcd=(lll&0xf0);
	 rw=0;rs=1;
	 en=1;en=0;
	
  	  lcd=(lll<<4&0xf0); 
	 rw=0;rs=1;
	 en=1;en=0;
	delay(3);
 }
 
 void lcd_string(char *c)
 {
 while(*c!='\0')   /*or while(*c)*/

	lcd_data(*c++);
	
 }