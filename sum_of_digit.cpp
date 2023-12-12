#include<bits/stdc++.h>
using namespace std;


int check(int x){

    int tot = 0;
    while(x>0){

        tot+=x%10;
        x/=10;
    }

    return tot;
}
int main(){

    int x, y;
    cin>>x>>y;
    int ans = 0;
    for(int i = 1;i<=x;i++){

        if(check(i)==y)ans++;
    }


    cout<<ans;
    return 0;
}