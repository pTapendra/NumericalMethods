#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define f(x,y) x+y

int main()
{
    float x0, y0, xn, yn, n, h, slope;
    cout << "f(x,y)=" << endl;
    cout << "Enter intial x0 and y0:"<<endl;
    cout<<"x0= ";
    cin >> x0 ;
    cout<<"y0= ";
    cin>> y0;
    cout << "Enter final value of x: ";
    cout<<"xn= ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    h = (xn - x0) / n;
    cout << "\nX\tY\tSlope\tYn\n";
     cout<< setprecision(4)<<fixed;
    for (int i = 0; i < n; i++)
    {
        slope = f(x0, y0);
        yn = y0 + h * slope;
        cout << x0 << "\t" << y0 << "\t" << slope << "\t" << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }
    cout << "\nValue of y at x = " << xn << " is " << yn;
    return 0;
}