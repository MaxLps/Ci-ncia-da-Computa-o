import copy
import time
import psutil
from collections import deque

class Node:
    def __init__(self, state, parent=None, action = [None], depth=0, cost=0):
        self.state = state     
        self.parent = parent
        self.action = action
        self.depth = depth
        self.cost = cost
    
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

def generate_node(node):
    zero = None
    state = copy.deepcopy(node.state)  # Cria uma cópia do estado do nó pai
    list_node = []

    for i, linha in enumerate(node.state):
        for j, elemento in enumerate(linha):
            if elemento == 0:
                zero = (i,j)
                break
        if zero == 0:
            break

    move = moves[(zero)]
    for valor in  move:
        if valor == "Down" and node.action[len(node.action) - 1] != "Up":
            action = node.action.copy()  
            action.append("Down")
            new_state = move_down(copy.deepcopy(state), zero)  
            new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)

        if valor == "Up" and node.action[len(node.action) - 1] != "Down":
            action = node.action.copy()  
            action.append("Up")
            new_state = move_up(copy.deepcopy(state), zero)  
            new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)

        if valor == "Right" and node.action[len(node.action) - 1] != "Left":
            action = node.action.copy()  
            action.append("Right")
            new_state = move_right(copy.deepcopy(state), zero)  
            new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)

        if valor == "Left" and node.action[len(node.action) - 1] != "Right":
            action = node.action.copy()  
            action.append("Left")
            new_state = move_left(copy.deepcopy(state), zero)  
            new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)
    return list_node


def matrices_equal(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        return False
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            if matrix1[i][j] != matrix2[i][j]:
                return False
    return True    

def imprime_matriz(matriz):
    for linha in matriz:
        for coluna in linha:
            print(coluna, end=' ')
        print()
    print("\n")    

objetivo = [[ 1, 2, 3 ],
            [ 4, 5, 6 ],
            [ 7, 8, 0 ]]

def IDFS(node, max_depth):
    pilha = deque()
    visitados = set()
    max_fringe_size = 0

    aux = copy.deepcopy(node)
    while not matrices_equal(objetivo, aux.state):
        visitados.add(matriz_para_tupla(aux.state))   
        lista = generate_node(aux)
        for i in lista:
            if not matriz_para_tupla(i.state) in visitados and i.depth <= max_depth:
                pilha.append(i)
                if len(pilha) > max_fringe_size:
                    max_fringe_size = len(pilha)
        aux = pilha.pop()
    return aux, len(pilha), len(visitados) + len(pilha), max_fringe_size
    

raiz = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

process = psutil.Process()

inicio = time.time()
memory_before = process.memory_info().rss

resultado, tamanho_pilha, visitados, max_fringe_size = IDFS(raiz, 70)

memory_after = process.memory_info().rss
fim = time.time()

tempo = fim - inicio
memoria = memory_after - memory_before
memoria = round(memoria / (1024 * 1024), 2)

caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_pilha,"\n",
      "max_fringe_size", max_fringe_size,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth:", resultado.depth,"\n",
      "running_time:", tempo,"\n",
      "max_search_depth: ",resultado.depth,"\n"
      "max_ram_usage: ", memoria,"\n")