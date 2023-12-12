#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    int dum = n;
    int rev = 0;
    while(dum>0){

        rev = rev*10 + dum%10;
        dum/=10;
    }

    cout<<(abs(rev-n)/9)<<'\n';
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