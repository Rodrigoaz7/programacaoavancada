#include "maincircuito.h"
#include "ui_maincircuito.h"
#include "modificarporta.h"
#include "modificarsaida.h"
#include "circuito_STL.h"
#include <QStringList>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <time.h>
#include <vector>
#include <cmath>

extern Circuito C;
MainCircuito::MainCircuito(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCircuito),
    NumIn(this),
    NumOut(this) ,
    NumPortas(this),
    newCircuito(this),
    modificarPorta(this),
    modificarSaida(this)
{
    ui->setupUi(this);

    // Cabecalhos da tabela de portas
    ui->tablePortas->setHorizontalHeaderLabels(QStringList() << "TIPO" << "Nº\nENTR"
                                               << "ENTR\n1" << "ENTR\n2" << "ENTR\n3" << "ENTR\n4");
    ui->tableSaidas->setHorizontalHeaderLabels(QStringList() << "ORIG\nSAÍDA");

    // Insere os widgets da barra de status
    statusBar()->insertWidget(0,new QLabel("Nº entradas: "));
    statusBar()->insertWidget(1,&NumIn);
    statusBar()->insertWidget(2,new QLabel("   Nº saídas: "));
    statusBar()->insertWidget(3,&NumOut);
    statusBar()->insertWidget(4,new QLabel("   Nº portas: "));
    statusBar()->insertWidget(5,&NumPortas);

    // Redimensiona todas as tabelas e reexibe os valores da barra de status
    // Essa funcao deve ser chamada sempre que mudar o circuito
    redimensiona_tabelas();

}

MainCircuito::~MainCircuito()
{
    delete ui;
}

// Funcoes de consulta
int MainCircuito::getNumEntradas() const
{
    int numCombinacoesEntrada = ui->tableTabelaVerdade->rowCount() - 1;
    if (numCombinacoesEntrada <= 0) return 0;

    int numInputs = round(log(numCombinacoesEntrada)/log(3));
    return numInputs;
}

int MainCircuito::getNumSaidas() const
{
    return ui->tableSaidas->rowCount();
}

int MainCircuito::getNumPortas() const
{
    return ui->tablePortas->rowCount();
}

// Redimensiona todas as tabelas e reexibe todos os valores da barra de status
// Essa funcao deve ser chamada sempre que mudar o circuito (digitar ou ler de arquivo)
void MainCircuito::redimensiona_tabelas()
{
    int numInputs, numOutputs, numPortas;
    QString texto;
    QLabel *prov;
    int i;

    numInputs = C.getNumIn();
    numOutputs = C.getNumOut();
    numPortas = C.getNumPortas();

    // ==========================================================
    // Ajusta os valores da barra de status
    // ==========================================================

    NumIn.setNum(numInputs);
    NumOut.setNum(numOutputs);
    NumPortas.setNum(numPortas);

    // ==========================================================
    // Redimensiona a tabela das portas e conexoes
    // ==========================================================

    // Limpa o conteudo, mas nao os cabecalhos
    ui->tablePortas->clearContents();

    ui->tablePortas->setRowCount(numPortas);
    for (i=0; i<numPortas; i++)
    {
        exibe_porta(i);
    }

    // ==========================================================
    // Redimensiona a tabela de saidas
    // ==========================================================

    // Limpa o conteudo, mas nao os cabecalhos
    ui->tableSaidas->clearContents();

    ui->tableSaidas->setRowCount(numOutputs);
    for (i=0; i<numOutputs; i++)
    {
        exibe_saida(i);
    }

    // ==========================================================
    // Redimensiona a tabela verdade
    // ==========================================================

    // Antes de redimensionar a tabela, anula todos os setSpan da primeira linha
    // Se nao fizer isso, dah erro ao redimensionar
    ui->tableTabelaVerdade->clearSpans();

    // Limpa todo o conteudo, inclusive cabecalhos
    ui->tableTabelaVerdade->clear();

    // Modifica as dimensoes
    ui->tableTabelaVerdade->setColumnCount(numInputs+numOutputs);
    int numCombinacoesEntrada = (numInputs>0 ? round(pow(3,numInputs)) : 0);
    // a tabela verdade tem uma linha a mais do que o numero de combinacoes de entrada
    // para conter o cabecalho
    ui->tableTabelaVerdade->setRowCount(1 + numCombinacoesEntrada);

    // Cria os cabecalhos na primeira linha
    // Entradas
    if (numInputs > 0)
    {
        ui->tableTabelaVerdade->setSpan(0,0,1,numInputs);
        prov = new QLabel("ENTRADAS");
        prov->setAlignment(Qt::AlignCenter);
        prov->setStyleSheet("font-weight: bold");
        ui->tableTabelaVerdade->setCellWidget(0,0,prov);
    }
    // Saidas
    if (numOutputs > 0)
    {
        ui->tableTabelaVerdade->setSpan(0,numInputs,1,numOutputs);
        prov = new QLabel("SAÍDAS");
        prov->setAlignment(Qt::AlignCenter);
        prov->setStyleSheet("font-weight: bold");
        ui->tableTabelaVerdade->setCellWidget(0,numInputs,prov);
    }

    // ==========================================================
    // Fixa os limites para os spin boxs de entradas de portas (classe ModificarPorta)
    // ==========================================================

    modificarPorta.setRangeInputs(-numInputs, numPortas);

    // ==========================================================
    // Fixa os limites para os spin boxs de origem das saidas (classe ModificarSaida)
    // ==========================================================

    modificarSaida.setRangeInputs(-numInputs, numPortas);
}

// Exibe os dados da i-esima porta
// Essa funcao deve ser chamada sempre que mudar caracteristicas da porta
// A funcao redimensiona_tabela jah chama essa funcao para todas as portas
void MainCircuito::exibe_porta(int i)
{
    if (i >= getNumPortas()) return;

    QString nomePorta;
    int numInputsPorta, idInputPorta[4];
    int j;
    QLabel *prov;
    nomePorta = QString::fromStdString(C.getPortas(i)->getTipo());
    //numInputsPorta = (nomePorta != "NT" ? 2+rand()%3 : 1);
    numInputsPorta = C.getPortas(i)->getIn();
    for (j=0; j<numInputsPorta; j++)
    {
        idInputPorta[j] = C.getPortas(i)->getId_in(j);
    }

    // Cria e define valores dos widgets da linha da tabela que corresponde aa porta

    // Coluna 0
    ui->tablePortas->setCellWidget(i,0,new QLabel(nomePorta));
    // Coluna 1
    prov = new QLabel;
    prov->setAlignment(Qt::AlignCenter);
    prov->setNum(numInputsPorta);
    ui->tablePortas->setCellWidget(i,1,prov);

    // As entradas de cada porta
    for (j=0; j<4; j++)
    {
        // Cria os widgets das celulas da tabela de portas
        // Coluna 2 em diante
        prov = new QLabel;
        prov->setAlignment(Qt::AlignCenter);
        if (j<numInputsPorta) prov->setNum(idInputPorta[j]);
        ui->tablePortas->setCellWidget(i,2+j,prov);
    }
}

// Exibe os dados da i-esima saida
// Essa funcao deve ser chamada sempre que mudar valores da saida
// A funcao redimensiona_tabela jah chama essa funcao para todas as saidas
void MainCircuito::exibe_saida(int i)
{
    if (i >= getNumSaidas()) return;

    int idOutput;

    QLabel *prov;
    idOutput = C.getId_out(i);

    // Cria o widget da celula da tabela de saidas
    // Coluna 0 (unica)
    prov = new QLabel;
    prov->setAlignment(Qt::AlignCenter);
    prov->setNum(idOutput);
    ui->tableSaidas->setCellWidget(i,0,prov);
}

void MainCircuito::on_actionSair_triggered()
{
    QCoreApplication::quit();
}

// Exibe a caixa de dialogo para fixar caracteristicas de um novo circuito
void MainCircuito::on_actionNovo_triggered()
{
    newCircuito.show();
}

// Abre uma caixa de dialogo para ler um arquivo
void MainCircuito::on_actionLer_triggered()
{
    C.ler("..//circuito_qt_incompleto//Saved Files//circuito.txt");

    /*QString fileName = QFileDialog::getOpenFileName(this, tr("Arquivo de circuito"), QString(),
            tr("Circuitos (*.txt);;Todos (*.*)"));
    if (!fileName.isEmpty()) {
        // Le o circuito do arquivo com nome "arq", usando a funcao apropriada da classe circuito
        string arq = fileName.toStdString();
        //C.ler(arq.c_str());
        // Provisoriamente, estamos apenas exibindo uma msg
        QMessageBox msgBox;
        msgBox.setText("Tenta ler um circuito a partir do arquivo "+fileName);
        msgBox.exec();

        // Feita a leitura, reexibe todas as tabelas
        redimensiona_tabelas();
    }*/
    redimensiona_tabelas();
}

// Abre uma caixa de dialogo para salvar um arquivo
void MainCircuito::on_actionSalvar_triggered()
{
    C.salvar("..//Circuito_qt_incompleto//Saved Files//circuito.txt");
    /*QString fileName = QFileDialog::getSaveFileName(this, tr("Arquivo de circuito"), QString(),
            tr("Circuitos (*.txt);;Todos (*.*)"));
        if (!fileName.isEmpty()) {
            // Salva o circuito no arquivo com nome "arq", usando a funcao apropriada da classe circuito
            string arq = fileName.toStdString();
            // Provisoriamente, estamos apenas exibindo uma msg
            QMessageBox msgBox;
            msgBox.setText("Tenta salvar o circuito no arquivo "+fileName);
            msgBox.exec();
        }*/
}

// Gera e exibe a tabela verdade para o circuito
// Chama a funcao simular da classe circuito
void MainCircuito::on_actionGerar_tabela_triggered()
{
    //
    // Gera todas as possibilidades de combinacao das entradas
    //

    int numInputs = getNumEntradas();
    int numOutputs = getNumSaidas();
    int numCombinacoesEntrada = (numInputs>0 ? round(pow(3,numInputs)) : 0);;
    QString texto;
    QLabel *prov;
    int i,j;

    int inputs[numInputs];  // -1=UNDEF; 0=FALSE; 1=TRUE
    bool_3S outputs[numOutputs];  // -1=UNDEF; 0=FALSE; 1=TRUE

    // Inicializa todas as entradas com UNDEF
    for (i=0; i<numInputs; i++) inputs[i] = -1;

    //
    // Gera todas as linhas da tabela verdade
    //

    for (i=0; i<numCombinacoesEntrada; i++)
    {
        //
        // Exibe a i-esima combinação de entrada: inputs[0] a inputs[numInputs-1]
        //

        // Cria os QLabels correspondentes aas entradas inputs[j]
        for (j=0; j<numInputs; j++)
        {
            switch (inputs[j])
            {
            default:
            case -1:
                texto="X";
                break;
            case 0:
                texto="F";
                break;
            case 1:
                texto="T";
                break;
            }
            prov = new QLabel(texto);
            prov->setAlignment(Qt::AlignCenter);
            ui->tableTabelaVerdade->setCellWidget(i+1, j, prov);
            //Funcao de simulacao do circuito
            C.simular(inputs, numInputs);
        }

        // Determina qual entrada deve ser incrementada na proxima linha
        // Incrementa a ultima possivel que nao for TRUE
        // Se a ultima for TRUE, faz essa ser UNDEF e tenta incrementar a anterior
        j = numInputs-1;
        while (inputs[j]==1 && j>=0) // inputs[j]==TRUE && j>=0
        {
          inputs[j] = -1;  // UNDEF
          j--;
        };
        // Incrementa a input selecionada
        if (j>=0) inputs[j] += 1;

        //
        // Exibe a j-esima saida
        //
        // Cria os QLabels correspondentes aas saidas outputs[j]

        //Imprimindo na tabela as saidas
        C.imprimirSaidas(outputs);

        for (j=0; j<numOutputs; j++)
        {
            switch (outputs[j])
            {
            default:
            case UNDEF_3S:
                texto="X";
                break;
            case FALSE_3S:
                texto="F";
                break;
            case TRUE_3S:
                texto="T";
                break;
            }
            cout << "OUTPUT: " << outputs[j] << endl;

            prov = new QLabel(texto);
            prov->setAlignment(Qt::AlignCenter);
            ui->tableTabelaVerdade->setCellWidget(i+1, j+numInputs, prov);
        }
    }
}

// Exibe a caixa de dialogo para fixar caracteristicas de uma porta
void MainCircuito::on_tablePortas_activated(const QModelIndex &index)
{
    int id_porta = index.row()+1;
    modificarPorta.setPorta(id_porta);
    modificarPorta.show();
}

// Exibe a caixa de dialogo para fixar caracteristicas de uma saida
void MainCircuito::on_tableSaidas_activated(const QModelIndex &index)
{
    int id_saida = index.row()+1;
    modificarSaida.setSaida(id_saida);
    modificarSaida.show();
}
