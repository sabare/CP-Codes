#include <bits/stdc++.h>
using namespace std;
void printMatrix(vector<vector<double>> arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    return;
}

double f(double x, double y, double z) { return x + y + z - 3; }
double g(double x, double y, double z) { return x * x + y * y + z * z - 5; }
double h(double x, double y, double z) { return exp(x) + x * y - x * z - 1; }
double fx(double x, double y, double z) { return 1; }
double fy(double x, double y, double z) { return 1; }
double fz(double x, double y, double z) { return 1; }
double gx(double x, double y, double z) { return 2 * x; }
double gy(double x, double y, double z) { return 2 * y; }
double gz(double x, double y, double z) { return 2 * z; }
double hx(double x, double y, double z) { return exp(x) + y - z; }
double hy(double x, double y, double z) { return x; }
double hz(double x, double y, double z) { return -1 * x; }
vector<double> multiplyVectorAndMat(vector<vector<double>> mat, vector<double> y)
{
    vector<double> ans;
    for (int i = 0; i < 3; i++)
    {
        double sum = 0;
        for (int j = 0; j < 3; j++)
        {
            sum += mat[i][j] * y[j];
        }
        ans.push_back(sum);
    }
    return ans;
}
vector<double> addVectors(vector<double> x, vector<double> y)
{
    vector<double> ans;
    for (int i = 0; i < x.size(); i++)
    {
        ans.push_back(x[i] + y[i]);
    }
    return ans;
}
double error(vector<double> x, vector<double> y)
{
    double ans = 0;
    for (int i = 0; i < x.size(); i++)
    {
        ans = ans + (x[i] - y[i]) * (x[i] - y[i]);
    }
    return ans;
}
vector<vector<double>> inverse(vector<vector<double>> mat)
{
    double determinant = 0;
    for (int i = 0; i < 3; i++)
        determinant =
            determinant + (mat[0][i] * (mat[1][(i + 1) % 3] * mat[2][(i + 2) % 3] -
                                        mat[1][(i + 2) % 3] * mat[2][(i + 1) % 3]));
    vector<vector<double>> ans(3, vector<double>(3, 0));
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
            ans[i][j] =
                ((mat[(j + 1) % 3][(i + 1) % 3] * mat[(j + 2) % 3][(i + 2) % 3]) -
                 (mat[(j + 1) % 3][(i + 2) % 3] * mat[(j + 2) % 3][(i + 1) % 3])) /
                determinant;
    }
    return ans;
}
void printVec(vector<double> y)
{
    for (int i = 0; i < y.size(); i++)
    {
        cout << y[i] << ",\t";
    }
    cout << "\n";
}
vector<double> gaussNewton(vector<double> initGuess, double tolerance)
{
    int iterCount = 0;
    vector<double> xPrev(3, 0);
    vector<double> x = initGuess;
    int i = 0;
    int maxIter = 100;
    while (i < maxIter && error(xPrev, x) > tolerance)
    {
        iterCount++;
        xPrev = x;
        vector<vector<double>> J(3, vector<double>(3, 0));
        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                J[i][0] = fx(x[0], x[1], x[2]);
                J[i][1] = fy(x[0], x[1], x[2]);
                J[i][2] = fz(x[0], x[1], x[2]);
            }
            if (i == 1)
            {
                J[i][0] = gx(x[0], x[1], x[2]);
                J[i][1] = gy(x[0], x[1], x[2]);
                J[i][2] = gz(x[0], x[1], x[2]);
            }
            if (i == 2)
            {
                J[i][0] = hx(x[0], x[1], x[2]);
                J[i][1] = hy(x[0], x[1], x[2]);
                J[i][2] = hz(x[0], x[1], x[2]);
            }
        }
        vector<double> res(3, 0);
        res[0] = -1 * f(x[0], x[1], x[2]);
        res[1] = -1 * g(x[0], x[1], x[2]);
        res[2] = -1 * h(x[0], x[1], x[2]);
        x = addVectors(x, multiplyVectorAndMat(inverse(J), res));
        printVec(x);
    }
    cout << "Number of Iterations : " << iterCount << endl;
    return x;
}
int main()
{
    vector<double> initGuess = {1, 0, 1};
    /*vector<vector<double>> mat = {
    {1,2,3},
    {7,1,3},
    {3,1,6}
  };
    printMatrix(inverse(mat), 3,3);*/
    vector<double> ans = gaussNewton(initGuess, 1e-5);
    cout << "Final values of x after Gauss Newton";
    cout << f(ans[0], ans[1], ans[2]) << ", " << g(ans[0], ans[1], ans[2]) << "," << h(ans[0], ans[1], ans[2]) << endl;
    return 0;
}