#include "simulator.h"
#include <unordered_map>
#include <unordered_set>

void
Simulator::createEvent(unsigned long long& t, map<string, short>& wires) {
    Event e;
    e.setTime(t);
    for (auto& name2val : wires) {
        string name = name2val.first;
        short val = name2val.second;

        Wire* wire = 0;
        size_t found = name.find(' ');
        if (found != string::npos) {
            int bit = stoi(name.substr(name.find(' ') + 1));
            name = name.substr(0, name.find(' '));
            wire = gm->str2wires[name][bit];
        }
        else {
            wire = gm->str2wire[name];
        }
        assert(wire != 0);
        for (auto& g : wire->fanouts) e.addGate(g);
    }
    eq.push(e);
}

void Simulator::runEvent() {
    // pop out Event from eq, and run
}

void
Simulator::simulate() {
    for (auto& data : vcd->data) {
        cout << "Simulating time: " << t << endl;
        unsigned long long t = data.first;
        createEvent(t, data.second);
    }
}