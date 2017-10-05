#ifndef MAINSUDOKU_H
#define MAINSUDOKU_H
#include <QMainWindow>
#include "sudoku.h"

namespace Ui {
class MainSudoku;
}

class MainSudoku : public QMainWindow
{
    Q_OBJECT
    Sudoku S; //Objeto global

public:
    explicit MainSudoku(QWidget *parent = 0);
    ~MainSudoku();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_tableSudoku_cellChanged(int row, int column);

    void on_actionSair_triggered();

    void on_actionReiniciar_triggered();

private:
    Ui::MainSudoku *ui;
    //Função de impressão da tabela
    void imprimir_tabela(Sudoku &S);
    //Função para desabilitar Valores pré-determinados do Sudoku
    void desabilitar_posicoes(Sudoku &S);

};

#endif // MAINSUDOKU_H
