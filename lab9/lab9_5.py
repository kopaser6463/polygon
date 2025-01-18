import numpy as np

a = np.array([3,9,1,1,2])#input
mod = a%3                #Цисла которое делятся на 3 станут 0
bins = np.bincount(mod)  #bincount очень удобен ведь есть все 3 возможных числа
ans = bins[0]            #Под 0 индексом числа который 0 остаток от деления на 3
print(ans)
