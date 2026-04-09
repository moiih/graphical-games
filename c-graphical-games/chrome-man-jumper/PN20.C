#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
    setcolor(2);
     rectangle(90,60,540,340);
   getch();
}
