from heapq import heapify
"""
def ponto_tupla(matriz):
    lista = [None] * 9  
    for i, linha in enumerate(matriz):
        for j, elemento in enumerate(linha):
            lista[elemento] = (i, j)
    return lista

objetivo = [[0,1,2],
            [3,4,5],
            [6,7,8]]

pontos_objtivo = ponto_tupla(objetivo)

def dist_manhattan(matriz): 
    pontos_matriz = ponto_tupla(matriz)
    cont = 0
    for i in range(9):
        if i != 0:
            ponto1 = pontos_objtivo[i]
            ponto2 = pontos_matriz[i]
            print(ponto1, ponto2)
            cont = cont + abs(ponto1[0] - ponto2[0]) + abs(ponto1[1] - ponto2[1])
    return cont

matriz = [[7,2,4],
          [5,0,6],
          [8,3,1]]

print(dist_manhattan(matriz))

"""

class Oi:
    def __init__(self, oi):
        self.oi = oi
        
elementos = [Oi(5), Oi(2), Oi(10), Oi(-80), Oi(0)]

# Aplicar a função sorted() para ordenar a lista de objetos
elemento = min(elementos, key=lambda x: x.oi)

# Obter o elemento de menor prioridade com base no atributo 'oi'
print(elemento.oi)  # Saída: 2
