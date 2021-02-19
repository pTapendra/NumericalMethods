#include<iostream>

using namespace std;

int main()
{
	 float x[100], y[100], xp, yp=0, p;
	 int i,j,n;

	 /* Input Section */
	 cout<<"Enter number of data: ";
	 cin>>n;
	 cout<<"Enter values of x and y:"<< endl;
	 for(i=1;i<=n;i++)
	 {
		  cout<<"x["<< i<<"] = ";
		  cin>>x[i];
		  cout<<"y["<< i<<"] = ";
		  cin>>y[i];
	 }
	 cout<<"Enter x to find y(x): ";
	 cin>>xp;

	 /* Implementing Lagrange Interpolation */
	 for(i=1;i<=n;i++)
	 {
		  p=1;
		  for(j=1;j<=n;j++)
		  {
			   if(i!=j)
			   {
			    	p = p* (xp - x[j])/(x[i] - x[j]);
			   }
		  }
		  yp = yp + p * y[i];
	 }
	 cout<< endl<<" Required interpolated value is y("<<xp<<")="<< yp;

	 return 0;
}
