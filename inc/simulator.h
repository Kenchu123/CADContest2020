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
            time = 0;
        }
        ~Event() {
            gates.clear();
            time = 0;
        }
        bool operator() (const Event& a, const Event& b) const {
            return a.time < b.time;
        }
        void setTime(unsigned long long t) { time = t; }
        void addGate(Gate* g) { gates.insert(g); }
        unordered_set<Gate*> gates;
        unsigned long long time;
    private:
};

class Simulator {
    public:
        GateMgr* gm;
        Vcd* vcd;
        priority_queue<Event> eq; // event sorted queue
        int time;
        Simulator() {}
        ~Simulator() {
            gm = 0; vcd = 0;
        }
        Simulator(GateMgr* g, Vcd* v): gm(g), vcd(v) {
            assert(gm != 0);
            assert(vcd != 0);
        }
        void createEvent(unsigned long long&, map<string, short>&);
        void runEvent();
        void simulate();
    private:
};


#endif