#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>

//  function: u(x) = 1- (1-exp(-10))x -exp(-10x)
double u(double x)
{
    return 1 - (1 - exp(-10)) * x - exp(-10 * x);
}

// Exact second derivative: u''(x) = -100exp(-10 x)
double calc_d2u_exact(double x)
{
    return 100 * exp(-10 * x);
}

// Approximation of second derivative: (u(x+h) - 2*u(x) + u(x-h)) / h^2
double calc_d2u_approx(double x, double h)
{
    return (u(x + h) - 2 * u(x) + u(x - h)) / (h * h);
}

int main()
{
    std::string filename = "problem_8_output.txt";
    std::ofstream ofile;
    ofile.open(filename);

    int width = 18;
    int prec = 10;

    // Range of stepsizes
    double hmin = 1.0e-8;
    double hmax = 1.0;

    int n = 3;
    double x[n] = {2.0, 3.0, 5.0};

    std::cout << "# " << "stepsize";

    for (int i = 0; i < n; i++)
    {
        std::cout << std::setw(width) << "d" << x[i] << "u_approx"
                  << std::setw(width) << "d" << x[i] << "u_exact";
    }

    std::cout << std::endl;

    double du_exact_array[n];

    for (int i = 0; i < n; i++)
    {
        du_exact_array[i] = calc_d2u_exact(x[0]);
    }

    for (double h = hmin; h <= hmax; h = h * 10.)
    {
        std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << h;
        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << h;

        for (int i = 0; i < n; i++)
        {
            double du_approx = calc_d2u_approx(x[i], h);
            double du_exact = du_exact_array[i];

            std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << du_approx
                      << std::setw(width) << std::setprecision(prec) << std::scientific << du_exact;

            ofile << std::setw(width) << std::setprecision(prec) << std::scientific << du_approx
                  << std::setw(width) << std::setprecision(prec) << std::scientific << du_exact;
        }

        std::cout << std::endl;
        ofile << std::endl;
    }

    ofile.close();

    return 0;
}