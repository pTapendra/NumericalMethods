#include<iostream>
#include<iomanip>
#include<cmath>
#include<stdlib.h>
/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/
//#define    f(x) x*sin(x)+cos(x)
//#define f(x) x*x*x-3*x*x+2*x-2
#define f(x) x*x+4*x+5

using namespace std;

int main()
{
	 /* Declaring required variables */
     cout<<"Given function is x*x+4*x+5."<<endl;
	 float x0, x1, x, f0, f1, f, e;
	 int i = 1;

	 /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(6)<< fixed;

	 /* Inputs */
     cout<<"Enter initial guess (x0,x1): "<<endl;
	 cin>>x0>>x1;

     cout<<"Enter tolerable error: ";
     cin>>e;

	 /* Calculating Functional Value */
	 f0 = f(x0);
	 f1 = f(x1);

	 /* Checking whether given guesses brackets the root or not. */
	 if( f0 * f1 > 0.0)
	 {
		  cout<<"Enter valid initial guesses!"<< endl;
          main();
	 }
   /* Implementing False Position Method */

	 cout<<"Calculation Table: "<< endl;
      cout<<"i"<<"\ta= x0 "<< setw(12)<<"\t b= x1"<<setw(12)<<"\t c= x2"<< setw(12)<<"f(x2)"<<endl;

	 do
	 {
		  /* Applying False Position Method */
		  /* x is next approximated root using False Position method */
		  x = x0 - (x0-x1) * f0/ (f0-f1);
		  f = f(x);

		cout<<i<< setw(14)<< x0<<setw(16)<< x1<< setw(16)<< x<< setw(14)<<f(x)<<endl;

		  if( f0 * f < 0)
		  {
			   x1 = x;
			   f1 = f;
		  }
		  else
		  {
			   x0 = x;
			   f0 = f;
		  }
		  i = i + 1;
	 }while(fabs(f)>e);

	 cout<< endl<<"The required root is: "<< x<< endl;

	 return 0;
}