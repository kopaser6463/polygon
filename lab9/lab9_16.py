import numpy as np

a = np.array([[1,1],
              [1,2]]) #input

one = np.identity(a.shape[0])#Едиичная матрица той же формы
diag = a * one               #Поэлементное умножение с единисной матрицей даёт главную диагональ
ans = diag.sum()             #Сумма элементов диагонали
print(ans)
