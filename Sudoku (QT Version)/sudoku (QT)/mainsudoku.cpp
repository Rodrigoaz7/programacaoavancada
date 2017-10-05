#include "mainsudoku.h"
#include "ui_mainsudoku.h"
#include "sudoku.h"
#include <QFileDialog>
#include <QFile>
#include <QVector>
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
        }
    }
}

//Função para desabilitar Valores pré-determinados do Sudoku
void MainSudoku::desabilitar_posicoes(Sudoku &S)
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
    Sudoku SNovo;
    ui->tableSudoku->blockSignals(true); //impedir o sinal de não deixar iniciar o jogo
    imprimir_tabela(SNovo);
    desabilitar_posicoes(SNovo);
    ui->tableSudoku->blockSignals(false); //Voltar o sinal à ativa
}

void MainSudoku::on_pushButton_clicked() //Botão de jogar/reiniciar
{
     ui->tableSudoku->blockSignals(true); //impedir o sinal de não deixar iniciar o jogo
     imprimir_tabela(S);
     desabilitar_posicoes(S);
     ui->tableSudoku->blockSignals(false); //Voltar o sinal à ativa
}

void MainSudoku::on_pushButton_2_clicked() //Resolver
{
    ui->tableSudoku->blockSignals(true);
    S.resolver();
    imprimir_tabela(S);
    ui->tableSudoku->blockSignals(false);
}

void MainSudoku::on_tableSudoku_cellChanged(int row, int column)
{
    QString valor = ui->tableSudoku->item(row,column)->text(); //Capturando valor na poição i,j
    int num = valor.split(" ")[0].toInt(); //Transformando valor em inteiro
    if(S.jogada_valida(Jogada(row,column,num))) //Se o numero for válido
    {
        S.fazer_jogada(Jogada(row,column,num));//Faz jogada (adiciona na matriz)
        S.imprimir(false);
        //cout << row << endl << column << endl << num << endl; //Apenas p/ teste
    }
    else
    {
        //QMessageBox msg;
        ui->tableSudoku->item(row,column)->setText("0"); //Se nao for valida, zera.
        //msg.setText("Valor inválido para esta posição!");
        //msg.exec();
    }
}
