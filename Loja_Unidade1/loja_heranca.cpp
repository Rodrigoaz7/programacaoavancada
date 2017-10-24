#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <fstream>
#include <stdlib.h>
#include "loja_heranca.h"
using namespace std;

void mensagem(string mens){cout << mens << endl; system("Pause"); system("cls");}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE PRODUTO
    ===============================================
*/

void Produto::criar(string n, unsigned p)
{
    if(p<=0 || n=="")
    {
        cerr << "Preco e/ou nomes invalidos! \n";
        return;
    }
    else
    {
        nome = n;
        preco = p*100; //transformando centavos em reais
    }
}

void Produto::copiar(const Produto &P)
{
    if(nome != P.nome) //Se nao forem dois produtos iguais
    {
        nome = P.nome;
        preco = P.preco;
    }
}

void Produto::limpar(void)
{
    if(nome != "" || preco!=0) nome.clear(); preco=0;
}

istream &Produto::digitar(istream &I)
{
    cout << "Digite o nome do produto: " << endl;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(I,nome);
    if(nome=="") cerr << "nome invalido!!!\n";
    cout << "Digite seu preco: " << endl;
    I >> preco;
    return I;
}

ostream &Produto::imprimir(ostream &O) const
{
    double prov;
    prov = preco/100.0;
    O << '"' << nome << '"' << ';' <<  '$' << prov;
    return O;
}

istream &Produto::ler(istream &I)
{
    I.ignore(numeric_limits<streamsize>::max(),'"'); //ignorar tudo até encontrar aspas
    //para poder ler as strings
    getline(I,nome,'"');
    I.ignore(numeric_limits<streamsize>::max(),'$'); //ignorar tudo até encontrar $
    I >> preco;
    return I;
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE LIVRO
    ===============================================
*/

Livro::~Livro(void)
{
    if(autor != "")
    {
        nome.clear();
        autor.clear();
        preco = 0;
    }
}

istream &Livro::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Nome do autor: " << endl;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    getline(I,autor);
    if(autor == "") cerr << "Livro sem autor ";
    return I;
}

ostream &Livro::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << ';' << '"' << autor << '"';
    return O;
}

istream &Livro::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),'"');
    getline(I,autor,'"');
    return I;
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE CD
    ===============================================
*/

CD::~CD(void)
{
    if(faixas > 0)
    {
        nome.clear();
        faixas = 0;
        preco = 0;
    }
}

istream &CD::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Numero de faixas: " << endl;
    I >> faixas;
    if(faixas <= 0) cerr << "CD sem faixas ";
    return I;
}

ostream &CD::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << ';' << faixas;
    return O;
}

istream &CD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> faixas;
    return I;
}


/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE DVD
    ===============================================
*/

DVD::~DVD(void)
{
    if(duracao > 0)
    {
        nome.clear();
        duracao = 0;
        preco = 0;
    }
}

istream &DVD::digitar(istream &I)
{
    Produto::digitar(I);
    cout << "Duracao: " << endl;
    I >> duracao;
    if(duracao <= 0) cerr << "DVD virgem !!! \n";
    return I;
}

ostream &DVD::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << ';' << duracao;
    return O;
}

istream &DVD::ler(istream &I)
{
    Produto::ler(I);
    I.ignore(numeric_limits<streamsize>::max(),';');
    I >> duracao;
    return I;
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE LISTALIVRO
    ===============================================
*/

void ListaLivro::criar(unsigned tam)
{
    if(tam>=0) {N = tam; x = new Livro[N];}
    else {cerr << "Tamanho invalido ! \n"; limpar(); return;}
}

void ListaLivro::copiar(const ListaLivro &L)
{
    if(N != L.N) limpar(); criar(L.N);
    for(unsigned i=0; i<N;i++) x[i] = L.x[i];
}

void ListaLivro::incluir(const Livro &L)
{
    ListaLivro prov(N+1); //Contrutor específico é encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = L;
    copiar(prov);
    mensagem("Livro adicionado com sucesso !");
}

void ListaLivro::excluir(unsigned id)
{
    if(id >= N) {cerr << "indice invalido!\n"; return;}
    else {
        ListaLivro prov(N-1);
        unsigned j=0;
        for(unsigned i=0; i<N;i++)
        {
            if(i != id)
            {
                prov.x[j] = x[i];
                j++;
            }
        }
        copiar(prov);
    }
    mensagem("Livro deletado com sucesso !");
}

void ListaLivro::imprimir() const
{
    cout << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++) cout << i << ") " << "L: " << x[i] << endl;
    cout << endl;
}

void ListaLivro::salvar(ostream &O) const
{
    O << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++) O << i << ") " << "L: " << x[i] << endl;
    O << endl;
}

void ListaLivro::ler(istream &I)
{
    unsigned tam;
    char prov2;
    int j;
    Livro prov;
    I.ignore(numeric_limits<streamsize>::max(),' ');
    I >> tam;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    for(unsigned i=0; i<tam; i++)
    {
        I >> j;
        if(j < 0){cerr << "Indice invalido\n"; return;}
        else
        {
            I.ignore(numeric_limits<streamsize>::max(),' ');
            I >> prov2;
            if(prov2 != 'L') {cerr << "Letra do produto invalida! \n"; return;}
            else
            {
                I.ignore(numeric_limits<streamsize>::max(),' ');
                prov.ler(I);
                incluir(prov);
                I.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }
    cout << "Arquivo(s) lido(s) com sucesso ! \n ";
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE LISTACD
    ===============================================
*/

void ListaCD::criar(unsigned tam)
{
    if(tam>=0) {N = tam; x = new CD[N];}
    else {cerr << "Tamanho invalido ! \n"; limpar(); return;}
}

void ListaCD::copiar(const ListaCD &L)
{
    if(N != L.N) limpar(); criar(L.N);
    for(unsigned i=0; i<N;i++) x[i] = L.x[i];
}

void ListaCD::incluir(const CD &C)
{
    ListaCD prov(N+1); //Contrutor específico é encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = C;
    copiar(prov);
    mensagem("CD adicionado com sucesso !");
}

void ListaCD::excluir(unsigned id)
{
    if(id >= N) {cerr << "indice invalido!\n"; return;}
    else {
        ListaCD prov(N-1);
        unsigned j=0;
        for(unsigned i=0; i<N;i++)
        {
            if(i != id) prov.x[j] = x[i]; j++;
        }
        copiar(prov);
    }
    mensagem("CD deletado com sucesso !");
}

void ListaCD::imprimir() const
{
    cout << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++) cout << i << ") " << "C: " << x[i] << endl;
    cout << endl;
}

void ListaCD::salvar(ostream &O) const
{
    O << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++) O << i << ") " << "C: " << x[i] << endl;
    O << endl;
}

void ListaCD::ler(istream &I)
{
    unsigned tam;
    char prov2;
    int j;
    CD prov;
    I.ignore(numeric_limits<streamsize>::max(),' ');
    I >> tam;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    for(unsigned i=0; i<tam; i++)
    {
        I >> j;
        if(j < 0){cerr << "Indice invalido\n"; return;}
        else
        {
            I.ignore(numeric_limits<streamsize>::max(),' ');
            I >> prov2;
            if(prov2 != 'C') {cerr << "Letra do produto invalida! \n"; return;}
            else
            {
                I.ignore(numeric_limits<streamsize>::max(),' ');
                prov.ler(I);
                incluir(prov);
                I.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }
    cout << "Arquivo(s) lido(s) com sucesso ! \n ";
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE LISTADVD
    ===============================================
*/

void ListaDVD::criar(unsigned tam)
{
    if(tam>=0) {N = tam; x = new DVD[N];}
    else {cerr << "Tamanho invalido ! \n"; limpar(); return;}
}

void ListaDVD::copiar(const ListaDVD &L)
{
    if(N != L.N) limpar(); criar(L.N);
    for(unsigned i=0; i<N;i++) x[i] = L.x[i];
}

void ListaDVD::incluir(const DVD &D)
{
    ListaDVD prov(N+1); //Contrutor específico é encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = D;
    copiar(prov);
    mensagem("DVD adicionado com sucesso !");
}

void ListaDVD::excluir(unsigned id)
{
    if(id >= N) {cerr << "indice invalido!\n"; return;}
    else {
        ListaDVD prov(N-1);
        unsigned j=0;
        for(unsigned i=0; i<N;i++)
        {
            if(i != id) prov.x[j] = x[i]; j++;
        }
        copiar(prov);
    }
    mensagem("DVD deletado com sucesso !");
}

void ListaDVD::imprimir() const
{
    cout << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++) cout  << i << ") " << "D: " << x[i] << endl;
    cout << endl;
}

void ListaDVD::salvar(ostream &O) const
{
    O << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++) O << i << ") " << "D: " << x[i] << endl;
    O << endl;
}

void ListaDVD::ler(istream &I)
{
    unsigned tam;
    char prov2;
    int j;
    DVD prov;
    I.ignore(numeric_limits<streamsize>::max(),' ');
    I >> tam;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    for(unsigned i=0; i<tam; i++)
    {
        I >> j;
        if(j < 0){cerr << "Indice invalido\n";return;}
        else
        {
            I.ignore(numeric_limits<streamsize>::max(),' ');
            I >> prov2;
            if(prov2 != 'D') {cerr << "Letra do produto invalida! \n";return;}
            else
            {
                I.ignore(numeric_limits<streamsize>::max(),' ');
                prov.ler(I);
                incluir(prov);
                I.ignore(numeric_limits<streamsize>::max(),'\n');
            }
        }
    }
    cout << "Arquivo(s) lido(s) com sucesso ! \n ";
}

/*
    ===============================================
    MÉTODOS E FUNÇÕES DA CLASSE LOJA
    ===============================================
*/

void Loja::imprimir() const
{
    LL.imprimir();
    LC.imprimir();
    LD.imprimir();
}

void Loja::ler(const char *arq)
{
    ifstream produto(arq);
    if(produto.is_open())
    {
        string prov;
        produto >> prov;
        cout << prov;
        if (prov != "LISTALIVRO" && prov != "LISTACD" && prov != "LISTADVD")
        {
            cerr << "Arquivo com cabecalho invalido\n";
        }
        else
        {
            LL.ler(produto);
            LC.ler(produto);
            LD.ler(produto);
        }
    }
    else
    {
        cerr << "Arquivo nao existe! \n";
    }
}

void Loja::salvar(const char* arq) const
{
    ofstream produto(arq);
    if(produto.is_open())
    {
        cout << "** Escrevendo no arquivo " << arq << "..." << endl;
        LL.salvar(produto);
        LC.salvar(produto);
        LD.salvar(produto);
    }
    else
    {
        cerr << "Houve um erro no arquivo! \n";
    }
    produto.close();
}
