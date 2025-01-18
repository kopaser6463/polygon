import numpy as np

with open("cats.bmp", "rb") as file:                        #Читаем изображение из bmp файла
    file_read = file.read()
    img_bytes = file_read[54:]                              #54 это byte ofset взятый из bmp header
    img = np.frombuffer(img_bytes, dtype = np.uint8)        #Перевод из byte в uint8
    
img = img.reshape([1024,1024,3])[::-1,]                     #bmp считает левый нижний угл местом начала коардинат + превод в обычный формат изображения

gray = img[:,:,[0,0,0]]                                     #Делаем изображение где остальные каналы заменяны 1
gray = (gray[:,:] > 110)                                    #Делаем threashhold по яркости
gray = gray[:,:,[0,0,0]]                                    #Восстанавливаем колличество измерений чтобы numpy умножил

gray2 = img[:,:,[1,1,1]]                                    #Делаем изображение где остальные каналы заменяны 2
gray2 = (gray2[:,:] < 84)                                   #Делаем threashhold по яркости
gray2 = gray2[:,:,[0,0,0]]                                  #Восстанавливаем колличество измерений чтобы numpy умножил

gray3 = img[:,:,[2,2,2]]                                    #Делаем изображение где остальные каналы заменяны 3
gray3 = (gray3[:,:] < 184)                                  #Делаем threashhold по яркости
gray3 = gray3[:,:,[0,0,0]]                                  #Восстанавливаем колличество измерений чтобы numpy умножил
white_space = np.invert(gray + gray2 + gray3) * np.array([255,255,255])   #Заливаем одну маску белым
best_img = (white_space + (gray + gray2 + gray3) * img).astype(np.uint8)  #Соединяем маски в одну и применняем на фото
best_img_resh = best_img[::-1,].reshape([1024*1024*3])      #Переводив изображение в 1 dim array
btd = np.array(best_img_resh, dtype = np.uint8).tobytes()   #Переводим новое изображение в байты

with open("cats5.bmp", "wb") as file:                       #Создаём новый файл
    file.write(file_read[:54])                              #Записываем туда header изначального bmp
    file.write(btd)                                         #Записываем байты изображения
    


