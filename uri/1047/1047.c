#include <stdio.h>

int calculaTempo(short int horaInicio, short int minutoInicio, short int horaFim, short int minutoFim){
    unsigned short int tempo;

    if(horaInicio > horaFim){
        tempo =  1440 - (horaInicio*60 + minutoInicio);
        tempo += horaFim*60 + minutoFim;
    }else
        tempo = (horaFim*60 + minutoFim) - (horaInicio*60 + minutoInicio);

    return(tempo);
}

int main(){
    short int horaInicio, minutoInicio, horaFim, minutoFim, retorno;

    scanf("%hi:%hi", &horaInicio, &minutoInicio);

    scanf("%hi:%hi", &horaFim, &minutoFim);

    retorno = calculaTempo(horaInicio, minutoInicio, horaFim, minutoFim);

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", retorno/60, retorno%60);

    return(0);
}