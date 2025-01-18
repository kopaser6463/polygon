import numpy as np

a = np.array([1,np.nan,1,2,3])                         #input
extra = np.extract(np.bitwise_xor(np.isnan(a),1),a)    #Не обящательно, просто чтобы не заменять nan на nan
values, counts = np.unique(extra, return_counts = True)#Функция unique возвращает количество повторений
index_max = counts.argmax()                            #Индекс числа которое встречается большее количество раз в values
ans = np.where(np.isnan(a), values[index_max], a)      #Замена nan на найденную моду
