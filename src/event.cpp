#include <queue>
#include <unordered_map>
#include <vector>
#include "event.h"
#include "global.h"

priority_queue<Event*, vector<Event*>, LessThanByTime> eq;
unordered_map<unsigned long long, Event*> evMap;
