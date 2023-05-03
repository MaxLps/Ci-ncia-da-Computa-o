import random

class Sala:
    def __init__(self, nome):
        self.nome = nome
        self.estado = None   #0 = limpo    1 = sujo
        
class Agente:
    def __init__(self, posicao):
        self.pontos = 0
        self.posicao = posicao

    def anda(self):
        if self.posicao == 0:
            self.posicao = 1  #anda para a direita
        else:
            self.posicao = 0  #anda para a esquerda    

    def limpa(self, salas):
        if salas[self.posicao].estado == 1:
            salas[self.posicao].estado = 0
            self.pontos = self.pontos + 1
            
class Simulacao:
    def __init__(self, estado1, estado2, posicao):
        self.salas = [Sala('sala 1'), Sala('sala 2')]
        self.aspirador = Agente(posicao)
        
        self.salas[0].estado = estado1
        self.salas[1].estado = estado2

    def simula_estado(self):
        if self.salas[0].estado == 0:
            self.salas[0].estado = random.randint(0,1)
        if self.salas[1].estado == 0:
            self.salas[1].estado = random.randint(0,1)  

cenario1 = Simulacao(1, 0, 0)
cenario2 = Simulacao(1, 0, 1)
cenario3 = Simulacao(0, 1, 0)
cenario4 = Simulacao(0, 1, 1)
cenario5 = Simulacao(1, 1, 0)
cenario6 = Simulacao(1, 1, 1)
cenario7 = Simulacao(0, 0, 0)
cenario8 = Simulacao(0, 0, 1)


for i in range(1000):
    
    cenario1.aspirador.limpa(cenario1.salas)
    cenario1.aspirador.anda()
    cenario1.simula_estado()

    cenario2.aspirador.limpa(cenario2.salas)
    cenario2.aspirador.anda()
    cenario2.simula_estado()

    cenario3.aspirador.limpa(cenario3.salas)
    cenario3.aspirador.anda()
    cenario3.simula_estado()

    cenario4.aspirador.limpa(cenario4.salas)
    cenario4.aspirador.anda()
    cenario4.simula_estado()

    cenario5.aspirador.limpa(cenario5.salas)
    cenario5.aspirador.anda()
    cenario5.simula_estado()


    cenario6.aspirador.limpa(cenario6.salas)
    cenario6.aspirador.anda()
    cenario6.simula_estado()

    cenario7.aspirador.limpa(cenario7.salas)
    cenario7.aspirador.anda()
    cenario7.simula_estado()

    cenario8.aspirador.limpa(cenario8.salas)
    cenario8.aspirador.anda()
    cenario8.simula_estado()

media_global = (cenario1.aspirador.pontos + cenario2.aspirador.pontos +
                cenario3.aspirador.pontos + cenario4.aspirador.pontos + 
                cenario5.aspirador.pontos + cenario6.aspirador.pontos +
                cenario7.aspirador.pontos + cenario8.aspirador.pontos)/8

print("Cenário 1:", cenario1.aspirador.pontos, "pontos\n")
print("Cenário 2:", cenario2.aspirador.pontos, "pontos\n")
print("Cenário 3:", cenario3.aspirador.pontos, "pontos\n")
print("Cenário 4:", cenario4.aspirador.pontos, "pontos\n")
print("Cenário 5:", cenario5.aspirador.pontos, "pontos\n")
print("Cenário 6:", cenario6.aspirador.pontos, "pontos\n")
print("Cenário 7:", cenario7.aspirador.pontos, "pontos\n")
print("Cenário 8:", cenario8.aspirador.pontos, "pontos\n")

print("Média global = ", media_global)