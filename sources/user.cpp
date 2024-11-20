#include "headers/user.h"
#include "headers/email.h"

User::User(string username, string password, string first_name, string last_name, string email, string phone_number,
               string address ){
    this->username = username;
    this->password = password;
    this->first_name = first_name;
    this->last_name = last_name;
    this->email = Email(email);
    this->phone_number = phone_number;
    this->address = address;
}