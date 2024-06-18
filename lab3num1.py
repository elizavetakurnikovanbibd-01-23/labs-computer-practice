def f(x):
    return x**4 * (24 + x**2)

# Метод прямоугольников (левый)
def rectangle_method(a, b, n):
    h = (b - a) / n
    result = 0
    for i in range(n):
        result += f(a + i * h)
    result *= h
    return result

# Метод трапеций
def trapezoidal_method(a, b, n):
    h = (b - a) / n
    result = (f(a) + f(b)) / 2
    for i in range(1, n):
        result += f(a + i * h)
    result *= h
    return result

# Метод парабол (Симпсона)
def simpson_method(a, b, n):
    if n % 2 != 0:
        n += 1  # n должно быть четным
    h = (b - a) / n
    result = f(a) + f(b)
    for i in range(1, n):
        if i % 2 == 0:
            result += 2 * f(a + i * h)
        else:
            result += 4 * f(a + i * h)
    result *= h / 3
    return result

# Пределы интегрирования
a = 1
b = 2
# Количество разбиений
n = 1000

print("Rectangle method:", rectangle_method(a, b, n))
print("Trapezoidal method:", trapezoidal_method(a, b, n))
print("Simpson method:", simpson_method(a, b, n))
