#include "mainwindow.h"
#include "courserepository.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    qDebug() << "Main Window Created";
    CourseRepository course_repo;
}

MainWindow::~MainWindow()
{
    delete ui;
}
