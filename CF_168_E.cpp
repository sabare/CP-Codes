#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n,m, k;
    cin>>n>>m>>k;

    vector<int> time(n);
    for(auto it: time){

        cin>>it;
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);
    for(int i =0;i<m;i++){

        int a, b;
        cin>>a>>b;

        adj[a-1].push_back(b-1);
        in_degree[b-1]++;
    }
    priority_queue<vector<int>> pq;

    for(int i = 0;i<in_degree.size();i++){

        if(in_degree[i]==0)pq.push({time[i], i});
    }
    int ans = pq.top()[0];
    
    while(!pq.empty()){

        auto var = pq.top();
        pq.pop();
        int node = var[1];
        for(auto it: adj[node]){

            pq.push({time[it],it});
            
        }
    }
}
int main(){

    int t;
    cin>>t;

    while(t--){

        solve();
    }   

    return 0;
}