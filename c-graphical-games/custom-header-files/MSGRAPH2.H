#include<math.h>
#include<dos.h>
void mybar3d(int x1,int y1,int x2,int y2,int dp,int color)
{
   int i,dx,dy,temp;
     dy=abs(y2-y1);
     dx=abs(x2-x1);
     temp=y2;

   setcolor(63);
     temp=temp-1;
    for(i=0; i<dy; i++)
    {
       line(x1,temp,x2,temp);
	temp=temp-1;
       delay(20);
    }

    setcolor(color);
     line(x2,y2,x2+dp,y2-dp+2);
       delay(200);
     line(x2+dp,y2-dp+2,x2+dp,y1-dp+2);
       delay(200);
     line(x2+dp,y1-dp+2,x2+dp-dx,y1-dp+2);
       delay(200);
     line(x2+dp-dx,y1-dp+2,x1,y1);
       delay(200);
     line(x2+dp,y1-dp+2,x2,y1);

    setcolor(color);
     line(x1,y1,x2,y1);
     line(x2,y1,x2,y2);
     line(x2,y2,x1,y2);
     line(x1,y2,x1,y1);
}

void mybar(int x1,int y1,int x2,int y2,int color)
{
   int i,dy,temp;
     dy=abs(y2-y1);
    for(i=0; i<=dy; i++)
    {
       line(x1,temp,x2,temp);
	temp=temp-1;
       delay(10);
    }

    setcolor(color);
     line(x1,y1,x2,y1);
     line(x2,y1,x2,y2);
     line(x2,y2,x1,y2);
     line(x1,y2,x2,y2);
}

void myline_bres(int x1,int y1,int x2,int y2,int color)
{
   int x,y,dx,dy,p,i;

    dx=x2-x1;
    dy=y2-y1;

     p=2*dy-dx;

    x=x1;
    y=y1;

     i=0;
    while( i<=dx )
    {
       putpixel(x,y,color);
	if( p<0 )
	{
	   x=x+1;
	    p=p+2*dy;
	}
	else
	{
	   x=x+1;
	   y=y+1;
	    p=p+(2*dy)-(2*dx);
	}
       i++;
    }
}

void myline_dda(float x1,float y1,float x2,float y2,int color)
{
   int temp;
   float dx,dy;
   float x,y,xinc,yinc,length,i;

     dx=x2-x1;
     dy=y2-y1;

      if( abs(dx)>=abs(dy) )
	 length=dx;
      else
	 length=dy;

     xinc=dx/length;
     yinc=dy/length;

      x=x1+0.5;
      y=y1+0.5;

	 setcolor(4);
	line(180,30,180,430);
	line(490,30,490,430);

      i=0;
     while( i<=length )
     {

	putpixel(x,y,color);
	 x=x+xinc;
	 y=y+yinc;

	  temp=y;
	 if( (temp%10)==0 )
	 {
	   setcolor(4);
	    line(x,y,x+3,y-3);
	    line(x,y,x-3,y-3);
	 }
	i++;
	 delay(5);
     }
}

void straight_line(int x1,int x2,int y,char dir)
{
   int i,dx;

    dx=x2-x1;

     i=0;
    if( dir=='l' )
    {
       while( i<=dx )
       {
	  putpixel(x1,y,1);
	   x1=x1+1;
	  i++;
	    delay(5);
       }
    }
    else if( dir=='r' )
    {
       while( i<=dx )
       {
	  putpixel(x2,y,1);
	   x2--;
	  i++;
	    delay(5);
       }
    }
}

