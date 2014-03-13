/*Q20) WRITE A PROGRAM TO CREATE AND DISPLAY THE ELEMENTS OF AN INTEGER ARRAY USING POINTERS */


#include<iostream.h>
#include<conio.h>

int i[5];
int *ptr=i;           //pointer 

void create();
void display();       // function prototypes

void main()           //main func
{ clrscr();
int choice;
char ch;
do{
cout<<"\n\t\t\t MENU";
cout<<"\n\t 1.create array";
cout<<"\n\t 2.display array";
cout<<"\n enter your choice";
cin>>choice;
switch(choice)
{ case 1: create(); break;
  case 2: display(); break;
  default: cout<<"\n\n wrong choice entered";
}
cout<<"\n DO YOU WANT TO CONTINUE..? N/Y";
cin>>ch;
}
while(ch=='y'||ch=='Y');
}

void create()             //func create
{
   for(int k=0; k<5; k++)
  {cout<<"\n enter the "<<k+1<<" element";
  cin>>*(ptr+k);}
}

void display()           //func display
 { for(int j=0; j<5; j++)
   cout<<"\n the numbers are : "<<*(ptr+j);
 }
