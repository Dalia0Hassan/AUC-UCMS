#include "eventrepository.h"

EventRepository::EventRepository() : ActivityRepository(ActivityType::Event, "events.csv") {}
