#ifndef GATE
#define GATE

#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string>
#include <vector>
#include "vlib.h"
#include "wire.h"
using namespace std;

class Gate;
class GateMgr;


class GateMgr {
    public:
        GateMgr(string u = "1ps"): vcd_time_unit(u) {}
        ~GateMgr() {}
        // vector<Gate*> gates;
        unordered_map<string, Wire*> str2wire;
        unordered_map<string, map<int, Wire*> > str2wires;
        unordered_map<string, Gate*> str2gate;
        string vcd_time_unit, sdf_time_unit;
        void readfiles(string path);
    private:
};

//
class Gate {
    friend class GateMgr;
    public:
        Gate() {}
        // Gate(string t, string name, vector<string> params, vector<int> bitSize) {
        //     type = t;
        //     name = name;
        //     // for (size_t i = 0;i < params.size(); ++i)
        //     //     wire[params[i]] = new Wire();
        // }
        ~Gate() {}

        unordered_map<string, Wire*> wire; // to get .gv string to wire, ex. "w1" to Wire*
        unordered_map<string, short> lastWireVal; // to get lastWireVal
        unordered_map<string, pair<int, int> > delay;

        unordered_set<string> input; // store input name in a gate, ex. "w1", "w2", "w3"
        unordered_set<string> output; // store output name in a gate, ex. "ci", "co", "q", "s"

        // short val;
        string type, name;
        void update();
        void update(unordered_map<string, short>&); // which input is set to val, ex. string : "w1", short : 3
        void step() {
            // vlib[type] is a function pointer to its vlib step
            vlib[type](wire);
        }
        void setVal(string n, string t) {
            name = n;
            type = t;
        }
        void setWire(string s, Wire* w) {
            // cout << "Gate setting wire: " << s << " " << w << endl;
            wire[s] = w;
            if (w) lastWireVal[s] = w->val;
            else lastWireVal[s] = 0;
        }
        void print() {
            cout << "Gate: " << name << ", type: " << type << endl;
            for (auto it = wire.begin(); it != wire.end(); ++it) {
                if (it->second)
                    cout << it->first << " " << it->second->name << endl;
            }
            cout << "--------------------" << endl;
        }
    private:
        bool transition(short, short);
        int getDelay(string, string, bool, bool); // getDelay(inwire, outwire, inedge, outedge)
};

#endif