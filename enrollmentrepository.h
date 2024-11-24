#ifndef ENROLLMENTREPOSITORY_H
#define ENROLLMENTREPOSITORY_H

#include "quuid.h"
#include "utils.h"
#include "instructor.h"

class EnrollmentRepository
{
public:
    EnrollmentRepository();

    // Logic

    // Precondition: student_id and course_id are valid
    // Postcondition: student_id is enrolled in course_id (only validates if student exists)
    void enroll_in_course(QString student_id, QUuid course_id);

    // Precondition: student_id and course_id are valid
    // Postcondition: student_id is removed from course_id (only validates if student exists)
    void drop_course(QString student_id, QUuid course_id);

    // Precondition: student_id and event_id are valid
    // Postcondition: student_id is enrolled in event_id (only validates if student exists)
    void enroll_in_event(QString student_id, QUuid event_id);

    // Precondition: student_id and event_id are valid
    // Postcondition: student_id is removed from event_id (only validates if student exists)
    void drop_event(QString student_id, QUuid event_id);

    // Getters

    // Precondition: student_id is valid
    // Postcondition: returns a list of course ids that student_id is enrolled in
    QList<QUuid> get_student_courses(QString student_id);

    // Precondition: student_id is valid
    // Postcondition: returns a list of event ids that student_id is enrolled in
    QList<QUuid> get_student_events(QString student_id);

    // (Not the right place, but for now)
    QList<class Instructor> get_instructors();


private:
    void enroll(QString student_id, QUuid activityId, ActivityType type);
    void drop(QString student_id, QUuid activityId, ActivityType type);
    QList<QUuid> get_student_activities(QString student_id, ActivityType type);
};

#endif // ENROLLMENTREPOSITORY_H
