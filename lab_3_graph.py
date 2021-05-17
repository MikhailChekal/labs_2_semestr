import matplotlib.pyplot as plt

p = [10, 100, 1000, 10000, 100000]
plt.plot(p, [2, 36, 1570, 138741, 13705552], marker = 's',  label="массив без амортизации") # massive без амортизации
a = [10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000]
a2 = [100, 10000, 1000000, 100000000, 10000000000]
plt.plot(a, [2, 16, 196, 849, 8013, 80630, 794070, 8089860], marker = 'v',  label="стек на основе списка") # стек на основе списка
plt.plot(a, [1, 5, 34, 312, 3041, 32739, 304789, 3058293], marker = 'v',  label="массив с амортизацией") # Массив с амортизацией

plt.plot(a, a, linestyle='dotted')
plt.plot(p, a2, linestyle='dotted')

plt.yscale('log')
plt.xscale('log')
plt.title('Сравнение реализаций стеков')
plt.legend()
plt.show()

