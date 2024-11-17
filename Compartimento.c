#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Compartimento.h"

const char * nomesRochas[]={
    " ",//vazio pois o enum CategoriaRochaMineral começa do 1
    "FERROM",
    "SOLARIS",
    "AQUAFERRO",
    "TERROLIS",
    "TERRASOL",
    "AQUATERRA",
    "CALQUER",
    "SOLARISFER",
    "TERRALIS",
    "AQUACALIS"
};

void faz_compartimento_vazio(Compartimento* compartimento, float peso_max){

    compartimento->primeiro = (Ccelula*) malloc(sizeof(Ccelula));
    compartimento->ultimo = compartimento->primeiro;
    compartimento->primeiro->prox = NULL;
    compartimento->tamanho = 0;
    compartimento->peso_atual = 0;
    compartimento->peso_maximo = peso_max;

}

int tamanho_do_compartimento(Compartimento* compartimento){
    return compartimento->tamanho;
}

int compartimento_eh_vazio(Compartimento* compartimento){
    return (compartimento->tamanho == 0);
}

int imprime_compartimento(Compartimento* compartimento, FILE *saida){    
    Ccelula* celula;
 
    if (compartimento_eh_vazio(compartimento)){
        printf("compartimento vazio!\n");
        fprintf(saida, "compartimento vazio!\n");
        return 0;
    }
  
    celula = compartimento->primeiro->prox;
    do{
   

        printf("%s %.2f\n",celula->rocha.categoria, celula->rocha.peso);
        fprintf(saida, "%s %.2f\n",celula->rocha.categoria, celula->rocha.peso);
        
        celula = celula->prox;
      
    }while(celula->prox != NULL);
  
    return 1;
}

float retorna_peso_atual(Compartimento* compartimento){
    return compartimento->peso_atual;
}

int trocar_rocha(Compartimento* compartimento, RochaMineral* rocha){
  
    Ccelula* celula;

    celula = compartimento->primeiro->prox;
    if (!compartimento_eh_vazio(compartimento)){
        do{
          
            
                if (strcmp(celula->rocha.categoria,rocha->categoria) == 0){  
                 

                    if (celula->rocha.peso > rocha->peso){
                    
                        compartimento->peso_atual -= celula->rocha.peso;
                        celula->rocha = *rocha;
                        compartimento->peso_atual += celula->rocha.peso;
                   
                        return 1;
                    }
                }

            celula = celula->prox;

        }while(celula->prox != NULL);
    }

    return 0;
}



int inserir_rocha(Compartimento* compartimento, RochaMineral* rocha){
    if((compartimento->peso_atual + rocha->peso) <= compartimento->peso_maximo){
        compartimento->ultimo->prox = (Ccelula*) malloc(sizeof(Ccelula));
        compartimento->ultimo = compartimento->ultimo->prox;
        compartimento->ultimo->rocha = *rocha;
        compartimento->ultimo->prox = NULL;
        compartimento->tamanho++;
        compartimento->peso_atual += rocha->peso;
        return 1;
    }

    return 0;
}

int remover_rocha(Compartimento* compartimento, char categoria[]){ //
    Ccelula* anterior;
    Ccelula* celula;

    celula = compartimento->primeiro->prox;
    anterior = compartimento->primeiro;



    do{

        if(strcmp(categoria, celula->rocha.categoria) == 0){
            anterior->prox = celula->prox;
            compartimento->peso_atual -= celula->rocha.peso;
            free(celula);
            compartimento->tamanho--;

            return 1; 

        }
        
        
        anterior = celula;
        celula = celula->prox;

    }while(celula != NULL);

    return 0;
}