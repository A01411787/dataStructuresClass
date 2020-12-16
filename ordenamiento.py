import numpy as np

def intercambio(lista):
    n = len(lista)
    comparaciones = []
    Intercambios = []
    for i in range(n-1):
        comp = 0
        Inter = 0
        for j in range(i+1,n):
            comp = comp + 1
            if lista[i] > lista[j]:
                Inter = Inter + 1
                aux = lista[i]
                lista[i] = lista[j]
                lista[j] = aux
        comparaciones.append(comp)
        Intercambios.append(Inter)
        print(lista, comp, Inter)
        
    return lista, np.sum(np.array(comparaciones)), np.sum(np.array(Intercambios))

#Python program for implementation of Bubble Sort 
  
def bubbleSort(arr): 
    n = len(arr) 
    comparaciones = []
    Intercambios = []

    for i in range(n-1): 
        comp = 0
        inter = 0
        for j in range(0, n-i-1): 
            comp = comp + 1
            #print(arr[j], arr[j+1])
            if arr[j] > arr[j+1] : 
                arr[j], arr[j+1] = arr[j+1], arr[j]
                inter = inter + 1
        comparaciones.append(comp)
        Intercambios.append(inter)
        print(arr, comp, inter)
        if(inter) == 0:
            return arr, np.sum(np.array(comparaciones)), np.sum(np.array(Intercambios))

    return arr, np.sum(np.array(comparaciones)), np.sum(np.array(Intercambios))

# Traverse through all array elements 
def selection_sort(arr):
    n = len(arr)
    comparaciones = []
    Intercambios = []
    for i in reversed(range(n)): 
        #print(i)
        #print(arr.index(max(arr[:i+1])), arr.index(arr[i]))
        #print(arr[:i+1])
        if arr.index(max(arr[:i+1])) < arr.index(arr[i]):
            #print("intercambio!")
            arr[i], arr[arr.index(max(arr[:i+1]))] = arr[arr.index(max(arr[:i+1]))], arr[i]
            inter = 1
        else:
            inter = 0
        comp = i
        
        comparaciones.append(comp)
        Intercambios.append(inter)
        print(arr, comp, inter)
        #print("\n")
    return arr, np.sum(np.array(comparaciones)), np.sum(np.array(Intercambios))

def insertion_sort(array):
    comparaciones = []
    Intercambios = []
    for index in range(1, len(array)):
        comp = 0
        inter = 0
        currentValue = array[index]
        currentPosition = index

        while currentPosition > 0 and array[currentPosition - 1] > currentValue:
            inter = inter + 1
            comp = comp + 1
            array[currentPosition] = array[currentPosition -1]
            currentPosition = currentPosition - 1
        #print(currentPosition)
        
        if currentPosition > 0:
            comp = comp + 1
        
        array[currentPosition] = currentValue
        comparaciones.append(comp)
        Intercambios.append(inter)
        print(array, comp, inter)

    return array, np.sum(np.array(comparaciones)), np.sum(np.array(Intercambios))


print("Intercambio" + str(intercambio([9,1, 6,4,10, 3, 5])))
print("Bubble sort" + str(bubbleSort([9,1, 6,4,10, 3, 5])))
print("Seleccion directa" + str(selection_sort([9,1, 6,4,10, 3, 5])))
print("insertion_sort" + str(insertion_sort([9,1, 6,4,10, 3, 5])))