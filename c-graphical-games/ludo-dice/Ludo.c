		    // Ab Player Strike par kaam kaena hai ....
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<stdlib.h>

//static int strike=1;
static int mode;
static int dicedot;

int roll_dice();
void start_game();

static int x[43]={ 370, 370, 370, 370, 397, 431, 465, 499, 533, 533, 533, 499, 465, 431, 397, 370, 370, 370, 370, 370, 330, 290, 290, 290, 290, 290, 253, 219, 185, 151, 117, 117, 117, 151, 185, 219, 253, 290, 290, 290, 290, 290, 330 };
static int y[43]={ 77,  102, 127, 152, 176, 176, 176, 176, 176, 210, 244, 244, 244, 244, 244, 272, 296, 320, 344, 368, 368, 368, 344, 320, 296, 272, 244, 244, 244, 244, 244, 210, 176, 176, 176, 176, 176, 152, 127, 102, 77,  52,  52  };
static int sy;
static int sb=12;
static int sg=23;
static int sr=34;

//void fill_space();       //  EPIC IDEA
//void nothing_just_move(int noondice,int color);

void move_red_token(int noondice,int color)
{
   int i,clr;
    for(i=0; i<noondice; i++)
    {
       if( sr==31 )
       {
	  break;
       }
       if( sr==42 )
       {
	  sr=0;
	   goto x;
       }
	 sr++;
       x:       //  :  GOTO LABEL
	setcolor(WHITE);
      circle( x[sr], y[sr], 7 );
       setfillstyle(SOLID_FILL,color);
	floodfill( x[sr], y[sr], WHITE );
	 delay(400);
	if( i==(noondice-1) )
	{
	   break;
	}

       if( x[sr]==370 && y[sr]==77 || x[sr]==499 && y[sr]==244 || x[sr]==290 && y[sr]==344 )
       {
	 if( x[sr]==370 && y[sr]==77 )
	    clr=YELLOW;
	 if( x[sr]==499 && y[sr]==244 )
	    clr=BLUE;
	 if( x[sr]==290 && y[sr]==344 )
	    clr=GREEN;
	  setfillstyle(SOLID_FILL,clr);
	   floodfill(x[sr],y[sr],WHITE);
	    setcolor(clr);
	  circle(x[sr],y[sr],7);
	   continue;
       }

       setfillstyle(SOLID_FILL,BLACK);
	floodfill( x[sr], y[sr], WHITE );
	  setcolor(BLACK);
       circle( x[sr], y[sr], 7 );
    }
}


void move_green_token(int noondice,int color)
{
   int i,clr;
    for(i=0; i<noondice; i++)
    {
       if( sg==20 )
       {
	  break;
       }
       if( sg==42 )
       {
	  sg=0;
	   goto x;
       }
	 sg++;
       x:       //  :  GOTO LABEL
	setcolor(WHITE);
      circle( x[sg], y[sg], 7 );
       setfillstyle(SOLID_FILL,color);
	floodfill( x[sg], y[sg], WHITE );
	 delay(400);
	if( i==(noondice-1) )
	{
	   break;
	}

       if( x[sg]==370 && y[sg]==77 || x[sg]==499 && y[sg]==244 || x[sg]==151 && y[sg]==176 )
       {
	 if( x[sg]==370 && y[sg]==77 )
	    clr=YELLOW;
	 if( x[sg]==499 && y[sg]==244 )
	    clr=BLUE;
	 if( x[sg]==151 && y[sg]==176 )
	    clr=RED;
	  setfillstyle(SOLID_FILL,clr);
	   floodfill(x[sg],y[sg],WHITE);
	    setcolor(clr);
	  circle(x[sg],y[sg],7);
	   continue;
       }

       setfillstyle(SOLID_FILL,BLACK);
	floodfill( x[sg], y[sg], WHITE );
	  setcolor(BLACK);
       circle( x[sg], y[sg], 7 );
    }
}


void move_blue_token(int noondice,int color)
{
   int i,clr;
    for(i=0; i<noondice; i++)
    {
       if( sb==9 )
       {
	  break;
       }
       if( sb==42 )
       {
	  sb=0;
	   goto x;
       }
	 sb++;
       x:       //  :  GOTO LABEL
	setcolor(WHITE);
      circle( x[sb], y[sb], 7 );
       setfillstyle(SOLID_FILL,color);
	floodfill( x[sb], y[sb], WHITE );
	 delay(400);
	if( i==(noondice-1) )
	{
	   break;
	}

       if( x[sb]==370 && y[sb]==77 || x[sb]==290 && y[sb]==344 || x[sb]==151 && y[sb]==176 )
       {
	 if( x[sb]==370 && y[sb]==77 )
	    clr=YELLOW;
	 if( x[sb]==290 && y[sb]==344 )
	    clr=GREEN;
	 if( x[sb]==151 && y[sb]==176 )
	    clr=RED;
	  setfillstyle(SOLID_FILL,clr);
	   floodfill(x[sb],y[sb],WHITE);
	    setcolor(clr);
	  circle(x[sb],y[sb],7);
	   continue;
       }

       setfillstyle(SOLID_FILL,BLACK);
	floodfill( x[sb], y[sb], WHITE );
	  setcolor(BLACK);
       circle( x[sb], y[sb], 7 );
    }
}

void move_yellow_token(int noondice,int color)
{
   int i,clr;
    for(i=0; i<noondice; i++)
    {
	 sy++;
	setcolor(WHITE);
      circle( x[sy], y[sy], 7 );
       setfillstyle(SOLID_FILL,color);
	floodfill( x[sy], y[sy], WHITE );
	 delay(400);
	if( i==(noondice-1) )
	{
	   break;
	}

       if( x[sy]==499 && y[sy]==244 || x[sy]==290 && y[sy]==344 || x[sy]==151 && y[sy]==176 )
       {
	 if( x[sy]==499 && y[sy]==244 )
	    clr=BLUE;
	 if( x[sy]==290 && y[sy]==344 )
	    clr=GREEN;
	 if( x[sy]==151 && y[sy]==176 )
	    clr=RED;
	  setfillstyle(SOLID_FILL,clr);
	   floodfill(x[sy],y[sy],WHITE);
	    setcolor(clr);
	  circle(x[sy],y[sy],7);
	   continue;
       }
       /*if( x[sy]==290 && y[sy]==344 )
       {
	  setfillstyle(SOLID_FILL,GREEN);
	   floodfill(x[sy],y[sy],WHITE);
	    setcolor(BLUE);
	  circle(x[sy],y[sy],7);
	   continue;
       }*/

       setfillstyle(SOLID_FILL,BLACK);
	floodfill( x[sy], y[sy], WHITE );
	  setcolor(BLACK);
       circle( x[sy], y[sy], 7 );
    }
}

void six()
{
   //  DICE DOTS : 4  ....

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+9,170+22+9, 4);
     circle(280+30+20,170+22+9, 4);
    circle(380-30-9,250-22-9, 4);

    circle(380-30-9,170+22+9, 4);
     circle(280+30+20,250-22-9, 4);
    circle(280+30+9,250-22-9, 4);


     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+9,170+22+9,dicedot);
       floodfill(280+30+20,170+22+9,dicedot);
      floodfill(380-30-9,250-22-9,dicedot);

      floodfill(380-30-9,170+22+9,dicedot);
       floodfill(280+30+20,250-22-9,dicedot);
      floodfill(280+30+9,250-22-9,dicedot);
}

void five()
{
   //  DICE DOTS : 5  .....

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+8,170+22+8, 4);
    circle(380-30-8,250-22-8, 4);
     circle(280+30+20,170+22+18, 4);
    circle(380-30-8,170+22+8, 4);
    circle(280+30+8,250-22-8, 4);


     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+8,170+22+8,dicedot);
      floodfill(380-30-8,250-22-8,dicedot);
	floodfill(280+30+20,170+22+18,dicedot);
      floodfill(380-30-8,170+22+8,dicedot);
      floodfill(280+30+8,250-22-8,dicedot);
}

void four()
{
   //  DICE DOTS : 4 ....

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+10,170+22+10, 4);
    circle(380-30-10,250-22-10, 4);
    circle(380-30-10,170+22+10, 4);
    circle(280+30+10,250-22-10, 4);


     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+9,170+22+9,dicedot);
      floodfill(380-30-9,250-22-9,dicedot);
      floodfill(380-30-9,170+22+9,dicedot);
      floodfill(280+30+9,250-22-9,dicedot);
}

void three()
{
   //  DICE DOTS : 3  ...

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+7,170+22+18, 4);
     //circle(380-30-8,170+22+8, 4);
    circle(280+30+20,170+22+18, 4);
     //circle(280+30+8,250-22-8, 4);
    circle(380-30-7,250-22-18, 4);

     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+8,170+22+18,dicedot);
	//floodfill(380-30-8,170+22+8,dicedot);
       floodfill(280+30+20,170+22+18,dicedot);
	//floodfill(280+30+8,250-22-8,dicedot);
      floodfill(380-30-8,250-22-18,dicedot);
}

void two()
{
   //  DICE DOTS : 2  ..

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+9,170+22+18, 4);
    circle(380-30-9,250-22-18, 4);

     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+9,170+22+18,dicedot);
      floodfill(380-30-9,250-22-18,dicedot);
}

void one()
{
   //  DICE DOTS : 1  .

   if( mode==1 )
      dicedot=WHITE;
   else if( mode==2 )
      dicedot=RED;

     setcolor(dicedot);
    circle(280+30+20,170+22+18, 4);

     setfillstyle(SOLID_FILL,RED);
      floodfill(280+30+20,170+22+18,dicedot);
}

void star(int x,int y)
{
   line(x,y-3,x,y+3);
    line(x-3,y-2,x+3,y+2);
    line(x+3,y-2,x-3,y+2);
   line(x-3,y,x+3,y);
    line(x-2,y-3,x+2,y+3);
    line(x+2,y-3,x-2,y+3);
}

void dice(int noondice)
{

   int dicefill,diceout;
   int i;
     //  Dice Outline Color
  if( mode==1)
  {
     setcolor(YELLOW);
      //rectangle(280+30-1,170+22-1,380-30+1,250-22+1);
       rectangle(280+30,170+22,380-30,250-22);  // Dice Outline Rectangle
  }
  else if( mode==2 )
  {
      setcolor(BLACK);
	rectangle(280+30,170+22,380-30,250-22);
      setfillstyle(SOLID_FILL,YELLOW);
	floodfill(280+30+1,170+22+1,BLACK);
  }

     //  Rolling-Dice Pattern ......

   for(i=0; i<7; i++)
   {
      if( mode==1 )
      {
	 dicefill=BLACK;
	 diceout=YELLOW;
      }
      else if( mode==2 )
      {
	if( i%2==0 )
	   dicefill=58;
	else if( i%2!=0 )
	   dicefill=YELLOW;

	 diceout=BLACK;
      }

      if( i==0 )
	 four();
      else if( i==1 )
	 six();
      else if( i==2 )
	 two();
      else if( i==3 )
	 five();
      else if( i==4 )
	 one();
      else if( i==5 )
	 four();
      else if( i==6 )
	 three();

	  delay(400);  //  Rolling Pattern Speed Control
	   setfillstyle(SOLID_FILL,dicefill);
	    floodfill(280+30+1,170+22+1,diceout); //  odd
	  delay(150);
   }

    if( mode==1 )
    {
       delay(150);  //  Rolling Pattern Speed Control
	setfillstyle(SOLID_FILL,BLACK);
	 floodfill(280+30+1,170+22+1,YELLOW);
    }
    if( mode==2 )
    {
       delay(150);  //  Rolling Pattern Speed Control
	setfillstyle(SOLID_FILL,YELLOW);
	 floodfill(280+30+1,170+22+1,BLACK);
    }

      if( noondice==1 )
	 one();
      else if( noondice==2 )
	 two();
      else if( noondice==3 )
	 three();
      else if( noondice==4 )
	 four();
      else if( noondice==5 )
	 five();
      else if( noondice==6 )
	 six();
}

void board()
{
   //int pbdrclr;
  if( mode==2 )
  {
     setfillstyle(SOLID_FILL,WHITE);
      floodfill(10,10,WHITE);
  }

  if( mode==1 )
     setcolor(WHITE);  //  Primary Border Color
  else if( mode==2 )
     setcolor(BLACK);  //  Primary Border Color

    //setcolor(pbdrclr);
   rectangle(90,30,570,390);
    rectangle(90+1,30+1,570-1,390-1);
     rectangle(90+2,30+2,570-2,390-2);
      rectangle(100,40,560,380);
     //   RED BLOCK
	setcolor(RED);
       rectangle(100,40,270,160);
	rectangle(100-1,40-1,270-1,160-1);
     //   BLUE BLOCK
	setcolor(YELLOW);
       rectangle(560,40,390,160);
	rectangle(560-1,40-1,390-1,160-1);
     //   GREEN BLOCK
	setcolor(BLUE);
       rectangle(560,380,390,260);
	rectangle(560-1,380-1,390-1,260-1);
     //   YELLOW BLOCK
	setcolor(GREEN);
       rectangle(100,380,270,260);
	rectangle(100-1,380-1,270-1,260-1);

    //        WINNER'S BLOCK

      //rectangle(280,170,380,250);
	setcolor(YELLOW);
       line(280,170,380,170);
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	   outtextxy(280+27,170+9,"WINNER");

	setcolor(BLUE);
       line(380,170,380,250);
	 settextstyle(TRIPLEX_FONT, VERT_DIR, 6);
	   outtextxy(380-11,170+17,"WINNER");

	setcolor(GREEN);
       line(380,250,280,250);
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
	   outtextxy(280+27,250-14,"WINNER");

	setcolor(RED);
       line(280,250,280,170);
	 settextstyle(TRIPLEX_FONT, VERT_DIR, 6);
	   outtextxy(280+20,170+17,"WINNER");

   //  Lines joining the tHe Colored Blocks to the Winner's Block
	setcolor(RED);
       line(270,160,280,170);
	setcolor(YELLOW);
       line(390,160,380,170);
	setcolor(BLUE);
       line(390,260,380,250);
	setcolor(GREEN);
       line(270,260,280,250);

     //...........  GALLARY BLOCKS  .............

       //   YELLOW

	 setcolor(YELLOW);
	line(310,40+1,310,170-1);  // First Vertical Line
	line(310+40, 40+1, 310+40, 170-1);  // Second Vertical Line
       //   CROSS GALLARY LINES : YELLOW


	 line(270+1,65,390,65);   // 1st Horiz
	 line(270+1,90,390,90);   // 2nd Horiz
	 line(270+1,115,390,115); // 3rd Horiz
	 line(270+1,140,390,140); // 4th Horiz

	  setfillstyle(SOLID_FILL,YELLOW);
	   floodfill(390-5,90-5,YELLOW);
	   floodfill(310+40-5,90-5,YELLOW);
	   floodfill(310+40-5,115-5,YELLOW);
	   floodfill(310+40-5,140-5,YELLOW);
	   floodfill(310+40-5,165-5,YELLOW);
	      setcolor(RED);
	     //outtextxy(310+40+5, 65+4,"*");
	     //outtextxy(270+5,90+5,"*");
	       star(310+40+6, 65+6);
	       star(270+6,90+6);


       //      Line Overs : YELLOW
	  setcolor(BLACK);
	 line(310,65,310,170-1);  // Ver
	 line(310+40,65,310+40,170-1); // Ver

	 line(390-2,65,310,65);
	 line(310,90,390-2,90);
	 line(310,115,310+40,115);
	 line(310,140,310+40,140);

	//   GREEN .........
	   setcolor(GREEN);
	  line(310,380-1,310,250);
	  line(310+40,380-1,310+40,250);

	      //  CROSS GALLARY LINES : GREEEN
	  line(270,355,390-2,355);
	  line(270,330,390-2,330);
	  line(270,305,390-2,305);
	  line(270,280,390-2,280);

	   setfillstyle(SOLID_FILL,GREEN);
	    floodfill(270+1,355-1,GREEN);
	    floodfill(310+1,355-1,GREEN);
	    floodfill(310+1,330-1,GREEN);
	    floodfill(310+1,305-1,GREEN);
	    floodfill(310+1,280-1,GREEN);
	     setcolor(BLUE);
	      //outtextxy(310-11,355-9,"*");
	      //outtextxy(390-11,330-10,"*");
	       star(310-7,355-7);
	       star(390-7,330-7);

	   //   Line Overs : GREEN
	      setcolor(BLACK);
	     line(310,355,310,250+1);  // Ver
	     line(310+40,355,310+40,250+1);  // Ver

	     line(270+1,355,310+40,355);
	     line(270+1,330,310+40,330);
	     line(310,305,310+40,305);
	     line(310,280,310+40,280);

	//   RED ..........
	   setcolor(RED);
	  line(100+1,227,280,227); // Hor
	  line(100+1,193,280,193); // Hor

	  line(135,260-2,135,160);
	  line(172,260-2,172,160);
	  line(208,260-2,208,160);
	  line(245,260-2,245,160);

	   setfillstyle(SOLID_FILL,RED);
	    floodfill(135+1,193-1,RED);
	    floodfill(135+1,227-1,RED);
	    floodfill(172+1,227-1,RED);
	    floodfill(208+1,227-1,RED);
	    floodfill(245+1,227-1,RED);
	     setcolor(GREEN);
	      //outtextxy(135+5,160+4,"*");
	      //outtextxy(172+4,260-10,"*");
	       star(135+6,160+6);
	       star(172+6,260-8);

	  //  Line Overs : RED
	     setcolor(BLACK);
	    line(135,227,280-1,227);
	    line(135,193,280-1,193);

	    line(135,227,135,160+1);
	    line(172,227,172,160+1);
	    line(208,227,208,193);
	    line(245,227,245,193);

       //   BLUE ...............
	   setcolor(BLUE);
	  line(560-1,227,380,227); // Hor
	  line(560-1,193,380,193); // Hor

	  line(525,260,525,160+1);
	  line(488,260,488,160+1);
	  line(452,260,452,160+1);
	  line(415,260,415,160+1);

	   setfillstyle(SOLID_FILL,BLUE);
	     floodfill(525-1,227+1,BLUE);
	    floodfill(525-1,227-1,BLUE);
	    floodfill(488-1,227-1,BLUE);
	    floodfill(452-1,227-1,BLUE);
	    floodfill(415-1,227-1,BLUE);
	     setcolor(YELLOW);
	      //outtextxy(525-11,260-9,"*");
	      //outtextxy(488-11,193-9,"*");
	       star(525-6,260-6);
	       star(488-6,193-6);

	 //  Line Overs : BLUE
	    setcolor(BLACK);
	   line(525,193,380+1,193); // Ver
	   line(525,227,380+1,227); // Ver

	   line(525,193,525,260-2);
	   line(488,193,488,260-2);
	   line(452,193,452,227);
	   line(415,193,415,227);



    // ............  TOKEN CIRCLES  ................

       //   RED TOKENS
	 if( mode==1 )
	 {
	   setcolor(WHITE);
	     circle(145,65,15);
	     circle(225,65,15);
	     circle(145,135,15);
	     circle(225,135,15);

	      setfillstyle(SOLID_FILL,RED);
	       floodfill(145,65,WHITE);
	       floodfill(225,65,WHITE);
	       floodfill(145,135,WHITE);
	       floodfill(225,135,WHITE);
	 }
	 else if( mode==2 )
	 {
	   setcolor(BLACK);
	     circle(145,65,15);
	     circle(225,65,15);
	     circle(145,135,15);
	     circle(225,135,15);

	      setfillstyle(SOLID_FILL,RED);
	       floodfill(145,65,BLACK);
	       floodfill(225,65,BLACK);
	       floodfill(145,135,BLACK);
	       floodfill(225,135,BLACK);
	 }

       //   YELLOW TOKENS
	 if( mode==1 )
	 {
	   setcolor(WHITE);
	     circle(430,65,15);
	     circle(520,65,15);
	     circle(430,135,15);
	     circle(520,135,15);

	      setfillstyle(SOLID_FILL,YELLOW);
	       floodfill(430,65,WHITE);
	       floodfill(520,65,WHITE);
	       floodfill(430,135,WHITE);
	       floodfill(520,135,WHITE);
	 }
	 else if( mode==2 )
	 {
	   setcolor(BLACK);
	     circle(430,65,15);
	     circle(520,65,15);
	     circle(430,135,15);
	     circle(520,135,15);

	      setfillstyle(SOLID_FILL,YELLOW);
	       floodfill(430,65,BLACK);
	       floodfill(520,65,BLACK);
	       floodfill(430,135,BLACK);
	       floodfill(520,135,BLACK);
	 }

       //   BLUE TOKENS
	 if( mode==1 )
	 {
	   setcolor(WHITE);
	     circle(430,285,15);
	     circle(520,285,15);
	     circle(430,355,15);
	     circle(520,355,15);

	      setfillstyle(SOLID_FILL,BLUE);
	       floodfill(430,285,WHITE);
	       floodfill(520,285,WHITE);
	       floodfill(430,355,WHITE);
	       floodfill(520,355,WHITE);
	 }
	 else if( mode==2 )
	 {
	   setcolor(BLACK);
	    circle(430,285,15);
	     circle(520,285,15);
	     circle(430,355,15);
	     circle(520,355,15);

	      setfillstyle(SOLID_FILL,BLUE);
	       floodfill(430,285,BLACK);
	       floodfill(520,285,BLACK);
	       floodfill(430,355,BLACK);
	       floodfill(520,355,BLACK);
	 }

       //   GREEN TOKENS
	 if( mode==1 )
	 {
	   setcolor(WHITE);
	     circle(145,285,15);
	     circle(225,285,15);
	     circle(145,355,15);
	     circle(225,355,15);

	      setfillstyle(SOLID_FILL,GREEN);
	       floodfill(145,285,WHITE);
	       floodfill(225,285,WHITE);
	       floodfill(145,355,WHITE);
	       floodfill(225,355,WHITE);
	 }
	 else if( mode==2 )
	 {
	   setcolor(BLACK);
	    circle(145,285,15);
	     circle(225,285,15);
	     circle(145,355,15);
	     circle(225,355,15);

	      setfillstyle(SOLID_FILL,GREEN);
	       floodfill(145,285,BLACK);
	       floodfill(225,285,BLACK);
	       floodfill(145,355,BLACK);
	       floodfill(225,355,BLACK);
	 }

       //rectangle(280+30,170+22,380-30,250-22);  // Dice Outline Rectangle
       /*move_yellow_token(43,YELLOW);
       move_blue_token(43,BLUE);
       move_green_token(43,GREEN);
       move_red_token(43,RED); */
      //dice(); // FAIR DICE
}

void main()
{
   int gd= DETECT, gm;
     printf("\n\n\n\n\n\n\t\t\tEnter The Mode :-\n ");
     printf("\n\t\t\t\t1. Dark Mode");
     printf("\n\t\t\t\t2. Light Mode");
      printf("\n\n\n\t\t\tMake Choice About The Mode :- ");
       scanf("%d", &mode );
    initgraph(&gd,&gm,"C:\\INCLUDE\\BGI");
     //board();
      start_game();
   getch();
}

int roll_dice()
{
   int s;
    randomize();
     s=rand()%7;
   return( ( s%6!=0 ) ? s : ((s=rand()%7)!=0) ? s : rand()%7 );
   //return(s);

     //    -: II-Method :-
   /*  #include<time.h>
   int s;
   time_t t;
    srand((unsigned) time(&t));
     s=rand()%7;
   return( ( s%6!=0 ) ? s : ((s=rand()%7)!=0) ? s : rand()%7 );
   //return(s);  */
}

void start_game()
{
   board();
   dice(roll_dice());
}
