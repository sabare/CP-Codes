#include<bits/stdc++.h>
using namespace std;

const double lambda = 10;

double f(double y, double t)
{
    return -1 * lambda * (y - exp(-1 * t)) - exp(-1 * t);
}

double y(double t, double y0)
{
    return exp(-1 * t) + (y0 - 1) * exp(-1 * lambda * t);
}

vector<double> exact_soln(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;
    vector<double> soln;
    for (int i = 0; i < n; i++)
    {
        soln.push_back(y(t0 + i * h, y0));
    }
    return soln;
}




//------------------------------------------------------------------

vector<double> implicit_euler(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;

    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        y.push_back((y[i] + h * (lambda - 1) * exp(-1 * (t0 + (i + 1) * h))) /
                    (1 + h * lambda));
    }
    return y;
}

vector<double> explicit_euler(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;
    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        y.push_back(y[i] + h * f(y[i], t0 + i * h));
    }
    return y;
}


vector<double> trapezoidal(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;

    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        y.push_back((y[i] + h / 2 * f(y[i], t0 + i * h) +
                     h / 2 * (lambda - 1) * exp(-1 * (t0 + (i + 1) * h))) / (1 + h * lambda / 2.0));
    }
    return y;
}

vector<double> rk2(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;

    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        double k1 = f(y[i], t0 + i * h);
        double k2 = f(y[i] + (h / 2) * k1, t0 + i * h + (h / 2));
        y.push_back(y[i] + h * k2);
    }
    return y;
}

vector<double> rk4(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;
    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        double k1 = f(y[i], t0 + i * h);
        double k2 = f(y[i] + (h / 2) * k1, t0 + i * h + (h / 2));
        double k3 = f(y[i] + (h / 2) * k2, t0 + i * h + (h / 2));
        double k4 = f(y[i] + h * k3, t0 + i * h + h);
        y.push_back(y[i] + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4));
    }
    return y;
}

vector<double> rk_fehlberg(double y0, double t0, double tmax, double h)
{
    int n = (tmax - t0) / h + 1;
    vector<double> y;
    y.push_back(y0);
    for (int i = 0; i < n - 1; i++)
    {
        double k1 = h * f(y[i], t0 + i * h);

        double k2 = h * f(y[i] + k1 / 4.0, t0 + i * h + (h / 4.0));

        double k3 = h * f(y[i] + 3.0 * k1 / 32.0 + 9.0 * k2 / 32.0, t0 + i * h + (3.0 * h / 8.0));

        double k4 = h * f(y[i] + 1932.0 * k1 / 2197.0 - 7200.0 * k2 / 2197.0 + 7296.0 * k3 / 2197.0,
                               t0 + i * h + 12.0 * h / 13.0);
        double k5 = h * f(y[i] + 439.0 * k1 / 216.0 - 8.0 * k2 + 3680.0 * k3 / 513.0 - 845.0 * k4 / 4104.0,
                               t0 + i * h + h);
        double k6 = h * f(y[i] - 8.0 * k1 / 27.0 + 2.0 * k2 - 3544.0 * k3 / 2565.0 +
                      1859.0 * k4 / 4104.0 - 11.0 * k5 / 40.0,
                  t0 + i * h + h / 2.0);

        y.push_back(y[i] + 16.0 * k1 / 135.0 + 6656.0 * k3 / 12825.0 +
                    28561.0 * k4 / 56430.0 - 9.0 * k5 / 50.0 + 2.0 * k6 / 55.0);
    }
    return y;
}

//---------------------------------------------------------------------

int main()
{
    vector<double> h_arr = {0.1, 0.05, 0.025, 0.0125, 0.00625};
    vector<double> err;
     for(auto h: h_arr){
        
        vector<double> solution_explicit_euler = explicit_euler(10, 0, 0.8, h);
        vector<double> solution_implicit_euler = implicit_euler(10, 0, 0.8, h);
        vector<double> solution_trapezoidal = trapezoidal(10, 0, 0.8, h);
        vector<double> exact_solution = exact_soln(10, 0, 0.8, h);
        vector<double> solution_rk2 = rk2(10, 0, 0.8, h);
        vector<double> solution_rk4 = rk4(10, 0, 0.8, h);
        vector<double> solution_rk_fehlberg = rk_fehlberg(10, 0, 0.8, h);
    

        for (int i = 0; i < solution_implicit_euler.size(); i++)
        {
            cout << setprecision(6) << solution_rk4[i] << " \t "
                << exact_solution[i] << endl;
        }
    
        double error = solution_rk4[solution_rk4.size()-1] - exact_solution[solution_rk4.size()-1];
        err.push_back(error);
    }
    cout<<'\n';

    for(int i = 1;i<err.size();i++){

        double p = abs(err[i]/err[i-1]);
        p = abs(log(p)/log(2));
        cout<<p<<'\n';
    }

    return 0;
}