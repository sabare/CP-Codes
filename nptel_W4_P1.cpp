#include<bits/stdc++.h>

using namespace std;

/*class UnionFind {

    private :
        vector<int> p, rank, setSize;
        int numSets;

    public :
            UnionFind(int n){

                p.assign(n, 0);
                for(int i=0;i<n;i++){

                    p[i]=i;

                }

                rank.assign(n, 0);
                setSize.assign(n, 1);
                numSets = n;
            }

            int findSet(int i){

                if(p[i]==i)return i;

                return p[i] = findSet(p[i]);
            }

            void UnionSet(int i, int j){

                int x = findSet(i);
                int y = findSet(j);

                if(rank[x] > rank[y])swap(x, y);

                p[x] = y;

                if(rank[x]==rank[y])rank[y]++;
                setSize[y] +=setSize[x];
                numSets--;
            }

};*/

void solve(){

    int n;
    cin>>n;
    vector<vector<int>> arr(n, vector<int>(2));
    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){

        cin>>arr[i][0]>>arr[i][1];

        if(arr[i][0] !=0 mp.find(arr[i][0])==mp.end())mp[-2] = arr[i][0];
        mp[arr[i][0]]=arr[i][1];
        if(mp.find(arr[i][1])==mp.end())mp[arr[i][1]]=-1;
        
    }

    vector<int> ans(n, 0);
    int i = 0;
    int a = -2;
    int b = 0;
    while(i<n){

        if(i&1){

            ans[i] = mp[b];
            b = mp[b];
        }
        else {

            ans[i] = mp[a];
            a = mp[a];
        }

        i++;
    }

    for(auto it: ans){

        cout<<it<<" ";
    }

    return;
}

int main(){

    solve();
    return 0;
}