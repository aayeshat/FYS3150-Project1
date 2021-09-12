
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
    int n = 5;
    double h = (x_max - x_min) / double(n + 2);

    arma::vec a = arma::vec(n).fill(-1.);
    arma::vec b = arma::vec(n).fill(2.);
    arma::vec c = arma::vec(n).fill(-1.);

    arma::vec v = arma::vec(n);
    arma::vec k = arma::vec(n);
    arma::vec g = arma::vec(n);
 
    arma::vec x = arma::linspace(h, 1 - h, n);

    // filename
    std::string filename = "problem_7a_output.txt";

    std::ofstream ofile;
    ofile.open(filename);

    int width = 12;
    int prec = 4;

    for (int i = 0; i < n; i++)
    {
        double f = 100 * exp(-10 * x[i]); // f(x) = 100*exp(-10x)
        g[i] = pow(h, 2) * f;             //h^2f(x)
    }


    for (int i = 0; i < n-1; i++)
    {

        b[i] = b[i] - ((a[i] / b[i - 1]) * c[i - 1]);    //b_tilda_{i} = b_{i} - (a_{i}/b_tilda_{i-1})*c_{i-1} 

        cout << "b" << i +1<< " =" << b[i] << endl;

        g[i] = g[i] - (a[i] / b[i]) * g[i - 1];     // g_tilda_{i} = g_{i} - (a_{i}/b_tilda_{i})*g_tilda_{i-1} 

        cout << "g" << i +1<< " =" << g[i] << endl;

        x = x + h;
    }
    std ::cout << "-------------------" << endl;

    for (int i = n - 2; i >= 0; i--)
    {


        v[i] = (g[i] - (c[i] * v[i + 1])) / b[i];   //v_{i} = (g_tilda_{i} - c_{i}*v_{i+1})/b_tilda_{i} 

        std ::cout << "v" << i+1 << " = " << v[i] << std::endl;

        x = x + h;
    }

    std ::cout << "-------------------" << endl;

    for (int i = 0; i < n-1; i++)
    {
        std ::cout << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
                   << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
                   << std::endl;

        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x[i]
              << std::setw(width) << std::setprecision(prec) << std::scientific << v[i]
              << std::endl;
    }
    // Close the output file
    ofile.close();

    return 0;
}