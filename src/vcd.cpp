#include "vcd.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <assert.h>

#include "event.h"
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
Vcd::getsyms(string& v){
    if (v.find("$var") == 0){
        vector<string> tokens;
        string sym = "", name = "";
        unsigned start = 0, end = 0;
        tokens = split(v, ' ');
        sym = tokens[3];
        name = tokens[4];
        if (tokens[2] == "1"){
            symbols[sym] = make_pair(name, make_pair(start, end));
        }
        else {
            if (tokens.size() == 6){
                size_t col_pos = tokens[4].find(':');
                size_t l_pos = tokens[4].find('[');
                size_t r_pos = tokens[4].find(']');
                start = (unsigned)stoi(tokens[4].substr(l_pos + 1, col_pos - l_pos - 1));
                end = (unsigned)stoi(tokens[4].substr(col_pos + 1, tokens[4].size() - col_pos - 2));
                if (start > end){
                    unsigned tmp = start;
                    start = end;
                    end = tmp;
                }
                name = name.substr(0, l_pos);
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
    }
    else if(v.find("$timescale") == 0){
        string str = v;
        trimws(str);
        // if (str.size() == 10){
        //     timescale = v[i + 1];
        //     trimws(timescale);
        //     size_t start = timescale.find_first_not_of('\t');
        //     if(start != string::npos) timescale = timescale.substr(start);
        //     size_t end = timescale.find_last_not_of('\t');
        //     if(end != string::npos) timescale = timescale.substr(0, end + 1);
        // }
        // else 
        timescale = v.substr(11, 3);

    }
    else if(v.find("$scope") == 0){
        vector<string> tokens;
        tokens = split(v, ' ');
        if (tokens[1] == "module")
            scopes.push_back(tokens[2]);
    }
}

short 
Vcd::convert_val(char ch){
    if (ch == '0') return 0;
    else if (ch == '1') return 3;
    else if (ch == 'x') return 1;
    else if (ch == 'z') return 2;
    else{
        cerr << "Error : Wrong bit value from vcd : " << ch << endl;
        exit(1);
    }
} 

string 
Vcd::convert_short(short num){
    if (num == 0) return "0";
    else if (num == 1) return "x";
    else if (num == 2) return "z";
    else if (num == 3) return "1";
    else{
        cerr << "Error : Wrong bit value(short) from citcuit : " << num << endl;
        exit(1);
    }
} 

string 
Vcd::genAscii(int num){
    // printable ascii : 33 ~ 126
    assert(num >= 0);
    if (num <= 93){
        char c = (char)(num + 33);
        string s(1, c);
        return s;
    }
    else if (num > 93 && num <= 8929){
        char c0 = (char)((num - 94) % 94 + 33);
        char c1 = (char)((num - 94) / 94 + 33);
        string s0(1, c0);
        string s1(1, c1);
        return s0 + s1;
    }
    else if (num > 8929 && num <= 839513){
        char c0 = (char)((num - 8930) % 94 + 33);
        char c1 = (char)(((num - 8930) % 8836) / 94 + 33);
        char c2 = (char)((num - 8930) / 8836 + 33);
        string s0(1, c0);
        string s1(1, c1);
        string s2(1, c2);
        return s0 + s1 + s2;
    }
    else if (num > 839513 && num <= 78914409){
        char c0 = (char)((num - 839514) % 94 + 33);
        char c1 = (char)(((num - 839514) % 8836) / 94 + 33);
        char c2 = (char)(((num - 839514) % 830584) / 8836 + 33);
        char c3 = (char)((num - 839514) / 830584 + 33);
        string s0(1, c0);
        string s1(1, c1);
        string s2(1, c2);
        string s3(1, c3);
        return s0 + s1 + s2 + s3;
    }
    else{
        cerr << "Error : from genAscii(Too Big!)" << endl;
        exit(1);
    }
}

// public member function 
void 
Vcd::print(){
    cout << "timescale: " << timescale << endl;
    for (auto& e : data){
        // time
        cout << "@" << e.first << endl;
        for (auto& el : e.second){
            // name & value
            cout << "\t";
            cout << el.first << " " << el.second << endl;
            // (el.first.second == "") ? cout << el.first.first << "     "
            //                         : cout << el.first.first << "[" << el.first.second << "] ";
            // cout << el.second << endl;
        }
    }
    // cout << "timescale: " << timescale << endl;
    // for(auto& e : data){
    //     // name
    //     (e.first.second == "") ? cout << e.first.first << endl
    //                                  : cout << e.first.first << "[" << e.first.second << "]" << endl;
    //     for(auto& elem : e.second){
    //         // time & value
    //         cout << "\t" << elem.first << " " << elem.second << endl;
    //     }
    // }
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
Vcd::readvcd(unsigned long long& dumpoff_time){
    data.clear();
    fstream file;
    // vector<string> v;
    file.open(path, ios::in);
    if (!file) {
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    cout << "Reading vcd..." << endl;
    string buf;
    bool dumpvar_flg = false;
    unsigned long long time = 0;
    while (!file.eof()) {
        getline(file, buf);
        if (buf != "") {
            if (!dumpvar_flg) getsyms(buf);
            if (buf.find("$dumpvars") == 0) dumpvar_flg = true;
            else if (buf[0] == '$') continue;
            else if (buf.find("#") == 0){
                time = stoull(buf.substr(1));
                if (time > dumpoff_time) return;
            }
            else if (dumpvar_flg){
                // array elem
                if (buf[0] == 'b'){
                    size_t pos = buf.find(" ");
                    string bits = buf.substr(1, pos - 1);
                    reverse(bits.begin(), bits.end());
                    string sym = buf.substr(pos + 1);
                    unsigned start = symbols[sym].second.first;
                    unsigned end = symbols[sym].second.second;
                    assert(start < end);
                    for (int j = start;j < end;++j){
                        short value = (j - start > bits.size() - 1) ? convert_val(bits.back()) : convert_val(bits[j - start]);
                        data[time][symbols[sym].first + ' ' + to_string(j)] = value;
                    }
                }
                // one bit
                else {
                    string sym = buf.substr(1);
                    short value = convert_val(buf[0]);
                    data[time][symbols[sym].first] = value;
                }
            }
        }
    }
    file.close();
    return;
}

void 
Vcd::gensyms(string path, GateMgr* mgr){
    cout << "Dumping vcd $var..." << endl;
    // $timescale
    outfile << "$timescale " + timescale + " $end\n";
    // $scope 
    for (int i = 0;i < scopes.size();++i) {
        outfile << "$scope module " << scopes[i] << " $end\n";
    }
    // $var
    int cnt = 0;  
    for (auto& e : mgr -> str2wire){
        if (e.first == "1'b0" || e.first == "1'b1") continue;
        string asc = genAscii(cnt);
        outsyms[e.first] = make_pair(1, asc);
        outfile << "$var wire 1 " + asc + " " + e.first + " $end\n";
        cnt++;
    }
    for (auto& e : mgr -> str2wires){
        string asc = genAscii(cnt);
        assert(!e.second.empty());
        unsigned start = e.second.begin() -> first;
        unsigned end = e.second.rbegin() -> first;
        assert(start < end);
        outsyms[e.first] = make_pair(end - start + 1, asc);
        outfile << "$var wire " + to_string(end - start + 1) + " " + asc + " " + e.first + " " + "[" + to_string(end) + ":" + to_string(start) + "]" + " $end\n";
        cnt++;
    }
    // $upscope $end
    for (int i = 0;i < scopes.size();++i) {
        outfile << "$upscope $end\n";
    }
    // $enddefinitions $end
    outfile << "$enddefinitions $end\n";
    cout << "Finish Dumping vcd $var..." << endl;
}

void
Vcd::writevcd(const Event* e, GateMgr* mgr){
    outfile << ((e -> time == 0) ? "$dumpvars\n" : "#" + to_string(e -> time) + "\n");
    
    unordered_map<string, map<int, short> >  m; // for multi bits
    for (auto& el : e -> changeWires){
        // multi bits
        size_t pos = el.first.find(" ");
        if (pos != string::npos){
            string name = el.first.substr(0, pos);
            int idx = stoi(el.first.substr(pos + 1));
            for (auto& w : mgr->str2wires[name]) {
                if (w.first == idx)
                    m[name][w.first] = el.second;
                else
                    m[name][w.first] = w.second->val;
            }
            // int size = outsyms[name].first;
            // for (int i = 0;i < size;++i){
            //     if (i == idx) 
            //         m[name][idx] = el.second;
            //     else 
            //         m[name][i] = mgr -> str2wires[name][i] -> val;
            // }
        }
        // single bit
        else {
            outfile << convert_short(el.second) << outsyms[el.first].second << '\n';
        }
    }
    // multi bits
    for (auto& el : m){
        int size = outsyms[el.first].first;
        string bits = "";
        for (int i = size - 1;i >= 0 ;--i)
            bits += convert_short(el.second[i]);
        outfile << "b" + bits + " " + outsyms[el.first].second << '\n';
    }
    outfile << ((e -> time == 0) ? "$end\n" : ""); 
}