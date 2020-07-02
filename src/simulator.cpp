#include "simulator.h"
#include "global.h" // eq is global
#include <unordered_map>
#include <unordered_set>

unsigned long long global_time = 0;

void
Simulator::createEvent(unsigned long long& t, map<string, short>& wires) {
    // Check if same time Event exists
    auto it = evMap.find(t);
    if (it != evMap.end()) {
        // exists, shoud update the event
        it->second->addChangeWires(wires);
    }
    else {
        // Not exist, create a new one
        cout << "Creating Event [VCD] at time: " << t << endl;
        Event* e = new Event;
        e->setTime(t);
        e->addChangeWires(wires);
        evMap[t] = e;
        eq.push(e);
    }
}

void
Simulator::createEvent(unsigned long long& t, string& s, short v) {
    // Create Event with only one wire
    auto it = evMap.find(t);
    if (it != evMap.end()) {
        // exists, shoud update the event
        if (it->second) {
            it->second->addChangeWire(s, v);
        }
        else {
            cerr << "[Error] at createEvent, exist but = 0" << endl;
        }
    }
    else {
        // Not exist, create a new one
        cout << "Creating Event [Wire] at time: " << t << endl;
        Event* e = new Event;
        e->setTime(t);
        e->addChangeWire(s, v);
        evMap[t] = e;
        eq.push(e);
    }
}

void
Simulator::setEventChangeWires(const Event* e, unordered_set<Gate*>& gates) {
    for (auto& name2val : e->changeWires) {
        string name = name2val.first;
        short val = name2val.second;

        Wire* wire = 0;
        size_t found = name.find(' ');
        if (found != string::npos) {
            int bit = stoi(name.substr(name.find(' ') + 1));
            name = name.substr(0, name.find(' '));
            if (gm->str2wires[name][bit]) {
                wire = gm->str2wires[name][bit];
                gm->str2wires[name][bit]->setVal(val);
            }
            else {
                cerr << "Unknown Wire: " << name << " " << bit << endl;
                exit(1);
            }
        }
        else {
            if (gm->str2wire[name]) {
                wire = gm->str2wire[name];
                gm->str2wire[name]->setVal(val);
            }
            else {
                cerr << "Unknown Wire: " << name << endl;
                exit(1);
            }
        }
        assert(wire != 0);
        for (auto& g : wire->fanouts) gates.insert(g); // add invoked gates
        // cout << "wire->fanouts count: " << wire->fanouts.size() << endl;
    }
    cout << "SetEventChangeWires, changeWire Count: " << e->changeWires.size() << ", Gate Count: " << gates.size() << endl;
}

void Simulator::runEvent() {
    // pop out Event from eq, and run
    while (!eq.empty()) {
        cout << "Running ";
        const Event* e = eq.top();
        global_time = e->time;
        e->print();
        // cout << "Global time:" << global_time << endl;

        // Set changeWire value to its val
        unordered_set<Gate*> gates;
        setEventChangeWires(e, gates);
        // Run Gate update
        cout << "Running Gate updates ..." << endl;
        for (auto& g : gates) {
            if (g) g->update();
        }
        // change special glitch


        // call output vcd

        // delete e;
        cout << "Event finished, call next event" << endl;
        eq.pop();
    }
}

void
Simulator::syncFirstEvent() {
    const Event* e = eq.top();
    // sync gate lastWireVal to wire val
    cout << "Syncing first Event(time: "<< e->time << ") where gate's lastWireVal shoud = wire Val" << endl;
    unordered_set<Gate*> gates;
    setEventChangeWires(e, gates);
    for (auto& g : gates) g->syncLastVal();
}

void
Simulator::simulate() {
    cout << "Start simulating ..." << endl;
    for (auto& data : vcd->data) {
        unsigned long long t = data.first;
        Simulator::createEvent(t, data.second);
    }
    cout << "Initial Event Size: " << eq.size() << endl;
    runEvent();
}