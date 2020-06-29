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
    if(argc != 4 && argc != 5){
        cerr << "Usage: ./simulator <intermediate.file> <input.vcd> <SAIF_or_VCD_flag> [SAIF_or_output_VCD.saif.vcd]";
        exit(1);
    }
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

    vector<string> v = {"a1", "a2", "b1", "b2", "z"};
    vector<int> s = {1, 1, 1, 1, 1};
    Gate* g = new Gate("GEN_AO22_D1", v, s);
    g->step();

    Gate* g2 = new Gate("GEN_AO22_D2", v, s);
    g2->step();

    Gate* g3 = new Gate("GEN_AND2_D1", v, s);
    g3->step();

    Gate* g4 = new Gate("GEN_RAMS_SP_WENABLE32_1024x32", v, s);
    g4->step();
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

