QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AdminCourseView.cpp \
    AdminEventView.cpp \
    StudentCourseView.cpp \
    StudentEventView.cpp \
    activity.cpp \
    activityrepository.cpp \
    app.cpp \
    authenticationrepository.cpp \
    course.cpp \
    courserepository.cpp \
    createcourseview.cpp \
    createeventview.cpp \
    enrollmentrepository.cpp \
    eventrepository.cpp \
    instructor.cpp \
    main.cpp \
    studentprofile.cpp \
    user.cpp \
    student.cpp \
    admin.cpp \
    event.cpp \
    email.cpp \
    utils.cpp \
    mainwindow.cpp \
    register.cpp \
    admin_page.cpp \
    dashboard.cpp

HEADERS += mainwindow.h \
    AdminCourseView.h \
    AdminEventView.h \
    StudentCourseView.h \
    StudentEventView.h \
    activity.h \
    activityrepository.h \
    app.h \
    authenticationrepository.h \
    course.h \
    courserepository.h \
    createcourseview.h \
    createeventview.h \
    enrollmentrepository.h \
    eventrepository.h \
    instructor.h \
    studentprofile.h \
    user.h \
    student.h \
    admin.h \
    event.h \
    email.h \
    utils.h \
    register.h \
    admin_page.h \
    admin_page.h \
    dashboard.h


FORMS += mainwindow.ui \
    AdminEventView.ui \
    StudentCourseView.ui \
    StudentEventView.ui \
    admincourseview.ui \
    createcourseview.ui \
    createeventview.ui \
    register.ui \
    admin_page.ui \
    dashboard.ui \
    studentprofile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    admins-info.csv \
    courses-prerequisites.csv \
    courses.csv \
    events.csv \
    instructors.csv \
    students-courses.csv \
    students-events.csv \
    students-info.csv \
    users-auth.csv

RESOURCES +=
