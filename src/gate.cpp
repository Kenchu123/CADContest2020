#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <utility>
#include <typeinfo>
#include <assert.h>
#include "gate.h"
#include "vcd.h"
#include "json.hpp"
#include "global.h"
#include "event.h"

using namespace std;
using json = nlohmann::json;

// private member function
bool
Gate::transition(short bef, short aft){
    // posedge(i.e. 1) : 0->1, 0->x, 0->z, x->1, z->1 
    // negedge(i.e. 0) : 1->0, 1->x, 1->z, x->0, z->0
    // z->x, x->z wont change output, set as negedge.
    if ((bef == 0 && aft != 0) || (bef != 3 && aft == 3)) return 1;
    else if ((bef == 3 && aft != 3) || (bef != 0 && aft == 0)) return 0;
    else if ((bef == 2 && aft == 1) || (bef == 1 && aft == 2)) return 0;
    else{
        cerr << "Error : 1->1 or 0->0 or x->x or z->z occurred... before: " << bef << "after: " << aft << endl;
        exit(1);
    }
}

// get delay time given input and output wire, input edge and output edge
int 
Gate::getDelay(string i, string o, bool inedge, bool outedge){
    for (auto& el : delay){
        size_t wspa = el.first.find_last_of(" ");
        string input, output;
        bool flg = 0;
        output = el.first.substr(wspa + 1);
        if (output != o) continue;
        if (el.first.find("posedge") != string::npos){
            input = el.first.substr(9, wspa - 10);
            flg = 1;
        }
        else if (el.first.find("negedge") != string::npos){
            input = el.first.substr(9, wspa - 10);
            flg = 0;
        }
        else {
            input = el.first.substr(0, wspa);
            inedge = flg = 0;
        }
        if (outedge){
            if (inedge == flg && i == input) return el.second.first;
        }
        else {
            if (inedge == flg && i == input) return el.second.second;
        }
    }
    return 0;
}

// public member function
void 
Gate::update(){
    // cout << "Gate [" << name << "] update..." << endl;
    // print();
    unordered_map<string, bool> inputedge; 
    for (auto& e : input){
        // if input changes
        if (wire[e] && wire[e] -> val != lastWireVal[e]){
            inputedge[e] = transition(lastWireVal[e], wire[e] -> val);
            lastWireVal[e] = wire[e] -> val; // set input lastval
        }   
    }
    step();
    unordered_map<string, bool> outputedge; 
    for (auto& e : output){
        // if output changes
        if (wire[e] && wire[e] -> val != lastWireVal[e]){
            outputedge[e] = transition(lastWireVal[e], wire[e] -> val);
            // make ouput val back to lastWireVal, output shoud be change when delay timeup, not now
            wire[e]->setNewVal(wire[e] -> val); // new wire val stored, but shoud not to change now
            wire[e]->setVal(lastWireVal[e]); // set wire value to old value
            lastWireVal[e] = wire[e]->newVal; // gate lastWireVal = new wire Val
        }
    }
    for (auto& eo : outputedge){
        int delay = 1e9;
        for (auto& ei : inputedge){
            int delay_cand = getDelay(ei.first, eo.first, ei.second, eo.second);
            if (delay_cand < delay) 
                delay = delay_cand; // get min delay
        }
        if (wire[eo.first]) wire[eo.first] -> update(delay); // create Event, with new val stored
        // Normally, glitch is handled when calling wire->update().
    }
    // cout << "Gate [" << name << "] update finish" << endl;
}

void
Gate::update(unordered_map<string, short>& m) { // input (a1 a2 a3) is set to val
    // TODO:
    // compare to lastVal, and update lastVal
    // if has change, set input posedge/negedge and call step(), which will update output
    // if output change, set output, output lastVal, and posedge/negedge and call getDelay()
    // after, call ouptut wire to update, which call next gate ...
    unordered_map<string, bool> inputedge; 
    for (auto& e : input){
        if (m.find(e) != m.end()){
            // if input changes
            if (wire[e] -> val != lastWireVal[e]){
                inputedge[e] = transition(lastWireVal[e], wire[e] -> val);
                lastWireVal[e] = m[e]; // set input lastval
            }   
        }
    }
    step();
    unordered_map<string, bool> outputedge; 
    for (auto& e : output){
        // if output changes
        if (wire[e] -> val != lastWireVal[e]){
            outputedge[e] = transition(lastWireVal[e], wire[e] -> val);
            lastWireVal[e] = m[e]; // set output lastval
        }
    }

    for (auto& eo : outputedge){
        int delay = INT32_MAX;
        for (auto& ei : inputedge){
            int delay_cand = getDelay(ei.first, eo.first, ei.second, eo.second);
            if (delay_cand < delay) 
                delay = delay_cand; // get min delay
        }
        wire[eo.first] -> update(delay);
        // Normally, glitch is handled when calling wire->update().
    }
}

void 
GateMgr::readfiles(string path) {
    // read path/gv_intermediate.json, sdf_intermediate.json
    ifstream gv_file(path + "/gv_intermediate.json");
    ifstream sdf_file(path + "/sdf_intermediate.json");
    json gv, sdf;
    printf("Reading gv ...\n");
    gv_file >> gv;
    printf("Reading sdf ...\n");
    sdf_file >> sdf;
    printf("Converting gv JSON to STL ...\n");
    // converting gv
    const auto module_name          = gv["module_name"].get<string>();
    const auto submodule_names      = gv["submodule_names"].get< vector<string> >();
    const auto input                = gv["input"].get< vector<string> >();
    const auto input_bitSize        = gv["input bitsize"].get< vector<string> >();
    const auto output               = gv["output"].get< vector<string> >();
    const auto output_bitSize       = gv["output bitsize"].get< vector<string> >();
    const auto wire                 = gv["wire"].get< vector<string> >();
    const auto wire_bitSize         = gv["wire bitsize"].get< vector<string> >();
    const auto assign               = gv["assign"].get< unordered_map<string, string> >();
    printf("Finish Converting\n");
    assert(wire.size() == wire_bitSize.size());
    assert(input.size() == input_bitSize.size());
    assert(output.size() == output_bitSize.size());
    cout << "Constructing Wires ..." << endl;
    // making wires
    for (size_t i = 0; i < wire.size(); ++i) {
        if (wire_bitSize[i] == "1") {
            Wire* w = new Wire(wire[i], 0);
            str2wire[wire[i]] = w;
        }
        else {
            // multi wire
            size_t col = wire_bitSize[i].find(':');
            if (col == string::npos) cerr << "[Error] wire bitSize invalid!" << endl;
            // cout << "Multi Wire: " << wire[i] << ", bitSize: " << wire_bitSize[i] << endl;
            int l = stoi(wire_bitSize[i].substr(0, col));
            int r = stoi(wire_bitSize[i].substr(col + 1));
            for (size_t j = l; j <= r; ++j) {
                Wire* w = new Wire(wire[i] + ' ' + to_string(j), 0);
                str2wires[wire[i]][j] = w;
            }
        }
    }
    // making input wires
    for (size_t i = 0; i < input.size(); ++i) {
        if (input_bitSize[i] == "1") {
            Wire* w = new Wire(input[i], 1);
            str2wire[input[i]] = w;
        }
        else {
            // multi wire
            size_t col = input_bitSize[i].find(':');
            if (col == string::npos) cerr << "[Error] input bitSize invalid!" << endl;
            // cout << "Multi Wire: " << wire[i] << ", bitSize: " << input_bitSize[i] << endl;
            int l = stoi(input_bitSize[i].substr(0, col));
            int r = stoi(input_bitSize[i].substr(col + 1));
            for (size_t j = l; j <= r; ++j) {
                Wire* w = new Wire(input[i] + ' ' + to_string(j), 1);
                str2wires[input[i]][j] = w;
            }
        }
    }
    // making output wires
    for (size_t i = 0; i < output.size(); ++i) {
        if (output_bitSize[i] == "1") {
            Wire* w = new Wire(output[i], 2);
            str2wire[output[i]] = w;
        }
        else {
            // multi wire
            size_t col = output_bitSize[i].find(':');
            if (col == string::npos) cerr << "[Error] input bitSize invalid!" << endl;
            // cout << "Multi Wire: " << wire[i] << ", bitSize: " << output_bitSize[i] << endl;
            int l = stoi(output_bitSize[i].substr(0, col));
            int r = stoi(output_bitSize[i].substr(col + 1));
            for (size_t j = l; j <= r; ++j) {
                Wire* w = new Wire(output[i] + ' ' + to_string(j), 2);
                str2wires[output[i]][j] = w;
            }
        }
    }
    // making "1'b0", "1'b1"
    Wire* zero = new Wire("1'b0", 0);
    zero->setVal(0);
    Wire* one = new Wire("1'b1", 0);
    one->setVal(3);
    str2wire["1'b0"] = zero;
    str2wire["1'b1"] = one;

    // Check wires
    // cout << "str2wire" << endl;
    // for (auto it = str2wire.begin(); it != str2wire.end(); ++it) {
    //     it->second->print();
    // }
    // cout << "str2wires" << endl;
    // for (auto it = str2wires.begin(); it != str2wires.end(); ++it) {
    //     for (auto w = it->second.begin(); w != it->second.end(); ++w) w->second->print();
    // }

    // construct gates, multi wire not set
    cout << "Constructing Gates ..." << endl;
    for (auto& name : submodule_names) {
        // cout << "Constructing: " << name << endl;
        Gate* g = new Gate();
        g->setVal(name, gv["submodule"][name]["t"]);
        for (auto& el : gv["submodule"][name]["para"].items()) {
            if (el.value().is_array()) { // this is multi bus, only appears in sequential
                continue;
            }
            string wire_name = el.value();
            size_t spaceAt = wire_name.find(" ");
            // check if it's multi wire by if it's contains space
            if (spaceAt != string::npos) {
                size_t ind = stoi(wire_name.substr(spaceAt));
                wire_name = wire_name.substr(0, spaceAt);
                // cout << "Multi wire: " << wire_name << ", ind: " << ind << endl;
                if (str2wires.find(wire_name) == str2wires.end()) {
                    cerr << "Unknown Wire:" << wire_name << endl;
                }
                g->setWire(el.key(), str2wires[wire_name][ind]);
            }
            else {
                g->setWire(el.key(), str2wire[wire_name]);
            }
        }
        str2gate[name] = g;
    }
    // // Check gates
    // cout << "gates" << endl;
    // for (auto it = str2gate.begin(); it != str2gate.end(); ++it) {
    //     it->second->print();
    // }
    // Counts
    cout << "Wire count: " << wire.size() << endl;
    cout << "Input count: " << input.size() << endl;
    cout << "Output count: " << output.size() << endl;
    cout << "Gate count: " << str2gate.size() << endl;



    // converting sdf
    printf("Converting sdf JSON to STL ...\n");
    cout << "Getting Delay Time Information..." << endl;
    int sdf_timescale = -1, vcd_timescale = 1, timescale = 1;
    sdf_time_unit = sdf["timescale"];
    if (sdf_time_unit == "1fs") sdf_timescale = 1;
    else if (sdf_time_unit == "1ps") sdf_timescale = 1000;
    else if (sdf_time_unit == "1ns") sdf_timescale = 1000000;
    else if (sdf_time_unit == "1us") sdf_timescale = 1000000000;
    else {
        cerr << "not a valid TIMESCALE in sdf: " << sdf_time_unit << "!!! Error! Exiting..." << endl;
        exit(1);
    }
    if (vcd_time_unit == "1fs") vcd_timescale = 1;
    else if (vcd_time_unit == "1ps") vcd_timescale = 1000;
    else if (vcd_time_unit == "1ns") vcd_timescale = 1000000;
    else if (vcd_time_unit == "1us") vcd_timescale = 1000000000;
    else {
        cerr << "not a valid TIMESCALE in vcd: " << vcd_time_unit << "!!! Error! Exiting..." << endl;
        exit(1);
    }
    assert(sdf_timescale >= vcd_timescale);
    timescale = sdf_timescale / vcd_timescale;
    for (auto& instance : sdf["cell"].items()){
        for (auto& el : sdf["cell"][instance.key()]["d"].items()){
            assert(el.value().size() == 2);
            // get input or output
            size_t wspa = el.key().find_last_of(" ");
            if (el.key().find("negedge") != string::npos || el.key().find("posedge") != string::npos) {
                str2gate[instance.key()] -> input.insert(el.key().substr(9, wspa - 10));
                str2gate[instance.key()] -> output.insert(el.key().substr(wspa + 1));
            }
            else {
                str2gate[instance.key()] -> input.insert(el.key().substr(0, wspa));
                str2gate[instance.key()] -> output.insert(el.key().substr(wspa + 1));
            }
            // get delay
            const auto d = sdf["cell"][instance.key()]["d"][el.key()].get< vector<float> >();
            int r_delay = d[0] * timescale;
            int f_delay = d[1] * timescale;
            str2gate[instance.key()] -> delay[el.key()] = make_pair(r_delay, f_delay);
        }
    }
    printf("Finish Converting\n");

    // read wire fanouts
    printf("Reading wire fanouts from gv...\n");
    for (auto& name : submodule_names) {
        for (auto& el : gv["submodule"][name]["para"].items()) {
            if (el.value().is_array()) { // this is multi bus, only appears in sequential
                continue;
            }
            string wire_name = el.value();
            size_t spaceAt = wire_name.find(" ");
            // check if it's multi wire by if it's contains space
            if (spaceAt != string::npos) {
                size_t ind = stoi(wire_name.substr(spaceAt));
                wire_name = wire_name.substr(0, spaceAt);
                if (str2wires.find(wire_name) == str2wires.end()) {
                    cerr << "Unknown Wire:" << wire_name << endl;
                }
                if (str2gate[name] -> input.find(el.key()) != str2gate[name] -> input.end()){
                    str2wires[wire_name][ind] -> fanouts.push_back(str2gate[name]);
                    // cout << wire_name + ' ' + to_string(ind) << "set fanout " << name << endl;
                }   
            }
            else {
                if (str2gate[name] -> input.find(el.key()) != str2gate[name] -> input.end()){
                    str2wire[wire_name] -> fanouts.push_back(str2gate[name]);
                    // cout << wire_name << " set fanout " << name << endl;
                }
            }
        }
    }
    printf("Finish Reading...\n");

}