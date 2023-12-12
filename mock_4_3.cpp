#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    vector<vector<int>> dur;

    for(int i = 0;i<n;i++){

        int a; int b;
        cin>>a>>b;
        dur.push_back({a, b});
    }

    sort(dur.begin(), dur.end());
    int ans = 1;
    int cnt = 1;
    int last = dur[0][1];
    priority_queue<int, vector<int>, greater<int>> q;
    q.push(last);   
    for(int i = 1;i<n;i++){

        while(!q.empty() && dur[i][0]>q.top())q.pop();
        q.push(dur[i][1]);
        int sz = q.size();
        ans =max(ans, sz);
    }

    cout<<ans<<'\n';
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }

    return 0;
}