#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n, m;
    cin>>n>>m;

    
    vector<vector<int>> mat(n, vector<int>(m, 0));
    vector<vector<int>> grid(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    for(int i = 0;i<n;i++){

        for(int j = 0;j<m;j++){

            cin>>mat[i][j];
            if(mat[i][j] == 0){

                q.push({i, j});
                grid[i][j] = 0;
            }
        }
    }
    vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    int val = 1;
    int ans =INT_MAX;

    while(!q.empty()){

        int sz = q.size();
        while(sz--){

            auto crd = q.front();
            q.pop();

            for(auto d: dir){

                int dx = crd.first + d[0];
                int dy = crd.second + d[1];

                if(dx<0 || dx>=n || dy<0 || dy>=m)continue;

                if(grid[dx][dy]==-1){grid[dx][dy] = val; q.push({dx, dy});}
                else{

                    // cout<<grid[dx][dy]+val<<'\n';
                    ans = min(ans, grid[dx][dy] + val);
                    
                }

            }   
        }
        val++;
    }
    ans==INT_MAX?cout<<"-1\n":cout<<ans<<'\n';
    // cout<<"-1\n";
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