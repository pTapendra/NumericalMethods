#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
#define   f(x)  exp(-x*x)

int main(){
 int num, m;
    float a, b, h, sum, x,fa,fb;
    cout << "f(x)=e^(-x^2)"<<endl;
    cout << "Enter the number of strips: ";
    cin >> num;
    cout << "Enter the end points of interval(a, b): ";
    cin >> a >> b;
    if (num % 3 != 0){
        cout<<"Number of strips must be divisible by 3!";
    }
 cout<< setprecision(4)<< fixed;
 
    h = (b - a) / num;
    fa=f(a);
    fb=f(b);
    sum = fa + fb;

    for (int i = 1; i < num; i++)
    {
        m = (i % 3 == 0) ? 2 : 3;
        x = a + i * h;
        sum += m * f(x);
    }

    sum *= 3 * h / 8;

    cout << "Required Result = " << sum;
    return 0;
}
