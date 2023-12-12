#include<bits/stdc++.h>
using namespace std;

int lower_bound(int x, vector<int>& ax){
    int n = ax.size();
    int low = 0, high = n;
    int ans = 0;
    while(low<=high){

        int mid  = low +(high-low)/2;

        if(ax[mid]==x)return mid;
        if(ax[mid]>x){

            high = mid-1;
        }
        else {

            ans = mid;
            low = mid+1;
        }
    }

    return ans;
}

double f(int x0, int y0, int x1, int y1, int X){

    double ans = (X-x0)*1.0;
    ans/=(x1-x0);
    ans*=(y1-y0);
    ans+=y0;
    return ans;
}

int main(){
    int n;
    cin>>n;
    vector<int> ax(n+2);
    ax[0] = 2;
    for(int i = 0;i<n;i++){

        cin>>ax[i+1];
    }
    ax[n+1] = 2000;
    int idx = lower_bound(X, ax);
    int x0 = 
    f(x0, y0, x1, y1, X);
}