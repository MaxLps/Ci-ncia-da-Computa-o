#include <stdio.h>
int main(){
    double nota1, nota2, nota3, nota4, media, exame;
    scanf("%lf %lf %lf %lf",&nota1, &nota2, &nota3, &nota4);
    media = (nota1*2+nota2*3+nota3*4+nota4*1)/10;
    if (media>= 7){
        printf("Media: %.1lf\nAluno aprovado.\n",media);
    }
    if (media<5){
        printf("Media: %.1lf\nAluno reprovado.\n",media);
    }
    if (media>=5 && media<=6.9){
        printf("Media: %.1lf\nAluno em exame.\n",media);
        scanf("%lf",&exame);
        printf("Nota do exame: %.1lf\n",exame);
        media = (media + exame)/2;
        if(media>=5){
            printf("Aluno aprovado.\nMedia final: %.1lf\n",media);
        }
        else{
            printf("Media: %.1lf\nAluno reprovado.\n",media);
        }
    }
    return 0;
}