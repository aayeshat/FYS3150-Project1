
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

    int n = 10;

    int width = 12;
    int prec = 4;

    /*
        a(vec): an array containing lower diagonal (a[0] is not used)
        b(vec): an array containing main diagonal 
        c(vec): an array containing lower diagonal (c[-1] is not used)
        g(vec): right hand side of the system
    */

    arma::vec a = arma::vec(n).fill(-1.);
    arma::vec b = arma::vec(n).fill(2.);
    arma::vec c = arma::vec(n).fill(-1.);

    double x_0 = 0;
    double x_n = 1;
    double h = (x_n - x_0) / double(n+2 );


    arma::vec g = arma::linspace(h, 1 + h, n);

    arma::vec x = arma::vec(n);

    //  elimination:
    for (int k = 0; k < n; k++)
    {
        double q = a[k] / b[k - 1];

        b[k] = b[k] - c[k - 1] * q;

        g[k] = g[k] - g[k - 1] * q;
    }

    // backsubstitution:

    double q = g[n - 1] / b[n - 1];
    x[n - 1] = q;

    for (int k = n - 2; k > -1; k--)
    {
        q = (g[k] - c[k] * q) / b[k];
        x[k] = q;

        cout << "x" << k << std::setw(width) << std::setprecision(prec) << std::scientific << x[k] << endl;
    }

    std ::cout << "-------------------" << endl;
    for (int k = 0; k < n; k++)
    {

        cout << "x" << k << std::setw(width) << std::setprecision(prec) << std::scientific << x[k] << endl;
    }
    return 0;
}