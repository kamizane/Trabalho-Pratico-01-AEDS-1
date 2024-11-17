#include <stdio.h>
#include <string.h>
#include "Mineral.h"

void atribui_mineral(Mineral * mineral, char nome_mineral[]){
    char cor[20];
    float dureza;
    float reatividade;

    if (strcmp(nome_mineral, "Ferrolita")==0){
        strcpy(cor,"cinza");
        dureza =0.5;
        reatividade =0.7;
    } else if (strcmp(nome_mineral , "Solarium")==0){
        strcpy(cor,"amarelo");
        dureza = 0.9;
        reatividade =0.2;
    }else if (strcmp(nome_mineral , "Aquavitae")==0){
        strcpy(cor,"azul");
        dureza =0.5;
        reatividade =0.8;
        printf("aaaaa");
    } else if (strcmp(nome_mineral , "Terranita")==0){
        strcpy(cor,"marrom");
        dureza =0.7;
        reatividade =0.6;
    } else if (strcmp(nome_mineral ,"Calaris")==0){
        strcpy(cor,"vermelho");
        dureza =0.6;
        reatividade =0.5;
    }

    inicializa_mineral(mineral,nome_mineral, cor, dureza,reatividade);
}

void cria_catalogo_minerais(Mineral minerais[5]){
   
    Mineral Ferrolita;
    Mineral Solarium;
    Mineral Aquavitae;
    Mineral Terranita;
    Mineral Calaris;

    inicializa_mineral(&Ferrolita, "Ferrolita", "cinza" , 0.5, 0.7);
    inicializa_mineral(&Solarium, "Solarium", "amarelo" , 0.9, 0.2);
    inicializa_mineral(&Aquavitae, "Aquavitae", "azul" , 0.5, 0.8);
    inicializa_mineral(&Terranita, "Terranita", "marrom" , 0.7, 0.6);
    inicializa_mineral(&Calaris, "Calaris", "vermelho" , 0.6, 0.5);

    minerais[0] = Ferrolita;
    minerais[1] = Solarium;
    minerais[2] = Aquavitae;
    minerais[3] = Terranita;
    minerais[4] = Calaris;

}

void preenche_mineral(Mineral * mineral){ //pede ao uzuário todas as informações para inicializar
    char nome[20];
    char cor[20];
    float dureza;
    float reatividade;

    printf("Nome do mineral:\n");
    scanf(" %[^\n]", nome);

    printf("Cor do mineral:\n");
    scanf(" %[^\n]", cor);


    printf("Dureza do mineral:\n");
    scanf("%f", &dureza);

    printf("Reatividade do mineral:\n");
    scanf("%f", &reatividade);

    inicializa_mineral(mineral, nome, cor, dureza, reatividade);
}

int inicializa_mineral(Mineral * mineral, char nome[], char cor[], float dureza, float reatividade){ //joga tudo no tad
    set_nome(mineral, nome);
    set_cor(mineral, cor);
    set_dureza(mineral, dureza);
    set_reatividade(mineral, reatividade);
  
    return 0;
}


char * get_nome(Mineral * mineral){
    return (mineral->nome);
}


char * get_cor(Mineral * mineral){
    return (mineral->cor);
}


float get_dureza(Mineral * mineral){
    return mineral->dureza;
}


float get_reatividade(Mineral * mineral){
    return mineral->reatividade;
}


void set_nome(Mineral * mineral, char * nome){
    strcpy(mineral->nome , nome);
}


void set_cor(Mineral * mineral, char * cor){
    strcpy(mineral->cor, cor);
}


void set_dureza(Mineral * mineral, float dureza){
    mineral->dureza = dureza;
}


void set_reatividade(Mineral * mineral, float reatividade){
    mineral->reatividade = reatividade;
}



