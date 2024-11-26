#ifndef ADMINEVENTVIEW_H
#define ADMINEVENTVIEW_H

#include <QDialog>

namespace Ui {
class AdminEventView;
}

class AdminEventView : public QDialog
{
    Q_OBJECT

public:
    explicit AdminEventView(QWidget *parent = nullptr);
    ~AdminEventView();

private slots:
    void on_AddEvent_Button_clicked();

private:
    Ui::AdminEventView *ui;
};

#endif // ADMINEVENTVIEW_H
