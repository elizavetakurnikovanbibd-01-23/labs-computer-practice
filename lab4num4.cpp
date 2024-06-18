#include <iostream>
#include <vector>

using namespace std;

void progonka(vector<double>& a, vector<double>& b, vector<double>& c, 
             vector<double>& f, vector<double>& x) {
    int n = a.size();

    // Прямой ход
    vector<double> alpha(n);
    vector<double> beta(n);
    alpha[0] = -c[0] / b[0];
    beta[0] = f[0] / b[0];
    for (int i = 1; i < n; i++) {
        alpha[i] = -c[i] / (b[i] + a[i] * alpha[i - 1]);
        beta[i] = (f[i] - a[i] * beta[i - 1]) / (b[i] + a[i] * alpha[i - 1]);
    }

    // Обратный ход
    x[n - 1] = beta[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = alpha[i] * x[i + 1] + beta[i];
    }
}

int main() {
    // Задаем коэффициенты системы
    vector<double> a = {-11, 9, 0, 0, 0};
    vector<double> b = {-8, -17, -4, -14, 14};
    vector<double> c = {0, 1, 20, 3, 0};
    vector<double> f = {99, -75, 66, 54, 8};

    // Решаем систему
    vector<double> x(f.size());
    progonka(a, b, c, f, x);

    // Выводим результаты
    cout << "Решение системы:" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << "x" << i + 1 << " = " << x[i] << endl;
    }

    return 0;
}
