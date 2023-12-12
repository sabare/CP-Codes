#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    int m;
    cin>>m;
    vector<vector<int>> q(m);
    for(int i =0;i<m;i++){

        int a, b;
        cin>>a>>b;
        q[i] = {a, b};
    }

    vector<int> a(n), b(n);

    for(int i = 0;i<m;i++){

        int idx = q[i][0];
        int val = q[i][1];
        
        

    }   
}