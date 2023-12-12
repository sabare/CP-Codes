#include<bits/stdc++.h>
using namespace std;
int dp[1e5][1e5];
int fun(int i, int pre, vector<int>& a, vector<int>& b){
    if(i==n)return 0;
    if(dp[i][pre]!=-1)return dp[i][pre];
    int tk = 0, ntk = 0;
    if(pre==INT_MIN || (a[i]!=pre-1 && a[i]!=pre+1)){

        tk = a*b + fun(i+1, a[i], a, b);
    }

    ntk = fun(i+1, pre, a, b);

    return dp[i][pre] = max(tk, ntk);
}
int main(){

    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    vector<int>arr(n);
    sort(arr.begin(), arr.end());
    unordered_map<int, int> mp;
    for(auto it: arr){

        mp[it]++;
    }

    vector<int> a, b;
    for(auto it: mp){

        a.push_back(it.first);
        b.push_back(it.second);
    }

    fun(0, INT_MIN, a, b);
}