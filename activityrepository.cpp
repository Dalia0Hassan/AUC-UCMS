#include "activityrepository.h"
#include "course.h"
#include "utils.h"
// #include "event.h"
#include <QFile>
#include <QTextStream>
#include <QString>

ActivityRepository::ActivityRepository(ActivityType type, QString filename) {

    // Setting the filename and type
    this->filename = filename;
    this->type = type;

    // Initializing the container
    container = QHash<QUuid, Activity*>();
}

ActivityRepository::~ActivityRepository() {
    // Freeing the memory
    for (auto &activity : container)
        delete activity;
}

ActivityType ActivityRepository::get_type() const {
    return type;
}

void ActivityRepository::load() {

    // Open file
    QFile file("D:/AUC/Semester Two/CSCE2 Lab/Final Project/AUC-UCMS/" + filename);

    // Check if file is open
    if (!file.open(QIODevice::ReadOnly))
        throw std::runtime_error("Could not open file");

    // Read file
    QTextStream in(&file);

    // Skip the title
    in.readLine();

    // Read the data
    while (!in.atEnd()) {
        // Read the row and split it
        QStringList row = parseCsvLine(in.readLine());

        // Activity object to store data
        Activity* activity;

        // Constructing the time
        QStringList start_time_ist = row[CourseDataRow::StartTime].split(" ");
        QStringList end_time_list = row[CourseDataRow::EndTime].split(" ");

        QTime start_time = QTime(start_time_ist[0].toInt(), end_time_list[1].toInt());
        QTime end_time = QTime(end_time_list[0].toInt(), end_time_list[1].toInt());

        // Constructing the activity object
        if (type == ActivityType::Course) {

            // Constructing the date
            QStringList start_date_list = row[CourseDataRow::StartDate].split(" ");
            QStringList end_date_list = row[CourseDataRow::EndDate].split(" ");

            QDate start_date = QDate(start_date_list[0].toInt(), start_date_list[1].toInt(), start_date_list[2].toInt());
            QDate end_date = QDate(end_date_list[0].toInt(), end_date_list[1].toInt(), end_date_list[2].toInt());

            // Constructing days
            QStringList days_list = row[CourseDataRow::Days].split(" ");
            QSet<Day> days;
            for(QString &day : days_list)
                days.insert(static_cast<Day>(day.toInt()));

            // Course Object
            activity = new class Course(
                row[CourseDataRow::Title], row[CourseDataRow::Description], row[CourseDataRow::Location],
                QUuid(row[CourseDataRow::Id]), QUuid(row[CourseDataRow::InstructorId]),
                row[CourseDataRow::Capacity].toInt(), start_date, end_date,
                days, start_time, end_time
            );

        } else {
            // activity = new class Event(
            //     row[1], row[2], QDateTime::fromString(row[3]), row[4].toInt(), row[5]
            // );
        }

        // Add to container
        container.insert(activity->get_id(), activity);
    }
    file.close();
}
