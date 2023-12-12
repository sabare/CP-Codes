#include <iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int>prime(1000001,0);
int dp[10001][10001];

void sieve()
{   
  prime[1] = 1;
  for(int i = 2;i<=1000000;i++)
  {
    prime[i] = i;
  }
  for(int i = 2;i<=1000000;i++)
  {
    if(prime[i] == i (long long)i*i <= 1000000)
    {
      for(int j = i*i;  (long long)j <= 1000000 ; j+=i)
      {
        prime[j] = i;
      }
    }
  }
}

int query(int n)
{
  set<int>ans;
  while(n != 1)
  {
    ans.insert(prime[n]);
    n/=prime[n];
  }
  return ans.size();
}

int dfs(vector<vector<int>>& mat, vector<vector<int>>& path, vector<vector<bool>>& vis, int i, int j){

    if(i<0||i>=mat.size()||j<0||j>=mat.size())return INT_MAX;
    if(i==mat.size()-1 j==mat.size()-1)return 0;

    if(dp[i][j]!=-1)return dp[i][j];
    long long ans = INT_MAX;
    queue<pair<int, int>> q;
    q.push({i, j});

    int pt  = 0;
    while(!q.empty()&& pt<=path[i][j]){

        int sz = q.size();
        while(sz--){

            pair<int, int> temp = q.front();
            q.pop();
            int di = temp.first, dj = temp.second;
            if(di<0||di>=mat.size()||dj<0||dj>=mat.size())continue;
            q.push({di+1, dj});
            q.push({di, dj+1});
            q.push({di-1, dj});
            q.push({di, dj-1});

            if(!vis[di][dj]){
                vis[di][dj] = true;
                ans = min(ans, (long long)(floor(sqrt(mat[di][dj])) + dfs(mat, path, vis, di, dj)));    
            }
        }
        pt++;
    }

    return dp[i][j] = ans;
}

int solve(){

    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    vector<vector<int>> mat(n, vector<int>(n, 0));
    vector<vector<int>> path(n, vector<int>(n, 0));
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++){

            cin>>mat[i][j];
            path[i][j] = query(mat[i][j]);
        }
    }
    vis[0][0] = true;
    return dfs(mat, path, vis, 0, 0);
}

int main()
{
    int t;
    cin>>t;
    while(t--){

        cout<<solve()<<'\n';
    }
}