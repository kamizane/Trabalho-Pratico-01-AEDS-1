#ifndef LISTA_MINERAIS_H
#define LISTA_MINERAIS_H
#define InicioArranjo 0
#define MaxTam 3

#include "./Mineral.h"
#include "RochaMineral.h"

//definindo o tipo Apontador
typedef int Apontador;

//definindo o tipo ListaMinerais
typedef struct {
  Mineral minerais[MaxTam];
  Apontador Primeiro, Ultimo;
}ListaMinerais;

//cabeçalho das funções básicas
int listaMineraisEVazia(ListaMinerais* pLista);
int insereMineralLista(ListaMinerais* pLista, Mineral x);
void fListaMineraisVazia(ListaMinerais* pLista);
int retiraMineralLista(ListaMinerais* pLista, Mineral *pX, char *nome);
void imprimeListaMinerais(ListaMinerais* pLista);

#endif
