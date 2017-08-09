#include <iostream>

/*
Neste programa, voce deve desenvolver um aplicativo que permita armazenar uma quantidade qualquer de valores
(int, float, char, como preferir). A quantidade nao eh conhecida a priori.
Desenvolva as funcoes necessarias para executar o programa principal a seguir.
*/

using namespace std;

// Defina o tipo valor
typedef float valor;
// Defina o tipo lista_valor
struct lista_valor {
    int N;
    valor *x;
} lista;

lista_valor novaLista(int dimensao);
void insira_lista(lista_valor &L, valor V);
valor primeiro_lista(const lista_valor &L); //Passar assim, deixa o código mais eficaz, pois nao copia
void remover_primeiro_lista(lista_valor &L);
void imprimir_lista(const lista_valor &L); //Passar assim, deixa o código mais eficaz, pois nao copia
void libera_lista(lista_valor &L);


int main(void)
{
    valor V;
    lista_valor L=novaLista(0);
    int opcao;

    cout << "PROGRAMA PARA IMPLEMENTAR UMA LISTA DE VALORES\n";
    do
    {
        do
        {
            cout << "1 - Inserir um valor no fim da lista\n";
            cout << "2 - Imprimir o primeiro valor da lista\n";
            cout << "3 - Remover o primeiro valor da lista\n";
            cout << "4 - Imprimir o numero de elementos da lista\n";
            cout << "5 - Imprimir todos os valores da lista\n";
            cout << "0 - Terminar o programa\n";
            cin >> opcao;
        } while (opcao<0 || opcao>5);
        switch (opcao)
        {
        case 1:
            cout << "Valor a ser inserido: ";
            cin >> V;
            insira_lista(L, V);
            break;
        case 2:
            V = primeiro_lista(L);
            cout << "Primeiro da lista = " << V << endl;
            break;
        case 3:
            remover_primeiro_lista(L);
            break;
        case 4:
            cout << "Numero de valores da lista = " << L.N << endl;
            break;
        case 5:
            imprimir_lista(L);
            break;
        default:
            break;
        }
    } while (opcao!=0);
    // Liberar a memoria alocada
    libera_lista(L);
}

lista_valor novaLista(int dimensao)
{
    lista.x = new valor[dimensao];
    lista.N = dimensao;
}

void insira_lista(lista_valor &L, valor V)
{
    valor *prox;
    prox = new valor[L.N+1];

    for(int i=0; i<L.N;i++)
    {
        prox[i] = L.x[i];
    }

    prox[L.N] = V; //Já adiciona na ultima posicao do array
    delete[] L.x;
    L.x = prox;
    L.N++;
}

void libera_lista(lista_valor &L)
{
    L.N = 0;
    L.x = NULL;
}

valor primeiro_lista(const lista_valor &L)
{
    return L.x[0];
}

void remover_primeiro_lista(lista_valor &L)
{
    valor *prox;
    prox = new valor[L.N-1];

    for(int i=0; i<L.N;i++)
    {
        prox[i] = L.x[i+1];
    }

    delete[] L.x;
    L.x = prox;
    L.N--;
}

void imprimir_lista(const lista_valor &L)
{
    for(int i=0; i<L.N; i++)
    {
        cout << *(L.x+i) << endl;
    }
}

