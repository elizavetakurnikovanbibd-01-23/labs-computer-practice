import numpy as np

# Метод Крамера
def kramer(A, b):
    n = len(A)
    x = np.zeros(n)
    detA = np.linalg.det(A)

    # Проверка на ненулевой определитель
    if detA == 0:
        print("Система уравнений не имеет единственного решения.")
        return x

    # Вычисление определителей для каждого неизвестного
    for i in range(n):
        Ai = A.copy()
        Ai[:, i] = b
        detAi = np.linalg.det(Ai)
        x[i] = detAi / detA

    return x

# Метод Якоби
def jacobi(A, b, eps):
    n = len(A)
    x = np.zeros(n)
    x_prev = np.zeros(n)
    norm = 1

    while norm > eps:
        x_prev = x
        for i in range(n):
            sum = 0
            for j in range(n):
                if j != i:
                    sum += A[i][j] * x_prev[j]
            x[i] = (b[i] - sum) / A[i][i]
        norm = np.linalg.norm(x - x_prev)

    return x

# Задаем коэффициенты системы
A = np.array([
    [5, 3, -2],
    [2, 1, -1],
    [3, -2, -3]
])
b = np.array([-1, 0, 2])

# Решаем систему методом Крамера
x_kramer = kramer(A, b)
print("Решение методом Крамера:")
for i in range(len(x_kramer)):
    print(f"x{i+1} = {x_kramer[i]}")

# Решаем систему методом Якоби с точностью 0.01
x_jacobi = jacobi(A, b, 0.01)
print("Решение методом Якоби:")
for i in range(len(x_jacobi)):
    print(f"x{i+1} = {x_jacobi[i]}")
