import math

def f(x, y):
    return 7 * x*2 + 2 * x * y + 5 * y*2 + x - 10 * y

def df_dx(x, y):
    return 14 * x + 2 * y + 1

def df_dy(x, y):
    return 2 * x + 10 * y - 10

def coordinate_descent(x0, y0, eps):
    x = x0
    y = y0
    prev_x, prev_y = 0, 0

    while abs(x - prev_x) > eps or abs(y - prev_y) > eps:
        prev_x = x
        prev_y = y

        # Минимизация по x
        x = -df_dx(x, y) / 14  # Решение уравнения df_dx(x, y) = 0

        # Минимизация по y
        y = (10 - 2 * x) / 10  # Решение уравнения df_dy(x, y) = 0

    return x, y

if name == "__main__":
    x0 = 1.0  # Начальное значение x
    y0 = 1.0  # Начальное значение y
    eps = 1e-6  # Точность вычислений

    result = coordinate_descent(x0, y0, eps)

    print(f"Минимум функции найден в точке: ({result[0]}, {result[1]})")
    print(f"Значение функции в этой точке: {f(result[0], result[1])}")
