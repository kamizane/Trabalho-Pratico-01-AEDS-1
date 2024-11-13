#ifndef LISTA_MINERAIS_H
#define LISTA_MINERAIS_H
#define InicioArranjo 0
#define MaxTam 3

#include "./Mineral.h"

//typedef int TChave;
typedef int Apontador;

typedef struct {
  Mineral minerais[MaxTam];
  Apontador Primeiro, Ultimo;
}ListaMinerais;

int listaMineraisEVazia(ListaMinerais* pLista);
int insereMineralLista(ListaMinerais* pLista, Mineral x);
void fListaMineraisVazia(ListaMinerais* pLista);
int retiraMineralLista(ListaMinerais* pLista, Mineral *pX, char *nome);
void imprimeListaMinerais(ListaMinerais* pLista);

ListaMinerais getListaMinerais(ListaMinerais *lista){
  return *lista;
}

#endif
