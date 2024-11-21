#include "user.h"
#include "email.h"

User::User(QString username, QString password, QString first_name, QString last_name, QString s, QString phone_number,
               QString address ){
    this->username = username;
    this->password = password;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email = Email(email);
    this->phone_number = phone_number;
    this->address = address;
}
