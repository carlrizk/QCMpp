// Carl Rizk 180898
// Rima Al Ghossein
// Anthony Jeitany

#include <QApplication>
#include "adminwindow.h"

#include "application.h"

int main(int argc, char *argv[])
{

   QApplication a(argc, argv);

   QCMpp::Application app("data.qcmpp");


   return a.exec();
}
