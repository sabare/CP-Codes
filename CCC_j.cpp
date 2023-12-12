#include<bits/stdc++.h>

using namespace std;

int check(int l, int r, vector<unordered_map<char, int>> mp){
    int tot = 0;
    unordered_map<char, int> mp2 = mp[r];
    if(l==0){

        for(auto it: mp2){

            tot+=it.second%2;
        }
    }
    else{

        unordered_map<char, int> mp1 = mp[l-1];
        for(auto it: mp2){

            if(mp1.find(it.first)==mp1.end()){tot+= it.second%2;}
            else{

                tot+=(it.second - mp1[it.first])%2;
            }
        }
    }
    
    return tot/2;
}

int main(){

    string s;
    cin>>s;
    int n = s.length();

    int m, k;
    cin>>m>>k;

    vector<pair<int, int>> q(m);
    for(int i=0;i<m;i++){

        int a, b;
        cin>>a>>b;
        q[i] = {a, b};
    }

    vector<unordered_map<char, int>> mp(n);
    unordered_map<char, int> dum;
    for(int i=0;i<n;i++){

        dum[s[i]]++;
        mp[i] = dum;
    }

    for(int i=0;i<m;i++){

        int a = q[i].first;
        int b = q[i].second;
        
        if(check(a, b, mp)>k)cout<<"-1\n";
        else cout<<"1\n";
    }

    return 0;
}