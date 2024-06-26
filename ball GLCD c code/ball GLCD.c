#include <mega32.h>
#include <delay.h>
// Graphic Display functions
#include <glcd.h>

// Font used for displaying text
// on the graphic display
#include <font5x7.h>


// Declare your global variables here

void main(void)
{
// Declare your local variables here
char x=59;
char y=27;
char flag=0;
// Variable used to store graphic display
// controller initialization data
GLCDINIT_t glcd_init_data;

// Input/Output Ports initialization
// Port A initialization
// Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRA=(1<<DDA7) | (1<<DDA6) | (1<<DDA5) | (1<<DDA4) | (1<<DDA3) | (1<<DDA2) | (1<<DDA1) | (1<<DDA0);
// State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTA=(0<<PORTA7) | (0<<PORTA6) | (0<<PORTA5) | (0<<PORTA4) | (0<<PORTA3) | (0<<PORTA2) | (0<<PORTA1) | (0<<PORTA0);

// Port B initialization
// Function: Bit7=In Bit6=In Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out 
DDRB=(0<<DDB7) | (0<<DDB6) | (1<<DDB5) | (1<<DDB4) | (1<<DDB3) | (1<<DDB2) | (1<<DDB1) | (1<<DDB0);
// State: Bit7=T Bit6=T Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0 
PORTB=(0<<PORTB7) | (0<<PORTB6) | (0<<PORTB5) | (0<<PORTB4) | (0<<PORTB3) | (0<<PORTB2) | (0<<PORTB1) | (0<<PORTB0);

// Port C initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRC=(0<<DDC7) | (0<<DDC6) | (0<<DDC5) | (0<<DDC4) | (0<<DDC3) | (0<<DDC2) | (0<<DDC1) | (0<<DDC0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTC=(0<<PORTC7) | (0<<PORTC6) | (0<<PORTC5) | (0<<PORTC4) | (0<<PORTC3) | (0<<PORTC2) | (0<<PORTC1) | (0<<PORTC0);

// Port D initialization
// Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In 
DDRD=(0<<DDD7) | (0<<DDD6) | (0<<DDD5) | (0<<DDD4) | (0<<DDD3) | (0<<DDD2) | (0<<DDD1) | (0<<DDD0);
// State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=T Bit1=T Bit0=T 
PORTD=(0<<PORTD7) | (0<<PORTD6) | (0<<PORTD5) | (0<<PORTD4) | (0<<PORTD3) | (0<<PORTD2) | (0<<PORTD1) | (0<<PORTD0);



// Graphic Display Controller initialization
// The KS0108 connections are specified in the
// Project|Configure|C Compiler|Libraries|Graphic Display menu:
// DB0 - PORTA Bit 0
// DB1 - PORTA Bit 1
// DB2 - PORTA Bit 2
// DB3 - PORTA Bit 3
// DB4 - PORTA Bit 4
// DB5 - PORTA Bit 5
// DB6 - PORTA Bit 6
// DB7 - PORTA Bit 7
// E - PORTB Bit 0
// RD /WR - PORTB Bit 1
// RS - PORTB Bit 2
// /RST - PORTB Bit 3
// CS1 - PORTB Bit 4
// CS2 - PORTB Bit 5

// Specify the current font for displaying text
glcd_init_data.font=font5x7;
// Specify the function used for reading
// image data from external memory
glcd_init_data.readxmem=NULL;
// Specify the function used for writing
// image data to external memory
glcd_init_data.writexmem=NULL;


glcd_init(&glcd_init_data);

while (1)
      { 
        glcd_clear();
        glcd_fillcircle(x,y,5); 
        delay_ms(100);
        glcd_moveto(x++,y--);
        delay_ms(100); 
        if(y<3) flag=1;
        while(flag)
        { 
          glcd_clear();
          glcd_fillcircle(x,y,5); 
          delay_ms(100); 
          x+=2;
          glcd_moveto(x,y++);
          delay_ms(100);
          if(x>124) flag=2;
           while(flag==2)
          {
            glcd_clear();
            glcd_fillcircle(x,y,5); 
            delay_ms(100);
            glcd_moveto(x--,y++);
            delay_ms(100);
            if(y>60) flag=3;
            while(flag==3)
            {
              glcd_clear();
              glcd_fillcircle(x,y,5); 
              delay_ms(100);
              x-=2;
              glcd_moveto(x,y--);
              delay_ms(100);
              if(x<2) flag=4;
              if(y<3) flag=1;
              while(flag==4)
              {
                glcd_clear();
                glcd_fillcircle(x,y,5); 
                delay_ms(100);
                x+=4;
                glcd_moveto(x,y--);
                delay_ms(100);
                if(y<3) flag=1;
              }
            }
        }
       } 
        
        
        
         
         
         
         
        
        
        
         
        
        
        
        
        
         
        
        

      }
}
