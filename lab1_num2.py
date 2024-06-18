import math

EPSILON = 1e-6

def f(x):
    return math.log(x) + (x + 1)**3

def df(x):
    return 1 / x + 3 * (x + 1)**2

def ddf(x):
    return -1 / (x * x) + 6 * (x + 1)

# Метод дихотомии
def bisection(a, b):
    while (b - a) / 2.0 > EPSILON:
        c = (a + b) / 2.0
        if f(c) == 0.0:
            break
        elif f(c) * f(a) < 0:
            b = c
        else:
            a = c
    return (a + b) / 2.0

# Метод итераций
def iteration(x0):
    x = x0
    while True:
        x_next = x - f(x) / df(x)
        if abs(x_next - x) < EPSILON:
            break
        x = x_next
    return x

# Метод хорд
def secant(a, b):
    fa = f(a)
    fb = f(b)
    while abs(b - a) > EPSILON:
        c = a - fa * (b - a) / (fb - fa)
        if abs(f(c)) < EPSILON:
            break
        a, fa = b, fb
        b, fb = c, f(c)
    return c

# Метод Ньютона
def newton(x0):
    x = x0
    while True:
        x_next = x - f(x) / df(x)
        if abs(x_next - x) < EPSILON:
            break
        x = x_next
    return x

if __name__ == "__main__":
    # Для метода дихотомии нужно выбрать интервал, где функция меняет знак
    a, b = 0.1, 1.0  # интервал [a, b] для метода дихотомии
    print("Bisection method:", bisection(a, b))

    # Для метода итераций и Ньютона нужно выбрать начальное приближение
    x0 = 0.5
    print("Iteration method:", iteration(x0))
    print("Newton method:", newton(x0))

    # Для метода хорд также нужно выбрать интервал, где функция меняет знак
    print("Secant method:", secant(a, b))
