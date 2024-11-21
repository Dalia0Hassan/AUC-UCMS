#ifndef UCMS_ADMIN_H
#define UCMS_ADMIN_H

#include <QString>
#include "user.h"
#include "utils.h"

class Admin : public User {
    AdminType type;
    double salary;
public:
    Admin(QString username, QString password, QString name, QString email, AdminType type, QString adress, QString phone, QString first_name, QString last_name, double salary );

    // Getters
    AdminType get_type() const ;
    double get_salary() const ;

    // Setters
    void set_type (AdminType type);
    void set_salary(double salary);

};




#endif //UCMS_ADMIN_H
