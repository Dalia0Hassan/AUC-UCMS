QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD
=======
    activity.cpp \
    activityrepository.cpp \
    course.cpp \
    courserepository.cpp \
>>>>>>> 16651c3 (Introduced a base class (Activity) for Event and Course, Created respository for Activity and Course, Finished the logic for loading activities (courses/events))
    main.cpp \
    user.cpp \
    student.cpp \
    admin.cpp \
    event.cpp \
    email.cpp \
    utils.cpp \
    mainwindow.cpp

HEADERS += mainwindow.h \
<<<<<<< HEAD
=======
    activity.h \
    activityrepository.h \
    course.h \
    courserepository.h \
>>>>>>> 16651c3 (Introduced a base class (Activity) for Event and Course, Created respository for Activity and Course, Finished the logic for loading activities (courses/events))
    user.h \
    student.h \
    admin.h \
    event.h \
    email.h \
    utils.h \

FORMS += mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    courses-prerequisites.csv \
    courses.csv \
