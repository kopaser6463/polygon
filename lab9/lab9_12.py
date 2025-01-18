import numpy as np
a = np.array([1,1,2,3])              #input
ans = a.size != np.unique(a).size    #Равноценно сравнению с set в обычном питоне
print(ans)
