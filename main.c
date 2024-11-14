#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Sonda_espacial.h"
#include "Lista_sonda_espacial.h"
#include "Mineral.h"
#include "RochaMineral.h"
#include "Compartimento.h"


void operacao_R(Lista_sonda_espacial * lista_sondas, float lat_rocha, float long_rocha, float peso_rocha, char * lista_minerais_rocha);
float calcula_distancia(float x1, float y1, float x2, float y2);

void operacao_I(Lista_sonda_espacial * lista_sondas);

int main(int argc,char **argv){
    if(strcmp(argv[1],"-f")==0){
        FILE *file = NULL;
        file = fopen(argv[2],"r");
        if (file == NULL){
            printf("Arquivo não existe");
            return 0;
        }
        Lista_sonda_espacial lista_de_sondas_file;
        inicializa_lista_sonda_espacial(&lista_de_sondas_file);
        int numero_sondas;
        fscanf(file, "%d",&numero_sondas);

        for (int i=0; i<numero_sondas; i++){
            char id =(char)i;
            Sonda_espacial sonda;
            float lat_i,long_i,capacidade_i,velocidade_i,combustivel_i;
            fscanf(file, "%f %f %f %f %f", &lat_i,&long_i,&capacidade_i,&velocidade_i,&combustivel_i);
            inicializa_Sonda_Espacial(&sonda, &id, lat_i,long_i,capacidade_i,velocidade_i,combustivel_i);
            insere_item_lista_sonda_espacial(&lista_de_sondas_file,&sonda);
            
        }
        int N_instrucao;
        fscanf(file,"%d",&N_instrucao);
        for(int i=0;i<N_instrucao;i++){
            char instrucao;
            fscanf(file,"%c",&instrucao);
            switch (instrucao)
            {
            case 'R':
                char linha[255];
                fgets(linha,255,file);
                char * buffer = NULL;
                const char delim[2] = " ";
                buffer = strtok(linha,delim);
                float lat_rocha = atof (buffer);
                buffer = strtok(NULL,delim);
                float long_rocha = atof(buffer);
                buffer = strtok(NULL,delim);
                float peso_rocha = atof (buffer);
                int i = 0;
                char aux;
                Mineral minerais[2];
                ListaMinerais lista_minerais_file;
                fListaMineraisVazia(&lista_minerais_file);
                while(buffer != NULL){
                    buffer = strtok(NULL,delim);
                    strcpy(aux,buffer);
                    inicializa_mineral(&minerais[i],aux);
                    insereMineralLista(&lista_minerais_file,minerais[i]);
                    //strcpy(minerais[i].nome,buffer);//corrigir

                    i++;
                }
                operacao_R(&lista_de_sondas_file,lat_rocha, long_rocha, peso_rocha, &lista_minerais_file );

                break;
            case 'I':

                break;
            default:
                break;
            }
        }
        

    
    }
    else{
        int numero_de_sondas; //separa o numero de sondas 
        Lista_sonda_espacial Lista_de_sondas_terminal; //cria lista de sondas
        
        inicializa_lista_sonda_espacial(&Lista_de_sondas_terminal);//inicializa lista de sondas
        scanf("%d", &numero_de_sondas); //recebe o numero de sondas de entrada
        
        for(int i = 0; i<numero_de_sondas; i++){; //recebe todas as variaveis de acordo com o numero de sondas

            char id =(char)i;
            Sonda_espacial sonda;
            float lat_i,long_i,capacidade_i,velocidade_i,combustivel_i;
            scanf("%f %f %f %f %f", &lat_i,&long_i,&capacidade_i,&velocidade_i,&combustivel_i);
            inicializa_Sonda_Espacial(&sonda,&id,lat_i,long_i,capacidade_i,velocidade_i,combustivel_i);//inicializa as sondas com as variaveis recebidas
            insere_item_lista_sonda_espacial(&Lista_de_sondas_terminal,&sonda);//adiciona a sonda na lista de sondas
        }
        
        int N_instrucao_terminal; //cria variavel N_instrucao (numero de operaçoes que vao ser feitas)
        scanf("%d", &N_instrucao_terminal); //recebe a N_instrucao (numero de operaçoes que vao ser feitas)
        for(int i = 0; i<N_instrucao_terminal; i++){ //para cada N_instrucao lê a instrucao e realiza ela, chamando a função pronta
            char instrucao_terminal;
            scanf("%c", &instrucao_terminal);
            switch (instrucao_terminal)
            {
            case 'R': //coleta de uma nova rocha
                char linha_terminal[255];
                scanf("%[^\n]", &linha_terminal);
                char * buffer = NULL;
                const char delim[2] = " ";
                buffer = strtok(linha_terminal,delim);
                float lat_rocha_terminal =  atof (buffer);
                buffer = strtok(NULL,delim);
                float long_rocha_terminal = atof(buffer);
                buffer = strtok(NULL,delim);
                float peso_rocha_terminal = atof (buffer);
                int counter = 0;
                char aux[20];
                Mineral minerais_terminal[3];
                ListaMinerais lista_minerais_terminal;
                fListaMineraisVazia(&lista_minerais_terminal);
                while(buffer != NULL){
                    buffer = strtok(NULL,delim);
                    strcpy(aux,buffer);
                    inicializa_mineral(&minerais_terminal[i],aux);
                    insereMineralLista(&lista_minerais_terminal,minerais_terminal[i]);


                    i++;
                }
                operacao_R(&Lista_de_sondas_terminal,lat_rocha_terminal,long_rocha_terminal,peso_rocha_terminal,&lista_minerais_terminal);
                break;

            case 'I':

                operacao_I(&Lista_de_sondas_terminal);
                
                break;

            case 'E':
                break;

            default:
                break;
            }
        }
        
    }
    return 0;
}

void operacao_R(Lista_sonda_espacial * lista_sondas, float lat_rocha, float long_rocha, float peso_rocha, char * lista_minerais){
    RochaMineral rocha_file;
    inicializaRochaMineral(&rocha_file, lista_minerais);
    int cont = lista_sondas->QntItens;
    float menor_d;
    float distancia;
    char id_sonda_mais_perto[20];
    Celula* sonda_mais_perto;
    Celula* aux = lista_sondas->pPrimeiro->pProx;
    for (int i=0;i<cont;i++){
        distancia = calcula_distancia(aux->item_sonda.Localizacao_sonda.Longitude,aux->item_sonda.Localizacao_sonda.Latitude, long_rocha, lat_rocha);
        if (distancia < menor_d){
            menor_d = distancia;
            sonda_mais_perto = aux;
            strcpy(id_sonda_mais_perto,aux->item_sonda.Identificador);
        }
        aux = aux->pProx;
    }
    move_Sonda_Espacial(&sonda_mais_perto->item_sonda,lat_rocha,long_rocha);
    inserir_rocha(&sonda_mais_perto->item_sonda.Compartimento, &rocha_file);



    
}

float calcula_distancia(float x1, float y1, float x2, float y2){
    return (sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)));
}


void operacao_I(Lista_sonda_espacial * lista_sondas){
    int cont_sondas  = lista_sondas->QntItens;
    Celula* aux = lista_sondas->pPrimeiro->pProx;
    Ccelula* aux_comp = lista_sondas->pPrimeiro->pProx->item_sonda.Compartimento.primeiro->prox;
    for (int i=0;i<cont_sondas;i++){
        int cont_rochas = aux->item_sonda.Compartimento.tamanho;
        printf("%s\n", aux->item_sonda.Identificador);
        for (int j=0; j<cont_rochas;j++){
            printf("%s %.1f",aux_comp->rocha,aux_comp->rocha.peso);
            aux_comp = aux_comp->prox;
        }
        aux = aux->pProx;
    }
}