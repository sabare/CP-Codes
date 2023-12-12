#include<bits/stdc++.h>
using namespace std;

int fun(int mask, vector<vector<int>>& adj, int pos){

    if(mask==((1<<adj.size())-1)) return 0;

    int ans = 0;
    for(int i=0;i<adj.size();i++){

        if(!(mask&(1<<i))){

            ans = max(ans, adj[i][pos] + fun((mask)|(1<<i), adj, i));
        }
    }

    return ans;
}

void solve(vector<vector<int>>& adj){

    cout<<fun(1, adj, 0);
    return;
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(m);
    for(int i=0;i<n;i++){
        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    solve(adj);
    return;
}