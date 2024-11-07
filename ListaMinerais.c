#include "./Mineral.h"
#include "Listaminerais.h"
#include <stdio.h>
#include <string.h>
#define InicioArranjo 0
#define MaxTam = 3

//verificar se lista é vazia
int lEhVazia(Listaminerais* pLista){
    return (pLista->Ultimo == pLista->Primeiro);
}

int lInsere(Listaminerais* pLista, Mineral x){
    if (pLista->Ultimo == MaxTam){
        return 0;
    }
    pLista->minerais[pLista->Ultimo] = x;
    pLista->Ultimo++;
    return 1;
}

void fLVazia(Listaminerais* pLista){
    pLista->Primeiro = InicioArranjo;
    pLista->Ultimo = pLista->Primeiro;
}

void lRetira(Listaminerais* pLista, Mineral *pX, char *nome){
    
    if (lEhVazia(pLista)){
        return 0;
    }else{
        //*pX = pLista->minerais[p];
        //pLista->Ultimo--;  

        for (int i = pLista->Primeiro; i <= pLista->Ultimo; i++){
            if(strcmp(pLista->minerais[i].nome) == 0){
                *px = pLista->minerais[i];

                for(int j = i+1; j < pLista->Ultimo; j++){
                    pLista->minerais[j-1] = pLista->minerais[j];
                }

                pLista->Ultimo--;
                return 1;
            }
        }
    }
    return 0;
} 

void lImprime(Listaminerais* pLista){
    for (int i = pLista->Primeiro; i < pLista->Ultimo; i++){
        printf("Nome: %s, Cor: %s, Dureza: %f, Reatividade: %f\n", 
        pLista->minerais[i].nome, pLista->minerais[i].cor, pLista->minerais[i].dureza,
        pLista->minerais.reatividade);
    }
} 

