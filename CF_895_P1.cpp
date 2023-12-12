#include<bits/stdc++.h>
using namespace std;

void solve(){

    int x, y, a;
    cin>>x>>y>>a;

    float x1 = max(x,y);
    float x2 = min(x,y);

    cout<<(ceil((x1-x2)/(2.0*a)))<<'\n';
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