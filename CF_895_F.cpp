#include<bits/stdc++.h>
using namespace std;

void dfs(int i, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& arr){

    for(auto it: adj[i]){

        if(vis[it])continue;
        vis[it] = true;
        arr.push_back(it);
        dfs(it, adj, vis, arr);
    }
    return;
}

void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> c(n);

    for(int i=0;i<n;i++){

        cin>>a[i];
    }    
    
    for(int i=0;i<n;i++){

        cin>>c[i];
    }    

    vector<vector<int>> adj(n);

    for(int i=0;i<n;i++){

        adj[i].push_back(a[i]-1);
    }
    vector<int> in_degree(n, 0);
    for(auto it: a){
        in_degree[it-1]++;
    }

    vector<int> ans;
    queue<int> q;
    vector<bool> vis(n, false);
    for(int i=0;i<n;i++){

        if(in_degree[i]==0){
            q.push(i);
            ans.push_back(i);
            vis[i] = true;
        }
    }
    
    while(!q.empty()){
        
        int val = q.front();
        q.pop();
        
        for(auto it: adj[val]){

            if(--in_degree[it]==0){

                q.push(it);
                vis[it] = true;
                ans.push_back(it);
            }
            
        }

    }

    
    //cout<<"\n";
    for(int i = 0;i<n;i++){

        vector<int> arr;
        if(vis[i])continue;
        vis[i] = true;

        arr.push_back(i);
        
        dfs(i, adj, vis, arr);
        // for(auto it: arr){
        //     cout<<it<<' ';
        // }
        // cout<<'\n';

        int mini = INT_MAX;
        int pos = 0;

        for(int i = 0;i<arr.size();i++){

            if(c[arr[i]]<mini){

                mini = c[arr[i]];
                pos = i;
            }
        }

    
        //cout<<pos<<" <=\n";

        int temp = pos;
        temp = (temp+1)%(arr.size());
        while(temp!=pos){

            ans.push_back(arr[temp]);
            temp = (temp+1)%(arr.size());
        }
        ans.push_back(arr[temp]);

    }

    for(auto it: ans){

       cout<<it+1<<' ';
    }
    cout<<"\n";

    return ;

    
}

int main(){


    int t;
    cin>>t;
    while(t--){

        solve();
    }
}