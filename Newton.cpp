#include<iostream>
#include<cmath>
using namespace std;

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
