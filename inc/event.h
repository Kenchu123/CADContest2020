#ifndef EVENT
#define EVENT
#include <iostream>
#include <unordered_map>
#include <queue>
#include <map>

#include "gate.h"
#include "wire.h"
using namespace std;

class Event {
    public:
        Event() {
            time = 0;
        }
        ~Event() {
            time = 0;
        }
        void print() const {
            cout << "Event at time: " << time << endl;
        }
        void setTime(unsigned long long t) { time = t; }
        void addChangeWires(map<string, short>& wires) {
            for (auto& wire : wires) {
                changeWires[wire.first] = wire.second;
            }
        }
        void addChangeWire(string s, short v) {
            changeWires[s] = v;
        }

        unordered_map<string, short> changeWires; // wire name, its new Val, ex. "n10032 3", 1
        unsigned long long time;
    private:
};

#endif