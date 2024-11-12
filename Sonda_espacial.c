#include "Sonda_espacial.h"
#include <stdio.h>
#include <string.h>

void inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, char *latitude,char * longitude){
    set_Identificador(sonda, id);
    set_Compartimento(sonda);
    set_Localizacao(sonda,latitude,longitude);
    set_EstaLigada(sonda);

}
void preenche_Sonda_Espacial(Sonda_espacial * sonda){
    char id[20],latitude[20],longitude[20];
    printf("Digite o identificador da Sonda espacial: ");
    scanf("%[^\n]", id);

    printf("Digite a latitude da Sonda espacial: ");
    scanf("%[^\n]", latitude);

    printf("Digite a longitude da Sonda espacial: ");
    scanf("%[^\n]", longitude);

    inicializa_Sonda_Espacial(sonda, id, latitude, longitude);

}
int liga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == ON){
        return 0;
    } 
    else{
        sonda->EstaLigada = ON;
        return 1;
    }
}
int desliga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == OFF){
        return 0;
    }
    else{
        sonda->EstaLigada == OFF;
        return 1;
    }
}
void move_Sonda_Espacial (Sonda_espacial * sonda){
    
}
void set_Identificador(Sonda_espacial*sonda, char * id){
    strcpy(sonda->Identificador, id);
}

void set_Compartimento(Sonda_espacial*sonda){
    faz_compartimento_vazio(&sonda->Compartimento);
}
void set_Localizacao(Sonda_espacial * sonda, char * latitude, char*longitude){
    strcpy(sonda->Localizacao.Latitude, latitude);
    strcpy(sonda->Localizacao.Longitude, longitude);
}
void set_EstaLigada(Sonda_espacial *sonda){
    desliga_Sonda_Espacial(sonda);
}