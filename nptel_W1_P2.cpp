#include<bits/stdc++.h>
using namespace std;




void solve(){

    int n, m, s, x;
    cin>>m>>n>>s>>x;
    vector<vector<int>> arr(m, vector<int>(n, 0));

    for(int i = 0;i<m;i++){

        for(int j=0;j<n;j++){
            
            cin>>arr[i][j];
        }
    }
    


    s = s%(2*(n+m)-4);

    for(int i = 0;i<n;i++){

        if(i%x==0){

            cout<<gv(s, i, 0)<<" ";
        }
    }

    // for(int j =0;j<m;j++){

    //     if((j + (n-1))%x == 0)cout<<gv(s, n-1, j)<<" ";

    // }

    // for(int i=n-1;i>=0;i--){

    //     if((i+(m-1))%x==0)cout<<gv(s, i, m-1)<<" ";
    // }

    // for(int j = m-1;j>=0;j--){

    //     if(j%x==0)cout<<gv(s, 0, j)<<" ";
    // }

    return;

        
}


int main(){

    solve();
    return 0;
}