
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<math.h>

#define SIZE 10

using namespace std;

int main()
{
	 float a[SIZE][SIZE], x[SIZE],z[SIZE],D[SIZE];
	 float lambda,Dmax,temp=0,t,norm=0;
     float error=0.00001,MAXITR=100;
	 int i,j,max,n,count=0;
	 /* Inputs */
	 /* Reading order of square matrix */
	 cout<<"Enter Order of Matrix: ";
	 cin>>n;
	 /* Reading Square Matrix of Order n */
	 cout<<"Enter Elements of Matrix: "<< endl;
	 for(i=0;i<=n-1;i++)
	 {
		  for(j=0;j<=n-1;j++)
		  {
			   cout<<"a["<< i<<"] ["<< j<<"]= ";
               cin>>a[i][j];
		  }
	 }

	 /* Reading Intial Guess Vector */
	 cout<<"Enter Guess Values To Eigen Vector: "<< endl;
	 for(i=0;i<=n-1;i++)
	 {
		  cout<<"x["<< i<<"]= ";
		  cin>>x[i];
	 }
     cout<< setprecision(4)<< fixed;
     do{
     count++;
     if (count>MAXITR){
         cout<<"Termination Error!";
         exit(0);
     }

	 /* Multiplication */

	 for(i=0;i<=n-1;i++)
	 {          
		  for(j=0;j<=n-1;j++)
		  {
		     temp = temp+ a[i][j]*x[j];
		  }
          z[i]=temp;
          temp=0;
	 }

	 /* Finding largest value from x*/
	 lambda = fabs(z[0]);
	 for(i=1;i<=n-1;i++)
	 {
		  if(fabs(z[i])>lambda)
		  {
		   	lambda = fabs(z[i]);
		  }
	 }

	 /* Scaling */
	 for(i=0;i<=n-1;i++)
	 {
	  	z[i] = z[i]/lambda;
	 }

 
     	 /* Checking Accuracy */
     for(i=0;i<=n-1;i++){
          D[i]=fabs(z[i]-x[i]);
        }
     //replace x by z
     for(i=0;i<=n-1;i++){
     x[i]=z[i];
        }
             for(i=0;i<=n-1;i++){
                 if(i==(n-1)/2){
                  cout<<"\nX"<<count<<"=";}
                  cout<<"\t \n"<<x[i];
                }
     //compute largest error
	 Dmax= D[0];
	 for(i=1;i<=n-1;i++)
	 {
		  if(D[i]>Dmax)
		  {
		   	Dmax = D[i];
		  }
	 }

     }while(Dmax>error);
     cout<<"\n\n Eigen Value = "<< lambda<< endl;
     cout<<"\nEigen Vector: "<< endl;
	 cout<<"[";
   
    
   	 /* Normalization */
	 for(i=0;i<=n-1;i++)
	 { 
	   norm=norm+(x[i]*x[i]);
       cout<<x[i]<<"\t";
	 }
        t=1/sqrt(norm);
        	 for(i=0;i<=n-1;i++)
	            {  
                     x[i]=x[i]*t;

	        }
      cout<<"\b\b\b\b]";         

     

	 
	 
	 return 0;
}
