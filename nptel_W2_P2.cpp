#include<bits/stdc++.h>

using namespace std;

int main(){

    int n, k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    int i = 0, cnt  = 0;
    vector<int> temp;
    while(i<n){
        temp.push_back(a[i]);
        cnt++;

        if(cnt==k){

            sort(temp.begin(), temp.end());
            for(int i=0;i<temp.size();i++){

                cout<<temp[i]<<' ';
            }
            temp.clear();
            cnt = 0;
        }

        i++;
        
    }

    if(temp.size()){

        sort(temp.begin(), temp.end());
        for(int i=0;i<temp.size();i++){

            cout<<temp[i]<<' ';
        }
    }
    return 0;
}