#include "maincircuito.h"
#include "ui_maincircuito.h"
#include "circuito_STL.h"
#include <QStringList>
#include <QString>
#include <time.h>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

MainCircuito::MainCircuito(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainCircuito)
{
    ui->setupUi(this);
    // Cabecalhos das tabelas
    ui->tablePortas->setHorizontalHeaderLabels(QStringList() << "TIPO" << "Nº\nENTR"
                                               << "ENTR\n1" << "ENTR\n2" << "ENTR\n3" << "ENTR\n4");
    ui->tableSaidas->setHorizontalHeaderLabels(QStringList() << "ORIG\nSAÍDA");

    // Insere os widgets da barra de status (Label no fim da tela)
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

//leitura de arquivo
void MainCircuito::on_actionLer_triggered()
{
    C.ler("..//Circuito_Qt//circuito_right0.txt");
    redimensiona_tabelas();
}

// Redimensiona todas as tabelas e reexibe todos os valores da barra de status
// Essa funcao deve ser chamada sempre que mudar o circuito (digitar ou ler de arquivo)
void MainCircuito::redimensiona_tabelas()
{
    int numInputs, numOutputs, numPortas;
    QString texto;
    int numInputsPorta, idInputPorta, idOutput;
    QLabel *prov;
    int i,j;

    // Esses numeros devem ser lidos a partir de metodos de consulta da classe Circuito
    // Para fazer um teste, vamos atribuir quantidades aleatorias
    srand(time(NULL));
    numInputs = C.getNumIn(); //num de entradas do circuito
    numOutputs= C.getNumOut(); //num de saidas do circuito
    numPortas = C.getNumPortas(); //num de portas logicas do circuito

    // Ajusta os valores da barra de status
    NumIn.setNum(numInputs);
    NumOut.setNum(numOutputs);
    NumPortas.setNum(numPortas);

    // Redimensiona a tabela das portas e conexoes
    ui->tablePortas->clearContents();
    ui->tablePortas->setRowCount(numPortas);
    for (i=0; i<numPortas; i++)
    {
        //C.getPortas(i)->imprimir(ostream);

        texto = "AND";
        numInputsPorta = C.getPortas(i)->getIn();

        // Cria os widgets das celulas da tabela de portas
        // Coluna 0
        ui->tablePortas->setCellWidget(i,0,new QLabel(texto));
        // Coluna 1
        prov = new QLabel;
        prov->setAlignment(Qt::AlignCenter);
        prov->setNum(numInputsPorta);
        ui->tablePortas->setCellWidget(i,1,prov);

        // As entradas de cada porta
        for (j=0; j<numInputsPorta; j++)
        {
            idInputPorta = C.getPortas(i)->getId_in(j);

            // Cria os widgets das celulas da tabela de portas
            // Coluna 2 em diante
            prov = new QLabel;
            prov->setAlignment(Qt::AlignCenter);
            prov->setNum(idInputPorta);
            ui->tablePortas->setCellWidget(i,2+j,prov);
        }

    }

    // Redimensiona a tabela de saidas
    ui->tableSaidas->clearContents();
    ui->tableSaidas->setRowCount(numOutputs);
    for (i=0; i<numOutputs; i++)
    {
        idOutput = C.getId_out(i);
        // Cria os widgets das celulas da tabela de saidas
        // Coluna 0 (unica)
        prov = new QLabel;
        prov->setAlignment(Qt::AlignCenter);
        prov->setNum(idOutput);
        ui->tableSaidas->setCellWidget(i,0,prov);
    }

    // Tabela verdade eh nao selecionavel
    ui->tableTabelaVerdade->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableTabelaVerdade->setTabKeyNavigation(false);

    //if(numInputs == 0) numInputs =2;
    //if(numOutputs == 0) numOutputs = 2;
    // Redimensiona a tabela verdade
    ui->tableTabelaVerdade->clearContents();
    if(numInputs == 0 || numOutputs ==0) ui->tableTabelaVerdade->setColumnCount(7);
    else ui->tableTabelaVerdade->setColumnCount(numInputs+numOutputs);
    int numPossiveisInputs;
    if(numInputs == 0) numPossiveisInputs = 10;
    else numPossiveisInputs = round(pow(3,numInputs));
    ui->tableTabelaVerdade->setRowCount(1+numPossiveisInputs); // 1 linha a mais para cabecalho

    // Cria os cabecalhos na primeira linha
    // Entradas
    if(numInputs == 0) ui->tableTabelaVerdade->setSpan(0,0,1,2);
    else ui->tableTabelaVerdade->setSpan(0,0,1,numInputs);
    prov = new QLabel("ENTRADAS");
    prov->setAlignment(Qt::AlignCenter);
    prov->setStyleSheet("font-weight: bold");
    ui->tableTabelaVerdade->setCellWidget(0,0,prov);
    // Saidas
    if(numInputs == 0 || numOutputs ==0) ui->tableTabelaVerdade->setSpan(0,2,1,2);
    else ui->tableTabelaVerdade->setSpan(0,numInputs,1,numOutputs);
    prov = new QLabel("SAÍDAS");
    prov->setAlignment(Qt::AlignCenter);
    prov->setStyleSheet("font-weight: bold");
    if(numInputs == 0) ui->tableTabelaVerdade->setCellWidget(0,2,prov);
    else ui->tableTabelaVerdade->setCellWidget(0,numInputs,prov);

    // Exibe as possibilidades de combinacao das entradas

    // Inicializa com todas as entradas UNDEF
    if(numInputs==0) numInputs = 2;
    std::vector<int> inputs(numInputs);  // -1=UNDEF; 0=FALSE; 1=TRUE

    for (i=0; i<numInputs; i++) inputs[i] = -1;

    // Gera todas as linhas da tabela verdade
    for (j=0; j<numPossiveisInputs; j++)
    {
        // Exibe a j-esima combinação de entrada
        for (i=0; i<numInputs; i++)
        {
            switch (inputs[i])
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
            ui->tableTabelaVerdade->setCellWidget(1+j,i,prov);
        }

        // Determina qual entrada deve ser incrementada na proxima linha
        // Incrementa a ultima possivel que nao for TRUE
        // Senao, faz essa ser UNDEF e tenta incrementar a anterior
        i = numInputs-1;
        while (inputs[i]==1 && i>=0) // inputs[i]==TRUE && i>=0
        {
          inputs[i] = -1;  // UNDEF
          i--;
        };
        // Incrementa a input selecionada
        if (i>=0) inputs[i] += 1;

        if(numOutputs == 0) numOutputs = 2;
        // Gera os labels da j-esima saida
        for (i=0; i<numOutputs; i++)
        {
            prov = new QLabel("?");
            prov->setAlignment(Qt::AlignCenter);
            ui->tableTabelaVerdade->setCellWidget(1+j,numInputs+i,prov);
        }
    }

}

void MainCircuito::on_actionSair_triggered()
{
    QCoreApplication::quit();
}


void MainCircuito::on_actionSalvar_triggered()
{
    C.salvar("..//Circuito_Qt//Saved Files//teste.txt");
}

void MainCircuito::on_actionGerar_tabela_triggered()
{
    QLabel *prov;
    int numInputs = C.getNumIn();
    int numPossiveisInputs;
    if(numInputs == 0) numPossiveisInputs = 10;
    else numPossiveisInputs = round(pow(3,numInputs));
    bool_3S saida[2*numInputs-1];

    for(int i=1; i<=numPossiveisInputs;i++)
    {
        for(int j=numInputs; j<(2*numInputs);j++)
        {
            C.calcularEntradas(i-1);
            C.simular();
            C.imprimirSaidas(saida);

            //if(saida == TRUE_3S) prov = new QLabel("T");
            //else if(saida == FALSE_3S) prov = new QLabel("F");
            //else prov = new QLabel("X");
            prov->setAlignment(Qt::AlignCenter);
            ui->tableTabelaVerdade->setCellWidget(i,j,prov);

        }
    }
}

void MainCircuito::on_actionNovo_triggered()
{
    Circuito Novo;
    C = Novo;
    redimensiona_tabelas();
}
