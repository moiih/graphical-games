#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<string.h>
#include<process.h>
#include"msgraph.h"
#include<dos.h>
#include<math.h>

void settings(char []);

void main()
{
   int gd= DETECT, gm;
   float per[3];
   int x2[3],temp1,i;
   float temp2;
   char st1[10],st2[10];
   char ch,ch2[10];
   FILE *fp=fopen("justin.txt","r");
    clrscr();

    printf("\n\t\t\t-: WELCOME TO STUDENT RECORDS :-");
    printf("\n\t\t\t   **************************\n");
     fscanf(fp,"%s",st2);
     strcpy(ch2,st2);
    printf("\n\n ( PRESS 's' TO OPEN THE SETTINGS .)");
    printf("\n\n Enter The Password To Open The Software :  ");
     scanf("%s",st1);

    if( strcmp(st1,"s")==0 )
    {
      fclose(fp);
       settings(ch2);
    }

    //fscanf(fp,"%s",st2);
     if( strcmp(st1,st2)!=0 )
     {
       //clrscr();
	printf("\n\n\n\n\n\t\t\t    SORRY !! INCORRECT PASSWORD .");
	 delay(2000);
       exit(0);
      }

     clrscr();
    printf("\n\t\t\t-: WELCOME TO STUDENTS RECORD :-");
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

     printf("--------------------------------------------------");
    printf("\n     Your Students' Data Is Given Below :-\n");
     for(i=0; i<3; i++)
     {
	printf("\n\n\t\t\t\tStudent %d = %d%", i+1, x2[i] );
     }
       delay(2000);

      initgraph(&gd,&gm,"C:\\TURBOC3:\\BGI");

      setbkcolor(14);
     myline_dda(150,110,150,310, 1);
     myline_dda(150,310,480,310, 1);

     setcolor(1);
    /*  ARROWS FOR FIRST LINE  */
      outtextxy(140,106,"Y");
     line(150,110,145,115);
     line(150,110,155,115);
       delay(500);
    /*  ARROWS FOR SECOND LINE  */
      outtextxy(482,310,"X");
     line(480,310,475,305);
     line(480,310,475,315);
       delay(500);

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
	mybar3d( (150+110*i)+30, x2[i], (150+110*i)+60, 310, 6, 2);
	    delay(1000);
     }

      setcolor(5);
     settextstyle(TRIPLEX_FONT, VERT_DIR, 6);
       outtextxy((150-4),(110+50),"Percetage(%)");

 getch();

}

void settings(char ch1[])
{
   char oldpass[10],newpass[10],temp[10];
   FILE *fp=fopen("justin.txt","w");
    //printf("\n\n\t1.Change Password ?(Y/N) : ");
       printf("\n\n\t\tEnter Old Password : ");
	scanf("%s", oldpass );
       if( strcmp(ch1,oldpass)==0 )
       {
	  printf("\n\n\t\tEnter New Password : ");
	   scanf("%s", newpass );
	  fprintf(fp,"%s",newpass);
       }
       else
	  printf("\n\n\t\t\tWRONG OLD PASSWORD !");

}


