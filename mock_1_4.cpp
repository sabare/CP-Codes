#include<bits/stdc++.h>
using namespace std;

 long long int M = 1e9+7;

long long mod(long long x){

    return ((x%M)+M)%M;
}

long long add(long long a, long long b){


    return mod(mod(a)+mod(b));
}

long long mul(long long a, long long b){

    return mod(mod(a)*mod(b));
}

long long fact(long long n)
{
      if(n==0)
      return 1;
    long long res = 1;
    for (long long i = 2; i <= n; i++)
        res = mul(res, i);
    return res;
}


long long nCr(long long n, long long r)
{
    long long ans = fact(n)/(mul(fact(r), fact(n-r)));
    return mod(ans);
}

void solve(){

    int n, k, m;
    cin>>n>>k>>m;

    vector<int>a(n);
    for(int i=0;i<n;i++){

        cin>>a[i];
    }

    sort(a.begin(), a.end());

    int i = 0, j = 0;

    long long ans =  0;
    pair<int, int> val = {-1, -1};
    while(i<n-k+1){
        
        if(j==n-1){

            if(j-i+1>=k)
                ans = add(ans, nCr(j-i, k-1));
            i++;
        }
        else if(a[j+1] - a[i]>m){

            if(j-i+1>=k)
                ans = (ans + nCr(j-i, k-1));

            j++;i++;
        }
        else {

            j++;
        }
    }

    cout<<ans;
    return;
}

int main(){


    solve();
    return 0;
}