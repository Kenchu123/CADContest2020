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
    string dumpon_time = argv[4];
    string dompoff_time = argv[5];
    string output_path = "";
    if (argc == 7) output_path = argv[6];
    cout << "HI, this is the simulator" << endl;

    Vcd vcd(input_vcd_path);
    vcd.readvcd();
    // vcd.print(); 

    GateMgr gateMgr(vcd.timescale);
    gateMgr.readfiles(intermediat_path);

    vcd.gensyms(output_path, &gateMgr);
    // vcd.writevcd(output_path, &e, $gateMgr); // if flg == vcd
    Simulator sim(&gateMgr, &vcd);
    sim.simulate();

}


