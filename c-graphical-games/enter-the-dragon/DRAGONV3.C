		      // Transition: 2  #Modified Controls





















































#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<process.h>
#include<math.h>

static int bcount;
static int bx[10]={ 220,400,325,420,260,350,300,410,200,290 };
static int by[10]={ 100,80,160,220,210,130,110,190,200,100 };
static int size=20;
static int score;
static int hiscore=30;

void move_vert_line(int,int,char,int);
void check_ball_horiz_radius(int,int);
void check_bound_vert(int,int);
void score_board();
int menu_ui();
void shut();
void pause();
void help();
void clearpixel_horiz(int,int,int,int,char);
void clearpixel_vert(int,int,int,int,char);

void ball()
{
       setcolor(2);
	rectangle(190,60,460,260);
       setcolor(RED);
	circle(bx[bcount], by[bcount], 3);
	 setfillstyle(SOLID_FILL,BLUE);
	floodfill(bx[bcount], by[bcount], RED);
}

void check_bound_horiz(int x,int y)
{
   int i;
       for(i=61; i<=259; i++)
       {
	  if( ( x==190 && y==i ) || ( x==460 && y==i ) )
	  {
	     clrscr();
	      setcolor(2);
	       rectangle(190,60,460,260);
		score_board();
	      setcolor(RED);
	       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	       outtextxy(240, 140, "Oops !! GAME OVER .");
	      delay(5000);
	       exit(0);
	  }
       }
}

void check_ball_vert_radius(int x,int y)
{
   int i,temp;
     temp=by[bcount]-3;
    for(i=0; i<7; i++)
    {
       if( x==bx[bcount]  && y==(temp+i) )
       {
	  clrscr();
	  setcolor(2);
	   rectangle(190,60,460,260);
	    bcount++; // bcount increment
	    size=size+20; // size increment
	    score=score+10; // score increment
	   ball();
	    //break;
       }
    }
     //printf("\n\tbcount=%d", bcount );
     //printf("\n\tsize=%d", size );
}

void move_horiz_line(int x,int y,char dir,int speed)
{
   int i,k,xc,yc,c,temp,xtemp;
   char ch;
     i=0;
     k=0; xc=x; yc=y;
    if( dir=='r' )
    {
       for(c=0; c<=(470-x); c++)
       {
	   setcolor(2);
	    rectangle(190,60,460,260);
	   if( k<=size )
	   {
	       setcolor(2);
		rectangle(190,60,460,260);
	      ball();
	       setcolor(4);
		if( kbhit() )
		{
		    clearpixel_horiz(x,yc,x+k,yc,dir);
		}
	      putpixel(x+k,y,RED);
	       check_bound_horiz(x+k,y);
	       check_ball_vert_radius(x+k,y);
	      if( kbhit() )
	      {
		 ch=getch();
		 temp=ch;
		  if( temp==72 )  // ASCII 'Up Arrow'
		     move_vert_line(x+k,y,'u',speed);
		  else if( temp==80 ) // ASCII 'Down Arrow'
		     move_vert_line(x+k,y,'d',speed);
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_horiz_line(x+k,y,'d',speed);
		  }
		  else if( temp==109 )
		  {
		    clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
	      }
	     delay(speed);
	       k++;
	   }
	   else if( k>size )
	   {
	      clrscr();
	       setcolor(2);
		rectangle(190,60,460,260);
		 score_board();
	      ball();
	       setcolor(4);
	      line(xc+i,y,xc+size+i,y);
	       check_bound_horiz(xc+size+i,y);
	       check_ball_vert_radius(xc+size+i,y);
		if( kbhit() )
		{
		   ch=getch();
		   temp=ch;
		    if( temp==72 )  // ASCII 'Up Arrow'
		    {
		       clearpixel_horiz(x+i,y,x+size+i,y,dir);
		       move_vert_line(xc+size+i,y,'u',speed);
		    }
		  else if( temp==80 ) // ASCII 'Down Arrow'
		  {
		     clearpixel_horiz(x+i,y,x+size+i,y,dir);
		     move_vert_line(xc+size+i,y,'d',speed);
		  }
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_horiz_line(xc+size+i,y,'d',speed);
		  }
		  else if( temp==109 )
		  {
		    clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
		}
		 i++;
		 k=1000; // passing a fake value to k to eliminate it
	       delay(speed);
	      clrscr();
	   }
       }  // for loop closed
    } //  if loop closed

    else if( dir=='l' )
    {
      //xtemp=x;
       for(c=0; c<=(x-180); c++)
       {
	   setcolor(2);
	    rectangle(190,60,460,260);
	   if( k<=size )
	   {
	       setcolor(2);
		rectangle(190,60,460,260);
	      ball();
	       setcolor(4);
		if( kbhit() )
		{
		    clearpixel_horiz(x,yc,x-k,yc,dir);
		}
	      putpixel(xc-k,y,RED);
	       check_bound_horiz(xc-k,y);
	       check_ball_vert_radius(xc-k,y);
	      if( kbhit() )
	      {
		 ch=getch();
		 temp=ch;
		  if( temp==72 )  // ASCII 'Up Arrow'
		     move_vert_line(x-k,y,'u',speed);
		  else if( temp==80 ) // ASCII 'Down Arrow'
		     move_vert_line(x-k,y,'d',speed);
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_horiz_line(x-k,y,'d',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
	      }
	     delay(speed);
	       k++;
	   }
	   else if( k>size )
	   {
	      clrscr();
	       setcolor(2);
		rectangle(190,60,460,260);
		 score_board();
	      ball();
	       setcolor(4);
	      line(xc-i,y,xc-size-i,y);
		xtemp=xc-size-1;
	       check_bound_horiz(xc-size-i,y);
	       check_ball_vert_radius(xc-size-i,y);
		if( kbhit() )
		{
		   ch=getch();
		   temp=ch;
		    if( temp==72 )  // ASCII 'Up Arrow'
		   {
		      clearpixel_horiz(x-i,y,x-size-i,y,dir);
		      move_vert_line(xc-size-i,y,'u',speed);
		   }
		  else if( temp==80 ) // ASCII 'Down Arrow'
		  {
		     clearpixel_horiz(x-i,y,x-size-i,y,dir);
		     move_vert_line(xc-size-i,y,'d',speed);
		   }
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_horiz_line(xc-size-i,y,'d',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
		}
		 i++;
		 k=1000; // passing a fake value to k to eliminate it
	       delay(speed);
	      clrscr();
	   }
       }  // for loop closed
    }  // if loop closed
}

void main()
{
   int nitrox;
   int gd= DETECT, gm;
    initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
     nitrox=menu_ui();
      move_horiz_line(250,190,'r',nitrox);
   getch();
}

void move_vert_line(int x,int y,char dir,int speed)
{
   int i,k,yc,xc,c,temp,ytemp;
   char ch;
     i=0;
     k=0; yc=y; xc=x;
    if( dir=='d' )
    {
       for(c=0; c<=(270-y); c++)
       {
	   setcolor(2);
	    rectangle(190,60,460,260);
	   if( k<=size )
	   {
	       setcolor(2);
		rectangle(190,60,460,260);
	      ball();
	       setcolor(4);
		if( kbhit() )
		{
		    clearpixel_vert(xc,y,xc,y+k,dir);
		}
	      putpixel(x,y+k,RED);
	       check_bound_vert(x,y+k);
	       check_ball_horiz_radius(x,y+k);
	      if( kbhit() )
	      {
		 ch=getch();
		 temp=ch;
		  if( temp==75 )  // ASCII 'Left Arrow'
		     move_horiz_line(x,y+k,'l',speed);
		  else if( temp==77 ) // ASCII 'Right Arrow'
		     move_horiz_line(x,y+k,'r',speed);
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_vert_line(x,y+k,'r',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
	      }
	     delay(speed);
	       k++;
	   }
	   else if( k>size )
	   {
	      clrscr();
	       setcolor(2);
		rectangle(190,60,460,260);
		 score_board();
	      ball();
	       setcolor(4);
	      line(x,yc+i,x,yc+size+i);
	       check_bound_vert(x,yc+size+i);
	       check_ball_horiz_radius(x,yc+size+i);
		if( kbhit() )
		{
		   ch=getch();
		   temp=ch;
		    if( temp==75 )  // ASCII 'Left Arrow'
		    {
		       clearpixel_vert(x,y+i,x,y+size+i,dir);
		       move_horiz_line(x,yc+size+i,'l',speed);
		    }
		  else if( temp==77 ) // ASCII 'Right Arrow'
		  {
		     clearpixel_vert(x,y+i,x,y+size+i,dir);
		     move_horiz_line(x,yc+size+i,'r',speed);
		  }
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_vert_line(x,yc+size+i,'r',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
		}
		 i++;
		 k=1000; // passing a fake value to k to eliminate it
	       delay(speed);
	      clrscr();
	   }
       }  // for loop closed
    } //  if loop closed

    else if( dir=='u' )
    {
      ytemp=y;
       for(c=0; c<=(y-50); c++)
       {
	   setcolor(2);
	    rectangle(190,60,460,260);
	   if( k<=size )
	   {
	       setcolor(2);
		rectangle(190,60,460,260);
	      ball();
	       setcolor(4);
		if( kbhit() )
		{
		   clearpixel_vert(xc,y,xc,y-k,dir);
		}
	      putpixel(x,ytemp-k,RED);
	       check_bound_vert(x,ytemp-k);
	       check_ball_horiz_radius(x,ytemp-k);
	      if( kbhit() )
	      {
		 ch=getch();
		 temp=ch;
		  if( temp==75 )  // ASCII 'Left Arrow'
		     move_horiz_line(x,y-k,'l',speed);
		  else if( temp==77 ) // ASCII 'Right Arrow'
		     move_horiz_line(x,y-k,'r',speed);
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_vert_line(x,y-k,'r',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
	      }
	     delay(speed);
	       k++;
	   }
	   else if( k>size )
	   {
	      clrscr();
	       setcolor(2);
		rectangle(190,60,460,260);
		 score_board();
	      ball();
	       setcolor(4);
	      line(x,yc-i,x,yc-size-i);
		ytemp=yc-size-1;
	       check_bound_vert(x,yc-size-i);
	       check_ball_horiz_radius(x,yc-size-i);
		if( kbhit() )
		{
		   ch=getch();
		   temp=ch;
		    if( temp==75 )  // ASCII 'Left Arrow'
		    {
		       clearpixel_vert(x,y-i,x,y-size-i,dir);
		       move_horiz_line(x,yc-size-i,'l',speed);
		    }
		  else if( temp==77 ) // ASCII 'Right Arrow'
		  {
		     clearpixel_vert(x,y-i,x,y-size-i,dir);
		     move_horiz_line(x,yc-size-i,'r',speed);
		  }
		  else if( temp==27 )
		     shut();
		  else if( temp==32 )
		  {
		     pause();
		      move_vert_line(x,yc-size-i,'r',speed);
		  }
		  else if( temp==109 )
		  {
		   clrscr();
		      bcount=0;
		      size=20;
		      score=0;
		     temp=menu_ui();
		  }
		}
		 i++;
		 k=1000; // passing a fake value to k to eliminate it
	       delay(speed);
	      clrscr();
	   }
       }  // for loop closed
    }  // if loop closed
}

void check_ball_horiz_radius(int x,int y)
{
   int i,temp;
     temp=bx[bcount]-3;
    for(i=0; i<7; i++)
    {
       if( y==by[bcount] && x==(temp+i) )
       {
	  clrscr();
	  setcolor(2);
	   rectangle(190,60,460,260);
	    bcount++; // bcount increment
	    size=size+20; // size increment
	    score=score+10; // score increment
	   ball();
	    //break;
       }
    }
     //printf("\n\tbcount=%d", bcount );
     //printf("\n\tsize=%d", size );
}

void check_bound_vert(int x,int y)
{
   int i;
       for(i=190; i<=460; i++)
       {
	  if( ( x==i && y==60 ) || ( x==i && y==260 ) )
	  {
	     clrscr();
	      setcolor(2);
	       rectangle(190,60,460,260);
		score_board();
	      setcolor(RED);
	       settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
	       outtextxy(240, 140, "Oops !! GAME OVER .");
	      delay(5000);
	       exit(0);
	  }
       }
}

void score_board()
{
   setcolor(2);
    rectangle(190,60,460,260);
   setcolor(YELLOW);
     if( score>hiscore )
	hiscore=score;
    printf("\n\n\t\t\t%d\t\t\t\t\t       %d      ", score, hiscore );
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
   outtextxy(70,25,"Your Score : ");
   outtextxy(450,25,"High Score : ");
}

void help()
{
   int temp;
   char ch;
   clrscr();
    setfillstyle(SOLID_FILL,14);
     floodfill(2,2,BLACK);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
      setcolor(BLUE);
     outtextxy(250,40,"USER HELP");
     outtextxy(250,55,"---------");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
      setcolor(RED);
     outtextxy(170,100,"(*) '/\\' --> Up");
     outtextxy(170,130,"(*) '\\/' --> Down");
     outtextxy(170,160,"(*) '<' --> Left");
     outtextxy(170,190,"(*) '>' --> Right");
      setcolor(GREEN);
     outtextxy(130,250,"(#) Press 'SPACE' Anytime To Pause.");
     outtextxy(130,290,"(#) Feel Free To Exit The Game Anytime...Press 'ESC'.");
       setcolor(5);
    outtextxy(50,350,"($) Press Any key To Escape The 'Help-Screen'.");
      ch=getch();
      temp=ch;
       if( temp==27 )
       {
	 clrscr();
	  temp=menu_ui();
       }
}

void pause()
{
   int i,temp,flag=0;
   char ch;
    while( flag!=1 )
    {
       clrscr();
      setcolor(2);
       rectangle(190,60,460,260);
	score_board();
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
       setcolor(RED);
      outtextxy(290,140,"PAUSED.");
	delay(200);
       if( kbhit() )
       {
	  ch=getch();
	  temp=ch;
	   if( temp==27 );
	   {
	     clrscr();
	      flag=1;
	   }
       }
	if( flag==1 )
	   break;
    }
}

void shut()
{
    clrscr();
   setcolor(2);
    rectangle(190,60,460,260);
     score_board();
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
      setcolor(BLUE);
     outtextxy(245,140,"Play Soon Again...");
    delay(3000);
   exit(0);
}

int menu_ui()
{
   int ch,hit,temp;
    setfillstyle(SOLID_FILL,BLACK);
     floodfill(2,2,BLACK);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
      setcolor(RED);
     outtextxy(200,40,"THE DRAGON SNAKE");
     outtextxy(200,55,"**************************");
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
      setcolor(WHITE);
     outtextxy(140,150,"Press 'ENTER' To Start The Game... ");
      getch();
    clrscr();
     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
       setcolor(RED);
      outtextxy(200,40,"THE DRAGON SNAKE");
      outtextxy(200,55,"**************************");
     settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
       setcolor(BLACK);
      outtextxy(150,120,"Select Your Difficulty Level : ");
       setcolor(YELLOW);
      outtextxy(150,127,"---------------------");
	setcolor(GREEN);
       outtextxy(250,170,"(1) Easy");
       outtextxy(250,220,"(2) Normal ");
       outtextxy(250,270,"(3) Hard ");
	setcolor(BLUE);
      outtextxy(150,320,"Enter Your Choice :- ");
       setcolor(60);
      outtextxy(50,360,"(?)Press (4) For HELP.");
       scanf("%d", &ch );
      clrscr();
     floodfill(2,2,WHITE);
      if( ch==1 )
	 return(100);
      if( ch==2 )
	 return(50);
      if( ch==3 )
	 return(10);
      if( ch==4 )
	 help();
}

void clearpixel_horiz(int x1,int y1,int x2,int y2,char chkdir)
{
   int xc,yc,i;
    xc=abs(x2-x1);
     if( chkdir=='r' )
     {
	 for(i=0; i<xc; i++)
	 {
	    putpixel(x1+i,y1,7);
	     delay(20);
	 }
     }
     else if( chkdir=='l' )
     {
	for(i=0; i<xc; i++)
	{
	   putpixel(x1-i,y1,7);
	    delay(20);
	}
     }
}

void clearpixel_vert(int x1,int y1,int x2,int y2,char chkdir)
{
   int xc,yc,i;
    yc=abs(y2-y1);
     if( chkdir=='d' )
     {
	 for(i=0; i<yc; i++)
	 {
	    putpixel(x1,y1+i,7);
	     delay(20);
	 }
     }
     else if( chkdir=='u' )
     {
	for(i=0; i<yc; i++)
	{
	   putpixel(x1,y1-i,7);
	    delay(20);
	}
     }
}



