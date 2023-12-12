#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2){

    vector<vector<int>> ans(mat1.size(), vector<int>(mat2[0].size(), 0));
    for(int i=0;i<mat1.size();i++){

        for(int j = 0;j<mat2[0].size();j++){

            for(int k = 0;k<mat2.size();k++){

                ans[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }

    return ans;
}

bool Assert(int m , int k){

    //For 2 matrix to be multiplied, the 2nd dimension of 1st matrix must match with 1st dimension of 2nd matrix
    return m==k;
}

int main(){

    int n, m, k, l;

    cout<<"Enter 1st matrix dimentions NxM : ";
    cin>>n>>m;

    cout<<"Enter 2nd matrix dimentions NxM : ";
    cin>>k>>l;

    if(!Assert(m, k)){cout<<"The given 2 matrix cannot be multiplied";return 0;}

    vector<vector<int>> mat1(n, vector<int>(m));
    vector<vector<int>> mat2(k, vector<int>(l));
    cout<<"\nEnter values of 1st matrix :-\n";
    for(int i=0;i<n;i++){

        for(int j = 0;j<m;j++){

            cin>>mat1[i][j];
        }
    }

    cout<<"\nEnter values of 2nd matrix :-\n";
    for(int i=0;i<k;i++){

        for(int j = 0;j<l;j++){

            cin>>mat2[i][j];
        }
    }


    vector<vector<int>> ans = multiply(mat1, mat2);

    cout<<"\n The multiplied matrix is : \n";

    for(int i=0;i<n;i++){

        for(int j = 0;j<l;j++){

            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }

    cout<<'\n';
    return 0;
}