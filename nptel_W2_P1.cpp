#include<bits/stdc++.h>
using namespace std;

int lb(vector<int> tile, int num){

    int low = 0, high = tile.size()-1;
    int ans = high;
    while(low<=high){


        int mid = low + (high-low)/2;

        if(tile[mid]>num){ans = mid, high = mid-1;}
        else low = mid+1;
    }

    return ans;
}

int main(){

     int n;
     cin>>n;
     vector<int> a(n);
     vector<int> tile;

     for(int i=0;i<n;i++){

        cin>>a[i];  
     }  

     tile.push_back(a[0]);
     for(int i=1;i<n;i++){

        if(a[i]>=tile.back()){tile.push_back(a[i]);}
        else {
            int pos = lb(tile, a[i]);
            tile[pos] = a[i];
        }
     }
     int ans = tile.size();
     cout<<ans;

     return 0;

}