#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
void fun(int i, vector<vector<int>>& adj){
    
    
    return;

}

void solve(){

    int n;
    cin>>n;

    vector<int> val(n);
    for(int i = 0;i<n;i++){

        cin>>val[i];
    }

    vector<vector<int>> adj(n, vector<int>());
    vector<int> l;
    for(int i = 0;i<n;i++){

        int a, b;
        cin>>a>>b;

        if(a!=-1)adj[a].push_back(i);
        if(b!=-1)adj[b].push_back(i);

        if(a==-1 b==-1)l.push_back(i);
        
    }

    for(auto it: l){

        fun(it, adj);
    }
    return;
}

int main(){

    solve();

    return 0;
}