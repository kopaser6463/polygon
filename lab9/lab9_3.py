import numpy as np
a = np.array([1,5,10,0])                #input
ans = (a - a.min()) / (a.max()-a.min()) #Использование методов numpy в соответствии с данной формулой
print(ans)
