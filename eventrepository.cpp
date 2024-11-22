#include "eventrepository.h"

EventRepository::EventRepository() : ActivityRepository(ActivityType::Event, "events.csv") {
    // Testing CourseRepository
    load();
    QList<Activity*> activities = get_all();
    // print all
    for (auto &activity : activities)
        qDebug() << activity->get_title();

    remove(activities[0]);
    activities[1]->set_title("New Title");
    update(activities[1]);
    store();
}
