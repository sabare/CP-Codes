#include<bits/stdc++.h>

using namespace std;
int ans = 0;

void dfs(int i, vector<vector<int>>& adj, priority_queue<int> q1, priority_queue<int, vector<int>, greater<int>> q2, vector<bool>& vis, vector<int>& c){

    
    vis[i-1]=true;
    

    for(int j = 0;j<adj[i-1].size();j++){

        if(vis[adj[i-1][j]-1])continue;
        if(q1.empty()||q1.top()>c[j-1]){

            q1.push(c[j-1]);
        }
        else q2.push(c[j-1]);

        if(q1.size()>q2.size()+1){

            q2.push(q1.top());
            q1.pop();
        }
        else {

            q1.push(q2.top());
            q2.pop();
        }
        if(q1.size()==q2.size())ans+=(q1.top()+q2.top())/2;

        dfs(j, adj, q1, q2, vis);
        
    }
} 

int main(){

    int n;
    cin>>n;
    vector<int> c(n, 0);
    for(int i=0;i<n;i++){

        cin>>c[i];
    }
    vector<vector<int>> edg(n, vector<int>(2, 0));
    for(int i=0;i<n;i++){


        int a, b;
        cin>>a;
        cin>>b;
        edg[i] = {a,b};
    }

    vector<vector<int>>adj;
    for(int i=0;i<edg.size();i++){

        adj[edg[i][0]].push_back(edg[i][1]);
        adj[edg[i][1]].push_back(edg[i][0]);
    }

    vector<bool> vis(n, false);
    priority_queue<int> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    dfs(1, adj, q1, q2, vis, c);
    return ans;

}