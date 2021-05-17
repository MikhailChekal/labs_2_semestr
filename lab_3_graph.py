import matplotlib.pyplot as plt


b = [1000, 10000, 100000]
plt.plot(b, [996, 140687, 13730495]) # massive без амортизации
a = [100000, 1000000, 10000000, 100000000]
plt.plot(a, [7978, 80818, 772932, 7824070]) # стек на основе списка
plt.plot(a, [2991, 29987, 277257, 2849374]) # Массив с амортизацией
plt.yscale('log')
plt.xscale('log')
plt.title('Сравнение различных штук')
plt.show()