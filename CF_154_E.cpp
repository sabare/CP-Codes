#include<bits/stdc++.h>

using namespace std;

int fun(int i, int pre, int m, vector<int>& arr, int d){

    if(m==0 || i>=arr.size())return 0;

    long long pk = arr[i] - d*(i+1-pre) + fun(i+1, i+1, m-1, arr, d);
    long long npk = fun(i+1, pre, m, arr, d);

    return max(pk, npk);
}

void solve(){

    int n, m, d;
    cin>>n>>m>>d;

    vector<int> arr(n);
    for(int i = 0;i<n;i++)cin>>arr[i];

    
    cout<<fun(0, 0, m, arr, d)<<'\n';

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