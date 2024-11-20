#ifndef EMAIL_H
#define EMAIL_H
#include <regex>
#include <string>
using namespace  std ;
class Email
{
    string email ;
    bool is_valid_email (string s);
public:
    Email(string s );
    Email();
    string get_email();
    void set_email(string s);

};

#endif // EMAIL_H
