#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> Multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2){

    cout<<"\n\n 1st overloaded function (matrix and matrix)\n\n";
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

vector<int> Multiply(vector<vector<int>>& a, vector<int>& b){

    cout<<"\n\n 2nd overloaded Function (Matrix and vector)\n\n";
    vector<int> ans(b.size(), 0);

    for(int i = 0;i<a.size();i++){

        for(int j = 0;j<b.size();j++){

            ans[i]+=a[i][j]*b[j];
        }
    }

    return ans;
}


vector<int> Multiply(vector<int>& b, vector<vector<int>>& a){

    cout<<"\n\n 3rd overloaded Function (vector and matrix)\n\n";
    vector<int> ans(a[0].size(), 0);

    for(int i = 0;i<a[0].size();i++){

        for(int j = 0;j<b.size();j++){

            ans[i] += b[j]*ans[j][i];
        }
    }
    return ans;
}



int main(){

    int n, m;

    cout<<"Enter 1st matrix dimentions NxM : ";
    cin>>n>>m;

    vector<vector<int>> mat1(n, vector<int>(m));

    for(int i = 0;i<n;i++){

        for(int j = 0;j<m;j++){

            mat1[i][j] = max(i+1, j+1);
        }
    }

    vector<int> b(m);
    for(int i=0;i<m;i++)b[i]=i+1;

    vector<int> ans = Multiply(mat1, b);

    vector<int> ans = Multiply(b, mat1);

    

    cout<<'\n';
    return 0;
}