#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    string w1, w2;
    cin>>w1;
    cin>>w2;

    unordered_map<char, int> mp;

    for(int i=0;i<n;i++){

        mp[w1[i]]++;
        mp[w2[i]]--;
    }

    for(auto it: mp){

        if(abs(it.second)>3){cout<<"-1";return 0;}
    }

    int ch = w2.compare(w1);
    if(ch>=0)cout<<w1;
    else cout<<w2;
    return 0;

}