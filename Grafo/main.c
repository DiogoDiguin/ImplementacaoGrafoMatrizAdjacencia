//Bibliotecas
#include <stdio.h>
#include <stdlib.h>

//Constantes
#define maximo 10

//Vari�veis
int tamanho = 0;
int grafo[maximo];
int ma[maximo][maximo];
int op=1;

//Prototipa��o
int grafo_tamanho();
void grafo_desenhar();
void grafo_desenhar_matriz();
void grafo_inserir();
void grafo_remover();
void menu_mostrar();

//Fun��o principal
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

//Define o n�mero de v�rtices do grafo
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

//Fun��o para desenhar o vetor de v�rtices
void grafo_desenhar(){
    //Desenhando lista de v�rtices
    printf("Listas de vertices\n[");
    int i;
    for(i=0; i<tamanho; i++){
        printf("%i", grafo[i]);
    }
    printf("]\n\n");
}

//Fun��o para desenhar a matriz de arestas
void grafo_desenhar_ma(){
    //Desenhando a matriz de adjac�ncias
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

//Mostrar o menu de op��es
void menu_mostrar(){
    printf("Escolha uma opcao:\n");
    printf("1 - Inserir ARESTA\n");
    printf("2 - Remover ARESTA\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}
