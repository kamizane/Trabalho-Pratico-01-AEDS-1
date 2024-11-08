#ifndef SONDA_ESPACIAL_H
#define SONDA_ESPACIAL_H

typedef struct{
    char Latitude[20];
    char Longitude[20];
}Localizacao;

typedef enum{
    ON = 0,
    OFF = 1
}EstaLigada;


typedef struct {
    char Identificador[20];
    Compartimento Compartimento;
    Localizacao Localizacao;
    EstaLigada EstaLigada;
}Sonda_espacial;

void Inicializa_Sonda_Espacial(Sonda_espacial * sonda, char * id, char *latitude,char * longitude);
void Preenche_Sonda_Espacial(Sonda_espacial * sonda);
int Liga_Sonda_Espacial(Sonda_espacial * sonda);
int Desliga_Sonda_Espacial(Sonda_espacial * sonda);
void Move_Sonda_Espacial (Sonda_espacial * sonda);
void Set_Identificador(Sonda_espacial*sonda, char * id);
void Set_Compartimento(Sonda_espacial*sonda,float Compartimento);
void Set_Localizacao(Sonda_espacial * sonda, char * latitude, char*longitude);
void Set_EstaLigada(Sonda_espacial *sonda, EstaLigada estado);


#endif