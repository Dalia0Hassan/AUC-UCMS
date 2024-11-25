#include "dashboard.h"
#include "app.h"
#include "course.h"
#include "qpushbutton.h"
#include "ui_dashboard.h"
#include "adminloginpage.h"
#include "utils.h"
#include <QLabel>
#include <QLayout>


extern App *app;

Dashboard::Dashboard(QWidget *parent, UserType type)
    : QDialog(parent)
    , ui(new Ui::Dashboard)
{
    ui->setupUi(this);

    if (type == UserType::Student) {
        // Pull the courses and events from the app
        QList<Course*> courses = app->enrollment_manager->get_student_courses(app->auth_manager->get_current_user()->get_id());
        QList<Event*> events = app->enrollment_manager->get_student_events(app->auth_manager->get_current_user()->get_id());

        qDebug() << "Courses: " << courses.size();
        qDebug() << "Events: " << events.size();
        // Display courses and events dyanmically in their frames
        QFrame *frame_courses = ui->frame_courses;
        QVBoxLayout *frameLayout = new QVBoxLayout(frame_courses);
        for (auto &course : courses) {
            QHBoxLayout *childLayout1 = new QHBoxLayout();
            QHBoxLayout *childLayout2 = new QHBoxLayout();
            QVBoxLayout *childLayout3 = new QVBoxLayout();

            QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            frameLayout->addItem(spacer); // Add a spacer item between the child layouts

            QLabel *firstRow = new QLabel(
                course->get_title() + "  (" + app->enrollment_manager->get_instructor(course->get_instructor_id()).get_name() + ")",
                frame_courses);
            firstRow->setStyleSheet("font-weight: bold;");
            childLayout1->addWidget(firstRow);

            QString s = "Days: ";
            for(auto &day : course->get_days()) {
                s += days[day].left(3) + " ";
            }
            QLabel *secondRow = new QLabel(
                course->get_start_time().toString("hh:mm") + " - " + course->get_end_time().toString("hh:mm") + " - " + s,
                frame_courses);
            childLayout2->addWidget(secondRow);

            QPushButton *btn = new QPushButton("Drop", frame_courses);
            childLayout3->addWidget(btn);

            // Add child layouts to the frame's layout
            frameLayout->insertLayout(0, childLayout3);
            frameLayout->insertLayout(0, childLayout2);
            frameLayout->insertLayout(0, childLayout1);

            // Set the layout for the frame (optional if you want to reset it)
        }

        QFrame *frame_events = ui->frame_events;
        QVBoxLayout *frameLayout2 = new QVBoxLayout(frame_events);
        for(auto &event : events) {
            QHBoxLayout *childLayout1 = new QHBoxLayout();
            QHBoxLayout *childLayout2 = new QHBoxLayout();
            QVBoxLayout *childLayout3 = new QVBoxLayout();

            QSpacerItem *spacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
            frameLayout2->addItem(spacer); // Add a spacer item between the child layouts

            QLabel *firstRow = new QLabel(
                event->get_title() + "  (" + app->enrollment_manager->get_instructor(event->get_speaker_id()).get_name() + ")",
                frame_events);
            firstRow->setStyleSheet("font-weight: bold;");
            childLayout1->addWidget(firstRow);

            QLabel *secondRow = new QLabel(
                event->get_location() + "  ("  + event->get_start_time().toString("hh:mm") + " - " + event->get_end_time().toString("hh:mm") + ")",
                frame_events);
            childLayout2->addWidget(secondRow);

            QPushButton *btn = new QPushButton("Drop", frame_events);
            childLayout3->addWidget(btn);

            // Add child layouts to the frame's layout
            frameLayout2->insertLayout(0, childLayout3);
            frameLayout2->insertLayout(0, childLayout2);
            frameLayout2->insertLayout(0, childLayout1);

        }

    }

    load_logout_button();

}

void Dashboard::load_logout_button()
{
    QPushButton *logout_button = new QPushButton("Logout", this);
    logout_button->setGeometry(width() - 10, 10, 100, 30);
    // Connect button to logout method
    connect(logout_button, &QPushButton::clicked, this, [this](){
        app->auth_manager->logout();  // Accessing AuthManager's logout function through App instance
    });
    // Open the login window
    hide();
    Adminloginpage *login = new Adminloginpage(this);
    login->show();
}


Dashboard::~Dashboard()
{
    delete ui;
}
