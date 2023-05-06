from collections import deque

class Node:
    def __init__(self, state, parent=None, action = ["inicio"], depth=0, cost=0):
        self.state = state     
        self.parent = parent
        self.action = action
        self.depth = depth
        self.cost = cost
        
    def __str__(self):
        return str(self.state)
    
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
    
def gerete_node(node):
    zero = None
    state = node.state.copy()
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
            action = node.action
            action.append("Down")
            state = move_down(state, zero)
            new_node = Node(state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)
        
        if valor == "Up":
            action = node.action
            action.append("Up")
            state = move_up(state, zero)
            new_node = Node(state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)
            
        if valor == "Right":
            action = node.action
            action.append("Right")
            state = move_right(state, zero)
            new_node = Node(state, node, action, node.depth + 1, node.cost + 1)
            list_node.append(new_node)
            
        if valor == "left":
            action = node.action
            action.append("Left")
            state = move_left(state, zero)
            new_node = Node(state, node, action, node.depth + 1, node.cost + 1)
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

objetivo = [
        [1,2,3],
        [4,5,6],
        [7,8,0]   
        ]

def DFS(node):
    pilha = []
    
    
    while not matrices_equal(objetivo,node.state):
        for i in 
    
