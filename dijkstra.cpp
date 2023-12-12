#include<bits/stdc++.h>
using namespace std;

void dijkstra(vector<vector<vector<int>>>& adj, vector<int>& dis, vector<int>& path){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    dis[1] = 0;

    while(!pq.empty()){

        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){

            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dis[adjNode] > dist + edgeWeight){

                dis[adjNode] = dist + edgeWeight;
                path[adjNode] = node;
                pq.push({dis[adjNode], adjNode});
            }

        }

        
    }

    return;

}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<vector<int>>> adj(n+1);
    vector<int> dis(n+1, 1e9);
    vector<int> path(n+1, -1);
    for(int i = 0;i<m;i++){
        int a, b, c;
        cin>>a>>b>>c;

        adj[a].push_back({b, c});
        adj[b].push_back({a, c});        
    }

    dijkstra(adj, dis, path);

    vector<int> ans;

    int fin = n;
    while(fin!=1){

        if(fin==-1){cout<<-1;return 0;}
        ans.push_back(fin);
        fin = path[fin];
    }
    cout<<"1 ";
    for(int i = ans.size()-1;i>=0;i--){

        cout<<ans[i]<<' ';
    }
    cout<<'\n';
    return 0;
}