#include<bits/stdc++.h>
using namespace std;

const long double PI = 3.14159265358979323846;
const long double T_inf = 300;
const long double T_i = 25;
const long double T_t = 53.50;
const long double alpha = 1e-4;
const long double k = 400;
const long double t = 400;

long double f_err(long double x) { return exp(-x * x); }

long double erfh(long double x)
{
    long double a = 0;
    long double b = x;
    long double N = 51;
    long double dx = (b - a) / (N - 1);
    long double sum = 0;

    for (int i = 2; i < N; i++)
    {
        long double x_i = a + (i - 1) * dx;

        sum += (dx) * (f_err(x_i));
    }
    sum = sum + (dx / 2) * (f_err(a) + f_err(a + (N - 1) * dx));
    return sum * 2 / sqrt(PI);
}

long double erfch(long double x) { return 1 - erf(x); }

long double f(long double h)
{
    long double lhs = (T_t - T_i) / (T_inf - T_i);
    long double rhs =
        1 - exp(h * h * alpha * t / (k * k)) * erfch(h * sqrt(alpha * t) / k);
    return lhs - rhs;
}

long double f_deriv(long double h)
{
    long double ans = (-2 / sqrt(PI)) * sqrt(alpha * t) / k +
                      erfch(h * sqrt(alpha * t) / k) *
                          exp(h * h * alpha * t / (k * k)) *
                          (2 * h * alpha * t / (k * k));
    return ans;
}

long double bisection(long double low, long double high, long double tolerance)
{
    cout << "bisection" << endl;
    long double mid = low;
    int i = 0;
    int number_of_iter = 10;
    int mid_prev = 0;
    while (i < number_of_iter && abs(mid - mid_prev) > tolerance)
    {

        mid = (low + high) / 2;
        cout << setprecision(10) << mid << ", ";
        if (f(mid) == 0)
            return mid;
        else
        {
            if (f(low) * f(mid) < 0)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }
        i++;
    }
    return mid;
}


long double newton_raphson(long double init_guess, long double tolerance)
{
    cout << "newton_raphson\n";
    long double x_prev = init_guess;
    long double x = 0;
    int max_iter = 100;
    int i = 0;
    while (i < max_iter)
    {
        i++;
        x = x_prev - f(x_prev) / f_deriv(x_prev);
        cout << setprecision(10) << x << ", ";
        if (abs(x - x_prev) < tolerance)
        {
            break;
        }
        else
        {
            x_prev = x;
        }
    }
    return x;
}
int main()
{
    cout << "Program Start \n";
    // cout<<newton_raphson(5000, 1e-5);
    long double init_guess = bisection(1, 10000, 1e-5);
    cout << newton_raphson(init_guess, 1e-5);
}
