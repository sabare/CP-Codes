#include<bits/stdc++.h>
using namespace std;

int bC(int n, int k)
{
    // Base Cases
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
 
    // Recur
    return bC(n - 1, k - 1)
           + bC(n - 1, k);
}

void solve(int n, vector<int>& a, int k){

    int mod = 998244353;
    int c = 0;
     for(int i=0;i<n;i++){

        int b = 0;
        for(int j=0;j<i;j++){

            b+=bC(i-j+1, k)*a[j];
        }
        b%=mod;
        c^=b*(i+1);
     }  

     cout<<c;
}

int main(){

    int n,ao,x,y,m,k;
    cin>>n>>ao>>x>>y>>m>>k;
    vector<int> a(n, 0);
    a[0]=ao;
    for(int i=1;i<n;i++){

        a[i] = (a[i-1]*x + y)%m;
    }

    solve(n, a, k);
}


