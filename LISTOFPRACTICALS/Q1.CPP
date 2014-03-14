Q1)
WAP to arrange the array of structure student using Bubble/insertion/Selection Sort in
1. Descending order Of marks
2. Ascending oraer of roll no                 ~
3. Alphabetically arranged on name.
The structure  is as follows:
stfucf Student{ 
int roll no;
char name[20];
float marks;
}:


#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
/*array of structure student: sort:: descending, ascending, alphabetic arrangement on name*/

struct student
{int rollno;
char name[20];
float marks;};
student stud[20];
int n;

void enter()
{cout<<"Enter the no. of values";
cin>>n;
for(int i=0;i<n;i++)
{cout<<"Enter rollno \n";
cin>>stud[i].rollno;
cout<<"Enter name \n";
gets(stud[i].name);
cout<<"Enter marks \n";
cin>>stud[i].marks;
}
cout<<"\n_____________________________________________________\n";}

void display()
{for(int i=0;i<n;i++)
{cout<<endl<<stud[i].rollno<<endl;
puts(stud[i].name);
cout<<stud[i].marks<<endl;}}

void descend()
{student temp;
int max,pos;                                                   //BY SELECTION SORT
for(int i=0;i<n;i++)
{ max= stud[i].rollno;
  for(int j=i+1;j<n;j++)
   {if(stud[j].rollno>max)
      {max=stud[j].rollno;
       pos=j;}
                 }
 temp=stud[i];
 stud[i]=stud[pos];
 stud[pos]=temp;
  }
}

void ascend()                                                  //BY INSERTION SORT
{student temp;
int i,j;                      
for(i=1;i<n;i++)
    {temp=stud[i];
       j=i-1;
      while((temp.rollno<stud[j].rollno)&&(j>=0))
         {stud[j+1]=stud[j];
                     j=j-1;}
      stud[j+1]=temp;
       }
   cout<<"Sorting done";}

void alphaarr()                                                //BY BUBBLE SORT
{int i,j;
student temp;
for(i=0;i<n;i++)
{ for(j=0;j<n-i-1;j++)
 {if((strcmp(stud[j].name,stud[j+1].name))>0)
  {temp=stud[j];
   stud[j]=stud[j+1];
    stud[j+1]=temp;} }
   }
    }


void main()
{
clrscr();
int choice;
char ch;
do{clrscr();
cout<<"*******************MENU TO C++******************\n";
cout<<"\t\t\t1.Entering\n";
cout<<"\t\t\t2.Display\n";
cout<<"\t\t\t3.Ascend\n";
cout<<"\t\t\t4.Descend\n";
cout<<"\t\t\t5.Alphabetic Arrangement\n";


cout<<"Enter the choice\n";cin>>choice;
switch(choice)
{case 1:cout<<"entering values\n";
	enter();break;
case 2:cout<<"display";display();break;

case 3:cout<<"ascending\n";
       ascend();break;

case 4:cout<<"descending\n";
    descend(); break;

case 5:cout<<"alphabetic arrangement\n";
     alphaarr();
                 break;

default : cout<<"wrong choice";
};
cout<<"do you wish to continue? ";
cin>>ch;
}
while(ch=='y');}