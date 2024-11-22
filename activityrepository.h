#ifndef ACTIVITYREPOSITORY_H
#define ACTIVITYREPOSITORY_H

#include "activity.h"
#include "utils.h"
class ActivityRepository
{
private:
    ActivityType type;
    QString filename;
    QHash<QUuid, Activity*> container;
public:

    // Constructors and destructor
    ActivityRepository(ActivityType type, QString filename);
    virtual ~ActivityRepository() = 0;

    // Data managers
    void load();
    void store();

    void add(Activity* activity);
    void remove(Activity* activity);
    void update(Activity* activity);
    Activity* get_activity(QUuid id);
    QList<Activity*> get_all();


    // Getters
    ActivityType get_type() const;
};

#endif // ACTIVITYREPOSITORY_H
