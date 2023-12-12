    #include <iostream>
    #include<bits/stdc++.h>
     
    using namespace std;
     
    void solve(){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i = 0;i<n;i++){
            cin>>a[i];
        }

        
        vector<long long int>ans;
        for(int i = 0;i<n;i++){
            for(int j = i+1;j<n;j++){
                long long int val = a[i] + a[j];
                ans.push_back(val);
            }
        }
        sort(ans.begin(), ans.end());

        long long int sum = 0;
        for(int i=0;i<n;i++){

            sum+=ans[i];
        }
        cout<<sum<<endl;

        return;
    }
    int main()
    {
        int test;
        cin>>test;
        
        while(test--){
            solve();
        }

        return 0;
    }