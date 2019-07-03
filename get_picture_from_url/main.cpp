#include "get_url_pix.h"
#include <QApplication>
//#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    get_url_pix w;
    w.show();

    return a.exec();
}
