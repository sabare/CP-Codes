#include<bits/stdc++.h>
using namespace std;

class Matrix {
    private:
        double** entries; 
        int numRows;      
        int numCols;      

    public:
        
        Matrix(int rows, int cols) : numRows(rows), numCols(cols) {
            entries = new double*[numRows];
            for (int i = 0; i < numRows; ++i) {
                entries[i] = new double[numCols];
            }
        }

        double& operator()(int row, int col) {
            
            return entries[row][col];
        }


        Matrix operator+( Matrix& other)  {

            Matrix result(numRows, numCols);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    result(i, j) = entries[i][j] + other.entries[i][j];
                }
            }
            return result;
        }

        Matrix operator-( Matrix& other)  {
            
            Matrix result(numRows, numCols);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    result(i, j) = entries[i][j] - other.entries[i][j];
                }
            }
            return result;
        }

        Matrix operator*( Matrix& other)  {
            
            Matrix result(numRows, other.numCols);
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < other.numCols; ++j) {
                    result(i, j) = 0.0;
                    for (int k = 0; k < numCols; ++k) {
                        result(i, j) += entries[i][k] * other.entries[k][j];
                    }
                }
            }
            return result;
        }

        double oneNorm()  {
            double norm = 0.0;
            for (int j = 0; j < numCols; ++j) {
                double colSum = 0.0;
                for (int i = 0; i < numRows; ++i) {
                    colSum += abs(entries[i][j]);
                }
                norm = max(norm, colSum);
            }
            return norm;
        }

        double maxNorm()  {
            double norm = 0.0;
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    norm = max(norm, abs(entries[i][j]));
                }
            }
            return norm;
        }

        double frobeniusNorm()  {
            double norm = 0.0;
            for (int i = 0; i < numRows; ++i) {
                for (int j = 0; j < numCols; ++j) {
                    norm += entries[i][j] * entries[i][j];
                }
            }
            return sqrt(norm);
        }
};

int main() {
    Matrix A(2, 2);
    A(0, 0) = 1.0;
    A(0, 1) = 2.0;
    A(1, 0) = 3.0;
    A(1, 1) = 4.0;

    Matrix B(2, 2);
    B(0, 0) = 5.0;
    B(0, 1) = 6.0;
    B(1, 0) = 7.0;
    B(1, 1) = 8.0;

    Matrix C = A + B;
    cout << "A + B =\n" << C(0, 0) << " " << C(0, 1) << "\n" << C(1, 0) << " " << C(1, 1) << endl;

    cout<<'\n';
    Matrix D = A - B;
    cout << "A - B =\n" << D(0, 0) << " " << D(0, 1) << "\n" << D(1, 0) << " " << D(1, 1) << endl;
    cout<<'\n';

    Matrix E = A * B;
    cout << "A * B =\n" << E(0, 0) << " " << E(0, 1) << "\n" << E(1, 0) << " " << E(1, 1) << endl;
    cout<<'\n';
    cout << "One-norm of A: " << A.oneNorm() << endl;
    cout << "Max-norm of A: " << A.maxNorm() << endl;
    cout << "Frobenius norm of A: " << A.frobeniusNorm() << endl;

    return 0;
}
