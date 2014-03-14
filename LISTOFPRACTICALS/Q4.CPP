/* WRITE A PROGRAM TO PERFORM THE FOLLOWING FUNCTIONS ON A 2D ARRAY OF SIZE MxM.
	     1.ADDITION OF 2 MATRICES
	     2.SUBTRACTION OF 2 MATRICES
	     3.MULTIPLICATION OF 2 MATRICES
	     4.TRANSPOSE OF 2 MATRICES
	     5.PRINT AND SUM OF BOTH DIAGONAL ELEMENTS  */


#include<iostream.h>
#include<string.h>                                  // header files
#include<conio.h>
#include<ctype.h>
int a[10][10], b[10][10],n;


void enter();
void display();                                     //function prototypes
void add();
void subtract();
void transpose();
void multiply();
void prints();

void enter()
{cout<<"enter the dimension";
 cin>>n;
 cout<<"entering for first matrix";                 //function to enter values
 for(int i=0;i<n;i++)
  for(int j=0;j<n;j++)
  {cin>>a[i][j];}
 cout<<"entering for second matrix";
 for(int v=0;v<n;v++)
  for(int u=0;u<n;u++)
  {cin>>b[v][u];}}

void display()
{cout<<"displaying matrices";
cout<<"matrix 1";                                   //function to display values
 for(int i=0;i<n;i++)
 { for(int j=0;j<n;j++)
  {cout<<a[i][j]<<" ";}
  cout<<endl   ;
    }
cout<<"matrix 2";
 for(int g=0;g<n;g++)
 { for(int p=0;p<n;p++)
  {cout<<b[g][p];}
  cout<<endl;}
 }
void add()
{
cout<<"Adding the matrices";
for(int i=0;i<n;i++)                                //function for addition
{ for(int j=0;j<n;j++)
 {cout<<a[i][j]+b[i][j]<<"\t\t";}
 cout<<endl;
}}

void subtract()
{
cout<<"subtracting the matrices";                   //addition
for(int i=0;i<n;i++)
{ for(int j=0;j<n;j++)
 {cout<<a[i][j]-b[i][j]<<"\t\t";}
 cout<<endl;
}}

void multiply()                                     //multiplication of matrices
{int sum=0;
cout<<"multiplying the matrices";
for(int i=0;i<n;i++)
 { for(int j=0;j<n;j++)
  {sum+=a[i][j]*b[j][i];
   cout<<sum<<"\t\t";}
   cout<<endl;}                                            
}

void transpose()                                  // transpose
{int c[10][10];
cout<<"transposing matrices";
 cout<<"transposing matrix 1";
for(int i=0;i<n;i++)
{ for(int j=0;j<n;j++)
{c[i][j]=a[j][i];
 cout<<c[i][j]<<"\t\t";}
cout<<endl;}

for(int d=0;d<n;d++)
{ for(int j=0;j<n;j++)
{c[d][j]=b[j][d];
 cout<<c[d][j]<<"\t\t";}
cout<<endl;}
 }

void prints()                                     //printing diagonal elements
{int s1=0,s2=0;
cout<<"Sum of diagonal elements of matrix\n";
for(int i=0;i<n;i++)
{for(int j=0;j<n;j++)
 {if((i==j)||((i+j)==(n-1))   )
   s1+=a[i][j];}}
cout<<"sum of diagonal elements of matrix 1 is: "<<s1<<endl;

for(int r=0;r<n;r++)
{for(int j=0;j<n;j++)
 {if((r==j)||((r+j)==(n-1)) )
   s2+=a[r][j];}}
cout<<"sum of diagonal elements of matrix 2 is: "<<s2;}

void main()
{clrscr();                                                        //main
char ch;
int choice;
cout<<"WELCOME TO C++ PROGRAM\n\n";
do{
cout<<"MENU\n";
cout<<"1.enter the matrices \n2.display\n3.addition\n4.subtraction\n5.multiply\n6.transpose7.prints\n";
cout<<"enter the choice: ";
cin>>choice;
switch(choice)
{case 1:enter();break;
 case 2:display();break;
 case 3:add();break;
 case 4:subtract();break;
 case 5:multiply();break;
 case 6:transpose();break;
 case 7:prints();break;
 default:cout<<"wrong choice";
}
cout<<"do you wish to continue?";
cin>>ch;}
while(ch=='y');
}






