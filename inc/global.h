#ifndef GLOBAL
#define GLOBAL
#include <queue>
#include <vector>
#include <unordered_map>
#include "event.h"
using namespace std;

extern unsigned long long global_time;


struct LessThanByTime
{
  bool operator()(Event* lhs, Event* rhs) const
  {
    return lhs->time > rhs->time;
  }
};

extern priority_queue<Event*, vector<Event*>, LessThanByTime> eq; // event sorted queue
extern unordered_map<unsigned long long, Event*> evMap;

#endif