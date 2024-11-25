#include "AdminEventView.h"
#include "ui_AdminEventView.h"
#include "utils.h"

AdminEventView::AdminEventView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminEventView)
{
    ui->setupUi(this);
    load_logout_button(this);
}

AdminEventView::~AdminEventView()
{
    delete ui;
}

// void AdminEventView::on_Events_TableWidget_cellActivated(int row, int column)
// {

// }

