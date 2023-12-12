#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll fun(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& vis){

    if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || vis[i][j])return 0;
    vis[i][j]=true;
    if(grid[i][j]==0)return 0;

    return grid[i][j] + fun(i+1, j, grid, vis) + fun(i-1, j, grid, vis) + fun(i, j+1, grid, vis) + fun(i, j-1, grid, vis);

}
void solve(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>grid[i][j];

    vector<vector<bool>> vis(n, vector<bool>(m, false));

    ll ans = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<m;j++){

            if(!vis[i][j]){

                ans = max (ans, fun(i, j, grid, vis));
            }
        }
    }

    cout<<ans;

    return;

}

int main(){

    solve();
    return 0;
}