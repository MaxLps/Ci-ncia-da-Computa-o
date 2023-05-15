from collections import deque
from heapq import heapify
import copy

class Node:
    def __init__(self, state, manhattan, parent=None, action = [None], depth=0, cost=0):
        self.state = state     
        self.parent = parent
        self.action = action
        self.depth = depth
        self.cost = cost
        self.manhattan = manhattan
    
moves = {
    (0, 0): ["Down", "Right"],
    (0, 1): ["Down", "Left", "Right"],
    (0, 2): ["Down", "Left"],
    (1, 0): ["Up", "Down", "Right"],
    (1, 1): ["Up", "Down", "Left", "Right"],
    (1, 2): ["Up", "Down", "Left"],
    (2, 0): ["Up", "Right"],
    (2, 1): ["Up", "Left", "Right"],
    (2, 2): ["Up", "Left"]
}

def matriz_para_tupla(matriz):
    tupla = [tuple(list) for list in matriz]
    return tuple(tupla)

def move_down(state, zero):
    state[zero[0]][zero[1]], state[zero[0]+1][zero[1]] = state[zero[0]+1][zero[1]], state[zero[0]][zero[1]]
    return state

def move_up(state, zero):
    state[zero[0]][zero[1]], state[zero[0]-1][zero[1]] = state[zero[0]-1][zero[1]], state[zero[0]][zero[1]]
    return state

def move_right(state, zero):
    state[zero[0]][zero[1]], state[zero[0]][zero[1]+1] = state[zero[0]][zero[1]+1], state[zero[0]][zero[1]]
    return state
    
def move_left(state, zero):
    state[zero[0]][zero[1]], state[zero[0]][zero[1]-1] = state[zero[0]][zero[1]-1], state[zero[0]][zero[1]]
    return state
    
def move_left(state, zero):
    state[zero[0]][zero[1]], state[zero[0]][zero[1]-1] = state[zero[0]][zero[1]-1], state[zero[0]][zero[1]]
    return state

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
            cont = cont + abs(ponto1[0] - ponto2[0]) + abs(ponto1[1] - ponto2[1])
    return cont

visitados = set()

def generate_node(node):
    zero = None
    state = copy.deepcopy(node.state)  
    list_node = []
    list_pontos = ponto_tupla(node.state)
    zero = list_pontos[0]

    move = moves[(zero)]
    for valor in  move:
        if valor == "Down":
            action = copy.deepcopy(node.action)  
            action.append("Down")
            new_state = move_down(copy.deepcopy(state), zero)
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                manhattan = dist_manhattan(new_state)
                new_node = Node(new_state, manhattan, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Up":
            action = copy.deepcopy(node.action)  
            action.append("Up")
            new_state = move_up(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                manhattan = dist_manhattan(new_state)
                new_node = Node(new_state, manhattan, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Right":
            action = copy.deepcopy(node.action)  
            action.append("Right")
            new_state = move_right(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                manhattan = dist_manhattan(new_state)
                new_node = Node(new_state, manhattan, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Left":
            action = copy.deepcopy(node.action)  
            action.append("Left")
            new_state = move_left(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                manhattan = dist_manhattan(new_state)
                new_node = Node(new_state, manhattan, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)
    return list_node 

objetivo = matriz_para_tupla([[ 0, 1, 2 ],
                              [ 3, 4, 5 ],
                              [ 6, 7, 8 ]])

def BFS(node):
    lista = []
    aux = copy.deepcopy(node)
    while not objetivo == matriz_para_tupla(aux.state):  
        lista.extend(generate_node(aux))
        aux = min(lista, key=lambda x: x.manhattan)
        lista.remove(aux)
    return aux, len(lista), len(visitados) + len(lista)

inicial = [[ 0, 8, 7 ],
           [ 6, 5, 4 ],
           [ 3, 2, 1 ]]

raiz = Node(inicial, dist_manhattan(inicial))

resultado, tamanho_fila, visitados = BFS(raiz)
caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_fila,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth: ",resultado.depth)