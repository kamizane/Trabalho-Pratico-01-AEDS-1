#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "Sonda_espacial.h"
#include "Lista_sonda_espacial.h"
#include "Mineral.h"
#include "RochaMineral.h"
#include "Compartimento.h"
#include "ListaMinerais.h"


void operacao_R(Lista_sonda_espacial * lista_sondas, float lat_rocha, float long_rocha, float peso_rocha, ListaMinerais* lista_minerais);//falta ver se ja tenho o tipo categoria naquela sonda e se ela tem espaço.
float calcula_distancia(float x1, float y1, float x2, float y2);
void operacao_I(Lista_sonda_espacial * lista_sondas);
int operacao_E(Lista_sonda_espacial * lista_sondas);

int main(int argc,char **argv){
    printf("comeecou");
    if(strcmp(argv[1],"-f")==0){
        printf("teste");
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

        if(numero_sondas == 0){
            printf("Nenhuma sonda foi enviada pela AEDS\n");
            return 0;
        }

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
        ListaMinerais lista_minerais_file;
        fListaMineraisVazia(&lista_minerais_file);
        for(int i=0;i<N_instrucao;i++){
            char instrucao;
            fscanf(file,"%c",&instrucao);
            char linha[255];
            switch (instrucao)
            {
            case 'R':
                
                fgets(linha,255,file);
                char * buffer = NULL;
                const char delim[2] = " ";
                buffer = strtok(linha,delim);
                float lat_rocha = atof (buffer);
                buffer = strtok(NULL,delim);
                float long_rocha = atof(buffer);
                buffer = strtok(NULL,delim);
                float peso_rocha = atof (buffer);
                Mineral minerais[2];
                char nome_mineral[15];
                int i = 0;
                while(buffer != NULL){
                    buffer = strtok(NULL,delim);
                    strcpy(nome_mineral,buffer);
                    atribui_mineral(&minerais[i],nome_mineral);
                    TItem a; 
                    a.Chave = minerais[i];
                    insereMineralLista(&lista_minerais_file, a);
                    //strcpy(minerais[i].nome,buffer);//corrigir
                    i++;
                }
                operacao_R(&lista_de_sondas_file,lat_rocha, long_rocha, peso_rocha, &lista_minerais_file);

                break;
            case 'I':
                operacao_I(&lista_de_sondas_file);
                break;
            case 'E':

                break;
            default:
                break;
            }
        }

    
    }
    else{
        printf("Iniciando AEDS");
        int numero_de_sondas; //separa o numero de sondas 
        Lista_sonda_espacial Lista_de_sondas_terminal; //cria lista de sondas
        
        inicializa_lista_sonda_espacial(&Lista_de_sondas_terminal);//inicializa lista de sondas
        printf("Digite o número de sondas enviada pela AEDS: ");
        scanf("%d", &numero_de_sondas); //recebe o numero de sondas de entrada
        if(numero_de_sondas == 0){
            printf("Nenhuma sonda foi enviada pela AEDS\n");
            return 0;
        }
        
        for(int i = 0; i<numero_de_sondas; i++){; //recebe todas as variaveis de acordo com o numero de sondas

            char id =(char)i;
            Sonda_espacial sonda;
            float lat_i,long_i,capacidade_i,velocidade_i,combustivel_i;
            printf("Digite a latitude, longitude, capacidade, velocidade e combustível da sonda (ex: -2 10 50 12 100): ");
            scanf("%f %f %f %f %f", &lat_i,&long_i,&capacidade_i,&velocidade_i,&combustivel_i);
            inicializa_Sonda_Espacial(&sonda,&id,lat_i,long_i,capacidade_i,velocidade_i,combustivel_i);//inicializa as sondas com as variaveis recebidas
            insere_item_lista_sonda_espacial(&Lista_de_sondas_terminal,&sonda);//adiciona a sonda na lista de sondas
        }
        
        int N_instrucao_terminal; //cria variavel N_instrucao (numero de operaçoes que vao ser feitas)
        printf("Digite o número de operações que as sondas realizarão: ");
        scanf("%d", &N_instrucao_terminal); //recebe a N_instrucao (numero de operaçoes que vao ser feitas)
        for(int i = 0; i<N_instrucao_terminal; i++){ //para cada N_instrucao lê a instrucao e realiza ela, chamando a função pronta
            char instrucao_terminal;
            printf("Insira qual é a opperaçao %d: ", i+1);
            scanf("%c", &instrucao_terminal);
            
            switch (instrucao_terminal)
            {
            case 'R': //coleta de uma nova rocha
                {char linha_terminal[255];
                printf("Digite a latitude, longitude, peso, categoria e os minerais da rocha (ex: -4.6 137.5 20 Ferrolita Aquavitae): ");
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
                    atribui_mineral(&minerais_terminal[i],aux);
                    TItem x;
                    x.Chave = minerais_terminal[i];
                    insereMineralLista(&lista_minerais_terminal, x);


                    i++;
                }
                operacao_R(&Lista_de_sondas_terminal,lat_rocha_terminal,long_rocha_terminal,peso_rocha_terminal,&lista_minerais_terminal);
                break;}

            case 'I':

                operacao_I(&Lista_de_sondas_terminal);
                
                break;

            case 'E':
                operacao_E(&Lista_de_sondas_terminal);
                break;

            default:
                printf("operacao invalida");
                break;
            }
        }
        
    }
    return 0;
}

void operacao_R(Lista_sonda_espacial * lista_sondas, float lat_rocha, float long_rocha, float peso_rocha, ListaMinerais* lista_minerais){
    LocalRochaMineral local;
    local.latitude = lat_rocha;
    local.longitude = long_rocha;
    RochaMineral rocha_file;

    static int contId = 1;

    inicializaRochaMineral(&rocha_file, contId, peso_rocha , lista_minerais,local,"00:00:00");
    int cont = lista_sondas->QntItens;
    float menor_d;
    float distancia;
    char id_sonda_mais_perto[20];
    Celula* sonda_mais_perto;
    Celula* aux = lista_sondas->pPrimeiro->pProx;
    for (int i=0;i<cont;i++){
        distancia = calcula_distancia(aux->item_sonda.Localizacao_sonda.Longitude,aux->item_sonda.Localizacao_sonda.Latitude, long_rocha, lat_rocha);
        //é ruim passar a latitude assim? deveria chamar uma função get?
        if (distancia < menor_d){
            if(trocar_rocha(&aux->item_sonda.Compartimento,&rocha_file)){
                menor_d = distancia;
                sonda_mais_perto = aux;
            }
            else if ((aux->item_sonda.Compartimento.peso_atual + rocha_file.peso) <= aux->item_sonda.Compartimento.peso_maximo ){
                menor_d = distancia;
                sonda_mais_perto = aux;
            }
            strcpy(id_sonda_mais_perto,aux->item_sonda.Identificador);
        }
        aux = aux->pProx;
    }
    move_Sonda_Espacial(&sonda_mais_perto->item_sonda,lat_rocha,long_rocha);
    inserir_rocha(&sonda_mais_perto->item_sonda.Compartimento, &rocha_file);

    contId++;
}

float calcula_distancia(float x1, float y1, float x2, float y2){
    return (sqrt(pow((x1 - x2),2) + pow((y1 - y2),2)));
}


void operacao_I(Lista_sonda_espacial * lista_sondas){
    int cont_sondas  = lista_sondas->QntItens;
    Celula* aux = lista_sondas->pPrimeiro->pProx;
    for (int i=0;i<cont_sondas;i++){
        int cont_rochas = aux->item_sonda.Compartimento.tamanho;
        printf("%s\n", aux->item_sonda.Identificador);
            imprime_compartimento(&aux->item_sonda.Compartimento);
            //printf("%s %.1f",aux_comp->rocha,aux_comp->rocha.peso);
            //aux_comp = aux_comp->prox;
        aux = aux->pProx;   
    }
}

int operacao_E(Lista_sonda_espacial * lista_sondas){
    if (verifica_lista_vazia(lista_sondas)){
        return 0;
    }
    int cont_sondas = lista_sondas->QntItens;
    Celula*aux = lista_sondas->pPrimeiro->pProx;
    for (int i=0; i<cont_sondas; i++){
        move_Sonda_Espacial(&aux->item_sonda, 0 , 0);
        aux = aux->pProx;
    }
    return 1;
}