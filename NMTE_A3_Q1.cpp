#include <bits/stdc++.h>

using namespace std;
void forward_elimination(double **a, double *b, int n)
{

  for (int j = 0; j < n - 1; j++)
  {
    double pivot = a[j][j];

    for (int i = j + 1; i < j + 2; i++)
    {
      double c = a[i][j] / pivot;
      b[i] = b[i] - c * b[j];
      for (int k = 0; k < n; k++)
      {
        a[i][k] = a[i][k] - c * a[j][k];
      }
    }
  }
}

double *back_substitution(double **a, double *b, int n)
{
  double *x = new double[n];
  for (int i = n - 1; i >= 0; i--)
  {
    x[i] = b[i] / a[i][i];
    for (int j = i + 1; j < n; j++)
    {
      x[i] = x[i] - (a[i][j] / a[i][i]) * x[j];
    }
  }
  return x;
}
double f(double j, int n) { return sin(5 * 3 * j / n); }
int main()
{
  int N;
  cin >> N;
  int n = N + 1;

  double **a = new double *[n];

  for (int i = 0; i < n; i++)
  {
    a[i] = new double[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == 0)
      {
        if (j == 0)
          a[i][j] = 1;
        else if (j == 1)
          a[i][j] = 2;
        else
          a[i][j] = 0;
      }
      else if (i == n - 1)
      {
        if (j == n - 2)
          a[i][j] = 2;
        else if (j == n - 1)
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
      else
      {
        if (j == i - 1)
          a[i][j] = 1;
        else if (j == i)
          a[i][j] = 4;
        else if (j == i + 1)
          a[i][j] = 1;
        else
          a[i][j] = 0;
      }
    }
  }
  double *b = new double[n];

  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      b[i] = (N / 3) * (-2.5 * f(0, N) + 2 * f(1, N) + 0.5 * f(2, N));
    }
    else if (i == n - 1)
    {
      b[i] = (N / 3) * (2.5 * f(N, N) - 2 * f(N - 1, N) - 0.5 - f(N - 2, N));
    }
    else
    {
      b[i] = N * (f(i + 1, N) - f(i - 1, N));
    }
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  for (int i = 0; i < n; i++)
    cout << b[i] << " " << endl;

  forward_elimination(a, b, n);
  double *x = back_substitution(a, b, n);
  cout << "Solution is" << endl;
  for (int i = 0; i < n; i++)
  {
    cout << x[i] << ", ";
  }
  return 0;
}