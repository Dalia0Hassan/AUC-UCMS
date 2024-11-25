#ifndef INSTRUCTOR_H
#define INSTRUCTOR_H

#include <QString>
#include <QUuid>

// No need to complicate things
class Instructor
{
private:
    QString name, department;
    QUuid id;
public:
    Instructor() = default;
    Instructor(QUuid id, QString name, QString department);

    // Getters
    QString get_name() const;
    QString get_department() const;
    QUuid get_id() const;
};

#endif // INSTRUCTOR_H
