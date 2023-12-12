#include<bits/stdc++.h>
using namespace std;

int main(){


    int n;
    cin>>n;

    string s;
    cin>>s;
    int i = 0, j=0;
    unordered_map<char, int> mp;
    int ans = 0;
    while(j<n){

        if(mp.find(s[j])==mp.end() || mp[s[j]]==0){

            mp[s[j]]++;
            j++;
            ans+=(j-i+1);
        }
        else {

            mp[s[i]]--;
            i++;
        }
    }

    return 0;

}