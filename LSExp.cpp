//For y = ax^b

#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
    int n;
    cout << "Enter number of data: ";
    cin >> n;
    float x[50],y[50];
    float sumX = 0, sumY = 0, sumX2 = 0, sumXY = 0, D1, D2, D3, a, b;
    for (int i = 1; i <= n; i++)
    {
        cout << "x" << i << ": ";
        cin >> x[i];
        cout << "y" << i << ": ";
        cin >> y[i];
        sumX += log(x[i]);
        sumY += log(y[i]);
        sumX2 += log(x[i]) * log(x[i]);
        sumXY += log(x[i]) * log(y[i]);
        cout << endl;
    }

    //Find Value of Constants
    D1 = sumY * sumX2 - sumXY * sumX;
    D2 = n * sumXY - sumX * sumY;
    D3 = n * sumX2 - sumX * sumX;
    a = exp(D1 / D3);
    b = D2 / D3;
    cout << "a = " << a << " and b = " << b << endl;
    cout << "The required curve is y = " << setprecision(4) << a << "x^" << b << endl;
    
   // cout << "The required curve is y = " << setprecision(4) << a << "e^" << b << "x" << endl;
    return 0;
}
