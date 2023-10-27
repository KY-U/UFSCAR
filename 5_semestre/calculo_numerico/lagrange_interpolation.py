#Bibliotecas
import numpy as np
from fractions import Fraction

#Pontos a serem interpolados
x0, y0 = -5, -9
x1, y1 = -2, -3
x2, y2 = 2, 7
x3, y3 = 6, -3

#Supressões de q(t)=(t−t0)⋯(t−ti−1)(t−ti)(t−ti+1)⋯(t−tka) retirando o fator (t-ti)
q0 = np.poly1d([x1, x2, x3], True)
q1 = np.poly1d([x0, x2, x3], True)
q2 = np.poly1d([x0, x1, x3], True)
q3 = np.poly1d([x0, x1, x2], True)

#Polinômios de Lagrange
print('1 / ', q0(x0))
print()
print(q0)

print('1 / ', q1(x1))
print()
print(q1)

print('1 / ', q2(x2))
print()
print(q2)

print('1 / ', q3(x3))
print()
print(q3)

