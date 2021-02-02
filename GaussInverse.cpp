#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    float M[100][100];
    int n,i,j;
    float ratio;
    //Take inputs
    cout<<"Input order of square matrix:";
    cin>>n;
    cout<<"Input respective elements of square matrix:"<<endl;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            cout<<"M["<<i<<"]["<<j<<"]=";
            cin>>M[i][j];

        }
    }
    //Augment Identity Matrix
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                M[i][j+n]=1;
            }
            else
            {
                M[i][j+n]=0;
            }
        }
    }
    //Apply Gauss Jordan Method
    cout<< setprecision(4)<< fixed;
    for(i=1;i<=n;i++){
        if(M[i][i]==0){cout<<"Enter valid matrix elements!"; return -1;}
        for(j=1;j<=n;j++){
            if(i!=j){
                ratio=M[j][i]/M[i][i];
                for(int k=1;k<=2*n;k++){
                    M[j][k]=M[j][k]-ratio*M[i][k];
                }
            }
        }
    }
    //convert principal diagonal to 1
    for(i=1;i<=n;i++){
        for(j=n+1;j<=2*n;j++){
            M[i][j]=M[i][j]/M[i][i];
        }
    }
    //display inverse matrix
    cout<<"The required inverse matrix is:"<<endl;
    for(i=1;i<=n;i++){
      //  cout<<"|";
        for(j=n+1;j<=2*n;j++){
            cout<<M[i][j]<<"\t";
        }
        cout<<endl;
     // cout<<"|"<<endl;
    }
    return 0;


}
    // cout<<"2x1+3x2=-2 \n-4x1+2x2=6"<<endl;
   // cout<<"x1+x2-x3=2 \n2x1+3x2+5x3=-3\n3x1+2x2-3x3=6 "<<endl;
     //cout<<"x1+2x2+3x3-x4=10\n2x1+3x2-3x3-x4=1\n2x1-x2+2x3+3x4=7\n3x1+2x2-4x3+3x4=2 "<<endl;
    // cout<<"x1+2x2+3x3-x4+x5=11\n2x1+3x2-3x3-x4-x5=0\n2x1-x2+2x3+3x4+2x5=9\n3x1+2x2-4x3+3x4-2x5=0\n5x1+2x2-3x3-3x4+3x5=3 "<<endl;