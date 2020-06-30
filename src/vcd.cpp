#include "vcd.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

// private member function
void 
Vcd::trimws(string& s){
    size_t start = s.find_first_not_of(' ');
    if(start != string::npos) s = s.substr(start);
    size_t end = s.find_last_not_of(' ');
    if(end != string::npos) s = s.substr(0, end + 1);
}

vector<string> 
Vcd::split(string& s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream Stream(s);
    while(getline(Stream, token, delimiter)){
       trimws(token);
       tokens.push_back(token);
    }
    return tokens;
}

void 
Vcd::getsyms(vector<string>& v){
    for (int i = 0;i < v.size();++i){
        if (v[i].find("$var") == 0){
            vector<string> tokens;
            string sym = "", name = "";
            unsigned start = 0, end = 0;
            tokens = split(v[i], ' ');
            sym = tokens[3];
            name = tokens[4];
            if (tokens.size() == 6){
                symbols[sym] = make_pair(name, make_pair(start, end));
            }
            else if (tokens.size() == 7){
                size_t pos = tokens[5].find(':');
                start = (unsigned)stoi(tokens[5].substr(1, pos - 1));
                end = (unsigned)stoi(tokens[5].substr(pos + 1, tokens[5].size() - pos - 2));
                if (start > end){
                    unsigned tmp = start;
                    start = end;
                    end = tmp;
                }
                symbols[sym] = make_pair(name, make_pair(start, end));
            }
            else{
                cerr << "Error : tokens size = " << tokens.size() << endl;
                exit(1);
            }
        }
        else if(v[i].find("$timescale") == 0)
            timescale = v[i].substr(11, 3);
    }
}

short 
Vcd::convert_val(char ch){
    if (ch == '0') return 0;
    else if (ch == '1') return 3;
    else if (ch == 'x') return 1;
    else if (ch == 'z') return 2;
    else{
        cerr << "Error : Wrong bit value from vcd" << endl;
        exit(1);
    }
} 

// public member function 
void 
Vcd::print(){
    cout << "timescale: " << timescale << endl;
    for(auto e : data){
        // name
        (e.first.second == "") ? cout << e.first.first << endl
                                     : cout << e.first.first << "[" << e.first.second << "]" << endl;
        for(auto elem : e.second){
            // time & value
            cout << "\t" << elem.first << " " << elem.second << endl;
        }
    }
}

// still four value 0, 1, x, z
// ex. map<pair<name, idx>, map<time,  value>> (if 1bit, idx = "")
//     <"a", "">  , 10000, 1
//                , 20000, 2
//     <"b", "0"> , 10000, 2
//                , 20000, 1
//                , 30000, 0
//     <"b", "1"> , 10000, 0
//     <"b", "2"> , 10000, 3
void
Vcd::readvcd(){
    data.clear();
    fstream file;
    vector<string> v;
    file.open(path, ios::in);
    if (!file) {
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    cout << "Reading vcd..." << endl;
    string buf;
    while (!file.eof()) {
        getline(file, buf);
        if (buf != "" && buf[0] != ' ')
        v.push_back(buf);
    }
    file.close();
    getsyms(v);
    unsigned long long time = 0;
    bool dumpvar_flg = false;
    for (int i = 0;i < v.size();++i){
        if (v[i].find("#") == 0){
            time = stoull(v[i].substr(1));
            dumpvar_flg = true;
        }
        else if (dumpvar_flg){
            // array elem
            if (v[i][0] == 'b'){
                size_t pos = v[i].find(" ");
                string bits = v[i].substr(1, pos - 1);
                reverse(bits.begin(), bits.end());
                string sym = v[i].substr(pos + 1);
                unsigned start = symbols[sym].second.first;
                unsigned end = symbols[sym].second.second;
                assert(start < end);
                for (int j = start;j < end;++j){
                    short value = (j - start > bits.size() - 1) ? convert_val(bits.back()) : convert_val(bits[j - start]);
                    data[make_pair(symbols[sym].first, to_string(j))][time] = value;
                }
            }
            // one bit
            else {
                string sym = v[i].substr(1);
                short value = convert_val(v[i][0]);
                data[make_pair(symbols[sym].first, "")][time] = value;
            }
        }
    }
    return;
}