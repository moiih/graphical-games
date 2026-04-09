#include<stdio.h>
#include<conio.h>
#include<graphics.h>

void star1(int x,int y)
{
   line(x,y-3,x,y+3);
    line(x-3,y-2,x+3,y+2);
    line(x+3,y-2,x-3,y+2);
}

void star2(int x,int y)
{
   line(x-3,y,x+3,y);
    line(x-2,y-3,x+2,y+3);
    line(x+2,y-3,x-2,y+3);
}

void main()
{
   int i,j=0,m,temp1,temp2;
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

    m=0;
   for(i=0; i<1500; i+=30)
   {
      if( i%2==0 )
      {
	 temp1=270+i;
	star1(temp1,250+j);
      }
      else
      {
	 temp2=270+i;
	star2(temp2,250+j);
      }

       if( m==10 )
       {
	  j=j+10;
	   m=0;
	   temp1=270;
	  break;
       }
	  m++;
   }

   getch();
}
