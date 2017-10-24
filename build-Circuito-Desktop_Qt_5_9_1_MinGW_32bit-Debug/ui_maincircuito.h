/********************************************************************************
** Form generated from reading UI file 'maincircuito.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINCIRCUITO_H
#define UI_MAINCIRCUITO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainCircuito
{
public:
    QAction *actionNovo;
    QAction *actionLer;
    QAction *actionSalvar;
    QAction *actionSair;
    QAction *actionGerar_tabela;
    QWidget *centralWidget;
    QTableWidget *tablePortas;
    QLabel *labelPortas;
    QTableWidget *tableSaidas;
    QLabel *labelSaidas;
    QLabel *labelCircuito;
    QLabel *labelCircuito_2;
    QTableWidget *tableTabelaVerdade;
    QMenuBar *menuBar;
    QMenu *menuCircuito;
    QMenu *menuSimular;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainCircuito)
    {
        if (MainCircuito->objectName().isEmpty())
            MainCircuito->setObjectName(QStringLiteral("MainCircuito"));
        MainCircuito->resize(800, 640);
        actionNovo = new QAction(MainCircuito);
        actionNovo->setObjectName(QStringLiteral("actionNovo"));
        actionLer = new QAction(MainCircuito);
        actionLer->setObjectName(QStringLiteral("actionLer"));
        actionSalvar = new QAction(MainCircuito);
        actionSalvar->setObjectName(QStringLiteral("actionSalvar"));
        actionSair = new QAction(MainCircuito);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        actionGerar_tabela = new QAction(MainCircuito);
        actionGerar_tabela->setObjectName(QStringLiteral("actionGerar_tabela"));
        centralWidget = new QWidget(MainCircuito);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tablePortas = new QTableWidget(centralWidget);
        if (tablePortas->columnCount() < 6)
            tablePortas->setColumnCount(6);
        if (tablePortas->rowCount() < 1)
            tablePortas->setRowCount(1);
        tablePortas->setObjectName(QStringLiteral("tablePortas"));
        tablePortas->setGeometry(QRect(0, 48, 311, 551));
        tablePortas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tablePortas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tablePortas->setTabKeyNavigation(false);
        tablePortas->setAlternatingRowColors(true);
        tablePortas->setSelectionBehavior(QAbstractItemView::SelectRows);
        tablePortas->setRowCount(1);
        tablePortas->setColumnCount(6);
        tablePortas->horizontalHeader()->setDefaultSectionSize(45);
        tablePortas->horizontalHeader()->setHighlightSections(false);
        tablePortas->horizontalHeader()->setMinimumSectionSize(25);
        tablePortas->verticalHeader()->setVisible(true);
        tablePortas->verticalHeader()->setDefaultSectionSize(25);
        tablePortas->verticalHeader()->setMinimumSectionSize(20);
        labelPortas = new QLabel(centralWidget);
        labelPortas->setObjectName(QStringLiteral("labelPortas"));
        labelPortas->setGeometry(QRect(0, 24, 311, 25));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelPortas->setFont(font);
        labelPortas->setFrameShape(QFrame::Box);
        labelPortas->setAlignment(Qt::AlignCenter);
        tableSaidas = new QTableWidget(centralWidget);
        if (tableSaidas->columnCount() < 1)
            tableSaidas->setColumnCount(1);
        if (tableSaidas->rowCount() < 1)
            tableSaidas->setRowCount(1);
        tableSaidas->setObjectName(QStringLiteral("tableSaidas"));
        tableSaidas->setGeometry(QRect(310, 48, 86, 551));
        tableSaidas->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableSaidas->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableSaidas->setTabKeyNavigation(false);
        tableSaidas->setAlternatingRowColors(true);
        tableSaidas->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableSaidas->setRowCount(1);
        tableSaidas->setColumnCount(1);
        tableSaidas->horizontalHeader()->setDefaultSectionSize(45);
        tableSaidas->horizontalHeader()->setHighlightSections(false);
        tableSaidas->horizontalHeader()->setMinimumSectionSize(25);
        tableSaidas->verticalHeader()->setVisible(true);
        tableSaidas->verticalHeader()->setDefaultSectionSize(25);
        tableSaidas->verticalHeader()->setMinimumSectionSize(20);
        labelSaidas = new QLabel(centralWidget);
        labelSaidas->setObjectName(QStringLiteral("labelSaidas"));
        labelSaidas->setGeometry(QRect(310, 24, 86, 25));
        labelSaidas->setFont(font);
        labelSaidas->setFrameShape(QFrame::Box);
        labelSaidas->setAlignment(Qt::AlignCenter);
        labelCircuito = new QLabel(centralWidget);
        labelCircuito->setObjectName(QStringLiteral("labelCircuito"));
        labelCircuito->setGeometry(QRect(0, 0, 396, 25));
        labelCircuito->setFont(font);
        labelCircuito->setFrameShape(QFrame::Box);
        labelCircuito->setAlignment(Qt::AlignCenter);
        labelCircuito_2 = new QLabel(centralWidget);
        labelCircuito_2->setObjectName(QStringLiteral("labelCircuito_2"));
        labelCircuito_2->setGeometry(QRect(404, 0, 396, 25));
        labelCircuito_2->setFont(font);
        labelCircuito_2->setFrameShape(QFrame::Box);
        labelCircuito_2->setAlignment(Qt::AlignCenter);
        tableTabelaVerdade = new QTableWidget(centralWidget);
        if (tableTabelaVerdade->columnCount() < 4)
            tableTabelaVerdade->setColumnCount(4);
        if (tableTabelaVerdade->rowCount() < 99)
            tableTabelaVerdade->setRowCount(99);
        tableTabelaVerdade->setObjectName(QStringLiteral("tableTabelaVerdade"));
        tableTabelaVerdade->setGeometry(QRect(404, 24, 396, 575));
        tableTabelaVerdade->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        tableTabelaVerdade->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableTabelaVerdade->setTabKeyNavigation(false);
        tableTabelaVerdade->setAlternatingRowColors(true);
        tableTabelaVerdade->setRowCount(99);
        tableTabelaVerdade->setColumnCount(4);
        tableTabelaVerdade->horizontalHeader()->setVisible(false);
        tableTabelaVerdade->horizontalHeader()->setDefaultSectionSize(45);
        tableTabelaVerdade->horizontalHeader()->setHighlightSections(false);
        tableTabelaVerdade->horizontalHeader()->setMinimumSectionSize(25);
        tableTabelaVerdade->verticalHeader()->setVisible(false);
        tableTabelaVerdade->verticalHeader()->setDefaultSectionSize(25);
        tableTabelaVerdade->verticalHeader()->setHighlightSections(false);
        MainCircuito->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainCircuito);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 21));
        menuCircuito = new QMenu(menuBar);
        menuCircuito->setObjectName(QStringLiteral("menuCircuito"));
        menuSimular = new QMenu(menuBar);
        menuSimular->setObjectName(QStringLiteral("menuSimular"));
        MainCircuito->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainCircuito);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainCircuito->setStatusBar(statusBar);

        menuBar->addAction(menuCircuito->menuAction());
        menuBar->addAction(menuSimular->menuAction());
        menuCircuito->addAction(actionNovo);
        menuCircuito->addAction(actionLer);
        menuCircuito->addAction(actionSalvar);
        menuCircuito->addSeparator();
        menuCircuito->addAction(actionSair);
        menuSimular->addAction(actionGerar_tabela);

        retranslateUi(MainCircuito);

        QMetaObject::connectSlotsByName(MainCircuito);
    } // setupUi

    void retranslateUi(QMainWindow *MainCircuito)
    {
        MainCircuito->setWindowTitle(QApplication::translate("MainCircuito", "Simulador de Circuitos Digitais", Q_NULLPTR));
        actionNovo->setText(QApplication::translate("MainCircuito", "Novo...", Q_NULLPTR));
        actionLer->setText(QApplication::translate("MainCircuito", "Ler...", Q_NULLPTR));
        actionSalvar->setText(QApplication::translate("MainCircuito", "Salvar...", Q_NULLPTR));
        actionSair->setText(QApplication::translate("MainCircuito", "Sair", Q_NULLPTR));
        actionGerar_tabela->setText(QApplication::translate("MainCircuito", "Gerar tabela", Q_NULLPTR));
        labelPortas->setText(QApplication::translate("MainCircuito", "PORTAS E CONEX\303\225ES", Q_NULLPTR));
        labelSaidas->setText(QApplication::translate("MainCircuito", "SA\303\215DAS", Q_NULLPTR));
        labelCircuito->setText(QApplication::translate("MainCircuito", "CIRCUITO", Q_NULLPTR));
        labelCircuito_2->setText(QApplication::translate("MainCircuito", "TABELA VERDADE", Q_NULLPTR));
        menuCircuito->setTitle(QApplication::translate("MainCircuito", "Circuito", Q_NULLPTR));
        menuSimular->setTitle(QApplication::translate("MainCircuito", "Simular", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainCircuito: public Ui_MainCircuito {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINCIRCUITO_H
