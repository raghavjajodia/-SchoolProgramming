#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<string.h>
#include<stdio.h>
#include<ctype.h>
#include<math.h>
void create();
void display();
void vowels();
void uppercase();
void digits();
void words();
void lines();


int rollno,marks,n;
char name[30];

void main()
{
clrscr();
int choice;
char ch;
do{clrscr();
cout<<"\n MENU ";
cout<<"\n 1.CREATE";
cout<<"\n 2.DISPLAY";
cout<<"\n 3.NO OF UPPER CASE CHARACTERS ";
cout<<"\n 4.NO OF VOWELS";
cout<<"\n 5.NO OF DIGITS";
cout<<"\n 6.NO OF WORDS";
cout<<"\n 7.NUMBER OF LINES";
cout<<"\n enter ur choice";
cin>>choice;
switch(choice)
{
case 1:create();break;
case 2:display();break;
case 3:uppercase();break;
case 4:vowels();break;
case 5:digits();break;
case 6:words();break;
case 7:lines();break;
default: cout<<"\n wrong choice entered..!!";
}
cout<<"\n do you want to continue...??";
cin>>ch;
}
while(ch=='y'||ch=='Y');
}

void create()
{
char ch[30];
ofstream f1("marks.txt");
cout<<"enter";
gets(ch);
f1<<ch;
f1.close();
}

void display()
{ char ch;
ifstream f2("marks.txt");
while(!f2.eof())
{f2>>ch;
cout<<ch;}
f2.close();
}

//no of words
void words()
{
char ch[80];
int count;
ifstream f1("marks.txt");
while(!f1.eof())
{ f1>>ch;
 count++;
}
cout<<"\n the number of words are: "<<count;
f1.close();
}


void lines()
{
char ch[50];int count2=0;
ifstream f1("marks.txt");
while(!f1.eof())
{ f1.getline(ch,80);
count2++;
}
cout<<"\n no. of lines: "<<count2;
f1.close();
}


//no of vowels
void vowels()
{
int count=0;
char ch;
ifstream f1("marks.txt");
while(!f1.eof())

{f1>>ch;
 switch(ch)
  {case 'a':count++;break;
  case 'e':count++;break;
  case 'i':count++;break;
  case 'o':count++;break;
  case 'u':count++;break;
  case 'A':count++;break;
  case 'E':count++;break;
  case 'I':count++;break;
  case 'O':count++;break;
  case 'U':count++;break;
  }

  }
  cout<<"\n no of vowels are: "<<count;
  f1.close();
}


  // count no of digits
  void digits()
  {
  int count4=0;
  char ch;
  ifstream f1("marks.txt");
  while(!f1.eof())
  { f1>>ch;
  if(isdigit(ch))
  { count4++;
  cout<<ch;
  }
  }
  cout<<"\n the no of digits are: "<<count4;
  f1.close();
  }


  //no of uppercase character
  void uppercase()
  {
int count=0;
char ch;
ifstream f1("marks.txt");
while(!f1.eof())
{f1>>ch; 
if (isupper(ch))
  count++;}
  cout<<"\n no of uppercase alphabets are: "<<count;
   f1.close();
   }





