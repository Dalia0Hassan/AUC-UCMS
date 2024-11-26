#include "admin.h"
#include "user.h"

Admin::Admin(QString id, QString username, QString password, QString first_name, QString last_name, QString email,
             QString phone, AdminRole role, double salary ) : User(id, username, password,  first_name , last_name , email, phone, UserType::Admin) {
    set_salary(salary);
    set_role(role);
}

// Setters
void Admin::set_role(AdminRole role) {
    this->role = role;
}
// Todo : Ensure salary is not negative
void Admin::set_salary(double salary) {
    this->salary = salary;
}


// Getters
AdminRole Admin::get_role() const {
    return role;
}
double Admin::get_salary()  const {
    return salary;
}
