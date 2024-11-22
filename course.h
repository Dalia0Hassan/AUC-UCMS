#ifndef COURSE_H
#define COURSE_H

#include "activity.h"
#include "quuid.h"
#include "utils.h"
#include <QString>
#include <QDate>
#include <QTime>
#include <QList>
#include <quuid.h>


class Course : public Activity
{
private:
    QUuid instructor_id;
    QDate start_date, end_date;
    QSet<Day> days;
public:
    Course(
        QString title, QString description, QString location, QUuid id,
        QUuid instructor_id, int capcity, QDate start_date,
        QDate end_date, QSet<Day> days, QTime start_time, QTime end_time
    );

    // Getters
    QUuid get_instructor_id() const;
    QDate get_start_date() const;
    QDate get_end_date() const;
    QSet<Day> get_days() const;

private:
    // Setters
    void set_instructor_id(QUuid);
    void set_start_date(QDate);
    void set_end_date(QDate);
    void set_days(QSet<Day>);

    // Friend classes
    // friend class CourseController;
    // friend class CourseRepository;

};

#endif // COURSE_H
