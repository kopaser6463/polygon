import numpy as np
a = np.array([1,1,2,3,3,3])      #input
bins = np.bincount(a)            #bincount чтобы определить сколько каких значений, возможно лучше unique но будет менее удобно с индексами
ans = np.extract(bins[a]%2==0, a)#Выделяем значения по условию
print(ans)
