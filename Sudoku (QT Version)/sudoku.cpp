#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <QString>
#include <QMessageBox>
#include <QTextStream>
#include <stack>
#include "sudoku.h"

using namespace std;

// Construtor (por default, cria Jogada que termina o jogo)
Jogada::Jogada(int I, int J, int V)
{
    if (I<0 || I>8) I=-1;
    if (J<0 || J>8) J=-1;
    if (V<0 || V>9) V=-1;
    i = I;
    j = J;
    v = V;
}

int Sudoku::get_elemento(int I, int J) const
{
    if (I<0 || I>=9 || J<0 || J>=9) return 0;

    return x[I][J];
}

// Cria um tabuleiro com o conteudo do arquivo nome_arq
// Caso nao consiga ler do arquivo, cria tabuleiro vazip
Sudoku::Sudoku(const char *nome_arq)
{
    for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
    {
        x[i][j] = 0;
    }
    // Le o tabuleiro inicial de arquivo
    ifstream arq(nome_arq);
    if (!arq.is_open()) return;

    string prov;
    int valor;

    arq >> prov;
    if (prov != "SUDOKU") return;
    for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
    {
      arq >> valor;
      if (valor != 0)
      {
        Jogada J(i,j,valor);
        if (jogada_valida(J)) x[i][j] = valor;
      }
    }
    arq.close();
}

// Imprime o conteudo do tabuleiro na tela
// O parametro booleano de entrada "inicial" indica a posicao da impressao:
// true: lado direito da tela (tabuleiro inicial)
// false: lado esquerdo da tela (tabuleiro atual)
void Sudoku::imprimir(bool inicial) const
{
    int J = (inicial ? 32 : 4);
    for (unsigned i=0; i<9; i++)
    {
    for (unsigned j=0; j<9; j++)
    {
        if (x[i][j]>=0 && x[i][j]<=9) cout << int(x[i][j]) << " ";
    }
    cout << endl;
    }
}

// Testa se a jogada J eh possivel para o tabuleiro
bool Sudoku::jogada_valida(Jogada J) const
{
    unsigned i,j;
    // Testar a jogada
    if (J.i<0 || J.i>8) return false;
    if (J.j<0 || J.j>8) return false;
    if (J.v<0 || J.v>9) return false;

    // Testar se a casa nao estah vazia
    if (x[J.i][J.j] != 0)
    {
      // Soh pode apagar
      return (J.v == 0);
    }

    // Se chegou aqui, eh pq a casa estah vazia.
    // Portanto, nao pode apagar
    if (J.v == 0) return false;

    // Testar a linha
    for (i=0; i<9; i++)
    {
      if (x[i][J.j] == J.v) return false;
    }
    // Testar a coluna
    for (j=0; j<9; j++)
    {
      if (x[J.i][j] == J.v) return false;
    }
    // Testar o bloco
    unsigned iIni = 3*(J.i/3);
    unsigned jIni = 3*(J.j/3);
    for (i=0; i<3; i++) for (j=0; j<3; j++)
    {
      if (x[iIni+i][jIni+j] == J.v) return false;
    }
    return true;
}

// Testa se o tabuleiro estah completo (fim de jogo)
bool Sudoku::fim_de_jogo() const
{
    for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
    {
    if (x[i][j] == 0) return false;
    }
    return true;
}

// Retorna o numero de casas vazias no tabuleiro
unsigned Sudoku::num_casas_vazias() const
{
    unsigned N(0);
    for (unsigned i=0; i<9; i++) for (unsigned j=0; j<9; j++)
    {
    if (x[i][j] == 0) N++;
    }
    return N;
}

// Determina automaticamente a solucao do tabuleiro (preenche as casas vazias)
void Sudoku::resolver(int &n, int &tabuleiros_restantes, int &tabuleiros_testados)
{
    Sudoku S;
    stack<Sudoku> F;
    F.push(*this);//o primeiro da pilha recebe a origem
    unsigned i = 0, j = 0;
    do{
        S = F.top(); //Sudoku atual recebe o topo da pilha
        tabuleiros_testados++;
        F.pop();// o topo da pilha � removida
        if(S.fim_de_jogo()){
            S.imprimir(false);
            return;
        }
        while(S.x[i][j] != 0){//procura a proxima casa vazia no sudoku
            j++;
            if(j == 9){
                j = 0;
                i++;
            }
            if(i == 9){
                i = 0;
            }
        }
        for(int v =1; v<10;v++){//faz os "filhos" do primeiro da pilha
            Jogada J(i,j,v);
            if(S.jogada_valida(J)){
                S.fazer_jogada(J); //Se a jogada � valida, ent�o ela � feita.
                F.push(S);//Se a jogada � feita, � colocado outro Sudoku no topo da pilha
                S.x[i][j] = 0; //Esta posi��o recebe zero, para que seja testado outro tabuleiro com outro v
                n++;
            }
        }
        if(F.empty()) //Se nao houver sudokus ao final do while, entao nao ha solucao
        {
            cout << "Sudoku sem solucao " << endl;
            tabuleiros_restantes = F.size();
            tabuleiros_testados = 0;
            return;
        }
        cout << "Tabuleiros possiveis " << F.size() << endl;
}while(!F.top().fim_de_jogo());
    tabuleiros_restantes = F.size();
    *this = F.top();
    cout << "iteracoes: " << n << endl;
    cout << "n de tabuleiros testados: " << tabuleiros_testados << endl;
    imprimir(false);
    return;
}
