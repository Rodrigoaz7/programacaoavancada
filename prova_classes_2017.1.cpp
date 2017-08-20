#include <iostream>
using namespace std;

class Ponto
{
private:
    double p1,p2;
public:
    inline Ponto(): p1(0.0), p2(0.0) {}
    inline ~Ponto()
    {
        p1 = p2 = 0.0;
    }
    friend ostream &operator<<(ostream &O, const Ponto &P);
    friend istream &operator>>(istream &I, Ponto &P);
};

ostream &operator<<(ostream &O, const Ponto &P)
{
    O << '[' << P.p1 << ',' << P.p2 << ']';
    return O;
}

istream &operator>>(istream &I, Ponto &P)
{
    I >> P.p1 >> P.p2;
    return I;
}

class Linha
{
private:
    unsigned N;
    Ponto *x;
public:
    inline Linha(): N(0), x(NULL) {}
    Linha(const Linha &L);
    inline ~Linha() { if(N>0) delete[] x;}
    void operator=(const Linha &L);
    Linha operator+(const Linha &L) const;
    friend ostream &operator<<(ostream &O, const Linha &L);
    void adicionar(const Ponto &P);
};

Linha::Linha(const Linha &L)
{
    N = L.N;
    if(N>0) x = new Ponto[N];
    else x=NULL;
    for(unsigned i=0; i<N; i++) x[i] = L.x[i];
}

ostream &operator<<(ostream &O, const Linha &L)
{
    for (unsigned i=0; i<L.N; i++) O << L.x[i];
    return O;
}

void Linha::operator=(const Linha &L)
{
    if(this != &L) //Somente se a linha passada como parametro for diferente
    {
        if(N != L.N) //Se possuirem dimensoes diferentes
        {
            if(N>0) delete[] x; //Se a linha existir, desaloca ela.
            N = L.N; //Nova dimensao
            if(N>0) x = new Ponto[N]; //Se a nova dimensao nao for nula, entao aloca espaco de memoria
        }
        for(unsigned i=0; i<N; i++) x[i] = L.x[i]; //Copia os valores para nova linha
    }
}

Linha Linha::operator+(const Linha &L) const
{
    Linha prov;
    prov.N = N+L.N;
    prov.x = new Ponto[N+L.N];

    for(unsigned i=0; i<N; i++) prov.x[i] = x[i];
    for(unsigned i=0; i<L.N; i++) prov.x[i+N] = L.x[i];
    return prov;
}

void Linha::adicionar(const Ponto &P)
{
    Ponto *prov = new Ponto[N+1];

    for(unsigned i=0; i<N; i++) prov[i] = x[i];
    prov[N] = P;
    if(N > 0) delete[] x;
    N = N +1;
    x = prov;
}

int main(void)
{
    Linha L1,L2,L3;
    Ponto P;
    unsigned NPt, NPtAdic, i;
    do
    {
        cout << "Numero de pontos da 1a linha (>0): ";
        cin >> NPt;
    }
    while (NPt<=0);
    for (i=0; i<NPt; i++)
    {
        cout << "Digite o ponto indice " << i << ": ";
        cin >> P;
        L1.adicionar(P);
    }
    L2 = L1;
    do
    {
        cout << "Numero de pontos adicionais da 2a linha (>0): ";
        cin >> NPtAdic;
    }
    while (NPtAdic<=0);
    for (i=0; i<NPtAdic; i++)
    {
        cout << "Digite o ponto indice " << i+NPt << ": ";
        cin >> P;
        L2.adicionar(P);
    }
    L3 = L1+L2;
    cout << "1a linha: " << L1 << endl;
    cout << "2a linha: " << L2 << endl;
    cout << "3a linha: " << L3 << endl;

    return 0;
}
