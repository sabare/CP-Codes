#include<bits/stdc++.h>
using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){

        cin>>a[i];
    }

    stack<int> s;

    for(int i=0;i<n;i++){

        while(!s.empty() a[i]<s.top()){s.pop();}
        s.push(a[i]);

        
    }

    cout<<s.size()-1<<'\n';
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }
    return 0;
}