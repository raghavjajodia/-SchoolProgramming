Q-26)Declare a class ITEM in C++, containing item name ( 20 characters), item number(integer)
and Price. Write a menu driven program in C++ to  the following.
i.       TO create a file
ii.	 To read a file
iii.	 Display the item name fOr a given item no. if the record does nOt exists then displaY the
         error message "Record not found"
iv.	Arrange the file in ascending order Of priCe.




#include<fstream.h>           //header files
#include<conio.h>
#include<stdio.h>
#include<process.h>

class item                    //class definition for item
{ char itemnm[20];
 int itemno, price;
 public:
void getdata()
 { cout<<"\n the item name is: ";
   gets(itemnm);
   cout<<"\n the item no: ";
   cin>>itemno;
   cout<<"\n the price is: " ;
   cin>>price;
 }
void putdata()
 { cout<<"\n the item name is: ";
   puts(itemnm);
   cout<<"\n the item no: "<<itemno;
   cout<<"\n the price is: " <<price;
 }
char* retitemnm()
 { return(itemnm);}

int retitemno()
 { return(itemno);}
 } i1,i2;

 void create();             //function prototypes
 void search();
 void display();



void main()                 //main func
{ clrscr();
  int choice;
  char ch;
  do
 {
 cout<<"\n\t\t\t\t MENU ";
 cout<<"\n\t\t 1.CREATE ";
 cout<<"\n\t\t 2. SEARCH ";
 cout<<"\n\t\t 3.DISPLAY ";
 cout<<"\n\t\t 4.EXIT ";
 cout<<"\n\t\t ENTER YOUR CHOICE ";
 cin>>choice;
 switch(choice)
 { case 1:create(); break;
   case 2: search(); break;
   case 3: display();break;
   case 4: exit(0); break;
   default: cout<<"\n Wrong choice entered";
  }
cout<<"\n\t\t DO YOU WANT TO CONTINUE..?";
cin>>ch;
 }
while(ch=='y'|| ch=='Y');
 }
                              //func to create file
 void create()               
{  fstream f1("item1.dat",ios::binary|ios::out);
   i1.getdata();
   f1.write((char*)&i1,sizeof(i1));
   f1.close();
}

 void display()               //func to display file
 {
 fstream f2("item1.dat",ios::binary|ios::in);
 while(f2.read((char*)&i1,sizeof(i1)))
 {i1.putdata();}
 }



  void search()               //func search
 { int x, found=0;
  cout<<"\n\n Enter the itemno you want to search = ";
  cin>>x;
  fstream f1 ("item1.dat", ios::in| ios::binary);
  while(f1.read((char*)&i1 , sizeof(i1)))
 {
  if (x==i1.retitemno())
 {cout<<"record found";cout<<i1.retitemnm();
  found=1;
 }
 }
 if (found==0)
 cout<<"\n\n\t DATA NOT FOUND...!! ";
 f1.close();
 }

