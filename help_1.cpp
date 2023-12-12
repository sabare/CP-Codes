#include<bits/stdc++.h>
using namespace std;

vector<int> fin_ans;
int sz = 0;
void fun(vector<int>& arr, int i, int j, int val, vector<int>& ans){

    if(i>j){if(val>sz){sz = val;fin_ans = ans;}return;}
    if(i==j){

        ans[i] = arr[i];
        fun(arr, i+1, j-1, val+1, ans);
    }
    if(arr[i]==arr[j]){
        ans[i] = arr[i];
        ans[j] = arr[j];
        fun(arr, i+1, j-1, val+2, ans);
    }
    else{

        int val1 = arr[i];
        int val2 = arr[i+1];
        arr.erase(arr.begin()+i+1);
        arr[i] += val2;
        fun(arr, i, j-1, val, ans);

        arr.insert(arr.begin()+i+1, val2);
        arr[i]-=val2;

        val1 = arr[j];
        val2 = arr[j-1];

        arr.erase(arr.begin()+j-1);
        arr[j] += val2;
        fun(arr, i, j-1, val, ans);

        arr.insert(arr.begin()+j-1, val2);
        arr[j]-=val2;

    }

    return;
}

int main(){

    int n;
    cin>>n;
    vector<int> arr;
    for(int i = 0;i<n;i++){

        int a;
        cin>>a;
        arr.push_back(a);
    }
    
    vector<int> ans(n, INT_MIN);
    fun(arr, 0, n-1, 0, ans);

    for(auto it: fin_ans){
        if(it!=INT_MIN)
            cout<<it<<' ';
    }

    return 0;
}