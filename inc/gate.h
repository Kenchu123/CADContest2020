#ifndef GATE
#define GATE

#include <unordered_map>
#include <string>
#include <vector>
#include "vlib.h"
#include "wire.h"
using namespace std;

class Gate;
class GateMgr;


class GateMgr {
    public:
        GateMgr() {}
        ~GateMgr() {}
        vector<Gate*> gates;
        unordered_map<string, Wire*> str2wire;
        unordered_map<string, vector<Wire*> > str2wires;
        unordered_map<string, Gate*> str2gate;
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

        unordered_map<string, Wire*> wire; // to get .gv string to wire
        int delay;
        short val;
        string type, name;
        void step() {
            // vlib[type] is a function pointer to its vlib step
            vlib[type](wire);
        }
        void setVal(string n, string t) {
            name = n;
            type = t;
        }
        void setWire(string s, Wire* w) {
            cout << "Gate setting wire: " << s << " " << w << endl;
            wire[s] = w;
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
};

#endif