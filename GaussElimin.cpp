#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main()
{
	 float M[100][100],X[100],ratio;
	 int i,j,k,n;
     //Take inputs
    cout<<"The system of linear equations is:"<<endl;
   // cout<<"2x1+3x2=-2 \n-4x1+2x2=6"<<endl;
    //cout<<"x1+x2-x3=2 \n2x1+3x2+5x3=-3\n3x1+2x2-3x3=6 "<<endl;
    // cout<<"x1+2x2+3x3-x4=10\n2x1+3x2-3x3-x4=1\n2x1-x2+2x3+3x4=7\n3x1+2x2-4x3+3x4=2 "<<endl;
     cout<<"x1+2x2+3x3-x4+x5=11\n2x1+3x2-3x3-x4-x5=0\n2x1-x2+2x3+3x4+2x5=9\n3x1+2x2-4x3+3x4-2x5=0\n5x1+2x2-3x3-3x4+3x5=3 "<<endl;
	
	 cout<<"Enter number of unknowns: ";
	 cin>>n;
     //Read augmented matrix
	 cout<<"Enter Coefficients of Augmented Matrix: "<< endl;
	 for(i=1;i<=n;i++)
	 {
		  for(j=1;j<=n+1;j++)
		  {
			cout<<"M["<< i<<"]"<<"["<< j<<"]= ";
			cin>>M[i][j];
		  }
	 }
	// Apply Gauss Elimination
    cout<< setprecision(3)<< fixed;
    for(i=1;i<=n-1;i++)
	 {
        if(M[i][i]==0){
        cout<<"Enter valid coefficients of augmented matrix!";
        return -1;}
		  for(j=i+1;j<=n;j++)
		  {
			   ratio = M[j][i]/M[i][i];

			   for(k=1;k<=n+1;k++)
			   {
			  		M[j][k] = M[j][k] - ratio*M[i][k];
			   }
		  }
	 }
	//Back Substitution Method 
	 X[n] = M[n][n+1]/M[n][n];

	 for(i=n-1;i>=1;i--)
	 {
		  X[i] = M[i][n+1];
		  for(j=i+1;j<=n;j++)
		  {
		  		X[i] = X[i] - M[i][j]*X[j];
		  }
		  X[i] = X[i]/M[i][i];
	 }
     //Display Solution
	 cout<< endl<<"The required solution is : "<< endl;
	 for(i=1;i<=n;i++)
	 {
	  	cout<<"X["<< i<<"] = "<< X[i]<<"\t"<<endl;
	 }

	 return 0;
}