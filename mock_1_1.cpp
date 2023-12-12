#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, m;
    cin>>n>>m;

    vector<int> a(n+1);
    vector<int> b(m+1);

    for(int i = 0;i<=n;i++){

        cin>>a[i];
    }

    
    for(int i = 0;i<=m;i++){

        cin>>b[i];
    }

    vector<int> ans(n+m+1, 0);

    for(int i = 0;i<=n;i++){

        for(int j = 0;j<=m;j++){

            ans[i+j] += a[i]*b[j];
        }
    }

    // cout<<'a';
    for(auto it: ans){

        cout<<it<<' ';
    }
    return;
}

int main(){

    solve();
    return 0;
}