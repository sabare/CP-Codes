#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    
    vector<int> arr(n);

    for(int i = 0;i<n;i++){

        cin>>arr[i];
    }

    int o =0, e = 0;
    for(int i = 0;i<n;i++){

        if(arr[i]&1)o++;
        else e++;
    }
    int ans = 0;
    if(n ==1)ans = 1;
    else if(max(o, e)==1)ans = 2;
    else ans = max(o, e);

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