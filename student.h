#ifndef UCMS_STUDENT_H
#define UCMS_STUDENT_H
#include "user.h"
#include "utils.h"

class Student : public User {
    double gpa ;
    ClassStanding class_standing;

public :
    Student(QString , QString , QString , QString , double , ClassStanding );
    Student();
    double get_gpa();
    ClassStanding get_class_standing();
    void set_gpa(double);
    void set_class_standing(ClassStanding);
    QString to_QString();
    bool operator==(User);
    bool operator!=(User);
};
#endif //UCMS_STUDENT_H
