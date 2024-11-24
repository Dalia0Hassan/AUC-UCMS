#include "register.h"
#include "admin_page.h"
#include "app.h"
#include "ui_register.h"
#include "mainwindow.h"
#include "student.h"
#include "admin.h"

extern App *app;

Register::Register(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Register)
{
    ui->setupUi(this);
}

Register::~Register()
{
    delete ui;
}

void Register::on_pushButton_clicked()
{
    hide();
    MainWindow*mainwindow= new MainWindow(this);
    mainwindow->show();
}


void Register::on_pushButton_register_clicked()
{
    // Get the values from the input fields
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();
    QString first_name = ui->lineEdit_firstname->text();
    QString last_name = ui->lineEdit_lastname->text();
    QString email = ui->lineEdit_email->text();
    QString phone_number = ui->lineEdit_phone->text();
    QString id = ui->lineEdit_id->text();
    QString type = ui->comboBox_user_type->currentText();

    // Create a new user
    app->auth_manager->signup(id, username, password, first_name, last_name, email, phone_number, type);

}


void Register::on_pushButton_login_page_clicked()
{
    hide();
    MainWindow *mainwindow= new MainWindow(this);
    mainwindow->show();
}

