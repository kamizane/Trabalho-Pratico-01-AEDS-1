#include "Sonda_espacial.h"
#include <stdio.h>
#include <string.h>

void Inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, char *latitude,char * longitude){
    void Set_Identificador(sonda, id);
    void Set_Compartimento(sonda,200.3);
    void Set_Localizacao(sonda,latitude,longitude);
    void Set_EstaLigada(sonda, estado);

}
void Preenche_Sonda_Espacial(Sonda_espacial * sonda){
    char id[20],latitude[20],longitude[20];
    printf("Digite o identificador da Sonda espacial: ");
    scanf("%[^\n]", id);

    printf("Digite a latitude da Sonda espacial: ");
    scanf("%[^\n]", latitude);

    printf("Digite a longitude da Sonda espacial: ");
    scanf("%[^\n]", longitude);

    Inicializa_Sonda_Espacial(sonda, id, latitude, longitude);

}
int Liga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == ON){
        return 0;
    } 
    else{
        sonda->EstaLigada = ON;
        return 1;
    }
}
int Desliga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == OFF){
        return 0;
    }
    else{
        sonda->EstaLigada == OFF;
        return 1;
    }
}
void Move_Sonda_Espacial (Sonda_espacial * sonda){
    
}
void Set_Identificador(Sonda_espacial*sonda, char * id){
    strcpy(sonda->Identificador, id);
}

void Set_Compartimento(Sonda_espacial*sonda,float compartimento){
    sonda->Compartimento = compartimento;
}
void Set_Localizacao(Sonda_espacial * sonda, char * latitude, char*longitude){
    strcpy(sonda->Localizacao.Latitude, latitude);
    strcpy(sonda->Localizacao.Longitude, longitude);
}
void Set_EstaLigada(Sonda_espacial *sonda, EstaLigada estado){
    sonda->EstaLigada = estado;
}