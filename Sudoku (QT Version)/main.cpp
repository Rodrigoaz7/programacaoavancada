#include "mainsudoku.h"
#include "sudoku.h"
#include <QApplication>

Sudoku S;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainSudoku w;

    w.show();

    return a.exec();
}
