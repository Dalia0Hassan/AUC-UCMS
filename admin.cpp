#include "admin.h"
#include "user.h"

Admin::Admin(QString first_name, QString last_name, QString email, QString phone_number)
: User("username", "password", first_name, last_name, email, phone_number, "Address") {}
