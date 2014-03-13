/* Q 10)WRITE A PROGRAM TO PERFORM VARIOUS STACK OPERATION 
LIKE PUSH(),POP(),DISPLAY() ON A STATIC STACK.  */

#include<iostream.h>
#include<conio.h>
#include<process.h>      //header files
#include<stdio.h>
# define max 10

class stack{             // class defin for stack
int a[10];
int top;                 
public:
stack()
{
top=-1; }
void push();
void pop();
void display();
};
 
void stack::push(){       //func to push on stack
cout<<"enter the element";
int val;
if(top==(max-1))
cout<<"over flow error";
else{
cin>>val;
a[++top]=val;
}
}

void stack::pop(){        //popping elements from stack
if(top<0)
cout<<"underflow error";
else
{
cout<<"the deleted element is"<<a[top];
top--;
}
}

void stack::display()      //displaying elements of stack
{
for(int i=0;i<=top;i++)
cout<<a[i]<<" ";
}

void main()               //main function
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

