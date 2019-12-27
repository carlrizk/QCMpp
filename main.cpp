#include "mainwindow.h"

#include <QApplication>
#include "reponse.h"
#include "question.h"
#include <string>
#include <fstream>
#include <iostream>
using namespace QCMpp;

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
//    return a.exec();

    Reponse r1("first choice", true);
    Reponse r2("second choice",false);
    Reponse r3("thrid choice", false);
    Question q1("Reponse?");
    q1.add_choice(r1);
    q1.add_choice(r2);
    q1.add_choice(r3);

    Reponse r5;


    return 0;

}
