    #include<bits/stdc++.h>
    using namespace std;


    void solve(){


        int n, m;
        cin>>n>>m;

        vector<int> a(n), b(m);
        int tot = 0;
        for(int i=0;i<n;i++){

            cin>>a[i];
            tot+=a[i];
        }  
s
        for(int i=0;i<m;i++){

            cin>>b[i];
            tot-=b[i];
        }

        if(tot>0)cout<<"Yudhisthira\n";
        else if(tot<0)cout<<"Duryodhana\n";
        else cout<<"Draw\n";

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