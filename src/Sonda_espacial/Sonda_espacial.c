#include <stdio.h>
#include <string.h>
#include "./Sonda_espacial.h"

void inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, float latitude,float longitude, float capacidade, float velocidade, float combustivel){
    set_Identificador(sonda, id);
    set_Compartimento(sonda, capacidade);
    set_Localizacao_sonda(sonda,latitude,longitude);
    set_Velocidade(sonda, velocidade);
    set_Combustivel(sonda, combustivel);
    set_EstaLigada(sonda, OFF);
}
void preenche_Sonda_Espacial(Sonda_espacial * sonda){
    char id[20];
    float latitude = 0,longitude = 0;
    float capacidade = 0,velocidade = 0,combustivel = 0;
    printf("Digite o identificador da Sonda espacial: ");
    scanf("%[^\n]", id);

    printf("Digite a latitude da Sonda espacial: ");
    scanf("%f", &latitude);

    printf("Digite a longitude da Sonda espacial: ");
    scanf("%f", &longitude);


    inicializa_Sonda_Espacial(sonda, id, latitude, longitude,capacidade,velocidade,combustivel);


}
int liga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == ON){
        return 0;
    } 
    else{
        set_EstaLigada(sonda, ON);
        return 1;
    }
}
int desliga_Sonda_Espacial(Sonda_espacial * sonda){
    if (sonda->EstaLigada == OFF){
        return 0;
    }
    else{
        set_EstaLigada(sonda,OFF);
        return 1;
    }
}
void move_Sonda_Espacial (Sonda_espacial * sonda, float latitude, float longitude){
    set_Localizacao_sonda(sonda,latitude,longitude);
}
void set_Identificador(Sonda_espacial*sonda, char * id){
    strcpy(sonda->Identificador, id);
}

void set_Compartimento(Sonda_espacial*sonda, float capacidade){
    faz_compartimento_vazio(&sonda->Compartimento, capacidade);//pode ter um erro aqui
}
void set_Localizacao_sonda(Sonda_espacial * sonda, float latitude, float longitude){
    sonda->Localizacao_sonda.Latitude = latitude;
    sonda->Localizacao_sonda.Longitude = longitude;
}
void set_Velocidade(Sonda_espacial * sonda, float velocidade){
    sonda->Velocidade_sonda = velocidade;
}
void set_Combustivel(Sonda_espacial * sonda, float combustivel){
    sonda->Combustivel_sonda = combustivel;
}
void set_EstaLigada(Sonda_espacial *sonda, EstaLigada tipo){
    sonda->EstaLigada = tipo;
}