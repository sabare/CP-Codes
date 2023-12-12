#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;

    vector<int> a(n, 0);
    for(int i=0;i<n;i++){

        cin>>a[i];
    }
    int i = 0, j = 0;
    int ans = 0;
    for(int i=0;i<n;i++){

        int s = a[i];
        i++;
        int c = 1, l= 0;
        int flag = 1;
        int pos = i;
        while(i<n){

            if(a[i]==s flag)c++;
            else if(l==c || (a[i]==s !flag)){ans = max(ans, 2*l);break;}
            else if(a[i]!=s flag){
                pos = i;
                flag = 0;
                l++;
            }
            else{l++;}
            if(flag)pos = i;
            i++;
        }

        ans = max(ans, 2*l);
        i = pos -1;
    }

    cout<<ans;
}