#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n, m;
    cin>>n>>m;

    vector<int> h(n);
    vector<int> v(m);

    for(int i = 0;i<n;i++){

        cin>>h[i];
    }

    for(int i = 0;i<m;i++){

        cin>>v[i];
    }

    sort(h.begin(), h.end());
    sort(v.begin(), v.end());
    int j = 0;
    int cnt = 0;
    for(int i = 0;i<n;i++){

        while(j<m && h[i]>v[j])j++;
        if(j<m && v[j]>=h[i]){cnt++;j++;}
    }

    cout<<cnt<<'\n';
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }

    return 0;
}