
#include "../headers/student.h"

Student::Student(string first_name, string last_name, string email, string phone_number, double gpa, ClassStanding class_standing) : User(first_name, last_name, email, phone_number) {
    this->gpa = gpa;
    this->class_standing = class_standing;
}


void Student::set_class_standing(ClassStanding class_standing) {
    this->class_standing = class_standing;
}

void Student::set_gpa(double gpa) {
    if ( gpa < 0 || gpa > 4){
        throw invalid_argument("Invalid GPA");
    }
    this->gpa = gpa;
}

