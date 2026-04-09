/*void move_player1_token(int x,int y)
{
   int i,mcount=0,xc,yc;

    xc=x+mcount;
    yc=y+mcount;

     setcolor(WHITE);
    for(i=0; i<9; i++)
    {

       if( i<=3 )
       {
	circle(x,y+mcount,7);
       setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x,y+mcount,WHITE);
	 delay(1000);
       setfillstyle(SOLID_FILL,BLACK);
	floodfill(x,y+mcount,BLACK);
	 mcount+=25;
       }

	else if( i>3 );
	{
	  if( i==3 )
	  {
	   mcount=0;
	    x=397;
	    y=176;
	  }
	   circle(x,y+mcount,7);
	  setfillstyle(SOLID_FILL,YELLOW);
	   floodfill(x+mcount,y,WHITE);
	    delay(1000);
	  setfillstyle(SOLID_FILL,BLACK);
	   floodfill(x+mcount,y,BLACK);
	    mcount+=34;
	}
    }
} */

void move_player1_token(int x,int y,int inc)
{
   int i,mcount=0,xc,yc;

    //xc=x+mcount;
    yc=y+mcount;

     setcolor(WHITE);

      circle(x,yc,7);
       setfillstyle(SOLID_FILL,YELLOW);
	floodfill(x,yc,WHITE);
	 delay(1000);
       setfillstyle(SOLID_FILL,BLACK);
	floodfill(x,yc,BLACK);
	 mcount=mcount+inc;
}

void init_move(int x,int y)
{
   int i,inc;
    for(i=0; i<9; i++)
    {
       if( i<=3 )
       {
	  move_player1_token(x,y,25);
       }
       else if( i>3)
       {
	  x=397;
	  y=176;
	  inc=34;
	   move_player1_token(xc,y,inc);
       }
    }
}



