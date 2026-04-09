#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>

void mybar(int x1,int y1,int x2,int y2,int dp)
{
   int i,dx,dy,temp;
     dy=abs(y2-y1);
     dx=abs(x2-x1);
     temp=y2;
    for(i=0; i<=dy; i++)
    {
       line(x1,temp,x2,temp);
	temp=temp-1;
       //delay(5);
    }

     /*line(x2,y2,x2+40,y2-30);
     line(x2+40,y2-30,x2+40,y1-30);
     line(x2+40,y1-30,x2+30,y1-30);
     line(x2+30,y1-30,x1,y1);
     line(x2+40,y1-30,x2,y1);*/

     line(x2,y2,x2+dp,y2-dp+2);
     line(x2+dp,y2-dp+2,x2+dp,y1-dp+2);
     line(x2+dp,y1-dp+2,x2+dp-dx,y1-dp+2);
     line(x2+dp-dx,y1-dp+2,x1,y1);
     line(x2+dp,y1-dp+2,x2,y1);

}

void main()
{
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    mybar(150,90,160,300,5);
    bar3d(167,90,177,300,5,5);
   getch();
}

