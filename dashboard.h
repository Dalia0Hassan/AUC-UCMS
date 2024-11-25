#ifndef DASHBOARD_H
#define DASHBOARD_H

#include "utils.h"
#include <QDialog>

namespace Ui {
class Dashboard;
}

class Dashboard : public QDialog
{
    Q_OBJECT

public:
    explicit Dashboard(QWidget *parent = nullptr, UserType type = UserType::Student);
    ~Dashboard();

private:
    Ui::Dashboard *ui;
    void display(UserType type);
};

#endif // DASHBOARD_H
