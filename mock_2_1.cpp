#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n, k;
    cin>>n>>k;

    vector<int> arr(n, 0);
    long long ans = 0;
    for(int i = 0;i<n;i++){cin>>arr[i];ans+=arr[i];}
    int i = 0;
    int j = 0;
    long long tot = 0;
    for(j = 0;j<k-1 j<n;j++)tot+=arr[j];
    long long maxi = 0;
    maxi = min(maxi, tot);
    while(j<n){
        tot-=arr[i];
        tot+=arr[j];
        maxi = min(maxi, tot);
        i++;j++;
    }
    //cout<<ans<<' '<<maxi<<'\n';
    ans-=maxi;
    cout<<ans<<'\n';
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