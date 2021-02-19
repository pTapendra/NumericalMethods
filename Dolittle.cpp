#include <iostream>
#define max_size 100

using namespace std;

class factorize
{
    private:
        int n;
        float A[max_size][max_size],B[max_size],L[max_size][max_size],U[max_size][max_size];
        float Y[max_size];
    public:
        void Augment();
        void CalculateFactor();
        void Calculate();
};

void factorize::Augment()
{
    cout<<"Enter the number of unknowns:";
    cin>>n;
    cout<<"Enter the coefficient matrix A and constant matrix B respectively:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for (int j=1;j<=n+1;j++)
        {
            if(j==n+1)
            {
                cout<<"B["<<i<<"]=";
                cin>>B[i];
            }
            else
            {
                cout<<"A["<<i<<"]["<<j<<"]=";
                cin>>A[i][j];
            }
        }
    }
//     cout<<"\nThe augmented matrix is:\n";
//     for(int i=1;i<=n;i++)
//     {
//         for(int j=1;j<=n+1;j++)
//         {
//             if(j==n+1)
//                 cout<<":\t"<<b[i];
//             else
//                 cout<<a[i][j]<<"\t";
//         }
//         cout<<endl;
//     }
//  }
}
void factorize::CalculateFactor()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i>j)
            {
                float sum=0;
                for(int k=1;k<j;k++)
                {
                    sum+=L[i][k]*U[k][j];
                }
                L[i][j]=(A[i][j]-sum)/U[j][j];
                U[i][j]=0;
            }
            else
            {
                float sum=0;
                for(int k=1;k<i;k++)
                {
                    sum+=L[i][k]*U[k][j];
                }
                U[i][j]=A[i][j]-sum;
                if(i==j)
                    L[i][j]=1;
                else
                    L[i][j]=0;
            }
        }
    }
    cout<<"Lower Triangular Unit Matrix, L:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<L[i][j]<<"\t";
        cout<<endl;
    }
    cout<<"Upper Triangular Matrix, U:"<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            cout<<U[i][j]<<"\t";
        cout<<endl;
    }
}

void factorize::Calculate()
{
    for(int i=1;i<=n;i++)
    {
        float sum=0;
        for(int j=1;j<i;j++)
        {
            sum+=L[i][j]*Y[j];
        }
        Y[i]=(B[i]-sum);
    }
    for(int i=n;i>=1;i--)
    {
        float sum=0;
        for(int k=n;k>i;k--)
        {
            sum+=U[i][k]*Y[k];
        }
        Y[i]=(Y[i]-sum)/U[i][i];
    }
    cout<<"The required solution is:"<<endl;
    for(int i=1;i<=n;i++)
        cout<<"x["<<i<<"]="<<Y[i]<<endl;
}
int main()
{
    cout<<"Output:"<<endl;
    factorize M1;
    M1.Augment();
    M1.CalculateFactor();
    M1.Calculate();
    return 0;
}
