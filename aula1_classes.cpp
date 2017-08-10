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
class lista_valor {
private:
    valor *x;
    unsigned N;
public:
    //Construtores
    lista_valor(void);
    lista_valor(unsigned Tamanho);
    ~lista_valor(void); //destrutor

    void insira_lista(valor V);
    valor primeiro_lista(void) const;
    void imprimir_lista(void) const;
    void remover_primeiro_lista(void);
    inline unsigned tamanho(void) {return N;}
};

//Ao criar um objeto, o construtor deixará o ponteiro como nulo e sua dimensão zero.
lista_valor::lista_valor(void)
{
    N = 0;
    x = NULL;
}

lista_valor::lista_valor(unsigned Tamanho)
{
    if(Tamanho==0)
    {
        cerr << "Tamanho nulo???";
    }
    N = Tamanho;
    if(N>0) x = new valor[N];
    else x = NULL;
    for(int i=0; i<N; i++) x[i] = 0;
}

lista_valor::~lista_valor(void)
{
    delete[] x;
}

void lista_valor::insira_lista(valor V)
{
    valor *prox;
    prox = new valor[N+1];

    for(int i=0; i<N;i++) prox[i] = x[i];
    prox[N] = V; //Já adiciona na ultima posicao do array
    if(x!=NULL) delete[] x;
    x = prox;
    N++;
}

valor lista_valor::primeiro_lista(void) const
{
     return x[0];
}

void lista_valor::imprimir_lista(void) const
{
    for(int i=0; i<N; i++) cout << *(x+i) << endl;
}

void lista_valor::remover_primeiro_lista(void)
{
    valor *prox;
    prox = new valor[N-1];

    for(int i=0; i<N;i++) prox[i] = x[i+1];
    if(x!=NULL) delete[] x;
    x = prox;
    N--;
}

int main(void)
{
    valor V;
    lista_valor L; //objeto da classe lista_valor
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
            L.insira_lista(V);
            break;
        case 2:
            V = L.primeiro_lista();
            cout << "Primeiro da lista = " << V << endl;
            break;
        case 3:
            L.remover_primeiro_lista();
            break;
        case 4:
            cout << "Numero de valores da lista = " << L.tamanho() << endl;
            break;
        case 5:
            L.imprimir_lista();
            break;
        default:
            break;
        }
    } while (opcao!=0);
}

