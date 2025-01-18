import numpy as np
#Описание задачи может ввести в заблуждение
a = np.array([1,1,1,2,2,2])                        #input
values, counts = np.unique(a, return_counts = True)#Функция выделяет значения и их колличества
bool_trashhold = counts>2                          #threshold массив-маска
#extract = np.extract(bool_trashhold, values)
extract = values[bool_trashhold]                   #Выделяем значения по маске
ans = extract.sum()                                #Суммируем значения для получения ответа
print(ans)
