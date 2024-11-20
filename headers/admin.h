#include "user.h"

#ifndef UCMS_ADMIN_H
#define UCMS_ADMIN_H


class Admin : public User {
public:
    Admin(string first_name, string last_name, string email, string phone_number);
    Admin();
    string to_string();
    bool operator==(User u);
    bool operator!=(User u);
};




#endif //UCMS_ADMIN_H
