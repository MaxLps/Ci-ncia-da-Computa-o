from collections import deque
import copy
import time
import psutil

class Node:
    def __init__(self, state, parent=None, action = ["pai"], depth=0, cost=0):
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

visitados = set()
pilha = []

max_fringe_size = 0

def max_fringe():
    global pilha
    global max_fringe_size
    if len(pilha) > max_fringe_size:
        max_fringe_size = len(pilha)

def cria_no(new_state, move, node):
    global pilha
    if not matriz_para_tupla(new_state) in visitados:
        visitados.add(matriz_para_tupla(new_state))
        action = copy.deepcopy(node.action)  
        action.append(move)
        new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
        pilha.append(new_node)
        max_fringe()

def generate_node(node):
    zero = None
    state = copy.deepcopy(node.state)  

    for i, linha in enumerate(node.state):
        for j, elemento in enumerate(linha):
            if elemento == 0:
                zero = (i,j)
                break
        if elemento == 0:
            break

    move = moves[(zero)]
    for valor in  move:
        if valor == "Down":
            new_state = move_down(copy.deepcopy(state), zero)
            cria_no(new_state, valor, node)

        if valor == "Up":
            new_state = move_up(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node)
            
        if valor == "Right":
            new_state = move_right(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node)

        if valor == "Left":
            new_state = move_left(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node)
            
def matrices_equal(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        return False
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            if matrix1[i][j] != matrix2[i][j]:
                return False
    return True 

objetivo = [[ 1, 2, 3 ],
            [ 4, 5, 6 ],
            [ 7, 8, 0 ]]

def DFS(node):
    global pilha
    aux = node
    while not matrices_equal(objetivo, aux.state):
        if aux.depth < 40:
            generate_node(aux)
        aux = pilha.pop()
    return aux, len(pilha), len(visitados) + len(pilha)

raiz = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

process = psutil.Process()

inicio = time.time()
memory_before = process.memory_info().rss

resultado, tamanho_pilha, visitados = DFS(raiz)

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