#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
#define f(x,y,z) 2*x+y-z
#define g(x,y,z) x*z
int main()
{
    float x0, y0, z0, xn, yn, zn, n, h, k1, k2, k3, k4, k, l1, l2, l3, l4, l;
    cout << "For f(x,y,z) = 2*x+y-z and g(x,y,z) = xz"<< endl;
    cout << "Enter intital values x0, y0 and z0:";
    cin >> x0 >> y0 >> z0;
    cout << "Enter final value of x: ";
    cout<<"xn= ";
    cin >> xn;
    cout << "Enter number of steps: ";
    cin >> n;
    h = (xn - x0) / n;
    cout << "\nX\tY\tZ\tYn\tZn\n";
     cout<< setprecision(4)<<fixed;
    for (int i = 0; i < n; i++)
    {
        k1 = h * f(x0, y0, z0);
        l1 = h * g(x0, y0, z0);

        k2 = h * f(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);
        l2 = h * g(x0 + h / 2, y0 + k1 / 2, z0 + l1 / 2);

        k3 = h * f(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);
        l3 = h * g(x0 + h / 2, y0 + k2 / 2, z0 + l2 / 2);

        k4 = h * f(x0 + h, y0 + k3, z0 + l3);
        l4 = h * g(x0 + h, y0 + k3, z0 + l3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;
        yn = y0 + k;
        zn = z0 + l;
        cout<< x0 << "\t" << y0 << "\t" << z0 << "\t" << yn << "\t" << zn << endl;
        y0 = yn;
        z0 = zn;
        x0 = x0 + h;
    }
    cout << "\nValue of y at x = " << xn << " is: " << yn;
    cout << "\nValue of z at x = " << xn << " is: " << zn;
}
