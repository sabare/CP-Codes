#include<bits/stdc++.h>

using namespace std;


void dijkstra(vector<vector<int>>& adj, vector<bool>& vis){

    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(1);
    vis[1] = true;
    while(!pq.empty()){

        int sz = pq.size();

        while(sz--){

            int node = pq.top();
            pq.pop();
            cout<<node<<' ';
            for(auto it: adj[node]){

                if(vis[it])continue;
                vis[it] = true;
                pq.push(it);
            }
        }
    }

    return;
}
int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> adj(n+1);

    for(int i = 0;i<m;i++){

        int a, b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> vis(n+1, false);
    dijkstra(adj, vis);

    return 0;
}