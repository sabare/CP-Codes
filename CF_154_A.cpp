#include<bits/stdc++.h>

using namespace std;

void solve(){

    int n, m;
    cin>>n>>m;
    vector<vector<char>> c(n, vector<char>(m, ' '));

    for(int i= 0;i<n;i++)for(int j=0;j<m;j++)cin>>c[i][j];
    string s = "vika";
    int p = 0;
    for(int i=0;i<m;i++){

        if(p==4){cout<<"YES\n";return ;}
        for(int j=0;j<n;j++){

            if(c[j][i]==s[p]){

                p++;
                break;
            }

        }
    }

    p==4?cout<<"YES\n":cout<<"NO\n";
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