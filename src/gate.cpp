#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <typeinfo>
#include "gate.h"
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

void GateMgr::readfiles(string path) {
    // read path/gv_intermediate.json, sdf_intermediate.json
    ifstream gv_file(path + "/gv_intermediate.json");
    ifstream sdf_file(path + "/sdf_intermediate.json");
    json gv, sdf;
    printf("Reading gv ...\n");
    gv_file >> gv;
    printf("Reading sdf ...\n");
    sdf_file >> sdf;
    printf("Converting JSON to STL ...\n");
    // converting gv
    // sdf unset
    const auto module_name          = gv["module_name"].get<string>();
    const auto submodule_names      = gv["submodule_names"].get< vector<string> >();
    const auto input                = gv["input"].get< vector<string> >();
    const auto input_bitSize        = gv["input bitsize"].get< vector<int> >();
    const auto output               = gv["output"].get< vector<string> >();
    const auto output_bitSize       = gv["output bitsize"].get< vector<int> >();
    const auto wire                 = gv["wire"].get< vector<string> >();
    const auto wire_bitSize         = gv["wire bitsize"].get< vector<int> >();
    const auto assign               = gv["assign"].get< unordered_map<string, string> >();
    printf("Finish Converting\n");
    assert(wire.size() == wire_bitSize.size());
    assert(input.size() == input_bitSize.size());
    assert(output.size() == output_bitSize.size());
    cout << "Constructing Wires ..." << endl;
    // making wires
    for (size_t i = 0; i < wire.size(); ++i) {
        if (wire_bitSize[i] > 1) {
            cout << "Multi Wire: " << wire[i] << ", bitSize: " << wire_bitSize[i] << endl;
            for (size_t j = 0; j < wire_bitSize[i]; ++j) {
                Wire* w = new Wire(wire[i] + ' ' + to_string(j), 0);
                str2wires[wire[i]].push_back(w);
            }
        }
        else {
            Wire* w = new Wire(wire[i], 0);
            str2wire[wire[i]] = w;
        }
    }
    // making input wires
    for (size_t i = 0; i < input.size(); ++i) {
        if (input_bitSize[i] > 1) {
            for (size_t j = 0; j < input_bitSize[i]; ++j) {
                Wire* w = new Wire(input[i] + ' ' + to_string(j), 1);
                str2wires[input[i]].push_back(w);
            }
        }
        else {
            Wire* w = new Wire(input[i], 1);
            str2wire[input[i]] = w;
        }
    }
    // making output wires
    for (size_t i = 0; i < output.size(); ++i) {
        if (output_bitSize[i] > 1) {
            for (size_t j = 0; j < output_bitSize[i]; ++j) {
                Wire* w = new Wire(output[i] + ' ' + to_string(j), 2);
                str2wires[output[i]].push_back(w);
            }
        }
        else {
            Wire* w = new Wire(output[i], 2);
            str2wire[output[i]] = w;
        }
    }
    // making "1'b0", "1'b1"
    Wire* zero = new Wire("1'b0", 0);
    Wire* one = new Wire("1'b1", 0);
    str2wire["1'b0"] = zero;
    str2wire["1'b1"] = one;

    // Check wires
    cout << "str2wire" << endl;
    for (auto it = str2wire.begin(); it != str2wire.end(); ++it) {
        it->second->print();
    }
    cout << "str2wires" << endl;
    for (auto it = str2wires.begin(); it != str2wires.end(); ++it) {
        for (auto w : it->second) w->print();
    }

    // construct gates, multi wire not set
    cout << "Constructing Gates ..." << endl;
    for (auto& name : submodule_names) {
        cout << "Constructing: " << name << endl;
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
                cout << "Multi wire: " << wire_name << ", ind: " << ind << endl;
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
    // Check gates
    for (auto it = str2gate.begin(); it != str2gate.end(); ++it) {
        it->second->print();
    }

    
}