#include<bits/stdc++.h>
using namespace std;

int mod = 1e9 + 7;


long long binexp(int a, int b){

    if(b==0)
        return 1;
    
    long long res = binexp(a, b/2);
    if(b%2)
        return ((res*res)%mod *a)%mod;

    else
        return (res*res)%mod;
}

vector<long long> fct(1e6, 1);

long long factorial(int n){


    fct[0] = 1;
    for(int i = 1;i<=n;i++){

        fct[i] = (i*fct[i-1])%mod;
    }

    return fct[n];
}

long long Mod_Inv(long long n){
    
    return binexp(n, mod-2);
}

long long nCr(long long n, long long r){

    if(n<r)return 0;

    long long ans = fct[n];
    ans%=mod;
    ans*=Mod_Inv(fct[r]);
    ans%=mod;
    ans*=Mod_Inv(fct[n-r]);
    ans%=mod;
    return ans;
}

int main(){

    int n, r;
    cin>>n>>r;

    // cout<<binexp(a, b);
    factorial(n);
    cout<<nCr(n, r);
    return 0;
}