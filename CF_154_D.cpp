#include<bits/stdc++.h>

using namespace std;

void solve(){

    long long  n;
    cin>>n;

    long long val = ceil((1 + ceil(sqrt(1 + 8*n)))/2);

    
    if((val*(val-1))==2*n){

        cout<<val<<'\n';return ;
    }

    if(val*(val-1)<=2*n)val++;


    long long int diff = n - (((val-2)*(val-1))/2) ;
    long long ans = val -1 + diff;
    cout<<val-1 + diff<<'\n';

    return;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }

    return 0;
}