#include <QApplication>
#include "admin_ui.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

    Admin_ui w;
    w.show();

   return a.exec();
}
