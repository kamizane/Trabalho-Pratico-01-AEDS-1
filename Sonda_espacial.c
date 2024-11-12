#include "Sonda_espacial.h"
#include <stdio.h>
#include <string.h>

void inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, char *latitude,char * longitude, float capacidade, float velocidade, float combustivel){
    set_Identificador(sonda, id);
    set_Compartimento(sonda);
    set_Localizacao_sonda(sonda,latitude,longitude);
    set_Capacidade(sonda,capacidade);
    set_Velocidade(sonda, velocidade);
    set_Combustivel(sonda, combustivel);
    set_EstaLigada(sonda, OFF);

}
void preenche_Sonda_Espacial(Sonda_espacial * sonda){
    char id[20],latitude[20],longitude[20];
    float capacidade,velocidade,combustivel;
    printf("Digite o identificador da Sonda espacial: ");
    scanf("%[^\n]", id);

    printf("Digite a latitude da Sonda espacial: ");
    scanf("%[^\n]", latitude);

    printf("Digite a longitude da Sonda espacial: ");
    scanf("%[^\n]", longitude);

    inicializa_Sonda_Espacial(sonda, id, latitude, longitude,capacidade,velocidade,combustivel);

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
    faz_compartimento_vazio(&sonda->Compartimento);//pode ter um erro aqui
}
void set_Localizacao_sonda(Sonda_espacial * sonda, char * latitude, char*longitude){
    strcpy(sonda->Localizacao_sonda.Latitude, latitude);
    strcpy(sonda->Localizacao_sonda.Longitude, longitude);
}
void set_Capacidade(Sonda_espacial *sonda, float capacidade){
    sonda->Capacidade_sonda = capacidade;
}
void set_Velocidade(Sonda_espacial * sonda, float velocidade){
    sonda->Velocidade_sonda = velocidade;
}
void set_Combustivel(Sonda_espacial * sonda, float combustivel){
    sonda->Combustivel_sonda = combustivel;
}
void set_EstaLigada(Sonda_espacial *sonda, EstaLigada estado){
    sonda->EstaLigada = estado;
}