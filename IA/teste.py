from collections import deque
import copy
import time

# Definindo o estado objetivo do jogo
objetivo = [[0, 1, 2], 
            [3, 4, 5], 
            [6, 7, 8]] # Espaço em branco é o 0

paths = {
    (0,0): ["Right","Down"],
    (0,1): ["Right","Down","Left"],
    (0,2): ["Left","Down"],
    (1,0): ["Up","Right","Down"],
    (1,1): ["Left","Up","Down","Right"],
    (1,2): ["Left","Down","Up"],
    (2,0): ["Up", "Right"],
    (2,1): ["Left","Up","Right"],
    (2,2): ["Left","Up"]
}

class Node:
    def __init__(self, cost, depth, action, parent, state):
        self.cost = cost
        self.depth = depth
        self.action = action    
        self.parent = parent
        self.state = state

# Definindo a função para encontrar a posição do espaço em branco
def get_Zero(state):
    for i in range(3):
        for j in range(3):
            if state[i][j] == 0:
                return i, j
            
# Definindo a função para encontrar o proximo estado 

def get_NextNode(node):
    state = copy.deepcopy(node.state)
    zero = get_Zero(state)
    i, j = zero[0], zero[1]
    next_nodes = []
    
    # Para cada ação possível na posição do espaço em branco, gera um próximo estado
    
    action = paths[zero]
    
    for x in action:
        
        if x == "Up":
            new_state = copy.deepcopy(state)
            action = copy.deepcopy(node.action) 
            action.append("Up")
            new_state[i][j], new_state[i-1][j] = new_state[i-1][j], new_state[i][j]
            new_node = Node(node.cost + 1, node.depth + 1, action, node, new_state)
            next_nodes.append(new_node)
            
        if x == "Down":
            new_state = copy.deepcopy(state)
            action = copy.deepcopy(node.action) 
            action.append("Down")
            new_state[i][j], new_state[i+1][j] = new_state[i+1][j], new_state[i][j]
            new_node = Node(node.cost + 1, node.depth + 1, action, node, new_state)
            next_nodes.append(new_node)
        
        if x == "Right":
            new_state = copy.deepcopy(state)
            action = copy.deepcopy(node.action) 
            action.append("right")
            new_state[i][j], new_state[i][j+1] = new_state[i][j+1], new_state[i][j]
            new_node = Node(node.cost + 1, node.depth + 1, action, node, new_state)
            next_nodes.append(new_node)
        
        if x == "Left":
            new_state = copy.deepcopy(state)
            action = copy.deepcopy(node.action) 
            action.append("Left")
            new_state[i][j], new_state[i][j-1] = new_state[i][j-1], new_state[i][j]
            new_node = Node(node.cost + 1, node.depth + 1, action, node, new_state)
            next_nodes.append(new_node)
    
    return next_nodes

# Definindo a função para ser o Objetivo        

def testaObjetivo(state, objetivo):
    for i in range(len(state)):
        for j in range(len(state)):
            if state[i][j] != objetivo[i][j]:
                return False
    return True       

def bfs(initial):
    # Inicializando um conjunto vazio para armazenar os estados visitados

    visited = set()

    max_fringe_depth = 0
    max_search_depth = 0

    # Adicionando o estado inicial à fila

    frontier = deque() 
    
    frontier.append(initial)
    # Enquanto a fila não estiver vazia
    
    while frontier:
        # Remove o primeiro estado da fila
        node = frontier.popleft()
        if node.depth >= max_search_depth:
            max_search_depth = node.depth
        visited.add(tuple(map(tuple, node.state)))
        # Se o estado removido for o estado objetivo, retorna o caminho para esse estado
        # Expandir o nó atual
        aux = get_NextNode(node)
        for child in aux:
            if tuple(map(tuple, child.state)) not in visited:
                if testaObjetivo(child.state, objetivo):
                    return child.action, child.cost, len(visited), len(frontier), child.depth, max_fringe_depth, max_search_depth
                frontier.append(child)   
    
    return node.action, node.cost, len(visited), len(frontier), node.depth, max_fringe_depth, max_search_depth

# Definindo a Configuração Inicial

raiz = [[0,8,7], 
        [6,5,4], 
        [3,2,1]]

config_inicial = Node(0,0,["pai"],None, raiz)

start_time = time.time()
path_to_goal, cost_of_path, nodes_expande, fringe_size, search_depth, max_fringe_depth, max_search_depth = bfs(config_inicial)
final_time = time.time()
 
running_time = final_time - start_time

print(f"path_to_goal: {path_to_goal}")
print(f"cost_of_path: {cost_of_path}")
print(f"nodes_expanded: {nodes_expande}")
print(f"fringe_size: {fringe_size}")
print(f"search_depth: {search_depth}")
print(f"running_time: {running_time}")
print(f"max_fringe_depth: {max_fringe_depth}")
print(f"max_search_depth: {max_search_depth}")