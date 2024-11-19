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

    if(argc > 1 && strcmp( argv[1],"-f")==0){
        FILE *file = NULL;
        file = fopen(argv[2],"r");
        if (file == NULL){
            printf("Arquivo de entrada não existe");
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
            char id[20];
            sprintf(id, "%d", i+1);
            Sonda_espacial sonda;
            float lat_i,long_i,capacidade_i,velocidade_i,combustivel_i;
            fscanf(file, "%f %f %f %f %f", &lat_i,&long_i,&capacidade_i,&velocidade_i,&combustivel_i);
            inicializa_Sonda_Espacial(&sonda, id, lat_i,long_i,capacidade_i,velocidade_i,combustivel_i);
            insere_item_lista_sonda_espacial(&lista_de_sondas_file,&sonda);
            
        }
        int N_instrucao;
        fscanf(file,"%d\n",&N_instrucao);

        for(int i=0;i<N_instrucao;i++){
            char instrucao;
            fscanf(file,"%c",&instrucao);
            char linha[255];
            
            switch (instrucao)
            {
            case 'R':
                fgets(linha,255,file);

                fscanf(file,"%[^\n]", &linha);
                char * buffer = NULL;
                const char delim[3] = " ";
                buffer = strtok(linha,delim);
                float lat_rocha = atof (buffer);

                buffer = strtok(NULL,delim);
                float long_rocha = atof(buffer);

                buffer = strtok(NULL,delim);
                float peso_rocha = atof (buffer);


                Mineral minerais[2];
                char nome_mineral[15];
                ListaMinerais lista_minerais_file;
                fListaMineraisVazia(&lista_minerais_file);

                int m = 0;
                while((buffer = strtok(NULL, delim)) != NULL && m < 2){

                    strcpy(nome_mineral,buffer);
                    atribui_mineral(&minerais[m],nome_mineral);

                    TItem a = {minerais[m]}; 
                    insereMineralLista(&lista_minerais_file, a);

                    //strcpy(minerais[i].nome,buffer);//corrigir
                    m++;
                }
                printf("\n");
                operacao_R(&lista_de_sondas_file,lat_rocha, long_rocha, peso_rocha, &lista_minerais_file);

                fgets(linha,255,file);
                break;
            case 'I':
                operacao_I(&lista_de_sondas_file);
                fgets(linha,255,file);
                break;
            case 'E':

                break;
            default:
                break;
            }
        }

    
    }
    else{
        printf("Iniciando missao espacial\n");
        int numero_de_sondas; //separa o numero de sondas 
        Lista_sonda_espacial Lista_de_sondas_terminal; //cria lista de sondas
        
        inicializa_lista_sonda_espacial(&Lista_de_sondas_terminal);//inicializa lista de sondas
        printf("Digite o numero de sondas enviada pela AEDS: ");
        scanf("%d", &numero_de_sondas); //recebe o numero de sondas de entrada
        if(numero_de_sondas == 0){
            printf("Nenhuma sonda foi enviada pela AEDS\n");
            return 0;
        }
        
        for(int i = 0; i<numero_de_sondas; i++){; //recebe todas as variaveis de acordo com o numero de sondas
            char id[20];
            sprintf(id, "%d", i+1);
            Sonda_espacial sonda;
            float lat_i,long_i,capacidade_i,velocidade_i,combustivel_i;
            printf("Digite a latitude, longitude, capacidade, velocidade e combustivel da sonda %c (ex: -2 10 50 12 100): ", id);
            scanf("%f %f %f %f %f", &lat_i,&long_i,&capacidade_i,&velocidade_i,&combustivel_i);
            inicializa_Sonda_Espacial(&sonda,id,lat_i,long_i,capacidade_i,velocidade_i,combustivel_i);//inicializa as sondas com as variaveis recebidas
            insere_item_lista_sonda_espacial(&Lista_de_sondas_terminal,&sonda);//adiciona a sonda na lista de sondas
        }
        
        int N_instrucao_terminal; //cria variavel N_instrucao (numero de operaçoes que vao ser feitas)
        printf("Digite o numero de operacoes que as sondas realizarao: ");
        scanf("%d", &N_instrucao_terminal); //recebe a N_instrucao (numero de operaçoes que vao ser feitas)
        for(int i = 0; i<N_instrucao_terminal; i++){ //para cada N_instrucao lê a instrucao e realiza ela, chamando a função pronta
            char instrucao_terminal;
            printf("Insira a operacao %d: ", i+1);
            getc(stdin);
            scanf("%c", &instrucao_terminal);
            
            switch (instrucao_terminal)
            {
            case 'R': //coleta de uma nova rocha
                {char linha_terminal[255];
                printf("Digite a latitude, longitude, peso, categoria e os minerais da rocha (ex: -4.6 137.5 20 Ferrolita Aquavitae): \n");
                getchar();
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
                Mineral minerais_terminal[2];
                ListaMinerais lista_minerais_terminal;
                fListaMineraisVazia(&lista_minerais_terminal);
                int m = 0;
                while((buffer = strtok(NULL, delim)) != NULL && m < 2){
                    strcpy(aux,buffer);
                    atribui_mineral(&minerais_terminal[m],aux);
                    TItem x = {minerais_terminal[m]};
                    /*strcpy(x.Chave.nome, minerais_terminal[m].nome);
                    strcpy(x.Chave.cor, minerais_terminal[m].cor);
                    x.Chave.dureza = minerais_terminal[m].dureza;
                    x.Chave.reatividade = minerais_terminal[m].reatividade;*/
                    insereMineralLista(&lista_minerais_terminal, x);
                    

                    m++;
                }
                //imprimeListaMinerais(&lista_minerais_terminal);
                printf("\n");
                operacao_R(&Lista_de_sondas_terminal,lat_rocha_terminal,long_rocha_terminal,peso_rocha_terminal,&lista_minerais_terminal);
                break;}

            case 'I':

                operacao_I(&Lista_de_sondas_terminal);
                break;

            case 'E':
                operacao_E(&Lista_de_sondas_terminal);
                break;

            default:
                printf("operacao invalida\n");
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
    Celula* sonda_mais_perto;
    Celula* aux = lista_sondas->pPrimeiro->pProx;

    for (int i=0;i<cont;i++){
        distancia = calcula_distancia(aux->item_sonda.Localizacao_sonda.Longitude,aux->item_sonda.Localizacao_sonda.Latitude, long_rocha, lat_rocha);
        //é ruim passar a latitude assim? deveria chamar uma função get?
        if (distancia < menor_d){

            if(trocar_rocha(&aux->item_sonda.Compartimento,&rocha_file) == 1){
                menor_d = distancia;
                if(aux != NULL){
                sonda_mais_perto = aux;
                }
                move_Sonda_Espacial(&sonda_mais_perto->item_sonda,lat_rocha,long_rocha);
                return;
            // }else if(trocar_rocha(&aux->item_sonda.Compartimento,&rocha_file) == 2){
            //     menor_d = distancia;
            //     if(aux != NULL){
            //     sonda_mais_perto = aux;
            //     }
            //     move_Sonda_Espacial(&sonda_mais_perto->item_sonda,lat_rocha,long_rocha);
            }else if ((aux->item_sonda.Compartimento.peso_atual + rocha_file.peso) <= aux->item_sonda.Compartimento.peso_maximo ){

                menor_d = distancia;
                if(aux != NULL){
                sonda_mais_perto = aux;
                }

            }
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
    float media = 0;
    Celula*aux = lista_sondas->pPrimeiro->pProx;
    for (int i=0; i<cont_sondas; i++){
        move_Sonda_Espacial(&aux->item_sonda, 0 , 0);
        media += aux->item_sonda.Compartimento.peso_atual;
        aux = aux->pProx;
    }
    Compartimento lista_temp;
    faz_compartimento_vazio(&lista_temp,media);
    media = media / cont_sondas;
    for (int i=0; i<cont_sondas; i++){
        if (aux->item_sonda.Compartimento.peso_atual > media){
            
        }
        aux = aux->pProx;
    }




    return 1;
}