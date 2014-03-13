2.  WAP to insert an element in a 1 D array of integers in the following ways:
i.   Insert at the end
ii.  Insert in the sorted array
iii. Insert at a particular position
iv.  Insert in the beginning



#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
int a[30];
int n;

void enter();
void insertbeg();
void insertend();
void insertsorted();                                   \\ function prototypes
void insertparticular();
void show();


void main(){                                           \\main function    
clrscr();
char ch;
int choice;
do{
cout<<"\nwelcome to c++";
cout<<"\n1.enter\n2.insert at end\n3.insert in sorted aray\n4.insert at particular position\n5.insert in the beginning\n6.show\n7.exit";
cout<<"\nenter your choice";
cin>>choice;
switch(choice)
{case 1:enter();break;
case 2:insertend();break;
case 3:insertsorted();break;                            \\switch statement
case 4:insertparticular();break;
case 5:insertbeg();break;
case 6:show();break;
case 7:exit(0);
default:cout<<"\nwrong choice entered";
}
cout<<"\ndo you wish to continue(y/n)";
cin>>ch;
}while(ch=='y');
}

void enter(){                                          \\enter function
cout<<"\nenter the no. of elements";
cin>>n;
cout<<"\nenter the values";
for(int i=0;i<n;i++)
cin>>a[i];}

void show(){                                          \\ show function
for(int i=0;i<n;i++)
cout<<a[i]<<' ';}

void insertend(){                                     \\ insertend function
int p;
cout<<"\nenter the element";
cin>>p;
n++;
a[n-1]=p;}

void insertsorted(){                                  \\ insertsorted func   
int temp;
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++)
if(a[j]>a[j+1])
{temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;}
cout<<"sorted";
int num,pos;
cout<<"enter the value";
cin>>num;
for(int l=0;l<n;l++)
if(num<a[l])
{pos=l;
break;}
n=n+1;
for(int k=n-1;k>pos-1;k--)
a[k]=a[k-1];
a[pos]=num;
}

void insertparticular(){                             \\insertparticular
int k,l;
cout<<"\nenter the particular position :";
cin>>k;cout<<"enter the no.";cin>>l; n=n+1;
for(int i=n-1;i>k-2;i--)
a[i]=a[i-1];
a[k-1]=l; }

void insertbeg()                                     \\insertbeg
{int k;
cout<<"\nenter the element";
cin>>k;
n=n+1;
for(int i=n-1;i>0;i--)
a[i]=a[i-1];
a[0]=k;
}