#include <string>
#include "email.h"
using namespace std ;

#ifndef USER_H
#define USER_H

class User
{
    string username , password , ID ;
    string first_name , last_name ;
    Email email ;
    string phone_number;
    string address;
public:
    User(string username, string password, string first_name, string last_name, string email, string phone_number,
         string address ) ;
    void set_username(string username);
    void set_password(string password);
    string get_username();
    string get_password();
    string get_name();
    Email get_email();
    string get_phone_number();
    string get_address();
};



#endif // USER_H
