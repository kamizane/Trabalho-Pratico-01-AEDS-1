#include <stdio.h>
#include "Compatimento.h"
#include "RochaMineral.h"

int faz_compartimento_vazio(Compartimento* compartimento){

    compartimento->primeiro = (Ccelula*) malloc(sizeof(Ccelula));
    compartimento->ultimo = compartimento->primeiro;
    compartimento->primeiro->prox = NULL;
    compartimento->tamanho = 0;

}

int tamanho_do_compartimento(Compartimento* compartimento){
    return compartimento->tamanho;
}

int compartimento_eh_vazio(Compartimento* compartimento){
    return (compartimento->tamanho == 0);
}

int imprime_compartimento(Compartimento* compartimento){    
    Ccelula* celula;

    if (compartimento_eh_vazio(&compartimento)){
        printf("compartimento eh vazio!\n");
        return 0;
    }

    celula = compartimento->primeiro->prox;
    do{
        
        printf("%s",celula->rocha.categoria);
        
        celula = celula->prox;

    }while(celula->prox != NULL);


}

int trocar_rocha(Compartimento* compartimento, RochaMineral* rocha){

    Ccelula* celula;

    celula = compartimento->primeiro->prox;
    do{
        
        if (celula->rocha.categoria == rocha->categoria){

            if (celula->rocha.peso <= rocha->peso){
                celula->rocha = *rocha;

            }
        }
        
        celula = celula->prox;

    }while(celula->prox != NULL);
}

int inserir_rocha(Compartimento* compartimento, RochaMineral* rocha){

    compartimento->ultimo->prox = (Ccelula*) malloc(sizeof(Ccelula));
    compartimento->ultimo = compartimento->ultimo->prox;
    compartimento->ultimo->rocha = *rocha;
    compartimento->ultimo->prox = NULL;
    compartimento->tamanho++;

    return 0;

}

int remover_rocha(Compartimento* compartimento, char categoria[]){
    Ccelula* anterior;
    Ccelula* celula;

    celula = compartimento->primeiro->prox;
    anterior = compartimento->primeiro;

    do{

        if(celula->rocha.categoria == categoria){
            anterior->prox = celula->prox;
            
            free(celula);
            compartimento->tamanho--;

            return 1; 

        }
        
        anterior = celula;
        celula = celula->prox;

    }while(celula->prox != NULL);

    return 0;
}