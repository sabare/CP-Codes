#include<bits/stdc++.h>

using namespace std;

float pnorm(vector<int>& v, int p){


    float ans = 0;
    int n = v.size();
    for(int i = 0;i<n;i++){

        ans+= pow(abs(v[i]), p);
    }
    float inv = 1.0/(float(p)*1.0);
    ans = pow(ans, inv);

    return ans;
}

int main(){

    int n;
    cout<<"Enter size of vector : ";
    cin>>n;
    vector<int> v(n);

    cout<<"\n\n Enter values of the vector : ";
    for(int i = 0;i<n;i++)cin>>v[i];

    int p = 2;

    float v_val = 0;

    v_val = pnorm(v, p);

    cout<<"\n\n p-normal vector for the vector is :";
    cout<<v_val<<"\n\n";

    return 0;
}