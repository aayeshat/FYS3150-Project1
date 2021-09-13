
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <armadillo>

using namespace std;

int main()
{

    double x_min = 0;
    double x_max = 1;
    int n = 10;
    double h = (x_max - x_min) / double(n + 2);

    arma::vec a = arma::vec(n).fill(-1.);
    arma::vec b = arma::vec(n).fill(2.);
    arma::vec c = arma::vec(n).fill(-1.);

    arma::vec v = arma::vec(n);
    arma::vec g = arma::vec(n);

    arma::vec x = arma::linspace(h, 1 - h, n);

    // filename
    std::string filename = "problem_9b_n" + to_string(n) + "_output.txt";

    std::ofstream ofile;
    ofile.open(filename);

    int width = 12;
    int prec = 4;

    // Start measuring time
    clock_t t1 = clock();
    for (int i = 0; i < n; i++)
    {
        double f = 100 * exp(-10 * x[i]); // f(x) = 100*exp(-10x)
        g[i] = pow(h, 2) * f;             //h^2f(x)
    }

    //forward
    for (int i = 1; i < n - 1; i++)
    {

        b[i] = b[i] - (1 / b[i - 1]);

        cout << "b" << i + 1 << " =" << b[i] << endl;

        g[i] = g[i] - (((i - 1) / i) * g[i - 1]);

        cout << "g" << i + 1 << " =" << g[i] << endl;
    }
    std ::cout << "-------------------" << endl;

    //backward
    for (int i = n - 2; i >= 0; i--)
    {

        v[i] = g[i] - ((v[i + 1] / (i + 1)) * i);

        std ::cout << "v" << i + 1 << " = " << v[i] << std::endl;
    }

    std ::cout << "-------------------" << endl;

    for (int i = 0; i < n - 1; i++)
    {
        std ::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
                   << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
                   << std::endl;

        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
              << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
              << std::endl;
    }

    ofile.close();

    return 0;
}