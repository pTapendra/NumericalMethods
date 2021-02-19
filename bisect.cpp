#include<iostream>
#include<iomanip>
#include<math.h>

/*
 Defining equation to be solved.
 Change this equation to solve another problem.
*/
#define funct(x) pow(x,4)-260;
//#define funct(x) 5*x-exp(x)+sin(x);
//#define funct(x) pow(x,3)-x-1;


using namespace std;
float E=0.00005;
float c;
void bisect(float a, float b){
    float functa=funct(a);
    float functb=funct(b);
    if((functa*functb)>=0){
        cout<<"Enter valid a and b!";
        return;
    }
    c=a;
    while((b-a)>=E){
        c=(a+b)/2;
        float functc=funct(c);
        if (functc==0.0){
            cout<<c<<endl;
            break;
        }
        else if((functc*functa)<0){
            cout<<c<<endl;
            b=c;
        }
        else{
            cout<<c<<endl;
            a=c;
        }
    }

}

int main()
{
	 /* Declaring required variables */
	 float g, h;
	 /* Setting precision and writing floating point values in fixed-point notation. */
     cout<< setprecision(5)<<fixed;

	 /* Inputs */
	 cout<<"Enter first guess: ";
     cin>>g;
     cout<<"Enter second guess: ";
     cin>>h;
     cout<<"g= "<<g<<" h= "<<h<<endl;
     bisect(g,h);
	 cout<<"\n The required root is: "<<c<<endl;
    


	 return 0;
}