#include <stdio.h>
#include <string.h>
#include "Mineral.h"

int preenche_mineral(Mineral * mineral){ //pede ao uzuário todas as informações para inicializar
    char nome[20];
    char cor[20];
    float dureza;
    float reatividade;

    printf("Nome do mineral:\n");
    scanf(" %[^\n]", nome);

    printf("Cor do mineral:\n");
    scanf(" %[^\n]", cor);


    printf("Dureza do mineral:\n");
    scanf("%f", &dureza);

    printf("Reatividade do mineral:\n");
    scanf("%f", &reatividade);

    inicializa_mineral(mineral, nome, cor, dureza, reatividade);
}

int inicializa_mineral(Mineral * mineral, char nome[], char cor[], float dureza, float reatividade){ //joga tudo no tad
    set_nome(mineral, nome);
    set_cor(mineral, cor);
    set_dureza(mineral, dureza);
    set_reatividade(mineral, reatividade);
  
    return 0;
}


char * get_nome(Mineral * mineral){
    return (mineral->nome);
}


char * get_cor(Mineral * mineral){
    return (mineral->cor);
}


float get_dureza(Mineral * mineral){
    return mineral->dureza;
}


float get_reatividade(Mineral * mineral){
    return mineral->reatividade;
}


void set_nome(Mineral * mineral, char * nome){
    strcpy(mineral->nome , nome);
}


void set_cor(Mineral * mineral, char * cor){
    strcpy(mineral->cor, cor);
}


void set_dureza(Mineral * mineral, float dureza){
    mineral->dureza = dureza;
}


void set_reatividade(Mineral * mineral, float reatividade){
    mineral->reatividade = reatividade;
}



