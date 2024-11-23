#include "mainwindow.h"
#include "courserepository.h"
#include "enrollmentrepository.h"
#include "eventrepository.h"
#include "student.h"
#include "ui_mainwindow.h"
#include "authenticationrepository.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}
