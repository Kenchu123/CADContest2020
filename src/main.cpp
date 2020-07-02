#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include "gate.h"
#include "vcd.h"
#include "simulator.h"
using namespace std;


int main(int argc, char *argv[]) {
    if (argc != 6 && argc != 7) {
        cerr << "Usage: GPUSimulator.exe <intermediate_representation.file> <input.vcd> <SAIF_or_VCD_flag> <dumpon_time> <dumpoff_time> [SAIF_or_output_VCD.saif.vcd]" << endl;
        return 0;
    }
    string intermediat_path = argv[1];
    string input_vcd_path = argv[2];
    string saif_vcd_flag = argv[3];
    string dumpon_time_s = argv[4];
    string dumpoff_time_s = argv[5];
    unsigned long long dumpon_time = stoull(dumpon_time_s);
    unsigned long long dumpoff_time = stoull(dumpoff_time_s);
    string output_path = "";
    if (argc == 7) output_path = argv[6];
    cout << "HI, this is the simulator" << endl;

    Vcd vcd(input_vcd_path, output_path);
    vcd.readvcd(dumpoff_time);
    // vcd.print(); 

    GateMgr gateMgr(vcd.timescale);
    gateMgr.readfiles(intermediat_path);

    vcd.gensyms(output_path, &gateMgr);
    // vcd.writevcd(output_path, &e, $gateMgr); // if flg == vcd
    Simulator sim(&gateMgr, &vcd, dumpon_time, dumpoff_time);
    sim.simulate();

}


