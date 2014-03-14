#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

void create()
{clrscr();
 ofstream fout;
 fout.open("TRY.txt");
 char name[30],ch;
 int n;
 cout<<"enter the text";
 gets(name);
 fout<<name;
fout.close();}

void display()
{clrscr();
 ifstream fin;
 fin.open("TRY.txt");
  char name[30],ch;
 fin.seekg(0,ios::cur);
while(!fin.eof())
 {fin>>name;
cout<<name;
}
fin.close();
}

void replacech()
{clrscr();
char ch;
ifstream fin;
ofstream fout;
 fin.open("TRY.txt");
 fout.open("temp.txt");
 while(!fin.eof())
  {fin.get(ch);
  ++ch;
 fout<<ch;}
 fin.close();
 fout.close();
remove("TRY.txt");
rename("temp.txt","TRY.txt");
}

void uptolow()
{clrscr();
char ch;
 ifstream fin;
ofstream fout;
 fin.open("TRY.txt");
 fout.open("temp.txt");
while(!fin.eof())
{fin.get(ch);
 if(islower(ch))
   {ch=toupper(ch);
    fout<<ch;  }
 else
    fout<<ch;}
 fin.close();
 fout.close();
remove("TRY.txt");
rename("temp.txt","TRY.txt");
}


void main()
{clrscr();
int choice;
char chh;
do
{cout<<"******************MENU*******************";
  cout<<"\n\n1. CREATE FILE\n";
  cout<<"2. DISPLAY FILE\n";
  cout<<"3. REPLACE CHARACTER\n";
  cout<<"4. LOWER TO UPPER\n";

 cout<<"Enter the choice of task to perform: ";
 cin>>choice;
 switch(choice)
{ case 1:create();break;
  case 2:display();break;
  case 3:replacech();break;
  case 4:uptolow();break;
  default: cout<<"\nwrong choice entered";

}

 cout<<"\nDo you wish to continue?";
 cin>>chh;
}while(chh=='y'||chh=='Y');
}

