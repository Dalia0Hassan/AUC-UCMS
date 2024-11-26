#ifndef AUTHENTICATIONREPOSITORY_H
#define AUTHENTICATIONREPOSITORY_H

#include "qdir.h"
#include "user.h"
#include "utils.h"
#include <QString>

class AuthenticationRepository
{
private:
    User* current_user = nullptr;
public:
    AuthenticationRepository();
    ~AuthenticationRepository();

    // Logic
    void login(QString username, QString password);
    void logout();
    void signup(User* newUser, QString _type);

    // Getters
    User* get_current_user();

private:
    QStringList get_user_info(QString id, UserType type);
    void verifyCredentials(User *user, QFile& file);
};

#endif // AUTHENTICATIONREPOSITORY_H
