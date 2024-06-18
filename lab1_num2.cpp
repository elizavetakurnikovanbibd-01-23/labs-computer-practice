#include <iostream>
#include <cmath>

const double EPSILON = 1e-6;

double f(double x) {
    return log(x) + pow(x + 1, 3);
}

double df(double x) {
    return 1 / x + 3 * pow(x + 1, 2);
}

double ddf(double x) {
    return -1 / (x * x) + 6 * (x + 1);
}

// Метод дихотомии
double bisection(double a, double b) {
    double c;
    while ((b - a) / 2.0 > EPSILON) {
        c = (a + b) / 2.0;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return (a + b) / 2.0;
}

// Метод итераций
double iteration(double x0) {
    double x = x0, x_next;
    do {
        x_next = x - f(x) / df(x);
        if (fabs(x_next - x) < EPSILON)
            break;
        x = x_next;
    } while (true);
    return x;
}

// Метод хорд
double secant(double a, double b) {
    double fa = f(a), fb = f(b), c;
    while (fabs(b - a) > EPSILON) {
        c = a - fa * (b - a) / (fb - fa);
        if (fabs(f(c)) < EPSILON)
            break;
        a = b;
        fa = fb;
        b = c;
        fb = f(b);
    }
    return c;
}

// Метод Ньютона
double newton(double x0) {
    double x = x0, x_next;
    do {
        x_next = x - f(x) / df(x);
        if (fabs(x_next - x) < EPSILON)
            break;
        x = x_next;
    } while (true);
    return x;
}

int main() {
    // Для метода дихотомии нужно выбрать интервал, где функция меняет знак
    double a = 0.1, b = 1.0;  // интервал [a, b] для метода дихотомии
    std::cout << "Bisection method: " << bisection(a, b) << std::endl;

    // Для метода итераций и Ньютона нужно выбрать начальное приближение
    double x0 = 0.5;
    std::cout << "Iteration method: " << iteration(x0) << std::endl;
    std::cout << "Newton method: " << newton(x0) << std::endl;

    // Для метода хорд также нужно выбрать интервал, где функция меняет знак
    std::cout << "Secant method: " << secant(a, b) << std::endl;

    return 0;
}
