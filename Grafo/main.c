//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define maximo 10

//Variáveis
int tamanho = 0;
int grafo[maximo];
int ma[maximo][maximo];
int op=1;

//Prototipação
int grafo_tamanho();
void grafo_desenhar();
void grafo_desenhar_matriz();
void grafo_inserir();
void grafo_remover();
void menu_mostrar();

//Função principal
int main()
{
    while(tamanho<=0 || tamanho>maximo){
        tamanho = grafo_tamanho();

        if(tamanho<=0 || tamanho>maximo){
            system("cls");
            printf("Escolha um valor entre 1 e %i\n", maximo);
        }else{
            int i;
            for(i=0; i<tamanho; i++){
                grafo[i]=i;
            }
        }
    }

    while(op!=0){
        system("cls");
        grafo_desenhar();
        grafo_desenhar_ma();

        menu_mostrar();
        scanf("%i", &op);
        switch(op){
            case 1:
                grafo_inserir();
            break;

            case 2:
                grafo_remover();
            break;
        }
    }

    system("pause");
    return 0;
}

//Define o número de vértices do grafo
int grafo_tamanho(){
    int tamanho;
    printf("Escolha a quantidade de vertices do grafo: ");
    scanf("%i", &tamanho);
    return tamanho;
}

//Inserir aresta
void grafo_inserir(){
    int num1, num2;
    system("cls");

    printf("Escolha o vertice de origem entre 0 a %i: ", tamanho-1);
    scanf("%i", &num1);
    printf("Escolha o vertice de destino entre 0 a %i: ", tamanho-1);
    scanf("%i", &num2);

    if(num1>tamanho-1 || num2>tamanho-1 || num1<0 || num2<0){
        printf("\nOs valores precisam estar entre 0 e %i\n", tamanho);
        system("pause");
    }else{
        ma[num1][num2] = 1;
        ma[num2][num1] = 1;
    }
}

//Remover aresta
void grafo_remover(){
    int num1, num2;
    system("cls");

    printf("Escolha o vertice de origem entre 0 a %i: ", tamanho-1);
    scanf("%i", &num1);
    printf("Escolha o vertice de destino entre 0 a %i: ", tamanho-1);
    scanf("%i", &num2);

    if(num1>tamanho-1 || num2>tamanho-1 || num1<0 || num2<0){
        printf("\nOs valores precisam estar entre 0 e %i\n", tamanho);
        system("pause");
    }else{
        ma[num1][num2] = 0;
        ma[num2][num1] = 0;
    }
}

//Função para desenhar o vetor de vértices
void grafo_desenhar(){
    //Desenhando lista de vértices
    printf("Listas de vertices\n[");
    int i;
    for(i=0; i<tamanho; i++){
        printf("%i", grafo[i]);
    }
    printf("]\n\n");
}

//Função para desenhar a matriz de arestas
void grafo_desenhar_ma(){
    //Desenhando a matriz de adjacências
    printf("Matriz de adjacencia\n[\n");
    int i, j;
    for(i=0; i<tamanho; i++){
        for(j=0; j<tamanho; j++){
            printf("%i", ma[i][j]);
        }
        printf("\n");
    }
    printf("]\n\n");
}

//Mostrar o menu de opções
void menu_mostrar(){
    printf("Escolha uma opcao:\n");
    printf("1 - Inserir ARESTA\n");
    printf("2 - Remover ARESTA\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}
