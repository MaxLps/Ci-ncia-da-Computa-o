import random
import copy
import math

N = 8

def pares_ataque(matriz):
    pares = []
    for i in range(N):
        for j in range(N - 1):
            if matriz[i][j] == 1 and matriz[i][j + 1] == 1:
                pares.append(((i, j), (i, j + 1)))
    
    # Verificar pares na mesma coluna
    for j in range(N):
        for i in range(N - 1):
            if matriz[i][j] == 1 and matriz[i + 1][j] == 1:
                pares.append(((i, j), (i + 1, j)))
    # Verificar pares na mesma diagonal principal
    for i in range(N - 1):
        for j in range(N - 1):
            if matriz[i][j] == 1 and matriz[i + 1][j + 1] == 1:
                pares.append(((i, j), (i + 1, j + 1)))
    
    # Verificar pares na mesma diagonal secundária
    for i in range(N - 1):
        for j in range(1, N):
            if matriz[i][j] == 1 and matriz[i + 1][j - 1] == 1:
                pares.append(((i, j), (i + 1, j - 1)))
    return pares

class No:
    def __init__(self, estado):
        self.estado = estado
        self.heuristica = self.calc_heuristica()
    
    def ataque(self, i,j, atacados):
        #verificando linha
        for coluna in range(N):
            if self.estado[i][coluna] == 1 and coluna != j:
                if (i,coluna) < (i,j):
                    atacados.add(((i,coluna),(i,j)))
                else: 
                    atacados.add(((i,j),(i,coluna)))
            
        #diagonal esquerda superior
        linha = i - 1
        coluna = j - 1
        while linha >= 0 and coluna >= 0:
            if self.estado[linha][coluna] == 1:
                if (i,coluna) < (i,j):
                    atacados.add(((linha,coluna),(i,j)))
                else: 
                    atacados.add(((i,j),(linha,coluna)))
            linha -= 1
            coluna -= 1
            
        #diagonal direita superior
        linha = i - 1
        coluna = j + 1
        while linha >= 0 and coluna < N:
            if self.estado[linha][coluna] == 1:
                if (i,coluna) < (i,j):
                    atacados.add(((linha,coluna),(i,j)))
                else: 
                    atacados.add(((i,j),(linha,coluna)))
            linha -= 1
            coluna += 1
            
        #diagonal esquerda inferior
        linha = i + 1
        coluna = j - 1
        while linha < N and coluna >= 0:
            if self.estado[linha][coluna] == 1:
                if (i,coluna) < (i,j):
                    atacados.add(((linha,coluna),(i,j)))
                else: 
                    atacados.add(((i,j),(linha,coluna)))
            linha += 1
            coluna -= 1
            
        #diagonal direita inferior
        linha = i + 1
        coluna = j + 1
        while linha < N and coluna < N:
            if self.estado[linha][coluna] == 1:
                if (i,coluna) < (i,j):
                    atacados.add(((linha,coluna),(i,j)))
                else: 
                    atacados.add(((i,j),(linha,coluna)))
            linha += 1
            coluna += 1
        return len(atacados)
             
    def calc_heuristica(self):
        atacados = set()
        for i in range(N):
            for j in range(N):
                if self.estado[i][j] == 1:
                    self.ataque(i,j, atacados)
        return len(atacados)

def gera_estado(estado):
    lista_de_nos = []
    for j in range(N):
        for i in range(N):
            if estado[i][j] == 1:
                for k in range(N):
                    estado_novo = copy.deepcopy(estado)
                    if(k != i):
                        estado_novo[k][j] = 1
                        estado_novo[i][j] = 0
                        no_novo = No(estado_novo)
                        lista_de_nos.append((no_novo.heuristica,no_novo))
    return lista_de_nos

def subida_de_encosta(no):
    atual = no
    while 1:
        vizinhos = gera_estado(atual.estado)
        melhor_vizinho = min(vizinhos, key = lambda x : x[0])
        if melhor_vizinho[1].heuristica >= atual.heuristica:
            return atual
        atual = melhor_vizinho[1]
        
def escalonamento(t):
    t -= 1
    return t
        
def tempera_simulada(no, t):
    atual = no
    while True:
        vizinhos = gera_estado(atual.estado)
        if t == 0:
            return atual
        proximo = random.choice(vizinhos)
        delta = proximo[0] - atual.heuristica
        if delta > 0:
            atual = proximo[1]
        else:  
            if random.uniform(0,1) < math.exp(delta / t):
                atual = proximo[1]
        t = escalonamento(t)  

def gera_tabuleiro():
    matriz = [[0] * N for _ in range(N)]
    
    coluna = list(range(8))

    random.shuffle(coluna)

    for i in range(N):
        matriz[random.randint(0,7)][coluna[i]] = 1
    return matriz

def imprime_matriz(matriz):
    for i in matriz:
        for j in i:
            print(j, end="   ")
        print("\n")

somatorio_subida = 0
somatorio_tempera = 0

iteracoes = 100

for i in range(iteracoes):    
    estado = gera_tabuleiro()
    
    no1 = No(estado)
    no2 = No(estado)
    
    somatorio_subida += subida_de_encosta(no1).heuristica
    somatorio_tempera += tempera_simulada(no2,50).heuristica
    
print("Média de conflitos subida de encosta: ", somatorio_subida/iteracoes)
print("Média de conflitos encosta: ", somatorio_tempera/iteracoes)
    
