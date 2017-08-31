#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <fstream>
#include "loja_heranca.h"
using namespace std;

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE PRODUTO
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
    O << '"' << nome << '"' << ';' <<  '$' << float(preco)/100.0;
    return O;
}

istream &Produto::ler(istream &I)
{
     I.ignore(numeric_limits<streamsize>::max(),'"');
    //para poder ler as strings
    double prov;
    getline(I,nome,'"');
    I.ignore(numeric_limits<streamsize>::max(),'$');
    if(nome == ""){
        preco =0;
    }else{
        I >> prov;
    }
    return I;
}

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE LIVRO
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
    cout << endl << "Nome do autor: " << endl;
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

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE CD
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
    cout << endl << "Numero de faixas: " << endl;
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


/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE DVD
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
    cout << endl << "Duracao: " << endl;
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

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE LISTALIVRO
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
    ListaLivro prov(N+1); //Contrutor espec�fico � encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = L;
    copiar(prov);
}

void ListaLivro::excluir(unsigned id)
{
    if(id > N) {cerr << "indice invalido!\n"; return;}
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
}

void ListaLivro::imprimir() const
{
    cout << "============ LISTA DE LIVROS ================" << endl;
    for(unsigned i=0; i<N; i++) cout << x[i] << endl;
    cout << "=============================================" << endl;
}

void ListaLivro::salvar(ostream &O) const
{
    O << "LISTALIVRO " << N << endl;
    for(unsigned i=0; i<N; i++) O << "L: " << x[i];
    O << endl;
}
/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE LISTACD
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
    ListaCD prov(N+1); //Contrutor espec�fico � encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = C;
    copiar(prov);
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
}

void ListaCD::imprimir() const
{
    cout << "============ LISTA DE CDs ================" << endl;
    for(unsigned i=0; i<N; i++) cout << x[i] << endl;
    cout << "=============================================" << endl;
}

void ListaCD::salvar(ostream &O) const
{
    O << "LISTACD " << N << endl;
    for(unsigned i=0; i<N; i++) O << "C: " << x[i];
    O << endl;
}

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE LISTADVD
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
    ListaDVD prov(N+1); //Contrutor espec�fico � encarregado dessa parte
    for(unsigned i=0; i<N;i++) prov.x[i] = x[i];
    prov.x[prov.N-1] = D;
    copiar(prov);
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
}

void ListaDVD::imprimir() const
{
    cout << "============== LISTA DE DVDs ================" << endl;
    for(unsigned i=0; i<N; i++) cout << x[i] << endl;
    cout << "=============================================" << endl;
}

void ListaDVD::salvar(ostream &O) const
{
    O << "LISTADVD " << N << endl;
    for(unsigned i=0; i<N; i++) O << "D: " << x[i];
    O << endl;
}

/*
    ===============================================
    M�TODOS E FUN��ES DA CLASSE LOJA
    ===============================================
*/

void Loja::imprimir() const
{
    LL.imprimir();
    LC.imprimir();
    LD.imprimir();
}

//void Loja::ler(const char *arq)
//{
//    string T;
//    ifstream meu_arq(arq);
//    getline(meu_arq,T,' ');
//    if(meu_arq.good()){ //fun��o good retorna true se nao houver erros no arquivo
//        if(T == "LISTALIVRO"){
//            LL.ler(meu_arq);
//            //T.clear();
//            getline(meu_arq,T,' ');
//        }
//        if(T == "LISTACD"){
//            LC.ler(meu_arq);
//            //T.clear();
//            getline(meu_arq,T,' ');
//        }
//        if(T == "LISTADVD"){
//            LD.ler(meu_arq);
//            //T.clear();
//            getline(meu_arq,T,' ');
//        }
//    }else cerr << "O arquivo passado nao existe. Verifique se o nome esta correto." << endl;
//    meu_arq.close();
//}
//
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
