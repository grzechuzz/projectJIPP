#include "TicketsManager.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TicketsManager w;
    w.show();
    return a.exec();
}
