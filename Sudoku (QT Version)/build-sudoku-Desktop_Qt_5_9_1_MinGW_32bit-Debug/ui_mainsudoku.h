/********************************************************************************
** Form generated from reading UI file 'mainsudoku.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINSUDOKU_H
#define UI_MAINSUDOKU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainSudoku
{
public:
    QAction *actionReiniciar;
    QAction *actionSair;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelsudoku;
    QTableWidget *tableSudoku;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QMenuBar *menuBar;
    QMenu *menuArquivos;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainSudoku)
    {
        if (MainSudoku->objectName().isEmpty())
            MainSudoku->setObjectName(QStringLiteral("MainSudoku"));
        MainSudoku->resize(709, 399);
        actionReiniciar = new QAction(MainSudoku);
        actionReiniciar->setObjectName(QStringLiteral("actionReiniciar"));
        actionSair = new QAction(MainSudoku);
        actionSair->setObjectName(QStringLiteral("actionSair"));
        centralWidget = new QWidget(MainSudoku);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelsudoku = new QLabel(centralWidget);
        labelsudoku->setObjectName(QStringLiteral("labelsudoku"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        labelsudoku->setFont(font);
        labelsudoku->setCursor(QCursor(Qt::CrossCursor));
        labelsudoku->setToolTipDuration(-1);
        labelsudoku->setScaledContents(false);
        labelsudoku->setAlignment(Qt::AlignCenter);
        labelsudoku->setMargin(1);

        verticalLayout->addWidget(labelsudoku);

        tableSudoku = new QTableWidget(centralWidget);
        if (tableSudoku->columnCount() < 9)
            tableSudoku->setColumnCount(9);
        if (tableSudoku->rowCount() < 9)
            tableSudoku->setRowCount(9);
        tableSudoku->setObjectName(QStringLiteral("tableSudoku"));
        tableSudoku->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableSudoku->sizePolicy().hasHeightForWidth());
        tableSudoku->setSizePolicy(sizePolicy);
        tableSudoku->setMinimumSize(QSize(691, 0));
        tableSudoku->setMaximumSize(QSize(691, 500));
        tableSudoku->setSizeIncrement(QSize(100, 100));
        tableSudoku->setBaseSize(QSize(0, 0));
        tableSudoku->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableSudoku->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        tableSudoku->setAutoScroll(false);
        tableSudoku->setAutoScrollMargin(16);
        tableSudoku->setProperty("showDropIndicator", QVariant(true));
        tableSudoku->setDragEnabled(false);
        tableSudoku->setAlternatingRowColors(false);
        tableSudoku->setGridStyle(Qt::SolidLine);
        tableSudoku->setSortingEnabled(false);
        tableSudoku->setWordWrap(true);
        tableSudoku->setCornerButtonEnabled(true);
        tableSudoku->setRowCount(9);
        tableSudoku->setColumnCount(9);
        tableSudoku->horizontalHeader()->setVisible(false);
        tableSudoku->horizontalHeader()->setDefaultSectionSize(100);
        tableSudoku->horizontalHeader()->setHighlightSections(true);
        tableSudoku->verticalHeader()->setVisible(false);
        tableSudoku->verticalHeader()->setMinimumSectionSize(23);

        verticalLayout->addWidget(tableSudoku);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);

        MainSudoku->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainSudoku);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 21));
        menuArquivos = new QMenu(menuBar);
        menuArquivos->setObjectName(QStringLiteral("menuArquivos"));
        MainSudoku->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainSudoku);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainSudoku->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainSudoku);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainSudoku->setStatusBar(statusBar);

        menuBar->addAction(menuArquivos->menuAction());
        menuArquivos->addAction(actionReiniciar);
        menuArquivos->addSeparator();
        menuArquivos->addAction(actionSair);

        retranslateUi(MainSudoku);

        QMetaObject::connectSlotsByName(MainSudoku);
    } // setupUi

    void retranslateUi(QMainWindow *MainSudoku)
    {
        MainSudoku->setWindowTitle(QApplication::translate("MainSudoku", "MainSudoku", Q_NULLPTR));
        actionReiniciar->setText(QApplication::translate("MainSudoku", "Reiniciar", Q_NULLPTR));
        actionSair->setText(QApplication::translate("MainSudoku", "Sair", Q_NULLPTR));
        labelsudoku->setText(QApplication::translate("MainSudoku", "SUDOKU", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainSudoku", "Jogar", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainSudoku", "Resolver", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainSudoku", "Sair", Q_NULLPTR));
        menuArquivos->setTitle(QApplication::translate("MainSudoku", "Arquivos", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainSudoku: public Ui_MainSudoku {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINSUDOKU_H
