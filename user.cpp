#include "user.h"
#include "email.h"
#include <QUuid>

User::User(QString username, QString password, QString first_name, QString last_name, QString email , QString phone_number,
               QString address ){
    if ( Email::is_valid_email(email)){
        throw std::invalid_argument("Invalid email");
    }
    set_email(email);
    set_username(username);
    set_password(password);
    set_phone_number(phone_number);
    set_address(address);
    set_first_name(first_name);
    set_last_name(last_name);

    // Generate unique ID
    this->ID = QUuid::createUuid().toString();

}



// Setters
// TODO : Ensure unique username
void User::set_username(QString username) {
    this->username = username;
}

// TODO : Hash password and Ensure password is strong
void User::set_password(QString password) {
    this->password = password;
}

void User::set_email(QString email) {
    this->email.set_email(email);
}

// TODO : Ensure valid phone number + Unique phone number
void User::set_phone_number(QString phone_number) {
    this->phone_number = phone_number;
}

void User::set_address(QString address) {
    this->address = address;
}

void User::set_first_name(QString first_name) {
    this->first_name = first_name;
}

void User::set_last_name(QString last_name) {
    this->last_name = last_name;
}





// Getters
QString User::get_username() const{
    return username;
}

QString User::get_password() const {
    return password;
}

QString User::get_name() const {
    return first_name + " " + last_name;
}

QString User::get_email() const {
    return email.get_email();
}
// TODO : Ensure valid phone number + Unique phone number
QString User::get_phone_number() const  {
    return phone_number;
}
QString User::get_address()const  {
    return address;
}




// Overloaded operators
bool User::operator==( const User &s) {
    return this->get_username() == s.get_username();
}

bool User::operator!=(const User &s) {
    return this->get_username() != s.get_username();
}

