#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <math.h>

#define SIZE 10

using namespace std;

int main()
{
    float a[SIZE][SIZE], x[SIZE], x_new[SIZE];
    float temp, lambda_new, lambda_old, error;
    int i, j, n, step = 1;

    /* Setting precision and writing floating point values in fixed-point notation. */
    cout << setprecision(6) << fixed;

    /* Inputs */
    /* Reading order of square matrix */
    /*
    cout << "\nSHIVAM SINGH\n07313302720\nCSE-4A\n";
    cout << "Enter Order of Matrix: ";
    cin >> n;
    */

    /* Reading tolerable error */
    // cout<<"Enter Tolerable Error: ";
    error = 0.00001;

    /* Reading Square Matrix of Order n */
    cout << "Enter matrix elements row-wise: " << endl;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cout << "a[" << i << "]" << '[' << j << "]= ";
            cin >> a[i][j];
        }
    }

    /* Reading Intial Guess Vector */
    cout << "Enter Column Vector: " << endl;
    for (i = 1; i <= n; i++)
    {
        cout << "x[" << i << "]= ";
        cin >> x[i];
    }

    /* Initializing Lambda_Old */
    lambda_old = 1;
/* Multiplication */

/* Setting label for repetition */
up:
    for (i = 1; i <= n; i++)
    {
        temp = 0.0;
        for (j = 1; j <= n; j++)
        {
            temp = temp + a[i][j] * x[j];
        }
        x_new[i] = temp;
    }

    /* Replacing x by x_new */
    for (i = 1; i <= n; i++)
    {
        x[i] = x_new[i];
    }

    /* Finding largest value from x*/
    lambda_new = fabs(x[1]);
    for (i = 2; i <= n; i++)
    {
        if (fabs(x[i]) > lambda_new)
        {
            lambda_new = fabs(x[i]);
        }
    }

    /* Normalization */
    for (i = 1; i <= n; i++)
    {
        x[i] = x[i] / lambda_new;
    }

    /* Display */
    if (step == 2)
    {
        cout << '\n';
        cout << "Eigen Value = " << lambda_new << endl;
        cout << "Eigen Vector: " << endl;
        cout << "[";
        for (i = 1; i <= n; i++)
        {
            cout << x[i] << "\t";
        }
        cout << "\b\b\b]"; /* \b is for backspace */
    }

    /* Checking Accuracy */
    if (fabs(lambda_new - lambda_old) > error)
    {
        lambda_old = lambda_new;
        step++;
        goto up;
    }

    return (0);
}