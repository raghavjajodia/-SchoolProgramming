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
 }

 int retmonth()
 { return(date.mm);}

 int retyear()
 { return(date.yy);}

 int retitemno()
 { return(itemno);}
 }i1,i2;


 void create();
 void check();
 void display();
 void insert();
 void modify();
 void del();


  void main()
 { clrscr();
  int choice;
 char ch;
 do
 {clrscr();
 cout<<"\n\t\t\t\t MENU ";
 cout<<"\n\t\t 1.CREATE ";
 cout<<"\n\t\t 2.CHECK ";
 cout<<"\n\t\t 3.INSERT ";
 cout<<"\n\t\t 4.MODIFY ";
 cout<<"\n\t\t 5.DELETE ";
 cout<<"\n\t\t 6.DISPLAY";
 cout<<"\n\t\t ENTER YOUR CHOICE ";
 cin>>choice;
 switch(choice)
 { case 1:create(); break;
   case 2:check(); break;
   case 3:insert(); break;
   case 4:modify();break;
   case 5:del(); break;
   case 6:display();break;
   default: cout<<"\n Wrong choice entered";
  }
  cout<<"\n\t\t DO YOU WANT TO CONTINUE..?";
  cin>>ch;
 }
 while(ch=='y'|| ch=='Y');
 }

 void create()
{
 fstream f1("item2.dat",ios::binary|ios::out);
  i1.getdata();

  f1.write((char*)&i1,sizeof(i1));
  f1.close();
 }

 void display()
 {clrscr();
 fstream f2("item2.dat",ios::binary|ios::in);
 while(f2.read((char*)&i1,sizeof(i1)))
 {i1.putdata();}
 f2.close();
 }

 void check()
 {int m, y, found=0;;
 cout<<"\nEnter the desired month and year ";
 cin>>m>>y;

 fstream f2("item2.dat",ios::binary|ios::in);
  while(f2.read((char*)&i1,sizeof(i1)))
   {if((m==i1.retmonth())&&(y==i1.retyear()))
     {i1.putdata();
      found=1;}
   }
  if(found==0)
   cout<<"\nRecord not found";
 f2.close();
 }
 

 void insert()
 {
 cout<<"\n ENTER DETAILS OF THE RECORD TO BE INSERTED \t";
 i2.getdata();
  char last='y';
  fstream f1("item2.dat",ios::binary|ios::in);
  fstream f2("temp.dat",ios::binary|ios::out);
   while(f1.read((char*)&i1,sizeof(i1)))
    {
    if(i1.retitemno()>=i2.retitemno())
     { f2.write((char*)&i2,sizeof(i2));
      last='n'; break;
     }
    else
     f2.write((char*)&i1,sizeof(i1));
    }
   if(last=='y')
    f2.write((char*)&i2,sizeof(i2));
   else
    while (!f1.eof())
    {
    f1.read((char*)&i1,sizeof(i1));
      f2.write((char*)&i1,sizeof(i1));
    }

  f1.close();
  f2.close();

 remove("item1.dat");
 rename("temp.dat","item1.dat");
  }


  void modify()
 { char choice;
  fstream fio("item2.dat",ios::binary|ios::in|ios::out);
 int pos,bc;
 cout<<"\n \t enter the itemno you want to modify... ";
 cin>>bc;
 while(!fio.eof())
 {
 pos=fio.tellg();
 fio.read((char*)&i1,sizeof(i1));
 if(bc==i1.retitemno())
 { cout<<"\n the old data is";
 i1.putdata();
 cout<<"\n DO YOU WANT TO MODIFY ? n\y";
 cin>>choice;
 if(choice=='y'|| choice=='Y')
 {
 fio.seekg(pos);
 i1.getdata();
 fio.write((char*)&i1, sizeof(i1));
 }
 }}
 fio.close();
 }

 void del()
 {
 int rn;
 char choice='y';
 fstream f1("item2.dat",ios::binary| ios::in);
 fstream f2("temp.dat", ios::binary|ios::out);
cout<<"\n enter the item you want to del";
 cin>>rn;
 while(f1.read((char*)&i1,sizeof(i1)))
 {
 if(rn==i1.retitemno())
 { 	cout<<"\n do you want to delete? ";
	cin>>choice;
	if(choice=='n'|| choice=='N')
		f2.write((char*)&i1, sizeof(i1) );
 }
       else
	f2.write((char*)&i1, sizeof(i1));
}
  remove("item2.dat");
 rename("temp.dat", "item2.dat");

f1.close();
}





