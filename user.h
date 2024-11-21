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
    void set_username(QString username);
    void set_password(QString password);
    QString get_username();
    QString get_password();
    QString get_name();
    Email get_email();
    QString get_phone_number();
    QString get_address();
};



#endif // USER_H
