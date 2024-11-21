#ifndef UCMS_EVENT_H
#define UCMS_EVENT_H

#include <QDateTime>


class Event {
    QString title , description;
    QDateTime date_time ;
    int capacity;

public :
    Event ( QString , QString , QDateTime , int ) ;
    QString get_title();
    QString get_description();
    QDateTime get_date_time();
    int get_capacity();
    void set_title(QString);
    void set_description(QString);
    void set_date_time(QDateTime);



};

#endif //UCMS_EVENT_H


/*

1) IMPLEMENTATION.

2) SERVICES:
Authorization => Sign up, Sign in, Sign out, Modify account information.
Course => Create, Modify, Delete, Get, Enroll, Drop.
Event => Create, Modify, Delete, Get, Enroll, Drop.

3) DATA FILES:
users-auth.csv => username, id, email, password
users-profile => id, first_name, last_name, phone_number, address, type
students.csv => id, gpa, class_standing
admins.csv => id, title (Mr, Mrs, Dr, Prof, etc), department (IT, HR, etc), position (TA, Instructor, etc).
courses.csv => id, title, description, instructor_id, capacity, start_date, end_date, days, time, location.
events.csv => id, title, description, date_time, capacity, location.

*/
