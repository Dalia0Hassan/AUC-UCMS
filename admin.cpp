#include "admin.h"
#include "user.h"

Admin::Admin(QString username, QString password, QString name, QString email, AdminType type, QString adress,
             QString phone, QString first_name, QString last_name, double salary ) : User(username, password,  first_name , last_name , email, phone, adress) {
    set_salary(salary);
    set_type(type);
}

// Setters
void Admin::set_type(AdminType type) {
    this->type = type;
}
// Todo : Ensure salary is not negative
void Admin::set_salary(double salary) {
    this->salary = salary;
}


// Getters
AdminType Admin::get_type() const {
    return type;
}
double Admin::get_salary()  const {
    return salary;
}
