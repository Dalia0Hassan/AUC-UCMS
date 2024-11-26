#ifndef ADMINCOURSEVIEW_H
#define ADMINCOURSEVIEW_H

#include <QDialog>
#include <QLineEdit>
#include <QLabel>
#include <QLayout>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QDateEdit>

namespace Ui {
class AdminCourseView;
}

class AdminCourseView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminCourseView(QWidget *parent = nullptr);
    ~AdminCourseView();

private:
    Ui::AdminCourseView *ui;

};

#endif // ADMINCOURSEVIEW_H
