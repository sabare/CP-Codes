#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i = n-1;i>=0;i--)cin>>arr[i];
    int i = 0;
    int val = 1;
    int j = n-1;
    while(i<n){

        if(arr[i]>=val){if(j<0 || n-i!=arr[j]){cout<<"NO\n";return;}; j--; val++;}
        else i++;
    }

    cout<<"YES\n";    
    // ans==arr?cout<<"YES\n":cout<<"NO\n";
    return ;

}

int main(){

    int t;
    cin>>t;

    while(t--){

        solve();
    }

    return 0;
}