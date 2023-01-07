#include <stdio.h>
#include <stdlib.h>
struct arvb{
    int info;
    struct arvb* esq;
    struct arvb* dir;
};
typedef struct arvb Arvb;
Arvb* cria_arv(){
    return NULL;
}
Arvb* insere_arv(Arvb* arv, int n){
    if(arv == NULL){
        Arvb* arv = (Arvb*)malloc(sizeof(Arvb));
        arv->info = n;
        arv->esq = NULL;
        arv->dir = NULL;
    }
    else{
        if(n < arv->info){
            arv->esq = insere_arv(arv->esq, n);
        }
        else{
            if(n > arv->info){
                arv->dir = insere_arv(arv->dir, n);
            }
        }
    }
    return arv; 
}
Arvb* remove_arv(Arvb* arv, int n){
    if(arv == NULL){
        return NULL;
    }
    else{
        if(arv->info > n){
            arv->esq = remove_arv(arv->esq, n);
        }
        else{
            if(arv->info < n){
                arv->dir = remove_arv(arv->dir, n);
            }
            else{
                if(arv->esq == NULL && arv->dir == NULL){
                    free(arv);
                    arv = NULL;
                }
                else{
                    if(arv->esq == NULL){
                        Arvb* aux = arv;
                        arv = arv->dir;
                        free(aux);
                    }
                    else{
                        if(arv->dir == NULL){
                            Arvb* aux = arv;
                            arv = arv->esq;
                            free(aux);
                        }
                        else{
                            Arvb* aux = arv->esq;
                            while(aux->dir != NULL){
                                aux = aux->dir;
                            }
                            arv->info = aux->info;
                            aux->info = n;
                            arv->esq = remove_arv(arv->esq, n);
                        }
                    }
                }
            }
        }
    }
    return arv;
}
void imprime_arv(Arvb* arv){
    printf("<");
    printf("%d",arv->info);
    printf("<");
    imprime_arv(arv->esq);
    printf(">");
    printf("<");
    imprime_arv(arv->dir);
    printf(">");
}
int main(){
    int i, n;
    Arvb* arvore = cria_arv();
    printf("Insira os elementos da arvore\n");
    for(i=0; i<10; i++){
        scanf("%d",&n);
        insere_arv(arvore, n);
    }
    imprime_arv(arvore);
    printf("Qual elemento deve ser removido?\n");
    scanf("%d",&n);
    remove_arv(arvore, n);
    imprime_arv(arvore);
    return 0;
}