#include <stdio.h>
#include <stdbool.h>
#include<time.h>

double determinant(double matrix[][3], int n)
{
    double det = 0;
    if (n == 1)
    {
        det = matrix[0][0];
    }
    else if (n == 2)
    {
        det = (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            double temp_matrix[n- 1][3];
            for (int j = 0; j < n - 1; j++)
            {
                for (int k = 0; k < n - 1; k++)
                {
                    if (k < i)
                    {
                        temp_matrix[j][k] = matrix[j + 1][k];
                    }
                    else
                    {
                        temp_matrix[j][k] = matrix[j + 1][k + 1];
                    }
                }
            }

            double cofactor = (i % 2 == 0) ? 1 : -1;
            det += cofactor * matrix[0][i] * determinant(temp_matrix, n - 1);
        }
    }
    return det;
}

int main()
{
    int begin, tend;
    begin = clock();
    double matrix[][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    int n = 3;
    double result = determinant(matrix, n);
    tend = clock();
    printf("Determinant of the matrix is: %lf\n", result);
    printf("time=%dms\n", tend - begin);
    return 0;
}