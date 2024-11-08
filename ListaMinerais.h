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

int lEhVazia(ListaMinerais* pLista);
int lInsere(ListaMinerais* pLista, Mineral x);
void fLVazia(ListaMinerais* pLista);
int lRetira(ListaMinerais* pLista, Mineral *pX, char *nome);
void lImprime(ListaMinerais* pLista);

#endif
