#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{

    std::string filename = "problem_2_output.txt";

    std::ofstream ofile;
    ofile.open(filename);
    int width = 12;
    int prec = 4;

    double x_min = 0.0;
    double x_max = 1.0;
    int n_steps = 100;

    double h_step_size = (x_max - x_min) / n_steps;

    double e = 2.71828f;
    double ePow10 = pow(e, 10);

    double x = x_min;
    for (int i = 0; i < n_steps; i++)
    {
        double ePow10X = pow(e, 10 * x);
        double ux = 1 - ((1 - (1 / ePow10)) * x) - (1 / ePow10X);
        
        cout << std::setw(width) << std::setprecision(prec) << std::scientific << x
              << std::setw(width) << std::setprecision(prec) << std::scientific << ux
              << std::endl;

        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << x
              << std::setw(width) << std::setprecision(prec) << std::scientific << ux
              << std::endl;

        x = x + h_step_size;
    }

    ofile.close();
    return 0;
}