#include<bits/stdc++.h>
using namespace std;

void solve(int n, int m, int d, vector<pair<int, int>>& a, vector<pair<int, int>>& b){

    sort(a.begin(), a.end(), greater<pair<int, int>>());
    sort(b.begin(), b.end(), greater<pair<int, int>>());

    int i = 0, j = 0;
    vector<pair<int, int>> ans;
    while(d--){

        if(i>=n){ans.push_back({b[j].second, b[j].first});j++;}
        else if(j>=m){ans.push_back({a[i].second, a[i].first});i++;}

        else{

            if(a[i]>=b[j]){ans.push_back({a[i].second, a[i].first});i++;}
            else {ans.push_back({b[j].second, b[j].first});j++;}
        }

    }

    sort(ans.begin(), ans.end());
    for(auto it: ans){

        cout<<it.second<<" ";
    }

    return;

}
int main(){

    int m, n, d;
    cin>>m>>n>>d;
    vector<pair<int, int>>a(m);
    vector<pair<int, int>>b(n);
    for(int i=0;i<m;i++){int temp; cin>>temp; a[i] = {temp, i};}
    for(int i=0;i<n;i++){int temp; cin>>temp; b[i] = {temp, i};}

    solve(m, n, d, a, b);
    return 0;
}