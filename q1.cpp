#include<bits/stdc++.h>
using namespace std;


class Vector {
private:
    double* entries; 
    int size;        

public:
    
    Vector(int n) : size(n) {
        entries = new double[size];
    }


    double& operator[](int index) {
        if (index >= 0 && index < size) {
            return entries[index];
        } else {
            cout<<"Index out of range";
        }
    }

    Vector operator+( Vector& other)  {
       
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = entries[i] + other.entries[i];
        }
        return result;
    }

    Vector operator-( Vector& other)  {
        
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = entries[i] - other.entries[i];
        }
        return result;
    }

    double operator*( Vector& other)  {

        double dotProduct = 0.0;
        for (int i = 0; i < size; ++i) {
            dotProduct += entries[i] * other.entries[i];
        }
        return dotProduct;
    }

    double oneNorm()  {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) {
            norm += abs(entries[i]);
        }
        return norm;
    }

    double twoNorm()  {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) {
            norm += entries[i] * entries[i];
        }
        return sqrt(norm);
    }

    double maxNorm()  {
        double norm = 0.0;
        for (int i = 0; i < size; ++i) {
            norm = max(norm, abs(entries[i]));
        }
        return norm;
    }

    Vector operator*(double scalar)  {
        Vector result(size);
        for (int i = 0; i < size; ++i) {
            result[i] = entries[i] * scalar;
        }
        return result;
    }
};

int main() {
    
    Vector v1(3);
    v1[0] = 1.0;
    v1[1] = 2.0;
    v1[2] = 3.0;

    Vector v2(3);
    v2[0] = 4.0;
    v2[1] = 5.0;
    v2[2] = 6.0;

    Vector sum = v1 + v2;
    cout << "v1 + v2 = ";
    for (int i = 0; i < 3; ++i) {
        cout << sum[i] << " ";
    }
    cout << endl;

    Vector diff = v1 - v2;
    cout << "v1 - v2 = ";
    for (int i = 0; i < 3; ++i) {
        cout << diff[i] << " ";
    }
    cout << endl;

    double dotProduct = v1 * v2;
    cout << "v1 * v2 = " << dotProduct << endl;

    cout << "One-norm of v1: " << v1.oneNorm() << endl;
    cout << "Two-norm of v1: " << v1.twoNorm() << endl;
    cout << "Max-norm of v1: " << v1.maxNorm() << endl;

    Vector scaled = v1 * 2.0;
    cout << "2 * v1 = ";
    for (int i = 0; i < 3; ++i) {
        cout << scaled[i] << " ";
    }
    cout << endl;

    return 0;
}
