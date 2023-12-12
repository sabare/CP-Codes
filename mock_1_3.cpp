#include<bits/stdc++.h>
using namespace std;

long long fun(int i, int k, vector<int>& cur, vector<int>& fut, vector<vector<long long>>& dp){

    int n = cur.size();
    if(i==n)return 0;
   
    if(dp[i][k]!=-1)return dp[i][k];


    long long tk =  0, ntk = 0;

    if(k>=cur[i]){

        tk = fut[i]-cur[i] + fun(i+1, k-cur[i], cur, fut, dp);
    }

    ntk  = fun(i+1, k, cur, fut, dp);

    return dp[i][k] = max(tk, ntk);
}
void solve(){

    int n, k;
    cin>>n>>k;
    vector<int>cur(n);
    vector<int>fut(n);

    for(int i = 0;i<n;i++){

        cin>>cur[i];
    }
    
    for(int i = 0;i<n;i++){

        cin>>fut[i];
    }
    vector<vector<long long>> dp(n+1, vector<long long>(k+1, -1));
    cout<<fun(0, k, cur, fut, dp);
    return;
}

int main(){


    solve();

    return 0;
}