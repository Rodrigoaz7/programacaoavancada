#include "mainsudoku.h"
#include "ui_mainsudoku.h"
#include "sudoku.h"
#include <QMessageBox>
#include <QTextStream>
#include <iostream>
using namespace std;

MainSudoku::MainSudoku(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainSudoku)
{
    ui->setupUi(this);
}
void MainSudoku::imprimir_tabela(Sudoku &S)
{
    int myNumber;

    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            myNumber = S.get_elemento(i,j); //Preenchendo tabela com os valores da matriz x
            QTableWidgetItem *theItem = new QTableWidgetItem();
            theItem->setData(Qt::EditRole, myNumber); //Gambiarra para preencher números inteiros
            ui->tableSudoku->setItem(i, j, theItem); //Setando itens na tabela
            theItem->setTextAlignment(Qt::AlignCenter);
            if(ui->tableSudoku->item(i,j)->text() != '0')
            {
                ui->tableSudoku->item(i,j)->setBackground(Qt::darkCyan);
                ui->tableSudoku->item(i,j)->setTextColor(Qt::white);
            }
        }
    }
}

//Função para desabilitar Valores pré-determinados do Sudoku
void MainSudoku::desabilitar_posicoes()
{
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
              if(ui->tableSudoku->item(i,j)->text() != "0")
              {
                 ui->tableSudoku->item(i,j)->setFlags(ui->tableSudoku->item(i,j)->flags() & ~Qt::ItemIsEditable);
              }
        }
    }
}

void MainSudoku::fim_de_jogo() //Função para verificar o fim do jogo
{
    unsigned casas_vazias = S.num_casas_vazias();
    if(casas_vazias == 0)
    {
        QMessageBox msg;
        msg.setText("Parabéns, você ganhou!");
        msg.exec();
        on_actionReiniciar_triggered(); //Ao terminar, reinicia a partida
    }
}

MainSudoku::~MainSudoku()
{
    delete ui;
}

void MainSudoku::on_pushButton_3_clicked() //Botão de sair
{
    QCoreApplication::quit();
}

void MainSudoku::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

void MainSudoku::on_actionReiniciar_triggered()
{
    Sudoku SNovo; //Cria novo objeto (novo jogo)
    S = SNovo;
    ui->tableSudoku->blockSignals(true); //impedir o sinal de não deixar iniciar o jogo
    imprimir_tabela(S);
    desabilitar_posicoes();
    ui->tableSudoku->blockSignals(false); //Voltar o sinal à ativa
}

void MainSudoku::on_pushButton_clicked() //Botão de iniciar jogo
{
     ui->tableSudoku->blockSignals(true); //impedir o sinal de não deixar iniciar o jogo
     imprimir_tabela(S);
     desabilitar_posicoes();
     ui->tableSudoku->blockSignals(false); //Voltar o sinal à ativa
}

void MainSudoku::on_pushButton_2_clicked() //Resolver
{
    int num_iteracoes = 0;
    int tabuleiros_testados = 0;
    int tabuleiros_restantes = 0;
    ui->tableSudoku->blockSignals(true);
    S.resolver(num_iteracoes, tabuleiros_restantes, tabuleiros_testados);
    imprimir_tabela(S);

    QMessageBox msg;
    if(tabuleiros_testados != 0) // Se houver solução
    {
        msg.setText("Resolvido em " + QString::number(num_iteracoes) + " jogadas / "
                    + QString::number(tabuleiros_restantes) + " tabuleiros restantes / "
                    + QString::number(tabuleiros_testados) + " tabuleiros testados ");
        msg.exec();
    }
    else //Se não houver solução
    {
        msg.setText("Sudoku sem solução. Feitas " + QString::number(num_iteracoes) + " jogadas");
        msg.exec();
    }
    ui->tableSudoku->blockSignals(false);
}

void MainSudoku::on_tableSudoku_cellChanged(int row, int column)
{
    QString valor = ui->tableSudoku->item(row,column)->text(); //Capturando valor na poição i,j
    int num = valor.split(" ")[0].toInt(); //Transformando valor em inteiro
    if(S.jogada_valida(Jogada(row,column,num))) //Se o numero for válido
    {
        S.fazer_jogada(Jogada(row,column,num));//Faz jogada (adiciona na matriz)
        S.imprimir(false); // Apenas para teste
    }
    else
    {
        ui->tableSudoku->item(row,column)->setText("0"); //Se nao for valida, zera.
        QMessageBox msg_erro;
        msg_erro.setText("Valor inválido para esta posição!");
        msg_erro.exec();
    }
    fim_de_jogo();
}
