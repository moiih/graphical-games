#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
void main()
{
   float x1,x2,y1,y2,dx,dy;
   float x,y,xinc,yinc,length,i;
   int gd= DETECT, gm;

   initgraph(&gd,&gm,"");

    x1=0;  y1=0;
    x2=25;  y2=25;

     dx=x2-x1;
     dy=y2-y1;

    if( abs(dx) >= abs(dy) )
       length=dx;
    else
       length=dy;

    xinc=dx/length;
    yinc=dy/length;

     x=x1+0.5;
     y=y1+0.5;

     i=0;
    while( i<=length )
    {
       putpixel(x,y,62);
	x=x+xinc;
	y=y+yinc;
       i++;
    }

   getch();
}