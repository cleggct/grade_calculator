#include "lifedlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    lifedlg w;
    w.show();

    return a.exec();
}
