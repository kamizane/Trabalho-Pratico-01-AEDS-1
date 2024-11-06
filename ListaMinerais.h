#ifndef LISTA_MINERAIS_H
#define LISTA_MINERAIS_H
#define InicioArranjo 0
#define MaxTam 3

#include "./Mineral.h"

typedef int TChave;
typedef int Apontador;

typedef struct {
  TChave Chave;

} Mineral;

typedef struct {
  Mineral Item[MaxTam];
  Apontador Primeiro, Ultimo;
}ListaMinerais;

int LEhVazia(ListaMinerais* pLista);
int LInsere(ListaMinerais* pLista, Mineral x);
void FLVazia(ListaMinerais* pLista);
int LRetira(ListaMinerais* pLista, Mineral *pX, char *nome);
void LImprime(ListaMinerais* pLista);

#endif
