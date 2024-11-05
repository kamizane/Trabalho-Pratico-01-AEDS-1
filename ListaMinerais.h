#ifndef LISTA_MINERAIS_H
#define LISTA_MINERAIS_H
//#define InicioArranjo 0
#define MaxTam 3

#include "./Mineral.h"

typedef struct {
  Mineral minerais[MaxTam];
  int tamanho;
} ListaMinerais;

void inicializarLista(ListaMinerais *lista);

void inserirMineral(ListaMinerais *lista, Mineral mineral);

void removerMineral(ListaMinerais *lista, Mineral mineral);

void imprimirListaMinerais(const ListaMinerais *lista);


#endif
