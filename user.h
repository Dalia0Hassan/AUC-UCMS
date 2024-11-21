#ifndef USER_H
#define USER_H
#include <QString>
#include "email.h"


class User
{
    QString username , password , ID ;
    QString first_name , last_name ;
    Email email ;
    QString phone_number;
    QString address;
public:
    User(QString username, QString password, QString first_name, QString last_name, QString email, QString phone_number,
         QString address ) ;
    // Setters
    void set_username(QString username);
    void set_password(QString password);
    void set_email(QString email);
    void set_phone_number(QString phone_number);
    void set_address(QString address);
    void set_first_name(QString first_name);
    void set_last_name(QString last_name);

    // Getters
    QString get_username() const ;
    QString get_password() const ;
    QString get_name() const ;
    QString get_email() const ;
    QString get_phone_number() const ;
    QString get_address() const ;


    // operator overloading
    bool operator==(const User& user);
    bool operator!=(const User& user);

};



#endif // USER_H
