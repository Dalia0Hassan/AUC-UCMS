#include "mainwindow.h"
#include "app.h"
#include "ui_mainwindow.h"
#include "register.h"
#include "utils.h"

extern App *app;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QPixmap heroImage(getCurrentDir() + "/grade.png"); // Ensure path is valid
    if (!heroImage.isNull()) {
        int w = ui->label_hero_image->width();
        int h = ui->label_hero_image->height();
        ui->label_hero_image->setPixmap(heroImage.scaled(w, h, Qt::KeepAspectRatio));
    } else {
        qDebug() << "Failed to load image: grade.png";
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_Register_clicked()
{
    hide();
    Register * registerwindow= new Register(this);
    registerwindow->show();
}


void MainWindow::on_pushButton_Login_clicked()
{
    app->auth_manager->login(ui->lineEdit_username->text(), ui->lineEdit_password->text());
}
