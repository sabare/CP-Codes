#include<bits/stdc++.h>
using namespace std;


void solve(){


    int x, y;
    cin>>x>>y;

    int a = x+y;
    int b = x;
    // cout<<(a&b)<<" "<<(a^b)<<'\n';
    if((a&b) != x || (a^b)!=y){cout<<"-1\n";return;}
    cout<<a<<" "<<x<<'\n';
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