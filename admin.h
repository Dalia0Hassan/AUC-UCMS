#ifndef UCMS_ADMIN_H
#define UCMS_ADMIN_H

#include <QString>
#include "user.h"



class Admin : public User {
public:
    Admin(QString first_name, QString last_name, QString email, QString phone_number);
    Admin();
    QString to_QString();
    bool operator==(User u);
    bool operator!=(User u);
};




#endif //UCMS_ADMIN_H
