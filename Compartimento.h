#ifndef COMPARTIMENTO_H
#define COMPARTIMENTO_H

#include "RochaMineral.h"

typedef struct celula{

    RochaMineral rocha;
    struct celula* prox;

} Ccelula;

typedef struct{

    Ccelula * primeiro;
    Ccelula * ultimo;
    int tamanho;
    float peso_atual;
    float peso_maximo;

} Compartimento;


void faz_compartimento_vazio(Compartimento* compartimento, float peso_max);

int tamanho_do_compartimento(Compartimento* compartimento);

int compartimento_eh_vazio(Compartimento* compartimento);

int imprime_compartimento(Compartimento* compartimento);

float retorna_peso_atual(Compartimento* compartimento);

int trocar_rocha(Compartimento* compartimento, RochaMineral* rocha);

int inserir_rocha(Compartimento* compartimento, RochaMineral* rocha);

int remover_rocha(Compartimento* compartimento, char categoria[]);


#endif