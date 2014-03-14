/*Q-14) EACH NODE OF A QUEUE CONTAINS BOOKNO,BOOKNAME,PRICE AND SUBJECT IN ADDITION TO THE POINTER FIELD. WRITE FUNCTIONS TO INSERT, DELETE,AND SHOW ALL THE 
ELEMENTS. ALSO WRITE A FUNCTION TO COUNT THOSE NODES OF THE QUEUE, WHOSE SUBJECT IS "SCIENCE"*/


#include<iostream.h>
#include<process.h>
#include<conio.h>            //header files
#include<stdio.h>
#include<string.h>

struct node
{
int bookno;
float price;
char booknm[20];
char subject[10];           //structure node
node*link;
};

class queue{
node*front,*rear;           //class queue
public:
queue()
{
front=rear=NULL;
}
void qins();
void qdel();
void qdisp();
void countsubject();
};

void main()                 //main func
{
queue s1;
clrscr();
int a;
char ch;
do{
cout<<"\t\t\t\tmain menu \n";
cout<<" \t\t\t\t1.insert into queue\n";
cout<<"\t\t\t\t2.delete from queue\n";
cout<<"\t\t\t\t3.display queue\n";
cout<<"\t\t\t\t4.countsubject\n";
cout<<"\t\t\t\t5.exit\n";
cout<<"enter the choice\n";
cin>>a;
switch(a)
{
case 1: s1.qins();break;
case 2: s1.qdel();break;
case 3: s1.qdisp();break;
case 4: s1.countsubject();break;
case 5: exit(0);break;
default:cout<<"wrong no entered";
}
cout<<"\n do you want to continue\t";
cin>>ch;
}
while(ch=='y');
}

void queue::qins()       //insert in queue
{
node*temp;
temp=new node;
if(temp==NULL)
cout<<"no space";
else
{
cout<<"enter bookno";
cin>>temp ->bookno;
cout<<"enter booknm";
gets(temp->booknm);
cout<<"enter price ";
cin>>temp->price;
cout<<"enter subject";
gets(temp->subject);
temp->link=NULL;
}
if(rear==NULL)
front=rear=temp;
else{
rear->link=temp;
rear=temp;
}}

void queue::qdel()       //delete from queue
{
node*temp;
if(front==NULL)
cout<<"queue empty";
else
{
temp=front;
front=front->link;
delete temp;
}
}

void queue::qdisp()      //displaying the queue
{
node*temp;
for(temp=front;temp!=NULL;temp=temp->link)
{
cout<<temp->bookno<<" ";
puts(temp->booknm);
cout<<temp->price<<"  ";
puts(temp->subject);
}
}

void queue::countsubject()   //counting no. of subjects
{
node*temp;
int c=0;
for(temp=front;temp!=NULL;temp=temp->link)

if(strcmp(temp->subject,"science")==0)
c++;
cout<<"The no of data related to science subject ="<<c;

}
