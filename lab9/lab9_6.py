import numpy as np
#Либо я не провильно понял задачу либо пример либо счет с 1
a = np.array([3,2,3,3,1])                 #input array
ind = 2                                   #input index

try:
    ans = np.argwhere(a == a.max())[ind-1]#Находим все индексы и выбираем нужный, (С нуля или не с нуля?)
    print(ans.item())
except:
    print("Такого нет")
