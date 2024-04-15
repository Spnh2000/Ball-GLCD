# Ball-GLCD
Working with Graphical LCD, Simulation in Proteus and c code in code vision.

Using library functions such as:
void glcd_setpixel(x,y)
void glcd_putchar(x,y)
void glcd_line(x0,y0,x1,y1)
void glcd_circle(x,y,radius)
void glcd_moveto(x,y)
void glcd_outtext(char *str)

Regarding the program: A small ball (a circle) starts moving from the center of the LCD at a 45-degree angle, and whenever it collides with a wall, it reflects off the LCD at the appropriate angle. 

(Please ensure that you adjust the reset circuit.)

(If you are unable to open the Proteus file, please use the provided picture to draw the simulation in Proteus. Then, add the hex file located in 'ball GLCD c code\Debug\Exe')
