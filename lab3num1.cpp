#include <iostream>
#include <cmath>

double f(double x) {
    return x * x * x * x * (24 + x * x);
}

// Метод прямоугольников (левых)
double rectangle_method(double a, double b, double epsilon) {
    double n = 1.0;
    double current_result = 0.0;
    double previous_result = 0.0;
    while (true) {
        n *= 2.0;
        double h = (b - a) / n;
        double result = 0.0;
        for (int i = 0; i < n; ++i) {
            result += f(a + i * h);
        }
        result *= h;
        if (std::abs(result - previous_result) < epsilon) {
            return result;
        }
        previous_result = result;
    }
}

// Метод трапеций
double trapezoidal_method(double a, double b, double epsilon) {
    double n = 1.0;
    double current_result = 0.0;
    double previous_result = 0.0;
    while (true) {
        n *= 2.0;
        double h = (b - a) / n;
        double result = (f(a) + f(b)) / 2.0;
        for (int i = 1; i < n; ++i) {
            result += f(a + i * h);
        }
        result *= h;
        if (std::abs(result - previous_result) < epsilon) {
            return result;
        }
        previous_result = result;
    }
}

// Метод парабол (метод Симпсона)
double simpson_method(double a, double b, double epsilon) {
    double n = 2.0; // n должно быть четным
    double current_result = 0.0;
    double previous_result = 0.0;
    while (true) {
        n *= 2.0;
        double h = (b - a) / n;
        double result = (f(a) + f(b)) / 3.0;
        for (int i = 1; i < n; ++i) {
            if (i % 2 == 0) {
                result += 2.0 * f(a + i * h) / 3.0;
            } else {
                result += 4.0 * f(a + i * h) / 3.0;
            }
        }
        result *= h;
        if (std::abs(result - previous_result) < epsilon) {
            return result;
        }
        previous_result = result;
    }
}

int main() {
    double a = 1.0; // Нижний предел интегрирования
    double b = 2.0; // Верхний предел интегрирования
    double epsilon = 1e-6; // Точность вычислений

    double integral_rectangle = rectangle_method(a, b, epsilon);
    double integral_trapezoidal = trapezoidal_method(a, b, epsilon);
    double integral_simpson = simpson_method(a, b, epsilon);

    std::cout << "Rectangle method: " << integral_rectangle << std::endl;
    std::cout << "Trapezoidal method: " << integral_trapezoidal << std::endl;
    std::cout << "Simpson method: " << integral_simpson << std::endl;

    return 0;
}
