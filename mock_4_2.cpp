#include<bits/stdc++.h>
using namespace std;

long long dfs(int i, int j, vector<vector<int>>& grid, vector<vector<long long>>& dp){
    int n = grid.size(), m = grid[0].size();

    if(i==n-1 && j==m-1)return grid[i][j];

    if(i>=n || j>=m)return INT_MIN;
    if(dp[i][j]!=-1)return dp[i][j];
    return dp[i][j] = grid[i][j] + max(dfs(i+1, j, grid, dp), dfs(i, j+1, grid, dp));
}

int main(){

    int n, m;
    cin>>n>>m;

    vector<vector<int>>grid(n, vector<int>(m));
    for(int i = 0;i<n;i++){

        for(int j = 0;j<m;j++){

            cin>>grid[i][j];
        }
    }
    vector<vector<long long>> dp(n, vector<long long>(m, -1));
    cout<<dfs(0, 0, grid, dp);
    return 0;
}