#include<stdio.h>
#include<conio.h>
#include<graphics.h>

static int obcount;

void basic_line(int,int,int);
void obstacle(int);
void move_obstacle();
void check_out(int,int);
void skip_obst(int,int,int);

int absolute(int val)
{
   if( val<0 )
      return(-val);
}

void player(int x,int y,int speed)
{
      //   Length=22   Breadth=38
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
      delay(speed);
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
      delay(speed);
    }
}

void move_player(int c1,int c2)
{
   int i,temp;
   char ch;
      for(i=c1,obcount=c2; i<=545,obcount>=85; i++,obcount--)
      {
	    setcolor(2);
	     rectangle(90,60,540,350);
	    if( kbhit() )
	    {
	       ch=getch();
	       temp=ch;
		if( temp==32 )
		   skip_obst(i,270,40);
	    }
	     check_out(i,obcount);
	      basic_line(90,540,270);
	     obstacle(obcount);
	    player(i,270,200);
	     //delay(20);
	    clrscr();
      }
}

void main()
{
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     move_player(85,610);
   getch();
}

void basic_line(int x1,int x2,int y)
{
   int i,dx,m;
     setcolor(2);
      rectangle(90,60,540,350);
    x2=x2-1;
    dx=x2-x1;
     i=0;  m=0;
       while( i<=(dx-1) )
       {
	 if( m>=0 && m<9 )
	 {
	  putpixel(x2,y,WHITE);
	   m++;
	 }
	 else if( m>=10 || m<19 )
	 {
	  putpixel(x2,y,BLUE);
	  if( m==19 )
	   m=0;
	  m++;
	 }
	  x2--;
	   i++;
	  //delay(10);
       }
}

void obstacle(int x)
{
   int y=260;
     setcolor(2);
      rectangle(90,60,540,350);
      // GRASS BEFORE OBSTACLE
    if( (x-60+4)<540 )
    {
	line(x-60,270-1,x-60+5,270-10);
	line(x-60,270-1,x-60-1,270-7);
	line(x-60,270-1,x-60-12,270-12);
    }
      //    OBSTACLE
      setcolor(4);
    if( (x-10)<540 )
       line(x-10,y-10,x-10,y+10-1);
    if( (x+10)<540 )
       line(x-10,y-10,x+10,y-10);
    if( (x+10)<540 )
       line(x+10,y-10,x+10,y+10-1);

      //  GRASS AFTER OBSTACLE
      setcolor(2);
    if( (x+60+4)<540 )
    {
	line(x+60,270-1,x+60+5,270-10);
	line(x+60,270-1,x+60-1,270-7);
	line(x+60,270-1,x+60-12,270-12);
    }

}

/*void move_obstacle()
{
   int i;
      for(i=545; i>=85; i--)
      {
	    setcolor(2);
	     rectangle(90,60,540,350);
	      basic_line(90,540,270);
	    obstacle(i);
	     delay(20);
	    clrscr();
      }
}*/

void check_out(int plyr,int obst)
{
   if( absolute(plyr-obst)<15 )
   {
      setcolor(2);
       rectangle(90,60,540,350);
      basic_line(90,540,270);
     settextstyle(1,0,3);
      setcolor(4);
      outtextxy(175,190,"Crashed !! YOU ARE OUT .");
       delay(5000);
      exit(0);
   }
   /*else if( absolute(plyr-(270-10))<20 )
   {
      settextstyle(1,0,3);
      setcolor(4);
      outtextxy(175,190,"Crashed !! YOU ARE OUT .");
       delay(5000);
      exit(0);
   }*/
}

void skip_obst(int x,int y,int jump)
{
   int i,m;
     setcolor(2);
      rectangle(90,60,540,350);
     i=0;
    while( i<=jump )
    {
	setcolor(2);
	 rectangle(90,60,540,350);
	check_out(i,obcount);
	 basic_line(90,540,270);
       player(x+i,y-i,50);
	 obstacle(obcount);
	delay(70);
	  /*if( obcount<90 )
	  {
	    clrscr();
	      setcolor(2);
	       rectangle(90,60,540,350);
	      basic_line(90,540,270);
	     settextstyle(1,0,3);
	      setcolor(4);
	     outtextxy(175,190,"Crashed !! YOU ARE OUT .");
	      delay(5000);
	  }*/
	   obcount--;
	//delay(1);
       clrscr();
	 i++;
    }
     m=i-1;
     i=0;
    while( i<=jump )
    {
	setcolor(2);
	 rectangle(90,60,540,350);
	check_out(i,obcount);
	 basic_line(90,540,270);
       player(x+m+i,y-m+i,50);
	 obstacle(obcount);
	delay(70);
	  /*if( obcount>90 )
	  {
	    clrscr();
	      setcolor(2);
	       rectangle(90,60,540,350);
	      basic_line(90,540,270);
	     settextstyle(1,0,3);
	      setcolor(4);
	     outtextxy(175,190,"Crashed !! YOU ARE OUT .");
	      delay(5000);
	  }*/
	   obcount--;
	//delay(1);
       clrscr();
	 i++;
    }
     player(x+m+i-1,obcount+1);
}



