#ifndef MYMALLOC_H
#define MYMALLOC_H

struct bloco_de_memoria{
    int tamanho;
    struct bloco_de_memoria *prox;
}bloco_de_memoria;

typedef struct bloco_de_memoria Bloco;

void *MYmalloc(int q_memoria);
void MYfree(void *endereco);
void percorreLista(Bloco *lst);




#endif /* MYMALLOC_H */