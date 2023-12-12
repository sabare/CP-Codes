#include<bits/stdc++.h>
using namespace std;


void solve(){

    int n, k ,p, q;
    cin>>n>>k>>p>>q;
    vector<long long> a(n);
    vector<long long> b(n);

    for(int i = 0;i<n;i++)cin>>a[i];
    for(int i = 0;i<n;i++)cin>>b[i];

    vector<vector<long long>>arr;

    for(long long i = 0;i<k;i++){

        long long l, r, w;
        cin>>l>>r>>w;
        arr.push_back({l, r, w});        
    }

    vector<long long> r(n+1, 0);
    for(auto it: arr){

        r[(it[0])-1]+=it[2];
        r[(it[1])]-=it[2];
    }


    long long temp = 0;
    for(int i = 0;i<n;i++){

        temp+=r[i];
        r[i] = temp;
    }

    long long ecs = 0;
    long long srt  = 0;
    long long diff = 0;
    for(int i = 0;i<n;i++){

        // if(r[i]<=a[i])srt+=a[i]-r[i];
        // else if(r[i]<b[i])diff+=r[i]-a[i];
        // else{
        //     diff+=r[i]-a[i];
        //     ecs+=r[i]-b[i];
        // }

        if(r[i]>=b[i]){ecs+=r[i]-b[i]; r[i] = b[i];}
        if(r[i]<=a[i])srt+=a[i]-r[i];
        if(r[i]>=a[i])diff+=r[i]-a[i];
    }   
    // long long ans = 0;
    // if(srt>diff)ans=-1;
    // else {

    //     if(ecs<srt){

    //         ans = srt*(p+q);
    //     }
    //     else ans = (p*(ecs))+(q*(srt));
    // }

    long long ans = 0;
    srt-=ecs;
    if(srt<=0)ans = ecs*p + srt*q;
    else if(srt<=diff){

        ans = ecs*(p+q) + srt*(q+p);
    }
    else ans = -1;

    cout<<ans<<'\n';

    return;
}
int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }
}