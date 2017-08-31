#ifndef LOJA_H_INCLUDED
#define LOJA_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Produto
{
private:
    //funcoes auxiliares para a construcao do codigo
    void criar(string n,unsigned p);
    void limpar(void);
    void copiar(const Produto &P);
protected:
    string nome;
    unsigned preco;
public:
    inline Produto(const char *N="", unsigned P=0): nome(N), preco(P) {}
    inline Produto(string n, unsigned p){criar(n,p);}
    inline Produto(const Produto &P){copiar(P);}
    inline ~Produto(void){limpar();}

    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const{imprimir(O); return O;}
};

inline istream &operator>>(istream &I, Produto &X)
{
    return X.digitar(I);
}
inline ostream &operator<<(ostream &O, Produto &X)
{
    return X.imprimir(O);
}

class Livro:public Produto
{
private:
    string autor;
public:
    inline Livro(void): Produto(), autor("") {}
    ~Livro(void);
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const{imprimir(O); return O;}

};

inline istream &operator>>(istream &I, Livro &X){return X.digitar(I);}
inline ostream &operator<<(ostream &O, Livro &X){return X.imprimir(O);}

class CD:public Produto
{
private:
    unsigned int faixas;
public:
    inline CD(void): Produto(), faixas(0) {}
    ~CD(void);
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const{imprimir(O); return O;}
};

inline istream &operator>>(istream &I, CD &X){return X.digitar(I);}
inline ostream &operator<<(ostream &O, CD &X){return X.imprimir(O);}

class DVD:public Produto
{
private:
    unsigned int duracao;
public:
    inline DVD(void): Produto(), duracao(0) {}
    ~DVD(void);
    istream &digitar(istream &I);
    ostream &imprimir(ostream &O) const;
    istream &ler(istream &I);
    inline ostream &salvar(ostream &O) const{imprimir(O); return O;}
};
    inline istream &operator>>(istream &I, DVD &X){return X.digitar(I);}
    inline ostream &operator<<(ostream &O, DVD &X){return X.imprimir(O);}

class ListaLivro
{
private:
    Livro *x;
    unsigned N;
    void criar(unsigned tam);
    void copiar(const ListaLivro &L);
    inline void limpar(void){if(N>0) delete[] x;x=NULL;N = 0;}
public:
    inline ListaLivro(void): x(NULL), N(0) {}
    inline ListaLivro(unsigned tam){criar(tam);}
    inline ListaLivro(const ListaLivro &L){copiar(L);}
    inline ~ListaLivro(void){limpar();}

    void incluir(const Livro &L);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaCD
{
private:
    CD *x;
    unsigned N;
    void criar(unsigned tam);
    void copiar(const ListaCD &L);
    inline void limpar(void){if(N>0) delete[] x;x=NULL;N = 0;}
public:
    inline ListaCD(void): x(NULL), N(0) {}
    inline ListaCD(unsigned tam){criar(tam);}
    inline ListaCD(const ListaCD &L){copiar(L);}
    inline ~ListaCD(void){limpar();}

    void incluir(const CD &C);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class ListaDVD
{
private:
    DVD *x;
    unsigned N;
    void criar(unsigned tam);
    void copiar(const ListaDVD &L);
    inline void limpar(void){if(N>0) delete[] x;x=NULL;N = 0;}
public:
    inline ListaDVD(void): x(NULL), N(0) {}
    inline ListaDVD(unsigned tam){criar(tam);}
    inline ListaDVD(const ListaDVD &L){copiar(L);}
    inline ~ListaDVD(void){limpar();}

    void incluir(const DVD &D);
    void excluir(unsigned id);
    void imprimir() const;
    void ler(istream &I);
    void salvar(ostream &O) const;
};

class Loja
{
private:
    ListaLivro LL;
    ListaCD LC;
    ListaDVD LD;
public:
    inline Loja(): LL(), LC(), LD() {}
    inline void incluirLivro(const Livro &X){LL.incluir(X);}
    inline void excluirLivro(unsigned id){LL.excluir(id);}
    inline void incluirDVD(const DVD &X){LD.incluir(X);}
    inline void excluirDVD(unsigned id){LD.excluir(id);}
    inline void incluirCD(const CD &X){LC.incluir(X);}
    inline void excluirCD(unsigned id){LC.excluir(id);}
    void imprimir() const;
    void ler(const char* arq);
    void salvar(const char* arq) const;
};

#endif // LOJA_H_INCLUDED
