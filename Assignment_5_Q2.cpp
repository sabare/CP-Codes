#include<bits/stdc++.h>
using namespace std;

const double pi = 3.1415926535;
const double N = 32;

double f(double x) { return 1 - pow(x, 8); }

double x(double j) { return cos(pi * j / N); }

vector<double> exactDeriv()
{
    vector<double> deriv;
    for (int i = 1; i <= N - 1; i++)
    {
        deriv.push_back(-8 * pow(x(i), 7));
    }
    return deriv;
}

vector<double> firstDerivCentralDiff()
{
    vector<double> derivatives;

    for (int i = 1; i <= N - 1; i++)
    {
        double nr = f(x(i + 1)) - f(x(i - 1));
        double dr = x(i + 1) - x(i - 1);
        derivatives.push_back(nr / dr);
    }
    return derivatives;
}

vector<double> firstDerivCoordinateTransformation()
{
    vector<double> derivatives;

    for (int i = 1; i <= N - 1; i++)
    {
        double df_de = (f(x(i + 1)) - f(x(i - 1))) / (2 * pi / N);
        double de_dx = -1 / sin(pi * i / N);
        derivatives.push_back(df_de * de_dx);
    }
    return derivatives;
}

int main()
{

    vector<double> derivativesCentralDiff = firstDerivCentralDiff();
    vector<double> derivativesCoordinateTransformation = firstDerivCoordinateTransformation();
    vector<double> derivativesExact = exactDeriv();
    //cout << "x \t Non Linear \t Linear \t Actual \n";
    for (int i = 1; i <= N - 1; i++)
    {
        cout << abs(derivativesExact[i-1] - derivativesCoordinateTransformation[i-1])<<", ";
        // << "\t" << derivativesExact[i - 1] << "\t" << derivativesCentralDiff[i - 1] << "\t" << derivativesCoordinateTransformation[i - 1] << endl;
    }

    return 0;
}