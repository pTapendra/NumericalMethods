#include <iostream>
#include <cmath>
#include<iomanip>

using namespace std;

int main()
    {
        int n,degree;
        float x[50],y[50];
        cout << "Enter number of data pairs: ";
        cin >> n;
        cout << "Enter the degree of polynomial: ";
        cin >> degree;
        if (n < degree){
             cout << "Number of entries is less than degree"<<endl;}
        float M[50][50];
        cout<<setprecision(3)<<fixed;
        for (int i = 0; i < n; i++)
        {
            cout << "x" << i + 1 << ": ";
            cin >>x[i];
            cout << "y" << i + 1 << ": ";
            cin >>y[i];
            cout << endl;
        }
        int p = 0;
        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= degree; j++)
            {
                for (int k = 0; k < n; k++)
                {
                    M[i][j] += pow(x[k], p + j);
                    if (j == 0)
                        M[i][degree + 1] += pow(x[k], p) * y[k];
                }
            }
            p++;
        }

        //Solving
        //Augmented Matrix
        cout << "\nIn Augmented Matrix: " << endl;
        for (int i = 0; i <= degree; i++)
        {
            for (int j = 0; j <= degree + 1; j++)
            {
                if (j == degree + 1)
                    cout << ":\t";
                cout << M[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;

        //Row Operations on the Matrix
        for (int j = 0; j <= degree; j++)
        {
            for (int i = 0; i <= degree; i++)
            {
                if ((int)M[j][j] == 0){
                    cout << "Equation has no solution" << endl;}
                float ratio = (M[i][j] / M[j][j]);
                for (int k = 0; k <= degree + 1; k++)
                {
                    if (i != j)
                    {
                        M[i][k] -= (ratio)*M[j][k];
                    }
                    if (k == degree + 1)
                        cout << ":\t";
                    cout<< M[i][k];
                }
                cout << endl;
            }
            cout << endl;
        }

        //Displaying Unknown values
        cout << "The unknowns are" << endl;
        int count = 0;
        for (int i = 0; i <= degree; i++)
        {
            char var = (char)('a' + i);
            cout << var << " = " << M[count][degree + 1] / M[count][count] << endl;
            count++;
        }
        return 0;
    }

