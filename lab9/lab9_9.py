import numpy as np
#Либо я не провильно понял задачу либо пример не правильный
a = np.array([1,2,3])                                            #input a
b = np.array([3,4,5])                                            #input a

max_num = max(a.max(), b.max())                                  #max size для bin_count

a_bin = (np.bincount(a) > 0) * 1                                 #Отсекаем если есть хотябы 1 раз
a_bin = np.insert(a_bin,a.max()+1, np.zeros([max_num - a.max()]))#Они не подходят по размеру, дополняем
b_bin = (np.bincount(b) > 0) * 1                                 #Отсекаем если есть хотябы 1 раз
b_bin = np.insert(b_bin,b.max()+1, np.zeros([max_num - b.max()]))#Они не подходят по размеру, дополняем


sum_bin = a_bin + b_bin                                          #Сладываем в общий векток чтобы найти пересечения
ans = np.argwhere(sum_bin > 1).reshape(-1)                       #Берем индексы пересечений, так как это bin_count это и есть числа
print(ans)
