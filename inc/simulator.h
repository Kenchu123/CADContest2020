#ifndef SIMULATOR
#define SIMULATOR

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <iostream>
#include <utility>
#include <assert.h>

#include "vcd.h"
#include "wire.h"
#include "gate.h"
#include "event.h"

using namespace std;

class Simulator {
    public:
        GateMgr* gm;
        Vcd* vcd;
        Simulator() {}
        ~Simulator() {
            gm = 0; vcd = 0;
        }
        Simulator(GateMgr* g, Vcd* v): gm(g), vcd(v) {
            assert(gm != 0);
            assert(vcd != 0);
        }
        static void createEvent(unsigned long long&, map<string, short>&);
        static void createEvent(unsigned long long&, string&, short);
        void syncFirstEvent();
        // void setWireToVCD(const Event*);
        void runEvent();
        void simulate();
        void setEventChangeWires(const Event*, unordered_set<Gate*>&);
    private:
};


#endif