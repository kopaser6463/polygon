import numpy as np
#Неверная задача, или пример, в задаче колличество, в примере сумма
a = np.array([1,1,2,3,1,5]) #input
mean = a.mean()             #Среднее значение
threshold = 1 * (a > mean)  #threshold
ans = threshold.sum()       #Просто сумма колличества элементов, 1 * boolean -> int
print(ans)


#ИЛИ


a = np.array([1,1,2,3,1,5]) #input
mean = a.mean()             #Среднее значение
threshold = a * (a > mean)  #threshold, но вместо колличества теперь само значение
ans = threshold.sum()       #Просто сумма элементов
#print(ans)
