#include "../headers/user.h"
#include "utils.h"
#ifndef UCMS_STUDENT_H
#define UCMS_STUDENT_H

class Student : public User {
    double gpa ;
    ClassStanding class_standing;

public :
    Student(string , string , string , string , double , ClassStanding );
    Student();
    double get_gpa();
    ClassStanding get_class_standing();
    void set_gpa(double);
    void set_class_standing(ClassStanding);
    string to_string();
    bool operator==(User u);
    bool operator!=(User u);
};
#endif //UCMS_STUDENT_H
