#ifndef ACTIVITY_H
#define ACTIVITY_H

#include "utils.h"
#include <QString>
#include <QUuid>
#include <QTime>


// Parent class of Course and Event classes //
class Activity
{
private:
    ActivityType type;
    QString title, description, location;
    QUuid id;
    int capacity;
    QTime start_time, end_time;
public:
    // Constructors and destructor
    Activity(QString title, QString description, QString location, QUuid id, int capacity, QTime start_time, QTime end_time, ActivityType type);
    virtual ~Activity() = 0;

    // Getters
    QString get_title() const;
    QString get_description() const;
    QUuid get_id() const;
    QString get_location() const;
    int get_capacity() const;
    QTime get_start_time() const;
    QTime get_end_time() const;
    ActivityType get_type() const;

private:
    // Setters
    void set_title(QString);
    void set_description(QString);
    void set_id(QUuid);
    void set_location(QString);
    void set_capacity(int);
    void set_start_time(QTime);
    void set_end_time(QTime);
    void set_type(ActivityType);

    // Friend classes


};

#endif // ACTIVITY_H
