#include<bits/stdc++.h>
using namespace std;


int main() {

int k;

int n;
cin>>k>>n;

vector<int> v(n); 
for(int i=0;i<n;i++) cin>>v[i];
int z=min(k-1,n-1);
priority_queue<int,vector<int>, greater<int>> pq; 
for(int i=0;i<=z;i++)

    pq.push(v[i]);   
z++;
vector<int> ans;

while(!pq.empty()){ 
    
    int x=pq.top(); 
    ans.push_back(x+1); 
    pq.pop(); 
    if(z<n && v[z]<=x+1){
        int p=max(x+1,v[z]);
        pq.push(p);
        z++;
    }

    if(z<n && pq.size()<k){
        pq.push(v[z]);
        z++;
    }
}
for(int i=z;i<n;i++)
    ans.push_back(v[i]+1);

for(int x:ans)
    cout<<x<<' ';

return 0;
}