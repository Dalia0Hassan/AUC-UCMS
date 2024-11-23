#include "mainwindow.h"
#include "courserepository.h"
#include "eventrepository.h"
#include "student.h"
#include "ui_mainwindow.h"
#include "authenticationrepository.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    AuthenticationRepository authRepo;
    // authRepo.signup(new class Student(
    //     QUuid::createUuid(), "Ahmed", "123456", "Ahmed", "Ali",
    //     "somebody@something.somedomain", "12345678", "Somewhere in our vast universe", 2.2, ClassStanding::Freshman
    //     ));
    User* user = authRepo.login("Ahmed", "123456");
    qDebug() << user->get_email();
    qDebug() << user->get_firstname();
    qDebug() << user->get_lastname();
    qDebug() << user->get_phone_number();
    qDebug() << user->get_address();
    qDebug() << user->get_username();
    qDebug() << user->get_password();

}

MainWindow::~MainWindow()
{
    delete ui;
}
