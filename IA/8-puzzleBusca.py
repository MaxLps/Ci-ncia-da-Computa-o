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

def matrices_equal(matrix1, matrix2):
    if len(matrix1) != len(matrix2) or len(matrix1[0]) != len(matrix2[0]):
        return False
    for i in range(len(matrix1)):
        for j in range(len(matrix1[0])):
            if matrix1[i][j] != matrix2[i][j]:
                return False
    return True 

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

def max_fringe(lista, max_fringe_size):
    if len(lista) > max_fringe_size:
        max_fringe_size = len(lista)

def cria_no(new_state, move, node, fila, visitados):
    if not matriz_para_tupla(new_state) in visitados:
        visitados.add(matriz_para_tupla(new_state))
        action = copy.deepcopy(node.action)  
        action.append(move)
        new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
        fila.append(new_node)

def generate_node(node, lista, visitados):
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
            cria_no(new_state, valor, node, lista, visitados)

        if valor == "Up":
            new_state = move_up(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node, lista, visitados)
            
        if valor == "Right":
            new_state = move_right(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node, lista, visitados)

        if valor == "Left":
            new_state = move_left(copy.deepcopy(state), zero)  
            cria_no(new_state, valor, node, lista, visitados)


objetivo = [[ 0, 1, 2 ],
            [ 3, 4, 5 ],
            [ 6, 7, 8 ]]

def BFS(node):
    visitados = set()
    fila = deque()
    max_fringe_size = 0
    aux = node
    while not matrices_equal(objetivo, aux.state):  
        generate_node(aux, fila, visitados)
        if len(fila) > max_fringe_size:
            max_fringe_size = len(fila)
        aux = fila.popleft()
    return aux, len(fila), len(visitados) + len(fila), max_fringe_size

root = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

process = psutil.Process()

inicio = time.time()
memory_before = process.memory_info().rss

resultado, tamanho_fila, visitados, max_fringe_size = BFS(root)

memory_after = process.memory_info().rss
fim = time.time()

tempo = fim - inicio
memoria = memory_after - memory_before
memoria = round(memoria / (1024 * 1024), 2)

caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_fila,"\n",
      "max_fringe_size:", max_fringe_size,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth:", resultado.depth,"\n",
      "running_time:", tempo,"\n",
      "max_search_depth: ",resultado.depth,"\n"
      "max_ram_usage: ", memoria,"\n")

def DFS(node, max_depth):
    visitados = set()
    pilha = []
    max_fringe_size = 0
    aux = node
    while not matrices_equal(objetivo, aux.state): 
        if aux.depth <= max_depth:   
            generate_node(aux, pilha, visitados)
        if len(pilha) > max_fringe_size:
            max_fringe_size = len(pilha)
        if pilha:
            aux = pilha.pop()
        else:
            return None
    return aux, len(pilha), len(visitados) + len(pilha), max_fringe_size

root = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

process = psutil.Process()

inicio = time.time()
memory_before = process.memory_info().rss

resultado, tamanho_fila, visitados, max_fringe_size = DFS(root,50) 

memory_after = process.memory_info().rss
fim = time.time()

tempo = fim - inicio
memoria = memory_after - memory_before
memoria = round(memoria / (1024 * 1024), 2)

caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_fila,"\n",
      "max_fringe_size:", max_fringe_size,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth:", resultado.depth,"\n",
      "running_time:", tempo,"\n",
      "max_search_depth: ",resultado.depth,"\n"
      "max_ram_usage: ", memoria,"\n")

def IDFS(node):
    i = 0
    while True:
        resultado = DFS(node, i)
        if resultado is None:
            i += 1
        else:
            node = resultado[0]
            tamanho_fila = resultado[1]
            visitados = resultado[2]
            max_fringe_size = resultado[3]
            return node, tamanho_fila, visitados, max_fringe_size

root = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

process = psutil.Process()

inicio = time.time()
memory_before = process.memory_info().rss

resultado, tamanho_fila, visitados, max_fringe_size = IDFS(root) 

memory_after = process.memory_info().rss
fim = time.time()

tempo = fim - inicio
memoria = memory_after - memory_before
memoria = round(memoria / (1024 * 1024), 2)

caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_fila,"\n",
      "max_fringe_size:", max_fringe_size,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth:", resultado.depth,"\n",
      "running_time:", tempo,"\n",
      "max_search_depth: ",resultado.depth,"\n"
      "max_ram_usage: ", memoria,"\n")