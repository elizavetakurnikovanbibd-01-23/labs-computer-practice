import math

def f(x):
    return math.log(x) + (x + 1)**3

def g(x):
    return math.exp(- (x + 1)**3)

def iteration_method(x0, tol, max_iterations):
    x = x0
    for i in range(max_iterations):
        x_new = g(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    return None

root_iteration = iteration_method(0.5, 1e-6, 1000)
print(f"Корень методом итераций: {root_iteration}")

def bisection_method(a, b, tol):
    if f(a) * f(b) >= 0:
        print("Неверный выбор начальных точек a и b.")
        return None
    while (b - a) / 2.0 > tol:
        midpoint = (a + b) / 2.0
        if f(midpoint) == 0:
            return midpoint
        elif f(a) * f(midpoint) < 0:
            b = midpoint
        else:
            a = midpoint
    return (a + b) / 2.0

def secant_method(x0, x1, tol, max_iterations):
    for i in range(max_iterations):
        if f(x0) == f(x1):
            return None
        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0))
        if abs(x2 - x1) < tol:
            return x2
        x0, x1 = x1, x2
    return None

def f_prime(x):
    return 1/x + 3 * (x + 1)**2

def newton_method(x0, tol, max_iterations):
    x = x0
    for i in range(max_iterations):
        x_new = x - f(x) / f_prime(x)
        if abs(x_new - x) < tol:
            return x_new
        x = x_new
    return None

root_bisection = bisection_method(0.1, 1, 1e-6)
print(f"Корень методом дихотомии: {root_bisection}")

root_iteration = iteration_method(0.5, 1e-6, 1000)
print(f"Корень методом итераций: {root_iteration}")

root_secant = secant_method(0.1, 1, 1e-6, 1000)
print(f"Корень методом хорд: {root_secant}")

root_newton = newton_method(0.5, 1e-6, 1000)
print(f"Корень методом Ньютона: {root_newton}")
