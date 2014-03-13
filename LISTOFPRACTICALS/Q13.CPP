/* Q-13) WRITE A PROGRAM TO PERFORM VARIOUS QUEUE OPERATIONS
LIKE INSERT(),DELETE(),DISPLAY() ON A LINKED QUEUE HAVING 1 INTEGER AND 1 FLOATING TYPE DATA.
                        struct node
                        {
                         int x;
                         float y;
                         node*link;
                               };         */

#include<iostream.h>
#include<process.h>
#include<conio.h>

struct node            //structure node
{
int x;
float y;
node*link;
};

class queue{           //class def for queue
node*front,*rear;
public:
queue()
{
front=rear=NULL;
}
void qins();
void qdel();
void qdisp();
};

void main()            //main
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
cout<<"\t\t\t\t4.exit\n";
cout<<"enter the choice\n";
cin>>a;
switch(a)
{
case 1: s1.qins();break;
case 2: s1.qdel();break;
case 3: s1.qdisp();break;
case 4: exit(0);break;
default:cout<<"wrong no entered";
}
cout<<"\n do you want to continue\t";
cin>>ch;
}
while(ch=='y');
}

void queue::qins()      //inserting in queue
{
node*temp;
temp=new node;
if(temp==NULL)
cout<<"no space";
else
{
cout<<"enter x";
cin>>temp->x;
cout<<"enter y";
cin>>temp->y;
temp->link=NULL;
}
if(rear==NULL)
front=rear=temp;
else{
rear->link=temp;
rear=temp;
}}

void queue::qdel()      //delete from queue
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

void queue::qdisp()     //display elements of queue
{
node*temp;
for(temp=front;temp!=NULL;temp=temp->link)
{
cout<<temp->x;
cout<<temp->y;
}
}
