#include "courserepository.h"

CourseRepository::CourseRepository() : ActivityRepository(ActivityType::Course, "courses.csv") {
    qDebug() << "Course Repository Created";
}
