from collections import deque
import copy

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
    
def move_left(state, zero):
    state[zero[0]][zero[1]], state[zero[0]][zero[1]-1] = state[zero[0]][zero[1]-1], state[zero[0]][zero[1]]
    return state

visitados = set()

def generate_node(node):
    zero = None
    state = copy.deepcopy(node.state)  
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
        if valor == "Down":
            action = copy.deepcopy(node.action)  
            action.append("Down")
            new_state = move_down(copy.deepcopy(state), zero)
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Up":
            action = copy.deepcopy(node.action)  
            action.append("Up")
            new_state = move_up(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Right":
            action = copy.deepcopy(node.action)  
            action.append("Right")
            new_state = move_right(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)

        if valor == "Left":
            action = copy.deepcopy(node.action)  
            action.append("Left")
            new_state = move_left(copy.deepcopy(state), zero)  
            if not matriz_para_tupla(new_state) in visitados:
                visitados.add(matriz_para_tupla(new_state)) 
                new_node = Node(new_state, node, action, node.depth + 1, node.cost + 1)
                list_node.append(new_node)
    return list_node

def matrices_equal(matrix1, matrix2):
    if matriz_para_tupla(matrix1) == matriz_para_tupla(matrix2):
        return True
    return False   

def imprime_matriz(matriz):
    for linha in matriz:
        for coluna in linha:
            print(coluna, end=' ')
        print()
    print("\n")  

objetivo = matriz_para_tupla([[ 0, 1, 2 ],
                              [ 3, 4, 5 ],
                              [ 6, 7, 8 ]])

def BFS(node):
    fila = deque()
    aux = copy.deepcopy(node)
    while not objetivo == matriz_para_tupla(aux.state):  
        lista = generate_node(aux)
        for i in lista:
            fila.append(i)
        aux = fila.popleft()
    return aux, len(fila), len(visitados) + len(fila)

raiz = Node([[ 0, 8, 7 ],
             [ 6, 5, 4 ],
             [ 3, 2, 1 ]])

resultado, tamanho_fila, visitados = BFS(raiz)
caminho = resultado.action[1:]

print("path_to_goal: ", caminho,"\n",
      "cost_of_path: ", resultado.cost,"\n",
      "nodes_expanded: ", visitados,"\n",
      "fringe_size: ", tamanho_fila,"\n",
      "search_depth: ", resultado.depth,"\n",
      "max_search_depth: ",resultado.depth)