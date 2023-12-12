#include<bits/stdc++.h>

using namespace std;

void solve(){

    int n;
    cin>>n;
    vector<int> a(n);

    for(int i = 0;i<n;i++){

        cin>>a[i];
    }

    vector<int> ans;
    ans.push_back(a[0]);
    for(int i = 1;i<n;i++){

        if(ans.back()<=a[i])ans.push_back(a[i]);
        else {

            ans.push_back(1);
            ans.push_back(a[i]);
        }
    }

    cout<<ans.size()<<'\n';
    for(int i= 0;i<ans.size();i++){

        cout<<ans[i]<<" ";
    }

    cout<<'\n';

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