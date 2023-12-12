#include <bits/stdc++.h>
using namespace std;


class GaussQuadrature {
private:
    vector<double> gaussPoints;
    vector<double> weights;

public:
    GaussQuadrature() {
        gaussPoints = {-sqrt(3.0 / 5.0), 0.0, sqrt(3.0 / 5.0)};
        weights = {5.0 / 9.0, 8.0 / 9.0, 5.0 / 9.0};
    }

    double substitute(double (*func)(double))  {
        double result = 0.0;
        for (int i = 0; i < gaussPoints.size(); i++) {
            result += weights[i] * func(gaussPoints[i]);
        }
        return result;
    }
};

double polyFuncn_3(double x) {
    return 3*x*x*x - 2*x*x + x - 9;
}


double polyFuncn_4(double x) {
    return 15*x*x*x*x - 2*x*x*x + 4*x*x +3*x - 1;
}


double polyFuncn_5(double x) {
    return 3*x*x*x*x*x - 2*x*x*x + 4*x*x - 1;
}

double polyFuncn_6(double x) {
    return 70*x*x*x*x*x*x - 12*x*x*x + 4*x*x - 1;
}


int main() {
    GaussQuadrature gaussQuadrature;

    double integralResult = gaussQuadrature.substitute(polyFuncn_3);
    cout << "Degree 3 polynomial:" << endl;
    cout << "Exact Result: " << "-19.33" << endl;
    cout << "Quadrature Result: " << integralResult << endl;
    cout << endl;

    
    integralResult = gaussQuadrature.substitute(polyFuncn_4);
    cout << "Degree 4 polynomial:" << endl;
    cout << "Exact Result: " << "6.67" << endl;
    cout << "Quadrature Result: " << integralResult << endl;
    cout << endl;

    
    integralResult = gaussQuadrature.substitute(polyFuncn_5);
    cout << "Degree 5 polynomial:" << endl;
     cout << "Exact Result: " << "0.67" << endl;
    cout << "Quadrature Result: " << integralResult << endl;
    cout << endl;

    integralResult = gaussQuadrature.substitute(polyFuncn_6);
    cout << "Degree 6 polynomial:" << endl;
    cout << "Exact Result: " << "20.67" << endl;
    cout << "Quadrature Result: " << integralResult << endl;
    cout << endl;

    cout<<"\n\nWe see the difference in 6th power but exact result till 5th power";

    return 0;
}
