    #include<bits/stdc++.h>
    using namespace std;
     
    void solve(){
     
        int n;
        cin>>n;
     
        vector<vector<int>> a;
        for(int i = 0;i<n;i++){
     
            int b, c;
            cin>>b>>c;
     
            a.push_back({b, c});
        }
     
        int ans = INT_MAX;
     
        for(int i = 0;i<n;i++){
            
            if(a[i][0]>=ans){cout<<ans<<"\n";return;}
            int val = ((a[i][1]/2)-1 + (a[i][1]&1));
            ans = min(ans, a[i][0] + val);
        }
     
        cout<<ans<<'\n';
        return;
    }
     
    int main(){
     
     
        int t;
        cin>>t;
     
        while(t--){
            // cout<<"faf "<<t<<'\n';
            solve();
        }
     
        return 0;
    }