#include<bits/stdc++.h>
using namespace std;

bool bfs(long long a, long long b, long long n, vector<bool>& vis, vector<vector<vector<long long>>>& adj){

    vector<long long> dist(n, 0);
    queue<vector<long long>> q;
    vis[a] = true;
    q.push({a, b});

    while(!q.empty()){

        auto temp = q.front();
        long long node = temp[0];
        long long dis = temp[1];
        q.pop();
        for(auto it: adj[node]){
            long long adjNode = it[0];
            long long adjDis = it[1];
            if(vis[adjNode]){

                if((dis+adjDis)!=dist[adjNode]){
                    return false;
                }
                continue;
            }

            vis[adjNode] = true;
            dist[adjNode] = adjDis + dis;
            q.push({adjNode, dist[adjNode]});
        }
    }

    return true;
}

bool dfs(int a, int b, int n, vector<bool>& vis,vector<vector<vector<int>>>& adj, vector<long long>& dist){

    for(auto it: adj[a]){

        if(vis[it[0]]){

            if((b+it[1])!=dist[it[0]]){

                return false;
            }
            continue;
        }
        vis[it[0]] = true;
        dist[it[0]] = b + it[1];
        if(!dfs(it[0], dist[it[0]], n, vis, adj, dist))return false;;
    }

    return true;
}

void solve(){

    int n, m;
    cin>>n>>m;

    vector<vector<vector<int>>> adj(n);

    for(int i = 0;i<m;i++){

        int a, b, d;
        cin>>a>>b>>d;
        adj[a-1].push_back({b-1, d});
        adj[b-1].push_back({a-1, -d});

    }

    // for(auto it: adj){

    //     for(auto i: it){

    //         cout<<i[0]<<' ';
    //     }
    //     cout<<'\n';
    // }

    vector<bool> vis(n, false);

    for(int i = 0;i<n;i++){

        if(!vis[i]){
            vector<long long> dist(n, 0);
            if(!dfs(i, 0, n, vis, adj, dist)){cout<<"NO\n"; return;}
        }
    }


    cout<<"YES\n";
    return;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }

    return 0;
}