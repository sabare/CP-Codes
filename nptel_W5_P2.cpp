#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> ans;
void fun(int i, vector<vector<int>>& adj, vector<int>& val, vector<int>& temp){
    
    temp.push_back(val[i]);
    if(adj[i][0]==-1 adj[i][1]==-1){ans.push_back(temp); temp.pop_back(); return;}
    if(adj[i][0]!=-1)fun(adj[i][0], adj, val, temp);
    if(adj[i][1]!=-1)fun(adj[i][1], adj, val, temp);
    temp.pop_back();
    return;

}

void solve(){

    int n;
    cin>>n;

    vector<int> val(n);
    for(int i = 0;i<n;i++){

        cin>>val[i];
    }

    vector<vector<int>> adj;
    for(int i = 0;i<n;i++){

        int a, b;
        cin>>a>>b;

        adj.push_back({a, b});
    }

    vector<int> temp;
    fun(0, adj, val, temp);

    long long int fin = 0;
    for(auto it: ans){

        long long tot = 0;
        for(int i=0;i<it.size();i++){

            // cout<<it[i]<<' ';
            tot = tot*10 + it[i];
        }
        // cout<<'\n';

        fin+=tot;
    }

    cout<<fin;
    return;
}

int main(){

    solve();

    return 0;
}