#include<bits/stdc++.h>
using namespace std;

void fun(vector<vector<vector<int>>>& adj, vector<int>& dis){

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
            if(dist + edgeWeight>=time[adjNode])continue;
            if(dis[adjNode] > dist + edgeWeight){

                dis[adjNode] = dist + edgeWeight;
                pq.push({dis[adjNode], adjNode});
            }

        }

        
    }

    return;

}
vector<int> fun(int n, vector<int> time, vector<int> ep1, vector<int> ep2, vector<int> edg){

    vector<int> res(n, INT_MAX);

    int m = ep1.size();
    vector<vector<int>> adj(n+1);
    for(int i = 0;i<m;i++){

        adj[ep1[i]].push_back(ep2[i]);
        adj[ep2[i]].push_back(ep1[i]);
    }

    priority_queue<int, vector<int>, greater<int>> q;
    q.push(1);

    while(!q.empty()){


    }

}
int main(){


}