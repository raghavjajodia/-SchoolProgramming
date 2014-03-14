/*---------------------------------------------------
Q7) 	   Payroll Management System
  ---------------------------------------------------*/

#include<iostream.h>
#include<conio.h>
#include<iomanip.h>
#include<string.h>
#include<stdio.h>
#include<process.h>


class employee             //this class defines data related to monthly pay file
{
private:
int empno;                 //base class
char name[25];
float basic;
char address[30];
char pin[20];
float hrarate,darate,pfrate,hra,da,pf,gross,net;
void calculate()
{hra=(hrarate*basic)/100;
da=(darate*basic)/100;
pf=(pfrate*basic)/100;
gross=hra+da+pf;
net=basic-gross;}

public:
employee()                //no arguments constructor
{}
void readdata();          //this function reads the private members of employee
char* retename();         //this function returns empname
void displaydata();
int reteno();
		           //this function shows data of of object
};
employee data[10];
int n;

		           //this function reads data
void employee::readdata()
{
 clrscr();
 cout<<"\n ENTER THE EMPLOYEE NO.------------------>";
 cin>>empno;
 cout<<"\n ENTER THE NAME-------------------------->";
 gets(name);
 cout<<"\n ENTER THE BASIC SALARY------------------>";
 cin>>basic;
  cout<<"\n ENTER THE HOUSE RENTAL ALLOWANCE RATE-------------->";
 cin>>hrarate;
 cout<<"\n ENTER THE PF. rate--------------->";
 cin>>pfrate;
 cout<<"\n ENTER THE DA rate--------------->";
 cin>>darate;
 calculate();
}

//this function displays data
void employee::displaydata()
{
// clrscr();
 cout<<"\n EMPLOYEE NO.--------------------->"<<empno;
 cout<<"\n EMPLOYEE's NAME------------------>";puts(name);
 cout<<"\n BASIC SALARY--------------------->"<<puts(address);
 cout<<"\n HOUSE RENTAL ALLOWANCE----------->"<<hra;
 cout<<"\n PF--------------------->"<<pf;
 cout<<"\n DA--------------------->"<<da;
 cout<<"\n GROSS------------------>"<<gross;
 cout<<"\n NET-------------------->"<<net;
 cout<<"\n\n\n";
 }
int employee::reteno()
{return(empno);}

char* employee::retename()
{return(name);}

					    //this is the main function
void main()
{clrscr();
 int choice,num;
 char ch;
 char ename[20];
 do
 {                                              //display main menu


  cout<<"   MAIN MENU   ";
  cout<<"-----------------------\n";
  cout<<"ADD NEW EMPLOYEES          ....1\n";
  cout<<"ENTER EMPNO AND DISPLAY EMPLOYEE NAME   ....2\n";
  cout<<"SEARCH INFORMATION ABOUT EMPLOYEE BY NAME ....3\n";
  cout<<"SHOW DATA                                ....4\n";
  cout<<"EXIT                                     ....5\n";
  cout<<"ENTER YOUR CHOICE NO.-------------->";

cin>>choice;
switch(choice)
{
case 1 :cout<<"enter the no. of  employee data you want to enter";
cin>>n;
for(int i=0;i<n;i++)
data[i].readdata();
;break;             //call function to create the file

case 4 :for(int j=0;j<n;j++)
data[j].displaydata();break;                  //call function to delete the record of employee

case 2 :cout<<"enter num";
cin>>num;
for(int k=0;k<n;k++)
{if(data[k].reteno()==num)
puts(data[k].retename());
break;}
break;               //this function can modify information

case 3 :cout<<"enter name";
gets(ename);
for(int l=0;l<n;l++)
if(strcmp(data[l].retename(),ename)==0)
{data[l].displaydata();
break;}
break;               //this function searches information

case 5 :exit(0);break;          //this function generate  reports

default: cout<<"wrong choice entered";
  }
 cout<<"do you wish to continue?(y/n)";
 cin>>ch;
 }while(ch=='y');
}
