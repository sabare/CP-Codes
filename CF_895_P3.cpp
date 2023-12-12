    #include<bits/stdc++.h>
    using namespace std;
     
     
    long long prime(long long n){
     
        if(n%2==0)return 2;
     
        for(int i = 3;i<=sqrt(n);i++){
     
            if(n%i==0){
     
                return i;
            }

        }
     
        return n;
    }
    void solve(){  
     
     
     
        int l, r;
        cin>>l>>r;
        if(r<=3){cout<<"-1\n";return;}
        else{
     
            if(l<r){
     
                r-=r&1;
                cout<<2<<' '<<r-2<<'\n';
                return;
            }
            else{
                long long temp = r;
                long long pr = prime(temp);
                if(pr==r){cout<<"-1\n";return;}
                else{
     
                    cout<<pr<<" "<<r - pr<<'\n';
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