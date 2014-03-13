/* DEFINE FOLLOWING CLASS AND MAKE MENU DRIVEN PROGRAM FOR DOING VARIOUS OPERATIONS.
         class arr2d{
             int a[3][3];
             int m,n;
             public:
             void create2d();
             void show2d();
             void show2d_lower1();
             void show2d_lower2();
             void show2d_upper1();
             void show2d_upper2();
             void show2d_diagonal1();
             void show2d_diagonal2();
             };             */



#include<iostream.h>
#include<conio.h>
#include<process.h>                 //header files

class arr2d{
int a[3][3];
int m,n;                            //class arr 2d
public:
void create2d();
void show2d();
void show2d_lower1();
void show2d_lower2();
void show2d_upper1();
void show2d_upper2();
void show2d_diagonal1();            //member functions
void show2d_diagonal2();
};
arr2d s1;


void main()                        // void main
{
clrscr();
int a;
char ch;
do{
cout<<"\t\t\t\tmain menu \n";
cout<<" \t\t\t\t1.create 2d array\n";
cout<<"\t\t\t\t2.show array\n";
cout<<"\t\t\t\t3show lower1\n";
cout<<"\t\t\t\t4.show lower2\n";
cout<<"\t\t\t\t5.show upper1\n";
cout<<"\t\t\t\t6. show upper 2\n";
cout<<"\t\t\t\t7.show diagonal1\n";
cout<<"\t\t\t\t8.show diagonal2\n";
cout<<"enter the choice\n";
cin>>a;
switch(a)
{
case 1: s1.create2d();break;
case 2: s1.show2d();break;
case 3: s1.show2d_lower1();break;
case 4: s1.show2d_lower2();break;
case 5: s1.show2d_upper1();break;
case 6: s1.show2d_upper2();break;
case 7: s1.show2d_diagonal1();break;
case 8: s1.show2d_diagonal2();break;
case 9:exit(0);break;
default:cout<<"wrong no entered";
}
cout<<"\n do you want to continue\t";
cin>>ch;
}
while(ch=='y');
}

void arr2d::create2d()                            //create 2d
{
cout<<"enter the dimensions of matrix"<<endl;
cin>>m>>n;
if (m!=n){
cout<<"square matrix allowed";
exit(0);
}
else
{
cout<<"enter the elements\n";
for(int i=0;i<m;i++)
for(int j=0;j<n;j++)
cin>>a[i][j];
}
}

void arr2d::show2d()                             //show 2d
{
 cout<<"the matrix is\n";
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
cout<<a[i][j]<<" ";
cout<<endl;
}
}

void arr2d::show2d_lower1()                    //func to show lower part1 of matrix
{
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if(i>j)
cout<<a[i][j]<<" ";
else
cout<<" "<<" ";
cout<<endl;
}
}

void arr2d::show2d_lower2()                   // func to show lower part2 of matrix
{for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if(i+j>m-1)
cout<<a[i][j]<<" ";
else
cout<<" "<<" ";
cout<<endl;
}
}

void arr2d::show2d_upper1()                  // func to show upper part1 of matrix
{
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if(i<j)
cout<<a[i][j]<<endl;
}
}

void arr2d::show2d_upper2()                 // func to show upper part2 of matrix
{
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if((i+j)<m-1)
cout<<a[i][j]<<endl;
}
}

void arr2d::show2d_diagonal1()             // func to show upper part2 of matrix
{
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if(i==j)
cout<<a[i][j]<<endl;
}
}

void arr2d::show2d_diagonal2()           // func to show upper part2 of matrix
{
for(int i=0;i<m;i++)
{
for(int j=0;j<n;j++)
if((i+j)==m-1)
cout<<a[i][j]<<endl;
}}

