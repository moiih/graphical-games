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
