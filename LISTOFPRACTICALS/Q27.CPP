/*Q-27)RECORD WISE INSERTION/DELETION/MODIFICATION)
Declare a class ITEM in C++, containing item name ( 20 characters), item number{ integer)
Price and DOP(a structure variable Of date type, where date is defined to represent date,
month and year). Write a menu driven program in C++ to do the following.
i. TO create a file ( by wn.ting as many recOrds as the user wants)
ii.      To read a file
iii.	 TO Display only thOse  records purchase on a user given month and year
iv.      Insert a record at nth position, accept n from user.
v.       Delete the first record
vi.      Delete the last recOrd
vii.     Delete the nth record
viii.	 Modify the first  record
ix.	 Modify fhe last record
x .      Modify the nth record






#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<process.h>

struct DOP
{int dd, mm, yy;};

class item
{ char itemnm[20];
 int itemno, price;
 DOP date;
 public:
 void getdata()
 { cout<<"\n the item name is: ";
   gets(itemnm);
   cout<<"\n the item no: ";
   cin>>itemno;
   cout<<"\n the price is: " ;
   cin>>price;
   cout<<"\nthe date of purchase is ";
   cin>>date.dd>>date.mm>>date.yy;
 }
 void putdata()
 { cout<<"\n the item name is: ";
   puts(itemnm);
   cout<<"\n the item no: "<<itemno;
   cout<<"\n the price is: " <<price;
   cout<<"\ndate of purchase is"<<date.dd<<date.mm<<date.yy;
 }

 int retmonth()
 { return(date.mm);}

 int retyear()
 { return(date.yy);}

 int retitemno()
 { return(itemno);}
 }i1,i2;
int count=0;

void create();
void display();
void search();
void insertn();
void delfirst();
void dellast();
void deln();
void modifyfirst();
void modifylast();
void modifyn();

void main()
 { clrscr();
  int choice;
 char ch;
 do
 {clrscr();
 cout<<"\n\t\t\t\t MENU ";
 cout<<"\n\t\t 1.CREATE ";
 cout<<"\n\t\t 2.SEARCH ";
 cout<<"\n\t\t 3.INSERT AT NTH POSN ";
 cout<<"\n\t\t 4.DELETE THE FIRST RECORD ";
 cout<<"\n\t\t 5.DELETE THE LAST RECORD ";
 cout<<"\n\t\t 6.DELETE THE nth RECORD";
 cout<<"\n\t\t 7.MODIFY THE FIRST RECORD";
 cout<<"\n\t\t 8.MODIFY THE LAST RECORD";
 cout<<"\n\t\t 9.MODIFY THE NTH RECORD";
 cout<<"\n\t\t 10.DISPLAY";
 cout<<"\n\t\t 11.Exit";
 cout<<"\n\t\t ENTER YOUR CHOICE ";
 cin>>choice;
 switch(choice)
 { case 1:create(); break;
   case 2:search(); break;
   case 3:insertn(); break;
   case 4:delfirst();break;
   case 5:dellast(); break;
   case 6:deln();break;
   case 7:modifyfirst();break;
   case 8:modifylast();break;
   case 9:modifyn();break;
   case 10:display();break;
   case 11:exit(0);
   default: cout<<"\n Wrong choice entered";
  }
  cout<<"\n\t\t DO YOU WANT TO CONTINUE..?";
  cin>>ch;
 }
 while(ch=='y'|| ch=='Y');
 }

 void create()
{
 fstream f1("item.dat",ios::binary|ios::out);
  i1.getdata();
  f1.write((char*)&i1,sizeof(i1));
  f1.close();
 }

 void display()
 {clrscr();
 fstream f2("item.dat",ios::binary|ios::in);
 while(f2.read((char*)&i1,sizeof(i1)))
 i1.putdata();
 f2.close();
 }

 void search()
 {int m, y, found=0;;
 cout<<"\nEnter the desired month and year ";
 cin>>m>>y;

 fstream f2("item.dat",ios::binary|ios::in);
  while(f2.read((char*)&i1,sizeof(i1)))
   {if((m==i1.retmonth())&&(y==i1.retyear()))
     {i1.putdata();
      found=1;}
   }
  if(found==0)
   cout<<"\nRecord not found";
 f2.close();
 }


 void insertn()
 {int n;
 cout<<"\n ENTER POSITION OF THE RECORD TO BE INSERTED \t";
 cin>>n;
  fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<n-1;i++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}
cout<<"enter the details";
i2.getdata();
f2.write((char*)&i2,sizeof(i2));
f2.seekg(-sizeof(i2),ios::cur);
for(int j=n;j<count;j++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
  }


  void modifyfirst()
  {fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<count;i++)
{if(i==0)
 {i2.getdata();
 f2.write((char*)&i2,sizeof(i2));
 f1.seekg(sizeof(i1),ios::beg);
 }
else
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));} }
cout<<"Done!!!!";

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
 }

void modifylast()
  {fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<count;i++)
{if(i==count-i)
 {i2.getdata();
 f2.write((char*)&i2,sizeof(i2));
  }
else
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));} }
cout<<"Done!!!!";

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
 }

  void modifyn()
 {int n;
 cout<<"\n ENTER POSITION OF THE RECORD TO BE MODIFIED \t";
 cin>>n;
  fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<count;i++)
{if(n-1==i)
 {i2.getdata();
 f2.write((char*)&i2,sizeof(i2));}
else
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));} }
cout<<"Done!!!!";

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
 }

 void delfirst()
 {  fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
f1.seekg(sizeof(i1),ios::beg);
for(int i=1;i<count;i++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}
cout<<"DELETED!!!!";

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
}

 void dellast()
 {  fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<count-1;i++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}
cout<<"DELETED!!!!";


  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
}

 void deln()
 {int n;
 cout<<"\n ENTER POSITION OF THE RECORD TO BE DELETED \t";
 cin>>n;
  fstream f1("item.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
   count++;
for(int i=0;i<n-1;i++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}
cout<<"DELETED!!!!";
f2.seekg(sizeof(i1),ios::cur);
for(int j=n-1;j<count;j++)
{f1.read((char*)&i1,sizeof(i1));
f2.write((char*)&i1,sizeof(i1));}

  f1.close();
  f2.close();

 remove("item.dat");
 rename("temp.dat","item.dat");
}





