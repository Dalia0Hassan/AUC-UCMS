#include "mainwindow.h"
#include <QApplication>
#include <QFile>
#include <QUuid>
#include "app.h"

App *app;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow *w = new MainWindow();
    w->show();

    app = new App();
    app->set_current_window(w);

    return a.exec();
}
