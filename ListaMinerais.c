#include "./Mineral.h"
#include "ListaMinerais.h"
#include <stdio.h>
#include <string.h>
#define InicioArranjo 0
#define MaxTam = 3

//verificar se lista é vazia
int lEhVazia(ListaMinerais* pLista){
    return (pLista->Ultimo == pLista->Primeiro);
}

int lInsere(ListaMinerais* pLista, TItem x){
    if (pLista->Ultimo == MaxTam){
        return 0;
    }
    pLista->Item[pLista->Ultimo] = x;
    pLista->Ultimo++;
    return 1;
}

void fLVazia(ListaMinerais* pLista){
    pLista->Primeiro = InicioArranjo;
    pLista->Ultimo = pLista->Primeiro;
}

void lRetira(ListaMinerais* pLista, TItem *pX, char *nome){
    
    if (lEhVazia(pLista)){
        return 0;
    }else{
        //*pX = pLista->Item[p];
        //pLista->Ultimo--;  

        for (int i = pLista->Primeiro; i <= pLista->Ultimo; i++){
            if(strcmp(pLista->Item[i].nome) == 0){
                *px = pLista->Item[i];

                for(int j = i+1; j < pLista->Ultimo; j++){
                    pLista->Item[j-1] = pLista->Item[j];
                }

                pLista->Ultimo--;
                return 1;
            }
        }
    }
    return 0;
} 

void lImprime(ListaMinerais* pLista){
    for (int i = pLista->Primeiro; i < pLista->Ultimo; i++){
        printf("Nome: %s, Cor: %s, Dureza: %f, Reatividade: %f\n", 
        pLista->Item[i].nome, pLista->Item[i].cor, pLista->Item[i].dureza,
        pLista->Item.reatividade);
    }
} 

