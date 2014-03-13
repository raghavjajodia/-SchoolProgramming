/* WRITE A PROGRAM TO CREATE AN EMPLOYEE CLASS HAVING THE FOLLOWINF DATA MEMBERS
PRIVATE  DATA MEMBERS ARE
EMP NO    INTEGER
NAME      CHARACTER
ADDRESS   CHARACTER
PINCODE   CHARACTER
BASIC     FLOAT
HRA       FLOAT
DA        FLOAT
PF        FLOAT
PUBLIC MEMBERS ARE:
READDATA()
RETEMPNO()
RETEMPNM()
SHOWDATA(()
DISPLAY THE FOLLOWING MENU
CREATE
ADD
MODIFY
SEARCH ON THE BASIS OF EMPLOYEE NO AND NAME         */










#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<string.h>
class employee
{ int empno;
  char empnm[20];
  char address[30], pincode[8];
  float basic, hra, da, pf;
  public:
  void readdata()
  {cout<<"employee no. ";
  cin>>empno;
  cout<<"\n enter name " ;
  gets(empnm);
  cout<<"\n enter address ";
  gets(address);
  cout<<"\n enter pincode ";
  gets(pincode);
  cout<<"\n enter basic ";
  cin>>basic;
  cout<<"\n enter hra ";
  cin>>hra;
  cout<<"\n enter da ";
  cin>>da;
  cout<<"\n enter pf ";
  cin>>pf;
  }

  int retempno()
 {return(empno);}

  char* retempnm()
  { return(empnm);}

  void showdata()
  { cout<<"\n empno is "<<empno;
  cout<<"\n name is ";
  puts(empnm);
  cout<<"\n address is ";
  puts(address);
  cout<<"\n pincode is ";
  puts(pincode);
  cout<<"\n basic "<<basic;
  cout<<"\n hra "<<hra;
  cout<<"\n da "<<da;
  cout<<"\n pf "<<pf;
 }
 }e1,e2;

 void create();
 void add();
 void modify();
 void search();
// void sort();
 void display();

 void main()
 { clrscr();
  int choice;
 char ch;
 do
 {
 cout<<"\n\t\t\t\t MENU ";
 cout<<"\n\t\t 1.CREATE ";
 cout<<"\n\t\t 2.ADD ";
 cout<<"\n\t\t 3.MODIFY ";
 cout<<"\n\t\t 4.SEARCH ";
//  cout<<"\n\t\t 5.SORT ";
 cout<<"\n\t\t 5.DISPLAY ";
 cout<<"\n\t\t 6.EXIT ";
 cout<<"\n\t\t ENTER YOUR CHOICE ";
 cin>>choice;
 switch(choice)
 { case 1:create(); break;
   case 2: add();  break;
   case 3: modify(); break;
   case 4: search(); break;
  // case 5:sort(); break;
   case 5: display();break;
   case 6: exit(0); break;
   default: cout<<"\n Wrong choice entered";
  }
  cout<<"\n\t\t DO YOU WANT TO CONTINUE..?";
  cin>>ch;
 }
 while(ch=='y'|| ch=='Y');
 }

 void create()
 { fstream f1("emp1.dat",ios::binary|ios::beg);
 e1.readdata();

 f1.write((char*)&e1,sizeof(e1));
 f1.close();
 }

 void display()
 {
 fstream f2("emp1.dat",ios::binary|ios::in);
 while(f2.read((char*)&e1,sizeof(e1)))
 {e1.showdata();}

 }




  void search()
 { int c;
  void searchempno();
 void searchempnm();
  cout<<"\n\t\t SEARCH ON THE BASIS OF \n";
  cout<<"\t\t 1.empno \n ";
  cout<<"\t\t 2. empnm \n";
  cout<<"\t enter your choice \t";
  cin>>c;
  switch(c)
  { case 1: searchempno();  break;
    case 2: searchempnm();  break;
    default : cout<<"\n wrong choice entered (n\y)";
  }
  }

  void searchempno()
  {
  int x, found=0;
  cout<<"\n\n Enter the empno you want to search = ";
  cin>>x;
    fstream f1 ("emp1.dat", ios::in| ios::binary);
  while(f1.read((char*)&e1 , sizeof(e1)))
 {
  if (x==e1.retempno())
 { e1.showdata();
  found=1;
 }
 }
 if (found==0)
 cout<<"\n\n\t DATA NOT FOUND...!! ";
 f1.close();
 }

 void searchempnm()
 {
 int x, found=0;
 char ch[20];
 cout<<"\n\n\t ENTER EMPLOYEE NAME TO BE SEARCHED ";
 gets(ch);
 fstream f1("emp1.dat",ios::in|ios::binary);
 while(f1.read((char*)&e1,sizeof(e1)))
 { if(strcmp(ch,e1.retempnm())==0)
   { e1.showdata();
   found=1;
   }
 }
 if(found==0)
 cout<<"\n\t RECORD NOT FOUND...!! \t";
 }



  void modify()
 { char choice;
  fstream fio("emp1.dat",ios::binary|ios::in|ios::out);
 int pos,bc;
 cout<<"\n \t enter the empno you want to modify... ";
 cin>>bc;
 while(!fio.eof())
 {
 pos=fio.tellg();
 fio.read((char*)&e1,sizeof(e1));
 if(bc==e1.retempno())
 { cout<<"\n the old data is";
 e1.showdata();
 cout<<"\n DO YOU WANT TO MODIFY ? n\y";
 cin>>choice;
 if(choice=='y'|| choice=='Y')
 {
 fio.seekg(pos);
 e1.readdata();
 fio.write((char*)&e1, sizeof(e1));
 }
 }}
 fio.close();
 }



   void add()
    {
    cout<<"\n ENTER DETAILS OF THE RECORD TO BE INSERTED \t";
   e2.readdata();
    char last='y';
    fstream f1("emp1.dat",ios::binary|ios::in);
    fstream f2("temp.dat",ios::binary|ios::out);
    while(f1.read((char*)&e1,sizeof(e1)))
    {
    if(e1.retempno()>=e2.retempno())
    { f2.write((char*)&e2,sizeof(e2));
    last='n'; break;
    }
    else
    f2.write((char*)&e1,sizeof(e1));
    }
    if(last=='y')
    f2.write((char*)&e2,sizeof(e2));
    else
    while (!f1.eof())
    {
    f1.read((char*)&e1,sizeof(e1));
      f2.write((char*)&e1,sizeof(e1));
    }

    f1.close();
    f2.close();

   remove("emp1.dat");
     rename("temp.dat","emp1.dat");

    }


