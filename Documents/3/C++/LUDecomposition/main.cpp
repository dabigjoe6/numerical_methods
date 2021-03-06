#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    void lu(float[][10], float[][10], float[][10], int n);
    void output(float[][10], int);
    float a[10][10], l[10][10], u[10][10], data[3][2];
    int n = 0, i = 0, j = 0;

    data[0][0] = 5;
    data[0][1] = 106.8;
    data[1][0] = 8;
    data[1][1] = 177.2;
    data[2][0] = 12;
    data[2][1] = 279.2;

    n = 3;

    for(i = 0; i < n; ++i)
    {
        for(j = 0; j < n; ++j)
        {
            if(j == 2)
            {
                a[i][2] = 1;
            }
            else if(j == 1)
            {
                a[i][1] = data[i][0];
            }
            else if(j == 0)
            {
                  a[i][0] = data[i][0] * data[i][0];
            }
        }
    }

    lu(a, l, u, n);
    cout << "\nL Decomposition\n\n";
    output(l, n);
    cout << "\nU Decomposition\n\n";
    output(u, n);

    return 0;
}

 void lu(float a[][10], float l[][10], float u[][10], int n)
 {
     int i = 0, j = 0, k = 0;
     for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++)
         {
             if(j < i)
                l[j][i] = 0;
            else
            {
                l[j][i] = a[j][i];
                for(k = 0; k < i; k++)
                {
                    l[j][i] = l[j][i] - l[j][k] * u[k][i];
                }
            }
         }
     }
     for(j = 0; j < n; j++)
     {
         if(j < i)
            u[i][j] = 0;
        else if(j == i)
            u[i][j] = 1;
        else
        {
            u[i][j] = a[i][j] / l[i][i];
            for(k = 0; k < i; ++k)
            {
                u[i][j] = u[i][j] -((l[i][k] * u[k][j]) / l[i][i]);
            }
        }
     }
 }

 void output(float x[][10], int n)
 {
     int i = 0, j = 0;
     for(i = 0; i < n; i++)
     {
         for(j = 0; j < n; j++)
         {
             cout << setprecision(1) << x[i][j] << "\t";
         }

         cout << endl;
     }
 }


