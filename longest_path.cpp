#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    int m;
    cin>>n>>m;
    vector<vector<int>>adj(n);

    for(int i = 0;i<m;i++){

        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(0);
    vector<int> dis;
    while(!q.empty()){

        
    }
}

int main(){

    solve();

    return 0;
}