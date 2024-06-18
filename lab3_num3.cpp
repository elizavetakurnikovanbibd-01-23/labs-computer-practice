#include <iostream>
#include <cmath>
#include <iomanip>

double series_sum(double epsilon = 1e-6, int max_iterations = 100000) {
    double sum_value = 0.0;
    int k = 1;
    double term = 1.0; // Initial term to enter the loop

    while (std::abs(term) > epsilon && k <= max_iterations) {
        term = (24.0 / std::pow(2.0, k - 1)) + (std::pow(-1.0, k - 1) / (2.0 * std::pow(3.0, k - 1)));
        sum_value += term;
        ++k;
    }

    return sum_value;
}

int main() {
    double result = series_sum();
    std::cout << std::setprecision(10) << "Sum of the series: " << result << std::endl;
    return 0;
}
