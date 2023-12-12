#include<bits/stdc++.h>
using namespace std;

bool fun(vector<int>& a,vector<bool>& vis, int tar, int tot, int i, int k) {
    if (k == 0)
        return true;
    
    if (tot == tar) 
        return fun(a, vis, tar, 0, 0, k-1);
    
    for (int j = i; j < a.size(); j++) {
        if (vis[j] || tot + a[j] > tar) continue; 
        vis[j] = true;
        if (fun(a, vis, tar, tot + a[j], j+1, k)) return true;
        vis[j] = false;
    }
    
    return false;
}

int solution(vector<int>& a, int n){

    int tot = 0;
    int ans = 0;
    for(int i=0;i<a.size();i++){

        tot+=a[i];
    }

    for(int i=tot/4;i>=0;i--){

        vector<bool> vis(a.size(), false);
        if(fun(a, vis, i, 0, 0, 4)){cout<<i;return i;}
    }

    // int low = 0, high = tot/4;
    // while(low<=high){

    //     int mid = low + (high-low)/2;
    //     vector<bool> vis(a.size(), false);

    //     if(fun(a, vis, mid, 0, 0, 4)){ans = mid; low = mid+1;}
    //     else high = mid-1;
    // }

    return ans;
}


int main(){

    int n;
    cin>>n;
    vector<int> a(n, 0);
    for(int i=0;i<n;i++){

        cin>>a[i];
    }

    solution(a, n);
}