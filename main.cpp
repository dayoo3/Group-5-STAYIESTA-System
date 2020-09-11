#include "loginpanel.h"
#include "dblogin.h"
#include "allclasses.h"
#include <QApplication>
#include <QDebug>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    LoginPanel lp;
    lp.show();

    return a.exec();
}
