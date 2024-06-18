#include <iostream>
#include <complex>
#include <cmath>

int main() {
    // Определение комплексных чисел z1 и z2
    std::complex<double> z1(2, 3);  // Комплексное число 2 + 3i
    std::complex<double> z2(1, -4); // Комплексное число 1 - 4i

    // Сложение комплексных чисел
    std::complex<double> sum_z = z1 + z2;

    // Вычитание комплексных чисел
    std::complex<double> diff_z = z1 - z2;

    // Умножение комплексных чисел
    std::complex<double> prod_z = z1 * z2;

    // Деление комплексных чисел
    std::complex<double> div_z = z1 / z2;

    // Определение комплексного числа z3
    std::complex<double> z3(-1, 1); // Комплексное число -1 + i

    // Четвертая степень комплексного числа z3
    std::complex<double> z3_pow4 = std::pow(z3, 4);

    // Корень третьей степени комплексного числа z3
    double r = std::abs(z3);
    double theta = std::arg(z3);
    std::complex<double> z3_root3 = std::polar(std::pow(r, 1.0/3), theta / 3);

    // Вывод результатов
    std::cout << "Сумма: " << sum_z << std::endl;
    std::cout << "Разность: " << diff_z << std::endl;
    std::cout << "Произведение: " << prod_z << std::endl;
    std::cout << "Частное: " << div_z << std::endl;

    std::cout << "Четвертая степень: " << z3_pow4 << std::endl;
    std::cout << "Корень третьей степени: " << z3_root3 << std::endl;

    return 0;
}
