/*Given no. of game results, there could be people with winning cycle, print people who aren't part of winning cycle*/
#include<bits/stdc++.h>

using namespace std;


void print(int id, int i, vector<int>& path){

    while(id!=i){

        cout<<id<<" ";
        id=path[id];
    }
    cout<<i<<'\n';
    return;
}

void fun(int id, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path){
    // cout<<"yeg\n";
    vis[id]=true;
    for(int i = 0;i<adj[id].size();i++){

        if(!vis[adj[id][i]]){

            path[adj[id][i]]=id;
            fun(adj[id][i], adj, vis, path);
            
        }
        else if(path[adj[id][i]]!=-2){

            print(id, adj[id][i], path);
        }
        // cout<<path[adj[id][i]]<<'\n';
    }

    path[id]=-2;
    return;
}


bool checkCycle(int id, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& path){

    vis[id] = true;
    path[id]=1;

    for(int i=0;i<adj[id].size();i++){

        if(!vis[i]){

            if(checkCycle(i, adj, vis, path))return true;

        }
        else if(path[i])return true;
    }
    path[id]=0;

    return false;
}

void solve(int n, vector<vector<int>>& adj){

    vector<bool> vis(n+1, false);
    vector<int> path(n+1, -2);
    vis[0]=true;
    for(int i=0;i<=n;i++){

        if(!vis[i]){
            path[i]=-1;
            fun(i, adj, vis ,path);
            path[i]=-2;
        }

    }
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i=0;i<m;i++){

        int a, b, c, d;
        cin>>a>>b>>c>>d;
        if(c>d)adj[a].push_back(b);
        else adj[b].push_back(a);
    }

    solve(n, adj);

    return 0;
}