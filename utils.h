#ifndef UTILS_H
#define UTILS_H

#include <QString>
#include <QStringList>
#include <QList>


// Enums
enum ClassStanding {
    Freshman ,Sophomore  , Junior ,  Senior
};

enum UserType {
    Admin , Student
};

enum ActivityType {
    Course, Event
};

enum CourseDataRow {
    Id, Title , Description, Capacity, Location, StartDate, EndDate, Days, StartTime, EndTime, InstructorId
};

enum Day {
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
};

<<<<<<< HEAD
enum AdminType {
    Instructor, TA
};
=======
QStringList parseCsvLine(const QString &line);
>>>>>>> 16651c3 (Introduced a base class (Activity) for Event and Course, Created respository for Activity and Course, Finished the logic for loading activities (courses/events))

// Functions


#endif // UTILS_H
