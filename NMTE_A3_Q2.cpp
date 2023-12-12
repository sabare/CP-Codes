
#include <bits/stdc++.h>
#include <time.h>
using namespace std;

double **addTwoMatrices(double **mat1, double **mat2, int m, int n)
{
  double **ans = new double *[n];
  for (int i = 0; i < n; i++)
  {
    ans[i] = new double[n];
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans[i][j] = mat1[i][j] + mat2[i][j];
    }
  }
  return ans;
}

double **subtractTwoMatrices(double **mat1, double **mat2, int m, int n)
{
  double **ans = new double *[n];
  for (int i = 0; i < n; i++)
  {
    ans[i] = new double[n];
  }
  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      ans[i][j] = mat1[i][j] - mat2[i][j];
    }
  }
  return ans;
}

double **multiplyTwoMatrices(double **a, double **b, int m, int n,
                             int p)
{
  double **c = new double *[n];
  for (int i = 0; i < n; i++)
  {
    c[i] = new double[n];
  }
  for (int i = 1; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
      c[i][j] = 0;
      for (int k = 0; k < p; k++)
      {
        c[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return c;
}

double *subtractTwoVectors(double *a, double *b, int n)
{
  double *ans = new double[n];
  for (int i = 0; i < n; i++)
  {
    ans[i] = a[i] - b[i];
  }
  return ans;
}

double *multiplyMatrixAndVector(double **a, double *b, int n)
{
  double *ans = new double[n];
  for (int i = 0; i < n; i++)
  {
    double sum = 0;
    for (int j = 0; j < n; j++)
    {
      sum = sum + a[i][j] * b[j];
    }
    ans[i] = sum;
  }
  return ans;
}

void printMatrix(double **mat, int m, int n)
{

  for (int i = 0; i < m; i++)
  {
    for (int j = 0; j < n; j++)
    {
	cout<<mat[i][j];      
	
    }
    cout << "\n";
  }
}

void forward_elimination(double **a, double *b, int n)
{
  for (int j = 0; j < n; j++)
  {
    double maxi = 0;
    int max_pos = j;

    double pivot = a[j][j];
    for (int i = j + 1; i < n; i++)
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

double **mat_cpy(double **a, int n)
{
  double **cpy = new double *[n];
  for (int i = 0; i < n; i++)
  {
    cpy[i] = new double[n];
  }
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cpy[i][j] = a[i][j];
    }
  }
  return cpy;
}

double **solve(double **a, double **b, int n)
{
  double **ans = new double *[n];

  for (int i = 0; i < n; i++)
  {
    ans[i] = new double[n];
  }

  for (int i = 0; i < n; i++)
  {
    // for each column in b - ith column
    double *col = new double[n];
    for (int j = 0; j < n; j++)
    {
      col[j] = b[j][i]; // all elements in b in ith column
    }

    double **temp = mat_cpy(a, n);
    forward_elimination(a, col, n);

    double *ans_col = new double[n];

    double *x = back_substitution(a, col, n);
    for (int k = 0; k < n; k++)
    {
      ans[k][i] = x[k];
    }
    a = temp;
  }
  return ans;
}
double **lu_decomposition(double ***e, double ***f, double ***g, double **r, int n, int nblk)
{
  for (int i = 1; i < n - 1; i++)
  {
    e[i] = solve(f[i - 1], e[i], nblk);
    double **prod = new double *[nblk];
    for (int i = 0; i < nblk; i++)
    {
      prod[i] = new double[nblk];
    }

    f[i] = subtractTwoMatrices(f[i], multiplyTwoMatrices(e[i], g[i - 1], nblk, nblk, nblk), nblk, nblk);
  }
  for (int k = 1; k < n; k++)
  {
    r[k] = subtractTwoVectors(r[k], multiplyMatrixAndVector(e[k], r[k - 1], nblk), nblk);
  }
  double **x = new double *[n];
  for (int i = 0; i < n; i++)
  {
    x[i] = new double[nblk];
  }
  double **f_cpy = mat_cpy(f[n - 1], nblk);
  double *r_cpy = new double[nblk];
  for (int i = 0; i < nblk; i++)
  {
    r_cpy[i] = r[n - 1][i];
  }
  forward_elimination(f[n - 1], r[n - 1], nblk);
  x[n - 1] = back_substitution(f[n - 1], r[n - 1], nblk);
  f[n - 1] = f_cpy;
  r[n - 1] = r_cpy;

  for (int k = n - 2; k >= 0; k--)
  {
    double *temp = new double[nblk];
    temp = subtractTwoVectors(r[k], multiplyMatrixAndVector(g[k], x[k + 1], nblk), nblk);
    forward_elimination(f[k], temp, nblk);
    x[k] = back_substitution(f[k], temp, nblk);
  }
  return x;
}
int main()
{
  const int n = 10;
  const int nblk = 5;

  double ***e = new double **[n];
  double ***f = new double **[n];
  double ***g = new double **[n];
  double **r = new double *[n];
  for (int i = 0; i < n; i++)
  {
    r[i] = new double[nblk];
    for (int j = 0; j < nblk; j++)
    {
      if (j == 0)
      {
        r[i][j] = 0;
      }
      else if (j == nblk - 1)
      {
        r[i][j] = 2;
      }
      else
      {
        r[i][j] = 1.00 / nblk;
      }
    }
  }

  for (int k = 0; k < n; k++)
  {
    e[k] = new double *[nblk];
    for (int i = 0; i < nblk; i++)
    {
      e[k][i] = new double[nblk];
    }

    g[k] = new double *[nblk];
    for (int i = 0; i < nblk; i++)
    {
      g[k][i] = new double[nblk];
    }

    f[k] = new double *[nblk];
    for (int i = 0; i < nblk; i++)
    {
      f[k][i] = new double[nblk];
    }

    for (int i = 0; i < nblk; i++)
    {
      for (int j = 0; j < nblk; j++)
      {
        if (i == j)
        {
          e[k][i][j] = 1;
          g[k][i][j] = 1;
          f[k][i][j] = -4;
        }
        else if ((i < nblk - 1 && i + 1 == j) ||
                 (j < nblk - 1 && j + 1 == i))
        {
          e[k][i][j] = 0;
          g[k][i][j] = 0;
          f[k][i][j] = 1;
        }
        else
        {
          e[k][i][j] = 0;
          g[k][i][j] = 0;
          f[k][i][j] = 0;
        }
      }
    }
  }

  clock_t t;
  t = clock();
  double **x = lu_decomposition(e, f, g, r, n, nblk);
  t = clock() - t;
  printMatrix(x, n, nblk);
  cout << "Time taken in seconds: " << ((double)t) / CLOCKS_PER_SEC << "s\n";
  double *ans = x[n / 2 - 1];
  for (int i = 0; i < nblk; i++)
  {
    cout << ans[i] << ", ";
  }
  return 0;
}