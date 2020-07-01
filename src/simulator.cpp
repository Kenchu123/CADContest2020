#include "simulator.h"
#include <unordered_map>
#include <unordered_set>

void
Simulator::createEvent(unsigned long long& t, map<string, short>& wires, bool setWire) {
    cout << "Create Event at time: " << t << endl;
    Event e;
    e.setTime(t);
    e.setWireVal(setWire);
    for (auto& name2val : wires) {
        string name = name2val.first;

        Wire* wire = 0;
        size_t found = name.find(' ');
        if (found != string::npos) {
            int bit = stoi(name.substr(name.find(' ') + 1));
            name = name.substr(0, name.find(' '));
            if (gm->str2wires[name][bit]) {
                wire = gm->str2wires[name][bit];
            }
            else {
                cerr << "Unknown Wire: " << name << " " << bit << endl;
                exit(1);
            }
        }
        else {
            if (gm->str2wire[name]) {
                wire = gm->str2wire[name];
            }
            else {
                cerr << "Unknown Wire: " << name << endl;
                exit(1);
            }
        }
        assert(wire != 0);
        for (auto& g : wire->fanouts) e.addGate(g);
    }
    eq.push(e);
}

void
Simulator::setWireToVCD(const Event* e) {
    // use time to get inputVCD from vcd->data[t]
    cout << "Setting wire value from input vcd ..." << endl;
    for (auto& name2val : vcd->data[e->time]) {
        string name = name2val.first;
        short val = name2val.second;

        size_t found = name.find(' ');
        if (found != string::npos) {
            int bit = stoi(name.substr(name.find(' ') + 1));
            name = name.substr(0, name.find(' '));
            if (gm->str2wires[name][bit]) {
                gm->str2wires[name][bit]->setVal(val);
            }
            else {
                cerr << "Unknown Wire: " << name << " " << bit << endl;
                exit(1);
            }
        }
        else {
            if (gm->str2wire[name]) {
                gm->str2wire[name]->setVal(val);
            }
            else {
                cerr << "Unknown Wire: " << name << endl;
                exit(1);
            }
        }
    }
}

void Simulator::runEvent() {
    // pop out Event from eq, and run
    while (!eq.empty()) {
        const Event* e = &eq.top();
        eq.pop();
        e->print();
        if (e->setWire) {         // setWire = 1, because input VCD changes, so need to set wire val
            setWireToVCD(e);
        }
        for (auto& g: eq.top().gates) {
            g->update();
        }
    }
}

void
Simulator::syncFirstEvent() {
    const Event* e = &eq.top();
    setWireToVCD(e);
    // sync gate lastWireVal to wire val
    cout << "Syncing first Event where gate's lastWireVal shoud = wire Val" << endl;
    for (auto& g : e->gates) g->syncLastVal();
}

void
Simulator::simulate() {
    cout << "Start simulating ..." << endl;
    for (auto& data : vcd->data) {
        unsigned long long t = data.first;
        createEvent(t, data.second, 1);
    }
    cout << "Initial Event Size: " << eq.size() << endl;
    syncFirstEvent();
    // runEvent();
}