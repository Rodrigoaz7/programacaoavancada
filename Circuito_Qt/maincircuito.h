#ifndef MAINCIRCUITO_H
#define MAINCIRCUITO_H

#include <QMainWindow>
#include <QLabel>
#include "circuito_STL.h"

namespace Ui {
class MainCircuito;
}

class MainCircuito : public QMainWindow
{
    Q_OBJECT
    Circuito C;

public:
    explicit MainCircuito(QWidget *parent = 0);
    ~MainCircuito();
    void redimensiona_tabelas();

private slots:
    void on_actionSair_triggered();

    void on_actionLer_triggered();

    void on_actionSalvar_triggered();

    void on_actionGerar_tabela_triggered();

    void on_actionNovo_triggered();

private:
    Ui::MainCircuito *ui;
    QLabel NumIn;     // Exibe o numero de entradas do circuito
    QLabel NumOut;    // Exibe o numero de saidas do circuito
    QLabel NumPortas; // Exibe o numero de portas do circuito
};

#endif // MAINCIRCUITO_H
