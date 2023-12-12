#include<bits/stdc++.h>
using namespace std;

int bfs(int i, int target, vector<vector<int>>& adj){
    vector<bool> vis(adj.size(), false);
    queue<int> q;
    q.push(i);
    vis[i] = true;
    if(i==target)return 0;
    int lvl = 1;
    while(!q.empty()){

        int sz = q.size();
        while(sz--){

            int node = q.front();
            q.pop();

            for(auto it: adj[node]){

                if(vis[it])continue;
                if(it==target)return lvl;
                vis[it] = true;
                q.push(it);
            }
        }
        lvl++;
    }

    return lvl;

}
int dfs(int i, int parent, vector<vector<int>>& adj, vector<bool>& vis){

    for(auto it: adj[i]){

        if(vis[it] && it==parent)continue;
        if(vis[it])return it;
        vis[it]=true;
        int val = dfs(it, i, adj, vis);
        if(val!=-1)return val;
        vis[it]=false;
    }

    return -1;
}
void solve(){
    
    int n, a, b;
    cin>>n>>a>>b;
    a--;b--;
    vector<vector<int>>adj(n);

    for(int i=0;i<n;i++){

        int x, y;
        cin>>x>>y;
        adj[x-1].push_back(y-1);
        adj[y-1].push_back(x-1);

    }
    if(a==b){cout<<"NO\n"; return ;}
    vector<bool>vis(n, false);
    vis[b] = true;
    int target = dfs(b, -1, adj, vis);

    
    int val1 = bfs(a, target, adj);
    int val2 = bfs(b, target, adj);
    
    val1>val2?cout<<"YES\n":cout<<"NO\n";

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