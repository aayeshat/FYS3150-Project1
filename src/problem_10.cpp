
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <armadillo>
#include <time.h>

using namespace std;

int calculateTimeSpecial(int n)
{
    // Start measuring time
    clock_t t1 = clock();
    double x_min = 0;
    double x_max = 1;

    double h = (x_max - x_min) / double(n + 2);

    arma::vec a = arma::vec(n).fill(-1.);
    arma::vec b = arma::vec(n).fill(2.);
    arma::vec c = arma::vec(n).fill(-1.);

    arma::vec v = arma::vec(n);
    arma::vec g = arma::vec(n);

    arma::vec x = arma::linspace(h, 1 - h, n);

    for (int i = 0; i < n; i++)
    {
        double f = 100 * exp(-10 * x[i]); // f(x) = 100*exp(-10x)
        g[i] = pow(h, 2) * f;             //h^2f(x)
    }

    //forward
    for (int i = 1; i < n - 1; i++)
    {
        b[i] = b[i] - (1 / b[i - 1]);
        g[i] = g[i] - (((i - 1) / i) * g[i - 1]);
    }

    //backward
    for (double i = n - 2; i >= 0; i--)
    {
        v[i] = g[i] - ((v[i + 1] / (i + 1)) * i);
    }

    // Stop measuring time
    clock_t t2 = clock();

    // Calculate the elapsed time.
    double duration = ((double)(t2 - t1));
    return duration;
}

int calculateTimeGeneral(int n)
{
    // Start measuring time
    clock_t t1 = clock();

    double x_min = 0;
    double x_max = 1;

    double h = (x_max - x_min) / double(n + 2);

    arma::vec a = arma::vec(n).fill(-1.);
    arma::vec b = arma::vec(n).fill(2.);
    arma::vec c = arma::vec(n).fill(-1.);

    arma::vec v = arma::vec(n);
    arma::vec k = arma::vec(n);
    arma::vec g = arma::vec(n);

    arma::vec x = arma::linspace(h, 1 - h, n);

    for (int i = 0; i < n; i++)
    {
        double f = 100 * exp(-10 * x[i]); // f(x) = 100*exp(-10x)
        g[i] = pow(h, 2) * f;             //h^2f(x)
    }

    for (int i = 0; i < n - 1; i++)
    {
        b[i] = b[i] - ((a[i] / b[i - 1]) * c[i - 1]); //b_tilda_{i} = b_{i} - (a_{i}/b_tilda_{i-1})*c_{i-1}
        g[i] = g[i] - (a[i] / b[i]) * g[i - 1];       // g_tilda_{i} = g_{i} - (a_{i}/b_tilda_{i})*g_tilda_{i-1}h;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        v[i] = (g[i] - (c[i] * v[i + 1])) / b[i]; //v_{i} = (g_tilda_{i} - c_{i}*v_{i+1})/b_tilda_{i}
    }

    // Stop measuring time
    clock_t t2 = clock();

    // Calculate the elapsed time.
    double duration = ((double)(t2 - t1));
    return duration;
}

int main()
{

    std::string filename = "problem_10_output.txt";

    std::ofstream ofile;
    ofile.open(filename);

    int width = 12;

    cout << std::setw(width) << "    n   " << std::setw(width) << "special__ms" << std::setw(width) << "gerneral_ms" << std::endl;

    for (int n = 10; n < 100000000; n = n * 10)
    {
        double special_duration_ms = calculateTimeSpecial(n);
        double gerneral_duration_ms = calculateTimeGeneral(n);

        cout << std::setw(width) << n << std::setw(width) << special_duration_ms << std::setw(width) << gerneral_duration_ms << std::endl;
        ofile << std::setw(width) << n << std::setw(width) << special_duration_ms << std::setw(width) << gerneral_duration_ms << std::endl;
    }

    ofile.close();

    return 0;
}