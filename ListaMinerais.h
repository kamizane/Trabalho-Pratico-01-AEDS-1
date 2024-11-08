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
}Listaminerais;

int lEhVazia(Listaminerais* pLista);
int lInsere(Listaminerais* pLista, Mineral x);
void fLVazia(Listaminerais* pLista);
int lRetira(Listaminerais* pLista, Mineral *pX, char *nome);
void lImprime(Listaminerais* pLista);

#endif
