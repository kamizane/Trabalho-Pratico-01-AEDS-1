#include "./Mineral.h"
#include <stdio.h>
#define MaxTam = 3

void inicializarLista(ListaMinerais *lista){
    lista->tamanho = 0;
}

void inserirMineral(ListaMinerais *lista, Mineral mineral){
    if(lista->tamanho < MaxTam){
        lista->minerais[lista->tamanho++] = mineral;
    }else{
        printf("Lista cheia!\n");
    }
}

void removerMineral(ListaMinerais *lista, Mineral mineral){
    
}

void imprimirListaMinerais(const ListaMinerais *lista){
    for (int i = 0; i < lista->tamanho; i++) {
    printf("Nome: %s, Cor: %s, Dureza: %f, Reatividade: %f\n",
           lista->minerais[i].nome, lista->minerais[i].cor,
           lista->minerais[i].dureza, lista->minerais[i].reatividade);
  }
}