/*Q-19)   WRITE A PROGRAM TO SWAP 2 GIVEN NUMBERS USING POINTERS.    */

#include<iostream.h>
#include<conio.h>         //header files

void swap(int*, int*);    //prototype

void main()               //main
{
   clrscr();
   int a ,b;
   cout<<"\n enter the first number : " ;
   cin>>a;
   cout<<"\n enter the second number: ";           // function calling
   cin>>b;
   swap(&a,&b);                         
   cout<<"\n first number is : "<<a<<"\n second number is : "<<b;
}

void swap(int* x, int* y)               //func to swap the two no.s
{
  int temp;
  temp=*x;
  *x=*y;
  *y=temp;
}