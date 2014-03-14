/*
Q-11) WRITE A PROGRAM TO PERFORM VARIOUS QUEUE OPERATIONS 
LIKE INSERT(), DELETE(), DISPLAY() ON A CIRCULAR QUEUE(ARRAY).*/

#include<iostream.h>
#include<conio.h>
#include<process.h>    //header files
#include<stdio.h>
#define Max 15

class cqueue{
int a[Max],front,rear;
public:                // class queue
cqueue(){
front=rear=-1;}
void insert();
void deleteq();
void display();
};

void cqueue::insert()   //insertng in queue
{
if((front==0)&&(rear==Max-1)||(rear+1)==front)
cout<<"circular queue is full";
else
{
if(rear==(Max-1))
rear=0;
else
rear++;
cin>>a[rear];
}
if(front==-1)
front=0;
}

void cqueue::deleteq()   //deleting from queue
{
if(front==-1)
cout<<"queue is empty";
else
if(front==rear)
front=rear=-1;
else
{
if(front==(Max-1))
front=0;
else
front++;
}
}

void cqueue::display()    //displaying elements of queue
{
int i;
if(front==-1)
cout<<"circular queue is empty";
else
{
if(rear<front)
{
for(i=front;i<=Max-1;i++)
cout<<a[i]<<" ";
for(i=0;i<=rear;i++)
cout<<a[i]<<" ";}
else
{
for(i=front;i<=rear;i++)
cout<<a[i]<<" ";
cout<<endl;
}
}
}

void main()              //main function
{
cqueue s1;
clrscr();
int a;
char ch;
do{
cout<<"\t\t\t\tmain menu \n";
cout<<" \t\t\t\t1.insert into queue\n";
cout<<"\t\t\t\t2.delete from queue\n";
cout<<"\t\t\t\t3.display queue\n";
cout<<"\t\t\t\t4.exit\n";
cout<<"enter the choice\n";
cin>>a;
switch(a)
{
case 1: s1.insert();break;
case 2: s1.deleteq();break;
case 3: s1.display();break;
case 4: exit(0);break;
default:cout<<"wrong no entered";
}
cout<<"\n do you want to continue\t";
cin>>ch;
}
while(ch=='y');
}
