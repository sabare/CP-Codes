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

int fun(int m, vector<int>& a){

    if(m==0)return 0;

    long long val = 

}

int main(){

    int k, m;
    cin>>k>>m;
    vector<int> a(k);

    for(int i = 0;i<k;i++){

        cin>>a[i];
    }

    fun(m, a);
}