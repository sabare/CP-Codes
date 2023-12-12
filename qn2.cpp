#include<bits/stdc++.h>
using namespace std;

class Matrix{

    public:
        vector<vector<double>> mat;

        Matrix(){

            for(int i =0;i<3;i++){
                vector<double>temp;
                for(int j = 0;j<3;j++){

                    temp.push_back(0);
                }
                mat.push_back(temp);
            }
        }
        Matrix(vector<vector<double>>& val){

            for(int i = 0;i<3;i++){
                vector<double> temp;
                for(int j = 0;j<3;j++){

                    temp.push_back(val[i][j]);                    
                }
                mat.push_back(temp);
            }
        }

        Matrix(Matrix& other){

            for(int i = 0;i<3;i++){

                vector<double> temp;
                for(int j = 0;j<3;j++){

                    temp.push_back(other.mat[i][j]);
                }

                mat.push_back(temp);
            }
        }

        double det(){

            double deti;
            for(int i=0;i<3; i++)
                deti = deti + (mat[0][i] * (mat[1][(i+1)%3] * mat[2][(i+2)%3] - mat[1][(i+2)%3] * mat[2][(i+1)%3]));

            return deti;
        }

        vector<vector<double>> inverse(){
            double deti = det();
            int n = 3;
            vector<vector<double>> inv(n, vector<double>(n, 0));
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++)
                    inv[i][j] = ((mat[(j+1)%3][(i+1)%3] * mat[(j+2)%3][(i+2)%3]) - (mat[(j+1)%3][(i+2)%3] * mat[(j+2)%3][(i+1)%3]))/ deti;
            }

            return inv;
        }

        bool Singular(){

            return det()!=0;
        }

        void print(){

            for(int i = 0;i<3;i++){

                for(int j = 0;j<3;j++){

                    cout<<mat[i][j]<<' ';
                }

                cout<<'\n';
            }

            cout<<'\n';

            return;
        }

};

int main(){

    Matrix m1;
    for(int i = 0;i<3;i++){

        for(int j =0;j<3;j++){

            m1.mat[i][j] = max(i+1, j+1);
        }
    }
    cout<<m1.Singular()<<"\n\n";
    m1.print();

    vector<vector<double>> invi = m1.inverse();

    Matrix inv(invi);
    inv.print();

    return 0;

}