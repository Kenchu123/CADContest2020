#ifndef GATE
#define GATE

#include <unordered_map>
#include <string>
#include <vector>
#include "vlib.hpp"
#include "wire.h"
using namespace std;

class Gate() {
    public:
        unordered_map<string, Wire*> wire;
        // Something to call vlib function
        int delay;
        string type;
        Gate() {}
        Gate(vector<string> params, vector<int> bitSize) {
            for (size_t i = 0;i < params.size(); ++i)
                wire[params[i]] = new Wire(bitSize[i]);
        }
        ~Gate() {}
        void step() {
            // call vlib step
            // vlib[type] is a function pointer
            vlib[type].step(wire);
        }
    private:
}

#endif