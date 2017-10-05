#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->horizontalSlider, SIGNAL (valueChanged(int)), ui->progressBar, SLOT (setValue(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
