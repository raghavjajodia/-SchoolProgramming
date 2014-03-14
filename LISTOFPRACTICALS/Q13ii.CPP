/* Q-13) Each node of a stack, contains item no, item name and price in addition to the pointer
field. Write functions to insert, delete and show all the elements.  Also write a function to
count those nodes of the stack, whose price >100. */



#include<iostream.h>               //header files
#include<conio.h>
#include<process.h>


struct Node{                        //structure node
 int itemno;
 char itemnm[10];
 float price;
 Node *next;}

class Mynode                        //class mynode
{ Node *top;
  public: 
   Mynode()
 {top=NULL;}
  void insert(int ele);
  void delete();
  void display();
  void calculate();
};

void Mynode::insert()                //function to insert
{ Node *temp;
  temp=new Node;
 if(temp==NULL)
  {cout<<"ABORT!!!! stack overflow";
      exit(0);}
 
   cin>>temp->itemno;
   gets(temp->itemnm);
   cin(temp->marks);
     temp->next=NULL;

    if(top==NULL)
       {top=temp;}
    else
       {temp->next=top;
         top=temp;}
}

void Mynode::delete()                 //function to delete
{ Node *temp;
 if(top=NULL)
  {cout<<"ABORT!!!!....Underflow error";
    exit(0);}
 else 
   {temp=top;
    top=top->next;
    cout<<"\nthe record to be deleted is ";
    cout<<endl<<temp->itemno;
    cout<<endl;
    gets(temp->itemnm);
    cout<<endl<<temp->price;
   cout<<"\nDo you want to confirm delete?";
   cin>>ch;
    if(ch=='y'||ch='Y')
      delete temp;
   } 
 }   

void Mynode::display()              //function to display
{Node *temp=top;
 cout<<"\nDisplaying stack...";
  for(;temp!=NULL;temp=temp->next)
   {cout<<endl<<temp->itemno;
    cout<<endl;
    gets(temp->itemnm);
    cout<<endl<<temp->price;}
}
 
void Mynode::calculate()            //function to calculate nodes
{Node *temp=top;
  int count=0;
 cout<<"\nDisplaying Records for which price>100";
  for(;temp!=NULL;temp=temp->next)
   {if(temp->price>100)
     count++;}
 if(count==0)
   cout<<"\nNO item has price>100";
}

void main()                         //main function
{clrscr();
 Mynode s;
 do
{ clrscr();
  cout<<"\t\t\t\t\t\tMENU";
  cout<<"\n1. INSERT";
  cout<<"\n2. DELETE";
  cout<<"\n3. DISPLAY";
  cout<<"\n4. CHECK FOR PRICING";
 cin>>ch;
 switch(ch)
{ case 1: s.insert();break;
  case 2: s.delete();break;
  case 3: s.display();break;
  case 4: s.calculate();break;
  default: cout<<"wrong choice entered";}

cout<<"Do you wish to continue??";
cin>>ch;
}while(ch=='y'||ch='Y');
}






  
  
   