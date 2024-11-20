//
// Created by Ayman Refat on 20/11/2024.
//

#include "headers/event.h"

Event::Event(string title , string description, QDateTime data_time , int capacity) {
    this->title = title ;
    this->description = description;
    this->date_time = data_time;
    this->capacity = capacity;
}

