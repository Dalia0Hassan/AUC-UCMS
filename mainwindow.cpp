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
    EnrollmentRepository er;
    // er.drop_course(QUuid("{082e3fc9-4926-4fbe-ad96-ca7a03a77fc8}"), QUuid("{5e057939-f493-4ae6-8845-5feb1adc9601}"));
    er.enroll_in_event(QUuid("{efa508d7-7ee4-442b-88da-268a8ff135ed}"), QUuid("{bbca404c-4d93-43a9-af49-c102d62ac7b2}"));

    QList<QUuid> events = er.get_student_events(QUuid("{efa508d7-7ee4-442b-88da-268a8ff135ed}"));
    for (auto &event : events)
        qDebug() << event.toString();


    // AuthenticationRepository ar;
    // ar.signup(
    //     new class Student(
    //         QUuid::createUuid(), "johndoe", "password",
    //         "John", "Doe", "email@email.com", "23456789", "Somefuckingplace", 3.5, ClassStanding::Freshman
    //     )
    //     );

}

MainWindow::~MainWindow()
{
    delete ui;
}
