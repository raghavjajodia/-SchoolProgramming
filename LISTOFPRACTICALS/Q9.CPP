#include<fstream.h>
#include<conio.h>
#include<stdio.h>

class account
{ int accountno;
  char custname[50];
  int balance;
  public:
  void getdata()
  {cout<<"\n enter account number: ";
  cin>>accountno;
  cout<<"\n enter customer name: ";
  puts(custname);
  cout<<"\n enter balance: ";
  cin>>balance;
  }
  void putdata()
  { cout<<"\n account number: ";
  cout<<accountno;
  cout<<"\n customer name: ";
  puts(custname);
  cout<<"\n balance: ";
  cout<<balance;
 }
 };

 class transaction: private account
 {
