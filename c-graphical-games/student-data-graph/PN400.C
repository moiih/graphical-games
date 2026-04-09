#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
#include<dos.h>

void stu_graph();

void main()
{
   char st1[7],st2[7],ch;
   int flag=0;
   FILE *fp=fopen("Shiva.txt","r");
    clrscr();

    printf("\n\t\t\t-: WELCOME TO STUDENTS ROECORD :-");
    printf("\n\t\t\t   ***************************\n");
    m: printf("\n\n Enter The Password To Open The Software :  ");
     scanf("%s",st1);
    fscanf(fp,"%s",st2);
     if( strcmp(st1,st2)!=0 )
     {
       clrscr();
	printf("\n\n\n\n\n\t\t\t    SORRY !! INCORRECT PASSWORD .");
	 flag=1;
	 //delay(2000);
       //exit(0);
      }
     if( flag==0 )
	stu_graph();
     else if( flag==1 )
     {
	printf("\n\tTRY AGAIN?(Y/N) : ");
	scanf("%c",&ch);
	printf("\n\t%c",ch);
	if(ch=='y'||ch=='Y')
	   goto m;
	else if(ch!='y'||ch!='Y')
	   exit(0);
     }

   getch();
}

void stu_graph()
{
   int gd= DETECT, gm;
   float per[3];
   int x2[3],temp1,i;
   float temp2;
     clrscr();
    printf("\n\t\t\t-: WELCOME TO STUDENTS ROECORD :-");
    printf("\n\t\t\t   ***************************\n");
     for(i=0; i<3; i++)
     {
       printf("\n\n Enter The Percentage Of Students %d :- ", i+1 );
	scanf("%f", &per[i] );
     }

     for(i=0; i<3; i++)
     {
	temp1=per[i];
	temp2=per[i]-temp1;
	 if( temp2 >= 0.5 )
	    x2[i]=temp1+1;
	 else
	    x2[i]=temp1;
     }

     printf("\n---------------------------------------------\n");
    printf("\n\tYour Students' Data Is Given Below :-\n");
     for(i=0; i<3; i++)
     {
	printf("\n\n\t\tStudent %d = %d%", i+1, x2[i] );
     }
       delay(4000);

      initgraph(&gd,&gm,"C:\\TURBOC3:\\BGI");

      setbkcolor(14);
      setcolor(1);
     line(150,110,150,310);
      outtextxy(140,106,"Y");
       line(150,110,145,115);
       line(150,110,155,115);

     line(150,310,480,310);
      outtextxy(482,310,"X");
       line(480,310,475,305);
       line(480,310,475,315);

      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 6);
       setcolor(4);

     for(i=0; i<3; i++)
     {
	if( i==0 )
	    outtextxy( (150+110*i)+12, (310+3), "Student 1");
	 else if( i==1 )
	    outtextxy( (150+110*i)+12, (310+3), "Student 2");
	 else if( i==2 )
	    outtextxy( (150+110*i)+12, (310+3), "Student 3");

	  delay(1000);
     }

      setcolor(2);
     for(i=0; i<3; i++)
     {
	 x2[i]=310.0-(2.0*x2[i]);
	bar3d( (150+110*i)+30, x2[i], (150+110*i)+60, 310,6,6);
	    delay(1000);
     }

      setcolor(5);
     settextstyle(TRIPLEX_FONT, VERT_DIR, 6);
       outtextxy((150-4),(110+50),"Percetage(%)");

}
