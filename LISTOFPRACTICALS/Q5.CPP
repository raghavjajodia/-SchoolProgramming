/*q5)Write a program to define following macro/#define /constant
and their implementation:
i.   Area of rectangle
ii.  Area of square
iii. Area of triangle  */



#include<iostream.h>                                     //header files
#include<conio.h>

#define aor(x,y) x*y                                     //macros
#define aos(z) z*z
#define aot(a,b) 0.5*a*b                      
const MAX=100;                                           

void main()                                         
{clrscr();                                               //main
int ch;
char choice;
int l,m,n,p,q,r;
cout<<"*******PROGRAMMING MENU********";
cout<<"\n1. AREA OF RECTANGLE";
cout<<"\n2. AREA OF SQUARE";
cout<<"\n3. AREA OF TRIANGLE";
cout<<"\n4. CONSTANT";
do{       cout<<"\nEnter the choice of task you want to do ";
cin>>ch;
switch(ch)
{case 1:cout<<"\nEnter the dimensions of rectangle\n";
 	cin>>l>>m;
 	cout<<"\n Area of rectangle is "<<aor(l,m);
 	break;
case 2:cout<<"\n Enter the side of square\n";
      cin>>n;
      cout<<"\nArea of square is "<<aos(n);                    //switch
      break;
case 3:cout<<"\nEnter the base and altitude of a triangle ";
      cin>>p>>q;
      cout<<"\n Area of triangle is "<<aot(p,q);
      break;
case 4:cout<<"\nMax value is defined by "<<MAX;
      break;;

default:cout<<"\nWrong choiced entered";
}
cout<<"Do you wish to continue?";
cin>>choice;
}while(choice=='y'||choice=='Y');}