#include "event.h"

Event::Event(QString title , QString description, QDateTime data_time , int capacity) {
    this->title = title ;
    this->description = description;
    this->date_time = data_time;
    this->capacity = capacity;
}

