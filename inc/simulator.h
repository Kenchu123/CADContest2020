#ifndef SIMULATOR
#define SIMULATOR

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
#include <utility>
#include <queue>
#include <assert.h>

#include "vcd.h"
#include "wire.h"
#include "gate.h"

using namespace std;

class Event;

class Event {
    public:
        Event() {
            gates.clear();
            setWire = 0;
        }
        ~Event() {
            gates.clear();
            time = 0;
            setWire = 0;
        }
        void print() const {
            cout << "Event at time: " << time << endl;
            // for (auto& g : gates) {
            //     cout << "Invoked Gate: " << g->name << endl;
            // }
        }
        void setTime(unsigned long long t) { time = t; }
        void setWireVal(bool v) { setWire = v; }
        void addGate(Gate* g) { gates.insert(g); }
        unordered_set<Gate*> gates;
        unsigned long long time;
        bool setWire; // 1: need to set wire val before gate update, due to input vcd
                      // 0: don't need to set wire val, gate step will do

    private:
};

struct LessThanByTime
{
  bool operator()(const Event& lhs, const Event& rhs) const
  {
    return lhs.time > rhs.time;
  }
};

class Simulator {
    public:
        GateMgr* gm;
        Vcd* vcd;
        priority_queue<Event, vector<Event>, LessThanByTime> eq; // event sorted queue
        int time;
        Simulator() {}
        ~Simulator() {
            gm = 0; vcd = 0;
        }
        Simulator(GateMgr* g, Vcd* v): gm(g), vcd(v) {
            assert(gm != 0);
            assert(vcd != 0);
        }
        void createEvent(unsigned long long&, map<string, short>&, bool);
        void syncFirstEvent();
        void setWireToVCD(const Event*);
        void runEvent();
        void simulate();
    private:
};


#endif