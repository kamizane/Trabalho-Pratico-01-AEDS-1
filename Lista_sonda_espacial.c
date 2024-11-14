#include "Lista_sonda_espacial.h"
#include <stdio.h>
#include <stdlib.h>

void inicializa_lista_sonda_espacial(Lista_sonda_espacial * lista_sonda){
    lista_sonda->pPrimeiro = (Celula*) malloc (sizeof(Celula));
    lista_sonda->pUltimo = lista_sonda->pPrimeiro;
    lista_sonda->pPrimeiro->pProx = NULL;
    lista_sonda->QntItens = 0;
}
int verifica_lista_vazia(Lista_sonda_espacial * lista_sonda){
    return (lista_sonda->pPrimeiro == lista_sonda->pUltimo);
    
}
void insere_item_lista_sonda_espacial(Lista_sonda_espacial * lista_sonda, Sonda_espacial* pItem){
    lista_sonda->pUltimo->pProx = (Celula*) malloc (sizeof(Celula));
    lista_sonda->pUltimo = lista_sonda->pPrimeiro->pProx;
    lista_sonda->pUltimo->item_sonda = *pItem;
    lista_sonda->QntItens ++;
    lista_sonda->pUltimo->pProx = NULL;

}
int retira_item_lista_sonda_espacial(Lista_sonda_espacial* lista_sonda, char * id, Sonda_espacial * pitem){
    if (verifica_lista_vazia(lista_sonda)){
        return 0;

    }
    else{
        //percorre a lista de 2 a 2 para que quando encontrar o item a ser removido o pProx anterior consiga apontar para o próximo item após remoção.
        Celula* pAux = lista_sonda->pPrimeiro->pProx;
        Celula* pAux_ant = lista_sonda->pPrimeiro;
        int count = 1;
        //ércorre a lista até encontrar o ultimo item
        while (pAux->pProx != NULL){
            if(*pAux->item_sonda.Identificador == *id){//pode ter um erro aqui
                if (count == lista_sonda->QntItens){
                    *pitem = pAux->item_sonda;
                    pAux_ant->pProx = NULL;
                    lista_sonda->pUltimo = pAux_ant;
                    free(pAux);
                    return 1;
                }
                else{
                    *pitem = pAux->item_sonda;
                    pAux_ant->pProx = pAux->pProx;
                    free(pAux);
                    return 1;
                }
            }
            else{
                pAux = pAux->pProx;
                pAux_ant = pAux_ant->pProx;
                count ++;
            }

        }
        printf("sonda com identificador %s não encontrado.", *id);
        return 0;
    }
}
int imprime_lista_sonda_espacial(Lista_sonda_espacial* lista_sonda){
    if (verifica_lista_vazia(lista_sonda)){
        printf("Lista vazia\n");
        return 0;
    }
    else {
        Celula* pAux = lista_sonda->pPrimeiro->pProx;
        while(pAux->pProx!= NULL){
            printf("%s, ", pAux->item_sonda.Identificador);
            pAux = pAux->pProx;
        }
    }
    return 1;
}