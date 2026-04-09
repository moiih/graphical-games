#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void player(int x,int y)
{
   int size=20;
     setcolor(BLUE);
    if( x%2==0 )
    {
    rectangle(x-5,y-15-5-size,x+5,y-10-10);
      circle(x,y-size-15-5-5,4);
	   // Hands
     line(x-6,y-15-size-2,x-6-6,y-13-13);
     line(x+6,y-15-size-2,x+6+6,y-13-13);
	   // Legs
     line(x-2,y-10-9,x-6,y-1);
     line(x+2,y-10-9,x+6,y-1);
      delay(200);
    }
    else
    {
    rectangle(x-5,y-15-5-size,x+5,y-10-10);
      circle(x,y-size-15-5-5,4);
	   // Hands
     line(x-6,y-15-size-2,x-6-6,y-13-13);
     line(x+6,y-15-size-2,x+6+6,y-13-13);
	   // Legs
     line(x+3,y-10-9,x-6,y-1);
     line(x-3,y-10-9,x+6,y-1);
      delay(200);
    }
}

void skip_obst(int x,int y,int jump)
{
   int i,m;
     i=0;
    while( i<=jump )
    {
       player(x+i,y-i);
	delay(10);
       clrscr();
	 i++;
    }
     m=i-1;
     i=0;
    while( i<=jump )
    {
       player(x+m+i,y-m+i);
	delay(10);
       clrscr();
	 i++;
    }
}

void main()
{
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     skip_obst(200,270,50);
   getch();
}