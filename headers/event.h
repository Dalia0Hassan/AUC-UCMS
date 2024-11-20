#include <iostream>
#include <string>
#include <QDateTime>
using namespace std;
#ifndef UCMS_EVENT_H
#define UCMS_EVENT_H


class Event {
    string title , description;
    QDateTime date_time ;
    int capacity;

public :
    Event ( string , string , QDateTime , int ) ;
    string get_title();
    string get_description();
    QDateTime get_date_time();
    int get_capacity();
    void set_title(string);
    void set_description(string);
    void set_date_time(QDateTime);



};

#endif //UCMS_EVENT_H
