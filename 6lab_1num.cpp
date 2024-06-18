#include <iostream>
#include <cmath>

using namespace std;

// Функция, которую мы хотим минимизировать
double f(double x, double y) {
    return x * x + 3 * y * y + cos(x + y);
}

// Производная по x
double df_dx(double x, double y) {
    return 2 * x - sin(x + y);
}

// Производная по y
double df_dy(double x, double y) {
    return 6 * y - sin(x + y);
}

// Метод координатного спуска
pair<double, double> coordinate_descent(double x0, double y0, double eps) {
    double x = x0;
    double y = y0;
    double prev_x, prev_y;

    do {
        prev_x = x;
        prev_y = y;

        // Минимизация по x
        while (abs(df_dx(x, y)) > eps) {
            x -= eps * df_dx(x, y);
        }

        // Минимизация по y
        while (abs(df_dy(x, y)) > eps) {
            y -= eps * df_dy(x, y);
        }

    } while (abs(x - prev_x) > eps || abs(y - prev_y) > eps);

    return make_pair(x, y);
}

int main() {
    double x0 = 1.0; // Начальное значение x
    double y0 = 1.0; // Начальное значение y
    double eps = 1e-6; // Точность вычислений

    pair<double, double> result = coordinate_descent(x0, y0, eps);

    cout << "Минимум функции найден в точке: (" << result.first << ", " << result.second << ")" << endl;
    cout << "Значение функции в этой точке: " << f(result.first, result.second) << endl;

    return 0;
}
