#include <QApplication>
#include "admin_ui.h"

#include "application.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   QCMpp::Application app("data.qcmpp");


   return a.exec();
}
