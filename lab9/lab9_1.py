import numpy as np
a = np.array([1,2,1,5,1,2]) #input
a -= a.min()                #Особый трюк, bincount не наботает на отрицательный и не ъфективен для больших чисел                     
ans = np.bincount(a)[a]     #Ввиду природы bincount цифры являются своими же индексами
print(ans)

