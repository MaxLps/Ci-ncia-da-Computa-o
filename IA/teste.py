import copy

def imprime_matriz(matriz):
    for linha in matriz:
        for coluna in linha:
            print(coluna, end=' ')
        print()
    print("\n")

objetivo = [[1,2,3],[4,5,6],[7,8,0]]

matriz = objetivo.copy()

matriz[0][0] = 20

imprime_matriz(objetivo)

a = [[1,2,3],[4,5,6],[7,8,0]]

b = copy.deepcopy(a)

b[0][0] = 50

imprime_matriz(a)

objetivo[0][0], objetivo[0][1] = objetivo[0][1], objetivo[0][0]

imprime_matriz(objetivo)

teste1 = ["oi","tudo bem?","não"]

print(len(teste1))

objetivo = [[1,2,3],[4,5,6],[7,8,0]]
a = [[1,2,3],[4,5,6],[7,8,0]]

def heuristc(state, objetivo) -> int:
    count = 0
    for i in range(len(state)):
        for j in range(len(state[0])):
            if state[i][j] != objetivo[i][j]:
                count += 1
    return count

def matriz_para_string(matriz):
    s = ''
    for linha in matriz:
        s += ''.join(str(elem) for elem in linha)
    return s

print(matriz_para_string(a), "porra")

print(heuristc(a, objetivo), "oi")