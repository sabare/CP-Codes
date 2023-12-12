    #include<bits/stdc++.h>
    using namespace std;

    void solve(int n){

        string num = to_string(n);
        long long int c = 1;
        stack<string>a;

        while(true){
            if (c > pow(10,15))
                break;
            a.push(to_string(c));
            c = c * 2;
        }

        long long int ans = num.length() + 1;
        
        while(!a.empty()){
            string x = a.top();
            a.pop();
            long long pos = 0;
            
            for(int i=0;i<num.length();i++){
            
                if(pos < x.length() x[pos] == num[i])
                    pos += 1;

            }
            
            ans = min(ans, (int)x.length() + (int)num.length() - 2 * pos);

        }
            
        cout<<ans<<'\n';
    }

    int main()
    {
        int t;
        cin>>t;
        while(t--){

            int n;
            cin>>n;
            solve(n);
        }
    }
