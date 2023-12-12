#include<bits/stdc++.h>
using namespace std;


long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

void solve(){

    long long n, x, y;
    cin>>n>>x>>y;

    unordered_map<long long, long long> mp;

    long long k = 1;
    long long ans = 0;

    long long u = n/x;
    long long l = n/y;
    long long mid = n/lcm(x, y);

    // cout<<mid<<' ';
    ans += (n*(n+1))/2 - ((n-u+mid)*(n-u+mid+1))/2;


    ans -= ((l-mid)*(l - mid + 1))/2;

    cout<<ans<<'\n';
}

int main(){

    int t;
    cin>>t;

    while(t--){

        solve();
    }

    return 0;    
}