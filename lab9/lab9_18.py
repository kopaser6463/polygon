import numpy as np

sizew = 500
sizeh = 200

ind1 = np.arange(sizeh * sizew).reshape(sizeh,sizew)

ind2 = np.concatenate([ind1]*2, axis = 0)[1:sizeh + 1]               #матрица индексов ведущая вверх по модулю
ind3 = np.concatenate([ind1]*2, axis = 1)[:,1:sizew + 1]             #матрица индексов ведущая влево по модулювлево

ind4 = np.concatenate([ind1]*2, axis = 0)[sizeh - 1:sizeh*2-1]        #матрица индексов ведущая ввниз по модулювниз
ind5 = np.concatenate([ind1]*2, axis = 1)[:,sizew - 1: sizew * 2 - 1] #матрица индексов ведущая впрово по модулю


GlobalMap = np.zeros([sizeh,sizew], dtype = int)                           #Создаём глобальную карту
GlobalMap = (np.random.rand(sizeh,sizew) > 0.8).astype(int)
GlobalMap[5][4] = 1
GlobalMap[5][5] = 1
GlobalMap[5][6] = 1
GlobalMap[4][6] = 1
GlobalMap[3][5] = 1


def move():
    NeubourgMap = np.zeros([sizeh,sizew], dtype = int)

    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind2]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind3]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind4]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind5]

    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind2].reshape(sizeh*sizew)[ind3]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind2].reshape(sizeh*sizew)[ind5]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind4].reshape(sizeh*sizew)[ind3]
    NeubourgMap += GlobalMap.reshape(sizeh*sizew)[ind4].reshape(sizeh*sizew)[ind5]

    NewNeubourgMap1 = ( NeubourgMap == 3).astype(bool)
    NewNeubourgMap2 = ((NeubourgMap == 2) * GlobalMap).astype(bool)

    return (NewNeubourgMap1 + NewNeubourgMap2).astype(int)
def printer(map_p):
    z  = np.ones(sizeh) * 10
    z2 = np.ones(sizeh) * 13
    draw_map = (np.invert(map_p.astype(bool)) * (46 - 35)) + 35
    draw_map = np.insert(draw_map,sizew,z,axis = 1)
    draw_map = np.insert(draw_map,sizew+1,z2,axis = 1)
    #print(draw_map)
    print(draw_map.astype(np.uint8).tobytes().decode())

def start_main_loop():
    global GlobalMap
    while True:
        printer(GlobalMap)
        GlobalMap = move()
inp = input("Tap enter to start:")
start_main_loop()
#46 35 254
11
