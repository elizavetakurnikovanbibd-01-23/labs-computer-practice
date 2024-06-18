#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> zeidel(vector<vector<double>>& A, vector<double>& b, double eps) {
    int n = A.size();
    vector<double> x(n, 0);
    vector<double> x_prev(n, 0);
    double norm;

    do {
        x_prev = x;
        for (int i = 0; i < n; i++) {
            double sum = 0;
            for (int j = 0; j < i; j++) {
                sum += A[i][j] * x[j];
            }
            for (int j = i + 1; j < n; j++) {
                sum += A[i][j] * x_prev[j];
            }
            x[i] = (b[i] - sum) / A[i][i];
        }
        norm = 0;
        for (int i = 0; i < n; i++) {
            norm += abs(x[i] - x_prev[i]);
        }
    } while (norm > eps);

    return x;
}

int main() {
    // Задаем коэффициенты системы
    vector<vector<double>> A = {
        {-7, -1, 2, 2},
        {3, -20, 0, -8},
        {-9, 1, 8, -6},
        {-1, 0, -1, -6}
    };
    vector<double> b = {-24, -47, 28, -50};

    // Решаем систему с точностью 0.01
    vector<double> x = zeidel(A, b, 0.01);

    // Выводим результаты
    cout << "Решение системы:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
