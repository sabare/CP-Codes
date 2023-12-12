#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;

    string s;
    cin>>s;
    int ans = 0;
    for(int i=n-1; i>=1;i--){

        if(s[i]=='u'){

            s[i]='d';
            if(s[i-1]=='u')s[i-1]='d';
            else s[i-1]='u';
            ans++;
        }
    }

    for(int i=0;i<n;i++){

        if(s[i]=='u'){cout<<"-1\n";return;}
    }
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