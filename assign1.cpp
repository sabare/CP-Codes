#include<bits/stdc++.h>

using namespace std;

//Matrix X Matrix ((NxM) x (MxK)) => (NxK)result
vector<vector<int>> Multiply(vector<vector<int>>& mat1, vector<vector<int>>& mat2){

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

//Vector X Matrix ((1XN) x (NxM)) => (1xM)result
vector<int> Multiply(vector<int>& b, vector<vector<int>>& a){

    vector<int> ans(a[0].size(), 0);

    for(int i = 0;i<a[0].size();i++){

        for(int j = 0;j<b.size();j++){

            ans[i]+=a[j][i]*b[j];
        }
    }

    return ans;
}

//Matrix X Vector ((NxM) x (Mx1)) => (Nx1)result
vector<int> Multiply(vector<vector<int>>& a, vector<int>& b){

    vector<int> ans(a.size(), 0);

    for(int i = 0;i<a.size();i++){

        for(int j = 0;j<b.size();j++){

            ans[i]+=a[i][j]*b[j];
        }
    }

    return ans;
}

//Matrix X Scalar
vector<vector<int>> Multiply(vector<vector<int>>& a, int b){

    vector<vector<int>> ans(a.size(), vector<int>(a[0].size(), 0));
    for(int i = 0;i<a.size();i++){

        for(int j = 0;j<a[0].size(); j++){

            ans[i][j] = a[i][j]*b;
        }
    }

    return ans;
}

//Scalar X Matrix
vector<vector<int>> Multiply(int b, vector<vector<int>>& a){

    vector<vector<int>> ans(a.size(), vector<int>(a[0].size(), 0));
    for(int i = 0;i<a.size();i++){

        for(int j = 0;j<a[0].size(); j++){

            ans[i][j] = a[i][j]*b;
        }
    }

    return ans;
}



bool Assert(int m , int k){

    //For 2 matrix to be multiplied, the 2nd dimension of 1st matrix must match with 1st dimension of 2nd matrix
    return m==k;
}

float pnorm(vector<int>& v, int p){


    float ans = 0;
    int n = v.size();
    for(int i = 0;i<n;i++){

        ans+= pow(abs(v[i]), p);
    }
    float inv = 1.0/(float(p)*1.0);
    ans = pow(ans, inv);

    return ans;
}



void questionone(){

    int n, m, k, l;

    cout<<"Enter 1st matrix dimentions NxM : ";
    cin>>n>>m;

    cout<<"Enter 2nd matrix dimentions NxM : ";
    cin>>k>>l;

    if(!Assert(m, k)){cout<<"The given 2 matrix cannot be multiplied";return ;}

    vector<vector<int>> mat1(n, vector<int>(m));
    vector<vector<int>> mat2(k, vector<int>(l));

    //Input for 1st matrix
    cout<<"\nEnter values of 1st matrix :-\n";
    for(int i=0;i<n;i++){

        for(int j = 0;j<m;j++){

            cin>>mat1[i][j];
        }
    }

    //Input for 2nd matrix
    cout<<"\nEnter values of 2nd matrix :-\n";
    for(int i=0;i<k;i++){

        for(int j = 0;j<l;j++){

            cin>>mat2[i][j];
        }
    }


    vector<vector<int>> ans = Multiply(mat1, mat2);

    cout<<"\n The multiplied matrix is : \n";

    for(int i=0;i<n;i++){

        for(int j = 0;j<l;j++){

            cout<<ans[i][j]<<" ";
        }
        cout<<'\n';
    }

    cout<<'\n';

    return;
}

void questiontwo(){

    int n, m, sc;
    cout<<"\nEnter size of Matrix (NxM) : ";
    cin>>n>>m;

    cout<<"\nEnter a scalar : ";
    cin>>sc;

    vector<vector<int>> mat1(n, vector<int>(m, 0));
    cout<<"\n\nEnter values of matrix of size "<<n<<"x"<<m<<" :\n";
    for(int i = 0;i<n;i++){

        for(int j = 0;j<m;j++){

            cin>>mat1[i][j];
        }
    }

    vector<int> vec1(n);
    cout<<"\n\nEnter values of matrix of size 1x"<<n<<" :\n";
    for(int i = 0;i<n;i++){

        cin>>vec1[i];
    }

    vector<int> vec2(m);
    cout<<"\n\nEnter values of matrix of size "<<m<<"x1 :\n";
    for(int i = 0;i<m;i++){

        cin>>vec2[i];
    }

    cout<<"\n\nResult : ";

    vector<int> ans1;
    ans1 = Multiply(vec1, mat1);

    vector<int> ans2;
    ans2 = Multiply(mat1, vec2);
    
    vector<vector<int>> ans3;
    ans3 = Multiply(mat1, sc);
    
    vector<vector<int>> ans4;
    ans4 = Multiply(sc, mat1); 

    cout<<"\nVector X Matrix => (1x"<<m<<") :\n";
    for(int i = 0;i<ans1.size();i++){

        cout<<ans1[i]<<" ";
    }

    cout<<"\n\n";

    cout<<"\nVector X Matrix => ("<<n<<"x1) :\n";
    for(int i = 0;i<ans2.size();i++){

        cout<<ans2[i]<<'\n';
    }

    cout<<"\n\n";
    cout<<"\nMatrix X Scalar => ("<<n<<"x"<<m<<") :\n";
    for(int i = 0;i<ans3.size();i++){

        for(int j=0;j<ans3[0].size();j++){

            cout<<ans3[i][j]<<" ";
        }

        cout<<'\n';
    }

    cout<<"\n\n";
    cout<<"\nScalar X Matrix => ("<<n<<"x"<<m<<") :\n";
    for(int i = 0;i<ans4.size();i++){

        for(int j=0;j<ans4[0].size();j++){

            cout<<ans4[i][j]<<" ";
        }

        cout<<'\n';
    }

    return;

}

void questionthree(){

    int n;
    cout<<"Enter size of vector : ";
    cin>>n;
    vector<int> v(n);

    cout<<"\n\n Enter values of the vector : ";
    for(int i = 0;i<n;i++)cin>>v[i];

    int p = 2;
    float v_val = 0;

    v_val = pnorm(v, p);

    cout<<"\n\n p-normal vector for the vector is :";
    cout<<v_val<<"\n\n";

    return ;
}



int main(){

    cout<<"\n\nQuestion One : \n";
    questionone();

    cout<<"\n\nQuestion Two : \n";
    questiontwo();

    cout<<"\n\nQuestion Three : \n";
    questionthree();
    return 0;
}