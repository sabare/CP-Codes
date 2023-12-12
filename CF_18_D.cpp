#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<vector<int>> adj(n+1);
    for(int i=0;i<n-1;i++){

        int a, b;
        cin>>a>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    queue<int> q;
    q.push(1);
    int i = 1;
    vector<bool> vis(n+1, false);
    vis[1] = true;
    while(!q.empty()){

        int sz = q.size();
        vector<int> arr;
        while(sz--){

            int node = q.front();
            q.pop();
            for(auto it: adj[node]){

                if(vis[it])continue;
                vis[it] = true;
                arr.push_back(it);
                q.push(it);
            }

        }
        sort(arr.begin(), arr.end());
        vector<int> temp;
        f
    }

    return 0;
}