          // Moving Ball
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include"msgraph2.h"

void straight_line_2(int,int,int,char,int);
void moving_ball(float,float,float,float,int);
void escape();

void main()
{
   int gd= DETECT, gm;
   clrscr();
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    line(180,30,180,300);
    line(490,30,490,300);
     moving_ball(200,70,470,70, 15);
      myline_dda(470,70,470,150, 4);
     straight_line_2(200,470,150,'r', 15);
      myline_dda(200,150,200,230, 4);
     straight_line_2(200,470,230,'l', 15);

   getch();
}

void straight_line_2(int x1,int x2,int y,char dir,int radius)
{
   int i,dx;

    dx=x2-x1;

     i=0;
    if( dir=='l' )
    {
       while( i<=dx )
       {
	   setcolor(4);
	    line(180,30,180,430);
	    line(490,30,490,430);
	      escape();
	    pieslice(x1, y, 0, 360, radius);
	     setcolor(2);
	    circle(x1, y, radius+2);
	    circle(x1, y, radius+1);
	    circle(x1, y, radius);
	      //setcolor(4);
	      //outtextxy(x1,y,"MS");
	     delay(20);
	     clrscr();

	   x1++;
	  i++;
       }
    }
    else if( dir=='r' )
    {
       while( i<=dx )
       {
	     setcolor(4);
	    line(180,30,180,430);
	    line(490,30,490,430);
	      escape();
	    pieslice(x2, y, 0, 360, radius);
	     setcolor(2);
	    circle(x2, y, radius+2);
	    circle(x2, y, radius+1);
	    circle(x2, y, radius);
	      //setcolor(4);
	      //outtextxy(x2,y,"MS");
	     delay(20);
	     clrscr();
	    x2--;
	  i++;
       }
    }
}

void moving_ball(float x1,float y1,float x2,float y2,int radius)
{
   float dx,dy;
   float x,y,xinc,yinc,length,i;

      setcolor(4);
	line(180,30,180,430);
	line(490,30,490,430);
      delay(20);

     dx=x2-x1;
     dy=y2-y1;

      if( abs(dx)>=abs(dy) )
	 length=dx;
      else
	 length=dy;

     xinc=dx/length;
     yinc=dy/length;

      x=x1+0.5;
      y=y1+0.5;
			   +
      i=0;
     while( i<=length )
     {
	  setcolor(4);
	    line(180,30,180,430);
	    line(490,30,490,430);
	      escape();
	 pieslice(x, y, 0, 360, radius);
	     setcolor(2);
	    circle(x, y, radius+2);
	    circle(x, y, radius+1);
	    circle(x, y, radius);
	      //setcolor(4);
	      //outtextxy(x,y,"MS");
	     delay(20);
	     clrscr();

	 x=x+xinc;
	 y=y+yinc;
	i++;
     }
     setcolor(4);
	line(180,30,180,430);
	line(490,30,490,430);
}

void escape()
{
   if( kbhit() )
      exit(0);
}
