#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

#define f(x,y) 2*x+3*y

int main()
{
    float x0, y0, xn, yn, n, h, k1, k2, k3, k4, k;
    cout << "f(x,y)=2x +3y" << endl;
    cout << "Enter intital values x0 and y0:";
    cin >> x0 >> y0;
    cout << "Enter final value of x: ";
    cout<<"xn= ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    h = (xn - x0) / n;
    cout << "\nX\tY\tYn\n";
     cout<< setprecision(4)<<fixed;
    for (int i = 0; i < n; i++)
    {
        k1 = h * f(x0, y0);
        k2 = h * f(x0 + h / 2, y0 + k1 / 2);
        k3 = h * f(x0 + h / 2, y0 + k2 / 2);
        k4 = h * f(x0 + h, y0 + k3);
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        yn = y0 + k;
        cout<< x0 << "\t" << y0 << "\t"
             << yn << endl;
        y0 = yn;
        x0 = x0 + h;
    }
    cout << "\nValue of y at x = " << xn << " is: " << yn;
    return 0;
}