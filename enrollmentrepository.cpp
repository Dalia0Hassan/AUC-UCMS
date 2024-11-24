#include "enrollmentrepository.h"
#include "qdir.h"
#include "utils.h"

EnrollmentRepository::EnrollmentRepository() {}

void EnrollmentRepository::enroll_in_course(QString student_id, QUuid course_id) {
    enroll(student_id, course_id, ActivityType::CourseType);
}

void EnrollmentRepository::enroll_in_event(QString student_id, QUuid event_id) {
    enroll(student_id, event_id, ActivityType::EventType);
}

void EnrollmentRepository::drop_course(QString student_id, QUuid course_id) {
    drop(student_id, course_id, ActivityType::CourseType);
}

void EnrollmentRepository::drop_event(QString student_id, QUuid event_id) {
    drop(student_id, event_id, ActivityType::EventType);
}

QList<QUuid> EnrollmentRepository::get_student_courses(QString student_id) {
    return get_student_activities(student_id, ActivityType::CourseType);
}

QList<QUuid> EnrollmentRepository::get_student_events(QString student_id) {
    return get_student_activities(student_id, ActivityType::EventType);
}

QList<class Instructor> EnrollmentRepository::get_instructors() {
    QFile file(getCurrentDir() + "/instructors.csv");
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error(("Could not open file: " + file.fileName() + ", Error: " + file.errorString()).toStdString());

    QTextStream stream(&file);
    QList<class Instructor> instructors;
    while(!stream.atEnd()) {
        QStringList row = stream.readLine().split(",");
        class Instructor instructor(row[0], row[1]);
        instructors.append(instructor);
    }

    file.close();
    return instructors;

}

void EnrollmentRepository::enroll(QString student_id, QUuid activityId, ActivityType type) {
    QString filename = type == ActivityType::CourseType ? "students-courses.csv" : "students-events.csv";
    QFile file(getCurrentDir() + "/" + filename);

    if (!file.open(QIODevice::ReadWrite))
        throw std::runtime_error(("Could not open file: " + file.fileName() + ", Error: " + file.errorString()).toStdString());

    QTextStream stream(&file);
    QStringList newData;
    bool found = false;
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.split(",")[0] == student_id) {
            found = true;
            line += "," + activityId.toString();
        }
        newData.append(line);
    }

    if (!found)
        throw std::runtime_error("Student not found");

    // Write the new data
    file.resize(0);
    for (auto &line : newData)
        stream << line << "\n";

    file.close();
}

void EnrollmentRepository::drop(QString student_id, QUuid course_id, ActivityType type) {
    QString filename = type == ActivityType::CourseType ? "students-courses.csv" : "students-events.csv";
    QFile file(getCurrentDir() + "/" + filename);

    if (!file.open(QIODevice::ReadWrite))
        throw std::runtime_error(("Could not open file: " + file.fileName() + ", Error: " + file.errorString()).toStdString());

    QTextStream stream(&file);
    QStringList newData;
    bool found = false;
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.split(",")[0] == student_id) {
            found = true;
            QStringList activities = line.split(",");
            activities.removeAll(course_id.toString());
            line = activities.join(",");
        }
        newData.append(line);
    }

    if (!found)
        throw std::runtime_error("Student not found");

    // Write the new data
    file.resize(0);
    for (auto &line : newData)
        stream << line << "\n";

    file.close();

}

QList<QUuid> EnrollmentRepository::get_student_activities(QString student_id, ActivityType type) {
    QString filename = type == ActivityType::CourseType ? "students-courses.csv" : "students-events.csv";
    QFile file(getCurrentDir() + "/" + filename);

    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error(("Could not open file: " + file.fileName() + ", Error: " + file.errorString()).toStdString());

    QTextStream stream(&file);
    QStringList activities;
    while(!stream.atEnd()) {
        QString line = stream.readLine();
        if (line.split(",")[0] == student_id)
            activities = line.split(",");
    }

    file.close();

    QList<QUuid> result;
    for (int i = 1; i < activities.size(); i++)
        result.append(QUuid(activities[i]));

    return result;
}
