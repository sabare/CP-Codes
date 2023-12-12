#include<bits/stdc++.h>
using namespace std;


void forward_elimination(vector<vector<double>>& a, vector<double>& b, int n){
	for(int j=0;j<n;j++){

		double maxi = 0;
		int max_pos= j;

		for(int i=j;i<n;i++){

			if(maxi<a[i][j]){

				maxi=a[i][j];
				max_pos = i;
			}
		}

        
		vector<double> temp = a[j];
		a[j] = a[max_pos];
		a[max_pos] = temp;
		
		double temp2 = b[j];
		b[j] = b[max_pos];
		b[max_pos] = temp2;
		
		double pvt = a[j][j];
		for(int i=j+1;i<n;i++){

			double c = a[i][j]/pvt;
			b[i] = b[i] - c*b[j];
			
            for(int k=0;k<n;k++){
			
            	a[i][k] = a[i][k] - c*a[j][k];
            }
		}
	}

    return;
}
vector<double> back_substitution(vector<vector<double>>& a, vector<double>& b, int n){

    vector<double> fin(n);
	for(int i=n-1;i>=0;i--)
	{
		fin[i] = b[i]/ a[i][i];
		for(int j=i+1;j<n;j++)
			fin[i] = fin[i] - (a[i][j]/ a[i][i])* fin[j];
	}
	return fin;
}


int main(){
	int n;
	cin>>n;
	
    vector<vector<double>> a(n, vector<double>(n, 0));
	vector<double> b(n);

	// for(int i=0;i<n;i++){
	// 	for(int j=0;j<n;j++){
			
    //         cin>>a[i][j];
    //     }
	// }

	a[0] = {-4, 1, 1, 0, 0, 0, 0, 0};	
	a[1] = {1, 0, -4, 1, 1, 0, 0, 0};
	a[2] = {0, 0, 1, 0, -4, 1, 1, 0};
	a[3] = {2, -4, 0, 1, 0, 0, 0, 0};
	a[4] = {0, 1, 2, -4, 0, 1, 0, 0};
	a[5] = {0, 0, 0, 1, 2, -4, 0, 1};
	a[6] = {0, 0, 0, 0, 2, 0, -9, 1};
	a[7] = {0, 0, 0, 0, 0, 2, 2, -9};
	
	// for(int i=0;i<n;i++){

    //     cin>>b[i];
    // }
	b = {-1000, -500, -500, -500, 0, 0, -2000, -1500};

	
	forward_elimination(a,b,n);


	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){

            cout<<a[i][j]<<' ';
        }
        cout<<'\n';		
	}


	for(int i=0;i<n;i++){

        cout<<b[i]<<' ';
    }

    cout<<'\n';

	vector<double> fin;
    fin = back_substitution(a,b,n);
	
	
	ofstream File("A2_P2_output.txt", ios::out);
	
	cout<<'\n';
	for(int i=0;i<n;i++){
		cout<<fin[i]<<" ";
		
		File<<fin[i]<<"\n";
	}

	cout<<'\n';
	return 0;
}