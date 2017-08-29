#include "loja.h"
#include <string>
#include <cstring>
#include <iostream>
#include <limits>
#include <fstream>
using namespace std;

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

istream &digitar(istream &I)
{
    cout << "==============================================\n";
    cout << "Digite o nome do produto: " << endl;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(I,nome);
    if(nome="") cerr << "nome invalido!!!\n"; return;
    cout << endl << "Digite seu preco: " << endl;
    I >> preco;
    if(preco <= 0 ) cerr << "preco invalido! "; nome.clear(); return;
    return I;
}

ostream &imprimir(ostream &O) const
{
    O << "nome: " << nome << "\n" << "R$ " << preco << " reais \n\n";
    return O;
}

istream &ler(istream &I)
{

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
    cout << endl << "Nome do autor: " << endl;
    I.ignore(numeric_limits<streamsize>::max(),'\n');
    cin.getline(I,autor);
    if(autor == "") cerr << "Livro sem autor ";
    return I;
}

ostream &Livro::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << autor;
    return O;
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
    cout << endl << "Numero de faixas: " << endl;
    I >> faixas;
    if(faixas <= 0) cerr << "CD sem faixas ";
    return I;
}

ostream &CD::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << faixas;
    return O;
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
    cout << endl << "Duracao: " << endl;
    I >> duracao;
    if(duracao <= 0) cerr << "DVD virgem !!! \n";
    return I;
}

ostream &DVD::imprimir(ostream &O) const
{
    Produto::imprimir(O); //Chamando o imprimir dos atributos da classe Produto
    O << duracao;
    return O;
}

