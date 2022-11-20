//  Student Management project.
#include<stdio.h>
struct Student
{
   int roll,marks;
   char nm[10],mob[11],dob[11];
};
FILE *f,*t;
struct Student s;
void add()
{
   clrscr();
   gotoxy(10,10);
   printf("Student entry's Form - ");
   gotoxy(17,14);
   printf("Enter Roll  : ");
   gotoxy(17,16);
   printf("Enter Name  : ");
   gotoxy(17,18);
   printf("Enter Marks : ");
   gotoxy(17,20);
   printf("Enter Mobile: ");
   gotoxy(17,22);
   printf("Enter DOB   : ");
   gotoxy(31,14);
   scanf("%d",&s.roll);
   gotoxy(31,16);
   scanf("%s",s.nm);
   gotoxy(31,18);
   scanf("%d",&s.marks);
   gotoxy(31,20);
   scanf("%s",s.mob);
   gotoxy(31,22);
   scanf("%s",s.dob);
   f = fopen("c:/19/proj.dat","ab"); // open file in append mode
   fwrite(&s,sizeof(s),1,f);   // write struct in file object
   //  &struct,sizeof struct, nor ,file
   fclose(f); // close that file
   gotoxy(10,27);
   printf("Student Record Successfully Inserted.");
   getch();
}
void disp()
{
 //  int i;
   clrscr();
   // for(i=100;i<255;i++)
   // printf("%d - %c, ",i,i);
   // getch();
  printf("\n\n\n\n");
  f = fopen("c:/19/proj.dat","rb"); // open file in input mode
  printf("\n\tÉÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍÍÑÍÍÍÍÍÍÍÍÍÍÍÍ»");
  printf("\n\tº Roll.³   Name.     ³ Marks ³  Mobile     ³   DOB      º");
  printf("\n\tÇÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄÄÅÄÄÄÄÄÄÄÄÄÄÄÄ¶");
  while(1)
  {
     fread(&s,sizeof(s),1,f);   // read struct in file object
     if(feof(f)) break;
     printf("\n\tº %4d ³ %-10s  ³ %04d  ³ %-10s  ³ %-10s º",s.roll,s.nm,s.marks,s.mob,s.dob);
  }
  printf("\n\tÈÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍÍÏÍÍÍÍÍÍÍÍÍÍÍÍ¼");

   fclose(f);
   getch();

}
void del()
{
  int r,flag = 0;
  clrscr();
  printf("\n\n\n\n\t Plz enter Roll for delete : ");
  scanf("%d",&r);
  f = fopen("c:/19/proj.dat","rb");
  t = fopen("c:/19/temp.dat","wb");
  while(1)
  {
     fread(&s,sizeof(s),1,f);   // read struct in file object
     if(feof(f)) break;
     if(s.roll == r) // IF RECORD FOUND
       flag = 1;
     else   // ELSE WRITE THE REMAINING RECORD IN FILE
       fwrite(&s,sizeof(s),1,t);   // write struct in temp file object
   }
   fclose(f);
   fclose(t);
   if(flag)
   {
      printf("\n\n\n\tStudent Record Successfully Deleted....");
      remove("c:/19/proj.dat");
      rename("c:/19/temp.dat","c:/19/proj.dat");
   }
   else
   {
      printf("\n\n\n\tSorry Student Record does not exist...");
      remove("c:/19/temp.dat");
   }
   getch();

}
void upd()
{
  char c;
  int r,flag = 0;
  clrscr();
  printf("\n\n\n\n\t Plz enter Roll for Update : ");
  scanf("%d",&r);
  f = fopen("c:/19/proj.dat","rb");
  t = fopen("c:/19/temp.dat","wb");
  while(1)
  {
     fread(&s,sizeof(s),1,f);   // read struct in file object
     if(feof(f)) break;
     if(s.roll == r)
     {
       flag = 1;
       gotoxy(10,17);
       printf("Student exist with following Details : ");
      n:
       gotoxy(15,20);
       printf("Name  : %s",s.nm);
       gotoxy(45,20);
       printf("Marks : %d",s.marks);
       gotoxy(15,22);
       printf("DOB   : %s",s.dob);
       gotoxy(45,22);
       printf("Mobile: %s",s.mob);
       gotoxy(10,25);
       printf("Update Menu ");
       gotoxy(3,27);
       printf("n - for Name, m - for Marks, d - for DOB, b - for Mobile, x - for Save & exit");
       gotoxy(10,29);
       printf("Plz enter ur Choice : ");
       c = getch();
       if(c=='n')
       {
	 gotoxy(23,20);
	 printf("         ");
	 gotoxy(23,20);
	 scanf("%s",s.nm);
	 goto n;
       }
       else if(c=='m')
       {
	 gotoxy(53,20);
	 printf("         ");
	 gotoxy(53,20);
	 scanf("%d",&s.marks);
	 goto n;
       }
       else if(c=='d')
       {
	 gotoxy(23,22);
	 printf("           ");
	 gotoxy(23,22);
	 scanf("%s",s.dob);
	 goto n;
       }
       else if(c=='b')
       {
	 gotoxy(53,22);
	 printf("           ");
	 gotoxy(53,22);
	 scanf("%s",s.mob);
	 goto n;
       }
       else if(c=='x')
	 fwrite(&s,sizeof(s),1,t);   // write struct in temp file object
       else
	 goto n;
     }
     else
       fwrite(&s,sizeof(s),1,t);   // write struct in temp file object
   }
   fclose(f);
   fclose(t);
   if(flag)
   {
      printf("\n\n\n\tStudent Record Successfully Updated....");
      remove("c:/19/proj.dat");
      rename("c:/19/temp.dat","c:/19/proj.dat");
   }
   else
   {
      printf("\n\n\n\tSorry Student Record does not exist...");
      remove("c:/19/temp.dat");
   }
   getch();
}
void main()
{
  char c;
  while(1)
  {
     clrscr();
     printf("\n\n\n\n\n\n\n");
     printf("\n\n\t\t1. Add New Student.\n\n\t\t2. List of all Students\n\n\t\t3. Delete Existing Student\n\n\t\t4. Update Existing Student\n\n\t\t0. Exit");
     printf("\n\n\t Plz enter ur Choice : ");
     c = getche();
     if(c=='1')
       add();
     if(c=='2')
       disp();
     if(c=='3')
       del();
     if(c=='4')
       upd();
     if(c=='0')
       break;
   }
}