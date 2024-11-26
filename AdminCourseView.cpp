#include "AdminCourseView.h"
#include "ui_AdminCourseView.h"
#include "utils.h"
#include <QLineEdit>
#include <QDateEdit>
#include <QTimeEdit>
#include <QPushButton>
#include <QComboBox>
#include <QSet>
#include "course.h"
#include <QMessageBox>
#include <QWidget>
#include <QMainWindow>
#include "app.h"


extern App *app;

AdminCourseView::AdminCourseView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminCourseView)
{
    ui->setupUi(this);
    load_logout_button(this);
}

AdminCourseView::~AdminCourseView()
{
    delete ui;
}
