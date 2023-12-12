#include<bits/stdc++.h>
using namespace std;


void solve(){

    int m, k, a, b;
    cin>>m>>k>>a>>b;

    if(m/k <= b){

        m = m%k;
        if(m<=a)cout<<"0\n";
        else {

            m-=a;
            int cnt = 0;
            
            if(m%k==0)cout<<m/k<<'\n';
            else{

                int dum = m%k;
                if(a>=  k - (m%k)){

                    cout<<(m/k) + 1<<'\n';
                }
                else{

                    cnt+=m/k;
                    m = m%k;
                    cout<<cnt+m<<'\n';
                } 
            }
        }
    }

    else {

        m-=b*k;
        if(m<=a)cout<<"0\n";
        else {

            m-=a;
            
            int cnt = 0;
            if(m%k==0)cout<<m/k<<'\n';
            else{

                int dum = m%k;
                if(a>=  k - (m%k)){

                    cout<<(m/k) + 1<<'\n';
                }
                else{

                    cnt+=m/k;
                    m = m%k;
                    cout<<cnt+m<<'\n';
                } 
            }
        }
    }

    return;
}

int main(){

    int t;
    cin>>t;
    while(t--){

        solve();
    }

    return 0;
}