#include<iostream>
#include<cmath>
using namespace std;
// 3x+sinx-exp(x)//0.360
//2x-3cosx//0.914
//5x^3-4x^2-3x+1//1.16724
//for polynomials
void coefficient(int c[], int order){
    for(int i=order;i>=0;i--){
        cout<<"coefficient of x^"<<i<<" :";
        cin>>c[i];
    }
}

double function(double x, int order, int coef[]){
    double result = 0;
    while(order){
        result +=coef[order]*pow(x,order);
        order--;
    }
    return result + coef[0];
}

double derivative(double x, int order, int coef[]){
    double result = 0;
    while(order-1){
        result +=order*coef[order]*pow(x,order-1);
        order--;
    }
    return result + coef[1];
}

double calculation(double Guess,double RTE, int order, int coef[]){
    double x= Guess, xn , relativeError = 9999;
    while(RTE<relativeError){
        cout<<"\n xi="<<x;
        cout<<"\n f(x)="<<function(x,order,coef);
        cout<<" \n f'(x)="<<derivative(x,order,coef);
        xn = x - (function(x,order,coef)/derivative(x,order,coef));
        cout<<"\n ( xi+1) ="<<xn;
        relativeError = abs((xn-x)/xn);
        cout<<"\n Relative Error="<<relativeError;
        x=xn;
        cout<<endl<<endl;
    }
    return xn;
}

int main(){
    double RTE,Guess;
    int order;
    int *coef = NULL;
    cout<<"Enter the order of Polynomial :";cin>>order;
    cout<<"Enter Relative Tolerable error :";cin>>RTE;
    cout<<"Enter Initial guess :";cin>>Guess;
    coef = new int[order];
    coefficient(coef,order);
    double result = calculation(Guess, RTE,order,coef);
    cout<<"\n Root is: "<<result;
    return 0;
}
//for all
// int main()
// {
// 	 float x0, x1, f0, f1, g0, e;
// 	 int step = 1, N;

// 	 /* Setting precision and writing floating point values in fixed-point notation. */
//      cout<< setprecision(5)<< fixed;

//      /* Inputs */
// 	 cout<<"Enter initial guess: ";
// 	 cin>>x0;
// 	 cout<<"Enter tolerable error: ";
// 	 cin>>e;
// 	 cout<<"Enter maximum iteration: ";
// 	 cin>>N;
// 	 do
// 	 {
// 		  g0 = g(x0);
// 		  f0 = f(x0);
// 		  if(g0 == 0.0)
// 		  {
// 			   cout<<"Mathematical Error.";
// 			   exit(0);
// 		  }


// 		  x1 = x0 - f0/g0;


// 		  cout<<"Iteration-"<< step<<":\t x = "<< setw(10)<< x1<<" and f(x) = "<< setw(10)<< f(x1)<< endl;
// 		  x0 = x1;

// 		  step = step+1;

// 		  if(step > N)
// 		  {
// 			   cout<<"Not Convergent.";
// 			   exit(0);
// 		  }

// 		  f1 = f(x1);

// 	 }while(fabs(f1)>e);

// 	 cout<< endl<<"Root is: "<< x1;
// 	 return 0;
// }
