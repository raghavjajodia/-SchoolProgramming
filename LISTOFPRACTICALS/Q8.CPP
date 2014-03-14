/*Q8)  CONSIDER THE CLASSES: 
       class person
           { char name[20];
             protected:
             int age;
      public:
             void readdata();
             void dispdata();
         };
       class employee:public person
            {
           char department[20];
       protected:
           float salary;
       public:
            void read();
            void write();
            float retsal{retsal salary;}
            int retage(){return age;}
            int retdep(char*d)
            { if(strcmp(d,department)==0)
              return 1;
              else
              return 0;}
            };
complete the above classe and write main function having 5 employees(array of employee) and display a menu:
          1.create
          2.search on the basis of age
          3.search on the basis of department
          4.search on the basis of salary       */


#include<fstream.h>
#include<conio.h>
#include<string.h>       //header files
#include<stdio.h>

class person
{ char name[20];
protected:               //class definition
int age;
public:
void readdata()
{ cout<<"\n\t enter name: \t";
  gets(name);
  cout<<"\n\t enter age: \t";
  cin>>age;
}
void displaydata()
{ cout<<"\n the name is: \t";
  puts(name);
  cout<<"\n the age is: \t";
  cout<<age;
}
};

class employee:public person   
{ char department[20];

protected:
float salary;

public:
void reademp()
{ readdata();
 cout<<"\n enter the department: \n";
 gets(department);
 cout<<"\n enter the salary: \t";
  cin>>salary;
}

void writeemp()                // func to display employee details
{ displaydata();
 cout<<"\n the department is : \t";
  puts(department);
  cout<<"\n the salary is: \t";
  cout<<salary;
}

float retsal()                //func to return sal
{return salary;}

int retage()
{return age;}                //func to return age

int retdep(char*d)
{ if(strcmp(d,department)==0)   //func to return dept
  return 1;
  else
  return 0;
}
};
employee e[5];

void create();
void display();
void searchage();             //func prototypes
void searchdepartment();
void searchsalary();

void main()                   //main func
{ clrscr();
 int choice;
 char ch;
do
{
  cout<<"\n\t\t\t menu"<<"\n\t\t 1.create"<<"\n\t\t 2. dislpay data"<<"\n\t\t 3. search on basis of age";
  cout<<"\n\t\t 4.search on basis of department";
  cout<<"\n\t\t 5.search on basis of salary";
  cout<<"\n\n\t\t enter your choice =  ";
  cin>>choice;
switch(choice)
{
 case 1: create() ; break;
 case 2: display(); break;
 case 3: searchage() ;  break;
 case 4: searchdepartment()     ; break;
 case 5: searchsalary()     ; break;
 default: cout<<"\n wrong choice entered...!!";
}
 cout<<"\n\n Do you want to continue? n/y =  ";
 cin>>ch;
}
 while(ch=='y'||ch=='Y');
}

void create()              // func to read data     
{ for(int i=0; i<5;i++)                     
{ cout<<"enter the data of "<<i+1<<"object";
       e[i].reademp(); }}


 void searchage()            // searching the age
{ int x;
int found=0;
 cout<<"\n enter age";
 cin>>x;
 for(int i=0; i<5;i++)
 {
 if(x==e[i].retage())
 { e[i].writeemp();
  found=1;
 }
 }
 if(found==0)
 { cout<<"\n record not found..!!" ;
 }
}


 void searchdepartment()      // searching department
{ char dep[20];
  int found=2;
  cout<<"\n enter the department to be searched: \t";
  gets(dep);
  for(int j=0;j<5;j++)
  { if(e[j].retdep(dep))
    { e[j].writeemp();
    found=3;
    }
  }
  if(found==2)
  { cout<<"\n record not found..!!";
  }}

void searchsalary()         //searching salary
{ int y;
  int found=5;
  cout<<"\n enter salary to be searched: \t";
  cin>>y;
  for(int k=0; k<5;k++)
  { if(y==e[k].retsal())
   e[k].writeemp();
   found=6;
 }
 if(found==5)
 { cout<<"\n record not found...!! ";
 }

}

void display()               // display data
{ for(int k=0; k<5;k++)
  e[k].writeemp();
}