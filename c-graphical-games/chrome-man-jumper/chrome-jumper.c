		    // Check the "check_out()".
#include<stdio.h>
#include<conio.h>
#include<graphics.h>

static int lcount=100;
static int ob1count=350;
static int ob2count=500;
static int flag=1;

void player(int,int,int);
void move_basic_line(int,int,int);
void obstacle_first(int);
void check_out(int,int,int);
void dummy_player(int,int,int);
void skip_obst(int,int,int);
void obstacle_second(int);

int absolute(int val)
{
   if( val<0 )
      return(-val);
}

void main()
{
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");

// Now, 'lcount' is serving as 'x' of player & 'ob1count' is serving as 'y' of obstacle_first.
    player(lcount,270,100);
   getch();
}

void player(int x,int y,int speed)
{
      //   Length=38   Breadth=22
   int size=20,temp;
   char ch;
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
     line(x+3,y-10-9,x-5,y-1);
     line(x-3,y-10-9,x+5,y-1);
      delay(speed);
    }
	setcolor(2);
	 rectangle(90,60,540,350);
	lcount++;
	ob1count-=2;
	ob2count-=2;
	  delay(150);
	 if( lcount>300 )
	 {
	   clrscr();
	    exit(0);
	 }
	   //delay(50);
	  check_out(lcount,270,ob1count);
	  check_out(lcount,270,ob2count);
	   if( kbhit() )
	   {
	       ch=getch();
	       temp=ch;
		if( temp==32 )
		   skip_obst(lcount,270,40);
	   }
	     clrscr();
	    obstacle_first(ob1count);
	    obstacle_second(ob2count);
	     //delay(80);
	  setcolor(2);
	   rectangle(90,60,540,350);
	  move_basic_line(90,540,270);
	   player(lcount,270,100);
}

void move_basic_line(int x1,int x2,int y)
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
	    if( lcount%2==0 )
	       putpixel(x2,y,WHITE);
	    else
	       putpixel(x2,y,BLUE);
	   m++;
	 }
	 else if( m>=10 || m<19 )
	 {
	    if( lcount%2==0 )
	       putpixel(x2,y,BLUE);
	    else
	       putpixel(x2,y,WHITE);
	  if( m==19 )
	   m=0;
	  m++;
	 }
	  x2--;
	   i++;
       }
}

void obstacle_first(int x)
{
   int y=260;
     setcolor(2);
      rectangle(90,60,540,350);
      // GRASS BEFORE OBSTACLE
    if( (x-60+4)<540 && (x-60-12)>90 )
    {
	line(x-60,270-1,x-60+5,270-10);
	line(x-60,270-1,x-60-1,270-7);
	line(x-60,270-1,x-60-12,270-12);
    }
      //    OBSTACLE
      setcolor(4);
    if( (x-10)<540 && (x-10)>90 )
       line(x-10,y-10,x-10,y+10-1);
    if( (x+10)<540 && (x-10)>90  )
       line(x-10,y-10,x+10,y-10);
    if( (x+10)<540 && (x-10)>90 )
       line(x+10,y-10,x+10,y+10-1);

      //  GRASS AFTER OBSTACLE
      setcolor(2);
    if( (x+60+4)<540 && (x+60-12)>90 )
    {
	line(x+60,270-1,x+60+5,270-10);
	line(x+60,270-1,x+60-1,270-7);
	line(x+60,270-1,x+60-12,270-12);
    }
}

void check_out(int xplyr,int yplyr,int obst)
{
   if( absolute(xplyr-obst)<15 && absolute(yplyr-260)<11 )
   {
      setcolor(2);
       rectangle(90,60,540,350);
      //basic_line(90,540,270);
     settextstyle(1,0,3);
      setcolor(4);
      outtextxy(175,190,"Crashed !! YOU ARE OUT .");
       delay(5000);
      exit(0);
   }
    if( (xplyr-obst)>0 ) //  Continue From Here, "What After 'flag=2' ?"
       flag=2;
}

void dummy_player(int x,int y,int speed)
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
     line(x+3,y-10-9,x-5,y-1);
     line(x-3,y-10-9,x+5,y-1);
      delay(speed);
    }
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
	check_out(lcount,y-i,ob1count);
	check_out(lcount,y-i,ob2count);
	 move_basic_line(90,540,270);
	dummy_player(x-1+i,y-i,50);
	 obstacle_first(ob1count);
	 obstacle_second(ob2count);
	delay(70);
	  /*if( ob1count<90 )
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
	   ob1count--;
	   ob2count--;
	   lcount++;
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
	check_out(lcount,y-m+i,ob1count);
	check_out(lcount,y-m+i,ob2count);
	 move_basic_line(90,540,270);
	dummy_player(x+m+i,y-m+i,50);
	 obstacle_first(ob1count);
	 obstacle_second(ob2count);
	delay(70);
	  /*if( ob1count>90 )
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
	   ob1count--;
	   ob2count--;
	   lcount++;
	//delay(1);
       clrscr();
	 i++;
    }
      setcolor(2);
       rectangle(90,60,540,350);
	check_out(lcount,270,ob1count);
	check_out(lcount,270,ob2count);
      move_basic_line(90,540,270);
     player(lcount-1,270,100);
}

void obstacle_second(int x)
{
   int y=260;
     setcolor(2);
      rectangle(90,60,540,350);
      // GRASS BEFORE OBSTACLE
    if( (x-60+4)<540 && (x-60-12)>90 )
    {
	line(x-60,270-1,x-60+5,270-10);
	line(x-60,270-1,x-60-1,270-7);
	line(x-60,270-1,x-60-12,270-12);
    }
      //    OBSTACLE
      setcolor(4);
    if( (x-10)<540 && (x-10)>90 )
       line(x-10,y-10,x-10,y+10-1);
    if( (x+10)<540 && (x-10)>90  )
       line(x-10,y-10,x+10,y-10);
    if( (x+10)<540 && (x-10)>90 )
       line(x+10,y-10,x+10,y+10-1);

      //  GRASS AFTER OBSTACLE
      setcolor(2);
    if( (x+60+4)<540 && (x+60-12)>90 )
    {
	line(x+60,270-1,x+60+5,270-10);
	line(x+60,270-1,x+60-1,270-7);
	line(x+60,270-1,x+60-12,270-12);
    }
}


