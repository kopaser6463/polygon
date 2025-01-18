import numpy as np

a = np.array([1,2,5,6])              #input
extract = np.extract(a != a.max(), a)#Удалим самый большой элемент(и все его включения)
ans = extract.max()                  #Найдем новый максимум
print(ans)
