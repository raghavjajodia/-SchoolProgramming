/*Q-12) WRITE A PROGRAM TO PERFORM VARIOUS STACK OPERATIONS 
LIKE PUSH(),POP(),DISPLAY()ON A LINKED STACK HAVING FOLLOWING NODE STRUCTURE:-
        ROLLNO  INTEGER
        AGE     INTEGER      */



#include<iostream.h>
#include<conio.h>
#include<process.h>       //header
#include<stdio.h>

struct node{             //struct def for node
int rollno;
int age;
node *next;
};

class stack{              //class def for stack
node *top;
public:
stack()
{
top=NULL; }
void push();
void pop();
void display();
};

void stack::push(){       //pushing elements on stack
node *temp;
temp=new node;
if(temp==NULL){
cout<<"no free space available...overflow";
exit(0);
}
cout<<"enter the roll no";
cin>>temp->rollno;
cout<<"\n enter the age ";
cin>>temp->age;
temp->next=NULL;
if(top==NULL)
top=temp;
else
{ temp->next=top;
  top=temp;
}
}

void stack::pop(){          //func to pop out elements
node *temp;
if(top==NULL){
cout<<"no node to delete!!!underflow";
exit(0);}
else{
temp=top;
top=top->next;
delete temp;
}   }

void stack:: display(){     //display func
node *temp;
for(temp=top;temp!=NULL;temp=temp->next)
cout<<"the roll no is "<<temp->rollno<<"and age is "<<temp->age<<endl;}

void main()                //main func
{
stack s1;
clrscr();
int a;
char ch;
do{
cout<<"\t\t\t\tmain menu \n";
cout<<" \t\t\t\t1.insert into stack\n";
cout<<"\t\t\t\t2.delete from stack\n";
cout<<"\t\t\t\t3.display stack\n";
cout<<"\t\t\t\t4.exit\n";
cout<<"enter the choice\n";
cin>>a;
switch(a)
{
case 1: s1.push();break;
case 2: s1.pop();break;
case 3: s1.display();break;
case 4: exit(0);break;
default:cout<<"wrong no entered";
}
cout<<"\n do you want to continue\t";
cin>>ch;
}
while(ch=='y');
}

