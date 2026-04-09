#include<stdio.h>
#include<conio.h>
#include<graphics.h>

static int mode;

void dice()
{
    setcolor(YELLOW);
   rectangle(280+30,170+22,380-30,250-22);
   //  DOTS ....
     setcolor(RED);
    circle(280+30+8,170+22+8, 4);
    circle(380-30-8,250-22-8, 4);
    circle(380-30-8,170+22+8, 4);
    circle(280+30+8,250-22-8, 4);
    circle(280+30+20,170+22+18, 4);

     setfillstyle(SOLID_FILL,WHITE);
      floodfill(280+30+8,170+22+8,RED);
      floodfill(380-30-8,250-22-8,RED);
      floodfill(380-30-8,170+22+8,RED);
      floodfill(280+30+8,250-22-8,RED);
      floodfill(280+30+20,170+22+18,RED);

}

void star(int x,int y,int color)
{
    setcolor(color);
   line(x-5,y-5,x,y-10);
   line(x+5,y-5,x,y-10);
     line(x-5,y-5,x-12,y-5);
     line(x+5,y-5,x+12,y-5);
   line(x-12,y-5,x-4,y-1);
   line(x+12,y-5,x+4,y-1);
     line(x-3,y,x-7,y+5);
     line(x+3,y,x+7,y+5);
   line(x-7,y+5,x,y+2);
   line(x+7,y+5,x,y+2);

     setfillstyle(SOLID_FILL,color);
      floodfill(x,y,color);
}

void board()
{
   int pbdrclr;

  if( mode==2 )
  {
     setfillstyle(SOLID_FILL,WHITE);
      floodfill(10,10,WHITE);
  }

    dice();

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
	setcolor(BLUE);
       line(380,170,380,250);
	setcolor(GREEN);
       line(380,250,280,250);
	setcolor(RED);
       line(280,250,280,170);
	 /*settextstyle(TRIPLEX_FONT, VERT_DIR, 6);
	    outtextxy(280+20,170+17,"WINNER");*/

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
	     //star(310+40+20, 81, 60);
	      setcolor(RED);
	     outtextxy(310+40+5, 65+4,"*");
	     outtextxy(270+5,90+5,"*");

       //      Line Overs : YELLOW
	  setcolor(BLACK);
	 line(310,65,310,170-1);  // Ver
	 line(310+40,65,310+40,170-1); // Ver

	 line(390-2,65,310,65);
	 line(310,90,310+40,90);
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
	      outtextxy(310-11,355-9,"*");
	      outtextxy(390-11,330-10,"*");

	   //   Line Overs : GREEN
	      setcolor(BLACK);
	     line(310,355,310,250+1);  // Ver
	     line(310+40,355,310+40,250+1);  // Ver

	     line(270+1,355,310+40,355);
	     line(310,330,310+40,330);
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
	      outtextxy(135+5,160+4,"*");
	      outtextxy(172+4,260-10,"*");

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
	      outtextxy(525-11,260-9,"*");
	      outtextxy(488-11,193-9,"*");

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

}

void main()
{
   int gd= DETECT, gm;
     printf("\n\n\n\n\n\n\t\t\tEnter The Mode :-\n ");
     printf("\n\t\t\t\t1. Dark Mode");
     printf("\n\t\t\t\t2. Light Mode");
       scanf("%d", &mode );
    initgraph(&gd,&gm,"C:\\INCLUDE\\BGI");
     board();
   getch();
}
