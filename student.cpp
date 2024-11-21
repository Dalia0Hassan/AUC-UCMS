#include "student.h"
#include <QString>

Student::Student(QString first_name, QString last_name, QString email, QString phone_number, double gpa, ClassStanding class_standing) :
    User("username", "password", first_name, last_name, email, phone_number, "Address") {
    this->gpa = gpa;
    this->class_standing = class_standing;
}


void Student::set_class_standing(ClassStanding class_standing) {
    this->class_standing = class_standing;
}

void Student::set_gpa(double gpa) {
    if ( gpa < 0 || gpa > 4){
        throw std::invalid_argument("Invalid GPA");
    }
    this->gpa = gpa;
}

