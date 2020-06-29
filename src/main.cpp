#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
#include <map>
#include "gate.h"
using namespace std;

typedef vector<pair<unsigned long long, vector<pair<string, short>>>> myvcd;

void vcdParse(string, myvcd&, string&);

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

    GateMgr gateMgr;
    gateMgr.readfiles(intermediat_path);

    cout << "HI, this is the simulator" << endl;
    myvcd vcdinf;
    string timescale = "";
    vcdParse(argv[2], vcdinf, timescale);

    cout << "timescale: " << timescale << endl;
    for(int i = 0;i < vcdinf.size();++i){
        cout << "#" << vcdinf[i].first << endl;
        for(int j = 0;j < vcdinf[i].second.size();++j){
            cout << "\t\t" << vcdinf[i].second[j].first << " " << vcdinf[i].second[j].second << endl;
        }
    }
}

void vcdParse(string path, myvcd& vcd, string& ts){
    fstream file;
    vector<string> data;
    map<string, string> tok2name;
    file.open(path, ios::in);
    if (!file) {
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    else cout << "File open successfully!" << endl;
    cout << "Reading data from file..." << endl;
    string buf;
    while (!file.eof()) {
        getline(file, buf);
        data.push_back(buf);
    }
    file.close();
    for(int i = 0;i < data.size();++i){
        if(data[i].find("$var") == 0){
            string token = "", name = "";

        }
        else if(data[i].find("#") == 0){
            pair<unsigned long long, vector<pair<string, short>>> p(stoull(data[i].substr(1)))
            vcd.push_back(p);
        }
        else if(data[i].find("$timescale") == 0)
            ts = data[i].substr(11, 3);
    }
}
