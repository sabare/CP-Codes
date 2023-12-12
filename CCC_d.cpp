#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    unordered_map<int, int> mp;
    int ans = 0;
    for(int i=0;i<n;i++){

        cin>>a[i];
        mp[a[i]]++;
        ans = max(ans, mp[a[i]]);
    }

    cout<<ans<<'\n';
    return;
}

int main(){


    solve();

    return 0;
}