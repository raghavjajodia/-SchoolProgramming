#include<fstream.h>
#include<conio.h>
#include<stdio.h>
class stud
{ int rno;
char name[20];
public:
void enter()
{cout<<"\n enter the rol no ";
 cin>>rno;
 cout<<"\n enter the name ";
gets(name);
}

void display()
{ cout<<"\n the roll no is= "<<rno;
cout<<"\n the name is= ";
  puts(name);
}
int retrno()
{  return(rno);
}

}s1, s2;

 void create();
 void add();
 void del();
 void display();

 void main()
{
clrscr();
int choice;
char ch;
do
{
cout<<"\n\t\t\t MENU";
cout<<"\n\t 1.CREATE";
cout<<"\n\t 2.ADD";
cout<<"\n\t 3.DELETE";
cout<<"\n\t 4.DISPLAY";
cout<<"\n enter your choice";
cin>>choice;
switch(choice)
{ case 1:create() ;break;
  case 2:add() ;break;
  case 3:del() ;break;
  case 4:display() ;break;
  default: cout<<"\n wrong choice entered....!!";
}
cout<<"\t\n DO YOU WANT TO CONTINUE..?";
cin>>ch;
}
while(ch=='y'||ch=='Y');
}


void create()
{
fstream f1("stud.dat", ios::binary|ios::app);
s1.enter();
f1.write((char*)&s1, sizeof(s1) );
f1.close();

}


 void add()
 {
 cout<<"\n enter the detail to be inserted";
 s2.enter();
 char last='y';
 fstream f1("stud.dat",ios::binary|ios::in);
 fstream f2("temp.dat",ios::binary|ios::out);
 while(f1.read((char*)&s1,sizeof(s1)))
 { if(s1.retrno()>=s2.retrno())
  { f2.write((char*)&s2,sizeof(s2));
  last='n';
  break;
	 }
 else
 f2.write((char*)&s1,sizeof(s1));
 }

 if(last=='y')
 f2.write((char*)&s2,sizeof(s2));
 else
 while(!f1.eof())
 {
  f1.read((char*)&s1, sizeof(s1));
 f2.write((char*)&s1,sizeof(s1));
 }

 f1.close();
 f2.close();
   remove("stud.dat");
  rename("temp.dat","stud.dat");


 }

 void del()
 {
 int rn;
 char choice='y';
 fstream f3 ("stud.dat",ios::binary| ios::in);
 fstream ftemp("temp.dat", ios::binary|ios::out);
cout<<"\n enter the rno you want to del";
 cin>>rn;
 while(f3.read((char*)&s1, sizeof(s1)))
 {
 if(rn==s1.retrno())
 { 	cout<<"\n do you want to delete? ";
	cin>>choice;
	if(choice=='n'|| choice=='N')
		ftemp.write((char*)&s1, sizeof(s1) );
 }
       else
	ftemp.write((char*)&s1, sizeof(s1));
}
  remove("stud.dat");
 rename("temp.dat", "stud.dat");

f3.close();
}

   void display()
 {
 fstream f2("stud.dat", ios::binary|ios::in);
while(f2.read((char*)&s1, sizeof(s1)))
 s1.display();

      f2.close();
 }