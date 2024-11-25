#include "StudentCourseView.h"
#include "ui_StudentCourseView.h"

#include "utils.h"

StudentCourseView::StudentCourseView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentCourseView)
{
    ui->setupUi(this);
}

StudentCourseView::~StudentCourseView()
{
    delete ui;
    load_logout_button(this);
}
