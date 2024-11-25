#include "instructor.h"

Instructor::Instructor(QUuid id, QString name, QString department) {
    this->name = name;
    this->department = department;
    this->id = id;
}

QString Instructor::get_name() const {
    return name;
}

QString Instructor::get_department() const {
    return department;
}

QUuid Instructor::get_id() const {
    return id;
}
