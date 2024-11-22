#include "course.h"

Course::Course(QString title, QString description, QString location,
               QUuid id, QUuid instructor_id, int capcity,
               QDate start_date, QDate end_date, QSet<Day> days, QTime start_time, QTime end_time)
: Activity(title, description, location, id, capcity, start_time, end_time, ActivityType::Course) {
    set_instructor_id(instructor_id);
    set_start_date(start_date);
    set_end_date(end_date);
    set_days(days);
}

// Getters
QUuid Course::get_instructor_id() const {
    return instructor_id;
}

QDate Course::get_start_date() const {
    return start_date;
}

QDate Course::get_end_date() const {
    return end_date;
}

QSet<Day> Course::get_days() const {
    return days;
}

// Setters
void Course::set_instructor_id(QUuid instructor_id) {
    this->instructor_id = instructor_id;
}

void Course::set_start_date(QDate start_date) {
    this->start_date = start_date;
}

void Course::set_end_date(QDate end_date) {
    this->end_date = end_date;
}

void Course::set_days(QSet<Day> days) {
    this->days = days;
}
