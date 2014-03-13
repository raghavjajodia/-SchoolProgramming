3. WAP to delete an element from a I D array of integers in the following ways:
i.   Delete` from the end
ii,  Delete from the sorted array
iif. Delete from a particular position
iv.  Delete from the beginning





#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>
int a[30];
int n;

void enter();
void deletebeg();
void deleteend();
void deletesorted();                                        //function prototypes
void deleteparticular();
void show();


void main(){                                               //main
clrscr();
char ch;
int choice;
do{
cout<<"\nwelcome to c++";
cout<<"\n1.enter\n2.delete at end\n3.delete in sorted aray\n4.delete at particular position\n5.delete in the beginning\n6.show\n7.exit";
cout<<"\nenter your choice";
cin>>choice;
switch(choice)
{case 1:enter();break;
case 2:deleteend();break;
case 3:deletesorted();break;                                
case 4:deleteparticular();break;
case 5:deletebeg();break;
case 6:show();break;
case 7:exit(0);
default:cout<<"\nwrong choice entered";
}
cout<<"\ndo you wish to continue(y/n)";
cin>>ch;
}while(ch=='y');
}

void enter(){
cout<<"\nenter the no. of elements";                         \\function enter
cin>>n;
cout<<"\nenter the values";
for(int i=0;i<n;i++)
cin>>a[i];}

void show(){                                                 \\function show
for(int i=0;i<n;i++)
cout<<a[i]<<' ';}

void deleteend(){                                            \\function delete
n--;
cout<<"deleted";}

void deletesorted(){                                         \\function deletesorted
int temp;
for(int i=0;i<n;i++)
for(int j=0;j<n-i-1;j++)
if(a[j]>a[j+1])
{temp=a[j+1];
a[j+1]=a[j];
a[j]=temp;}
cout<<"sorted";
cout<<"enter the no. to be deleted";
int pos,num;
cin>>num;
for(int l=0;l<n;l++)
if(num==a[l])
{pos=l;
break;}
for(int k=pos;k<n-1;k++)
a[k]=a[k+1];
--n;
cout<<"deleted";

}

void deleteparticular(){                                    \\function delete particlar
int k,l;
cout<<"\nenter the particular position :";
cin>>k;
for(int i=k-1;i<n-1;i++)
a[i]=a[i+1];
--n;
cout<<"deleted";}

void deletebeg()                                            \\delete beginning
{for(int i=0;i<n-1;i++)
a[i]=a[i+1];
--n;
cout<<"deleted";
}