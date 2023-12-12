#include<bits/stdc++.h>

using namespace std;

void solve(){

    long long n;
    cin>>n;

    vector<vector<long long>> arr;
    long long sz = 0;
    for(long long i= 0;i<n;i++){

        long long a, b;
        cin>>a>>b;
        sz = max(sz, b);
        arr.push_back({b, a});
    }

    sort(arr.begin(), arr.end());

    long long last = 0;
    long long ans = 0;
    for(long long i = 0;i<n;i++){
       
       if(arr[i][0]>){

        last = i;
        ans++;
       }


    }

    cout<<ans<<'\n';
}

int main(){

    int t;
    cin>>t;

    while(t--){

        solve();
    }
}