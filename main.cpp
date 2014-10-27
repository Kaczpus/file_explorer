#include "file_explorer.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    File_explorer w;
    w.show();

    return a.exec();
}
