#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num;
    float a, b, h, sum;
    float y[50];
    cout << "Enter the number of intervals: ";
    cin >> num;
    cout << "Enter the end points of interval: ";
    cin >> a >> b;
    for (int i = 0; i <= num; i++)
    {
        cout << "Y" << i << ": ";
        cin >>y[i];
    }

    h = (b - a) / num;
    sum = y[0] + y[num];

    for (int i = 1; i < num; i++)
    {
        sum += 2 * y[i];
    }

    sum *= h / 2;

    cout << "Required Integral = " << sum;
    return 0;
}