#include <iostream>
#include <vector>

using namespace std;

int fun(int idx, vector<int>& k,vector<vector<int>>& l){

    if(idx==l.size())return 0;
    for(int i = 0;i<l[0].size();i++){

        if(l[idx][i]==1){

            ans = min({ans, fun(idx+1, k, l), fun(idx, k-1, l)})  
        }
    }
}
int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> l(n, vector<int>(m));
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            l[i][j] = s[j] - '0';
        }
    }

   fun(0, k, l);

    return 0;
}
