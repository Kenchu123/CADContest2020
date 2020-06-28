#include <iostream>
#include <stdio.h>
#include "gate.h"
using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 6 && argc != 7) {
        cerr << "Usage: GPUSimulator.exe <intermediate_representation.file> <input.vcd> <SAIF_or_VCD_flag> <dumpon_time> <dumpoff_time> [SAIF_or_output_VCD.saif.vcd]" << endl;
        return 0;
    }
    string intermediat_path = argv[1];
    string input_vcd_path = argv[2];
    string saif_vcd_flag = argv[3];
    string dumpon_time = argv[4];
    string dompoff_time = argv[5];
    string output_path = "";
    if (argc == 7) output_path = argv[6];

    cout << "Hi, this is simulator" << endl;
    // vector<string> v = {"a1", "a2", "b1", "b2", "z"};
    // vector<int> s = {1, 1, 1, 1, 1};
    // Gate* g = new Gate("GEN_AO22_D1", v, s);
    // g->step();

    // Gate* g2 = new Gate("GEN_AO22_D2", v, s);
    // g2->step();

    // Gate* g3 = new Gate("GEN_AND2_D1", v, s);
    // g3->step();

    // Gate* g4 = new Gate("GEN_RAMS_SP_WENABLE32_1024x32", v, s);
    // g4->step();

    GateMgr gateMgr;
    gateMgr.readfiles(intermediat_path);
}