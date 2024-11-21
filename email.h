#ifndef EMAIL_H
#define EMAIL_H
#include <QString>
#include <QRegularExpression>

class Email
{
    static const QRegularExpression emailRegExp;
    static bool is_valid_email (QString);
    QString email;
public:
    Email(QString);
    Email();
    QString get_email();
    void set_email(QString);
    bool operator==(Email);

};

#endif // EMAIL_H
