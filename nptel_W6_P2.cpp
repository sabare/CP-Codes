#include<bits/stdc++.h>

using namespace std;

void dijkstra(vector<vector<vector<int>>>& adj, vector<int>& dis, int src){

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, src});
    dis[src] = 0;

    while(!pq.empty()){

        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for(auto it: adj[node]){

            int adjNode = it[0];
            int edgeWeight = it[1];

            if(dis[adjNode] > dist + edgeWeight){

                dis[adjNode] = dist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }

        }

        
    }

    return;

}

int main(){

    int n;
    cin>>n;

    int src;
    cin>>src;

    vector<vector<vector<int>>> adj(n);

    for(int i = 0; i<n;i++){

        int cnt;
        cin>>cnt;
        while(cnt--){

            int a,b;
            cin>>a>>b;
            adj[i].push_back({a, b});
        }
    }
    vector<int> dis(n, INT_MAX);
    dijkstra(adj, dis, src);

    int tot = 0;

    for(auto it: dis){

        if(it==INT_MAX){cout<<"-1";return 0;}
        tot = max(tot,it);
    }

    cout<<tot;
    return 0;

}