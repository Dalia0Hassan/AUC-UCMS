#include "adminmanageprerequisites.h"
#include "ui_adminmanageprerequisites.h"
#include "utils.h"


AdminManagePrerequisites::AdminManagePrerequisites(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminManagePrerequisites)
{
    ui->setupUi(this);
    load_logout_button(this);
}

AdminManagePrerequisites::~AdminManagePrerequisites()
{
    delete ui;
}
