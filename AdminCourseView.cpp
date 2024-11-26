#include "AdminCourseView.h"
#include "ui_AdminCourseView.h"
#include "utils.h"

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
