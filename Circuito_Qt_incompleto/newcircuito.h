#ifndef NEWCIRCUITO_H
#define NEWCIRCUITO_H

#include <QDialog>
#include <circuito_STL.h>

/* =============================================================================== *
 * ESSA EH A CLASSE QUE REPRESENTA A CAIXA DE DIALOGO PARA CRIAR NOVOS CIRCUITOS   *
 * =============================================================================== */

namespace Ui {
class NewCircuito;
}

class MainCircuito;
class NewCircuito : public QDialog
{
    Q_OBJECT

public:
    explicit NewCircuito(QWidget *parent = 0);
    ~NewCircuito();
    Circuito Novo;

private slots:
    // Cria um novo circuito com as dimensoes especificadas pelo usuario
    // Deve chamar a funcao apropriada da classe Circuito
    void on_NewCircuito_accepted();

private:
    Ui::NewCircuito *ui;
    //MainCircuito* m_maincircuito;
};

#endif // NEWCIRCUITO_H
