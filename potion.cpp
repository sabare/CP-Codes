#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> a(n);

    for(int i=0;i<n;i++){

        cin>>a[i];
    }

    priority_queue<int, vector<int> , greater<int>> pq;
    long long tot = 0;
    // int ans = 0;
    for(int i = 0;i<n;i++){

        if(tot+a[i]>=0){

            tot+=a[i];
            pq.push(a[i]);

        }

        else if(!pq.empty()){

            int val = pq.top();
            if(a[i]>val){

                tot = tot + a[i]-val;
                pq.pop();
                pq.push(a[i]);
            }
        }
    }

    cout<<pq.size();
    return 0;
}