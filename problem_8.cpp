#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cmath>


//  function: u(x) = 1- (1-exp(-10))x -exp(-10x)
double u(double x)
{
    return 1 - (1 - exp(-10))* x - exp(-10 * x);
}

// Exact second derivative: u''(x) = -100exp(-10 x)
double calc_d2u_exact(double x)
{
    return 100 * exp(-10* x);
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
    double x = 2.0;

    // Exact
    double d2u_exact = calc_d2u_exact(x);

    // Range of stepsizes
    double hmin = 1.0e-8;
    double hmax = 1.0;

    std::cout << "#" << std::setw(width - 1) << "stepsize"
              << std::setw(width) << "d2u_approx"
              << std::setw(width) << "d2u_exact"
              << std::endl;

    double h = hmin;
    while (h <= hmax)
    {

        double d2u_approx = calc_d2u_approx(x, h);

        std::cout << std::setw(width) << std::setprecision(prec) << std::scientific << h
                  << std::setw(width) << std::setprecision(prec) << std::scientific << d2u_approx
                  << std::setw(width) << std::setprecision(prec) << std::scientific << d2u_exact
                  << std::endl;

        ofile << std::setw(width) << std::setprecision(prec) << std::scientific << h
              << std::setw(width) << std::setprecision(prec) << std::scientific << d2u_approx
              << std::setw(width) << std::setprecision(prec) << std::scientific << d2u_exact
              << std::endl;

        // Increase stepsize
        h = h * 10.;
    }

    ofile.close();

    return 0;
}