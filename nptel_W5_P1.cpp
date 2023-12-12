#include<bits/stdc++.h>

using namespace std;

void dfs(int i, vector<vector<int>>& adj ,vector<bool>& vis){

    if(vis[i])return;
    vis[i] = true;

    for(auto it: adj[i]){

        dfs(it, adj, vis);
    }

    return;
}

void solve(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    while(m--){

        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    int cnt = 0;
    for(int i = 1;i<=n;i++){

        if(!vis[i]){
            cnt++;
            dfs(i, adj, vis);
        }
    }
    cout<<cnt;
    return ;
}

int main(){

    solve();

    return 0;
}