#include<bits/stdc++.h>

using namespace std;

void forward_elimination(vector<vector<double>>& A, vector<vector<double>>& B, int n){

	
	for(int i=0;i<n-1;i++){
		
		for(int j= i+1;j<n;j++){
			
			float temp = A[j][i]/ A[i][i];
			
			for(int k = 0;k<n;k++){
			
				A[j][k] = A[j][k] - temp*A[i][k];
			}
			
			B[j][0] = B[j][0] - temp*B[i][0];
		}
	}
	return;
}


void backward_substitution(vector<vector<double>>& A, vector<vector<double>>& x, vector<vector<double>>& B, int n){

	
	for(int i = n-1;i>=0;i--){
		
		double temp = B[i][0];
		for(int j = n-1;j>i;j--){
			
			temp-=A[i][j]*x[j][0];
		}
		
		x[i][0] = temp/A[i][i];
		
		
	}
	
	return;
}

int main(){

    vector<int> N = {32, 64, 128, 512, 1024};
    ofstream File("A2_P1_output.txt", ios::out);
    for(auto n: N){
        
        vector<vector<double>> A(n, vector<double>(n, 0.0));
        vector<vector<double>> B(n, vector<double>(1, 1.0));
        vector<vector<double>> x(n, vector<double>(1, 0.0));
        
        for(int i=0;i<n;i++)for(int j=0;j<n;j++)A[i][j] = max(i+1, j+1);
        
        forward_elimination(A, B, n);
        backward_substitution(A, x, B, n);
        
        // for(int i=0;i<n;i++){
        //     cout<<x[i][0];
        //     cout<<'\n';
        // }

        double sum = 0;
        for(int i=0;i<n;i++){

            sum = sum + x[i][0]*x[i][0];
        }
        File<<n<<" : "<<1/sum<<endl;
        cout<<n<<" : "<<1/sum<<endl;
    }
	
	return 0;
}
