#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
//#define    f(x) x*sin(x)+cos(x)
//#define f(x) x*x*x-3*x*x+2*x-2
#define f(x) x*x+4*x+5
using namespace std;

int main()
{
	 cout<<"Given function is f(x)=x*x+4*x+5."<<endl;
	 float x0, x1, x2, f0, f1, f2, e;
	 int i = 1;
     int N;
	 
	 /* Setting precision and writing floating point values in fixed-point notation. */
   cout<< setprecision(6)<< fixed;

	 /* Inputs */
	 cout<<"Enter initial guess (x0,x1): "<<endl;
	 cin>>x0>>x1;
	 cout<<"Enter tolerable error: ";
	 cin>>e;
	 cout<<"Enter maximum iteration: ";
	 cin>>N;

	 /* Implementing Secant Method */
     cout<< endl<<"Calculation Table: "<< endl;
     cout<<"i"<<"\ta= x0 "<< setw(12)<<"\t b= x1"<<setw(12)<<"\t c= x2"<< setw(12)<<"f(x2)"<<endl;
	 do{
		  f0 = f(x0);
		  f1 = f(x1);
		  if(f0 == f1)
		  {
			   cout<<"Error! Enter another function.";
		  }

		  x2 = x1 - (x1 - x0) * f1/(f1-f0);
		  f2 = f(x2);
         cout<<i<< setw(14)<< x0<<setw(16)<< x1<< setw(16)<< x2<< setw(14)<<f(x2)<<endl;

		  x0 = x1;
		  f0 = f1;
		  x1 = x2;
		  f1 = f2;

		  i = i + 1;

		  if(i > N)
		  {
			   cout<<"Not Convergent.";
			   exit(0);
		  }
	 }while(fabs(f2)>e);

	 cout<< endl<<"The required root is: "<< x2;

	 return 0;
}