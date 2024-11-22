#include "mainwindow.h"
#include "eventrepository.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Main Window Created";
    EventRepository eventRepository = EventRepository();
}

MainWindow::~MainWindow()
{
    delete ui;
}
