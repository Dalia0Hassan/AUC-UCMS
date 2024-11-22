#include "mainwindow.h"
#include "courserepository.h"
#include "eventrepository.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    CourseRepository courseRepository;
}

MainWindow::~MainWindow()
{
    delete ui;
}
