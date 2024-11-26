#ifndef STUDENTCOURSEVIEW_H
#define STUDENTCOURSEVIEW_H

#include <QWidget>
#include <QList>
#include <QMessageBox>
#include <course.h>

// Define a Course struct for managing course data ( replace this with the actual Course model)

namespace Ui {
class StudentCourseView;
}


    class StudentCourseView : public QDialog {

    Q_OBJECT

public:
    explicit StudentCourseView(QWidget* parent = nullptr);
    ~StudentCourseView();

private slots:
    void onRegisterButtonClicked(); // Slot for handling registration button click

private:
    Ui::StudentCourseView* ui;       // Pointer to UI elements
    QList<Course> availableCourses; // List of courses to display (replace with the actual data in files)

    void populateCourseTable();     // Method to populate the course table

    bool registerCourse(); // (replace with the registeration logic)
};

#endif // STUDENTCOURSEVIEW_H
