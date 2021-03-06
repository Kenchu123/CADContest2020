#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include "json.hpp"

using json = nlohmann::basic_json<std::map, std::vector, std::string, bool, std::int64_t, std::uint64_t, float>;
using namespace std;

string readfile(string);
void getfileline(string, vector<string>&, char);
void trimws(string&);
vector<string> split(string&, char);
json parseSDF(string, vector<string>&);
json parseGV(string, vector<string>&);

int main(int argc, char *argv[]){
    if(argc != 4 && argc != 5){
        cerr << "Usage: ./GraphPreprocessing.exe <netlist.gv> <netlist.sdf> <std_cells.vlib> [intermediate_representation.file]";
        exit(1);
    }
    string gv_path = argv[1];
    string sdf_path = argv[2];
    string vlib_path = argv[3];
    string output_path = "", gv = "gv_intermediate.json", sdf = "sdf_intermediate.json";
    vector<string> sdf_data;
    vector<string> gv_data;
    json jsonfile_gv;
    json jsonfile_sdf;
    jsonfile_gv = parseGV(gv_path, gv_data);
    jsonfile_sdf = parseSDF(sdf_path, sdf_data);
    if(argc == 4){
        output_path = "intermediate";
    } 
    else{
        output_path = argv[4];
    }
    ofstream outfile_gv(output_path + "/" + gv);
    ofstream outfile_sdf(output_path + "/" + sdf);
    outfile_gv << jsonfile_gv.dump(); // save in one line
    // outfile_gv << jsonfile_gv.dump(4); // save indent line
    outfile_sdf << jsonfile_sdf.dump(); // save in one line
    // outfile_sdf << jsonfile_sdf.dump(4); // save indent line
}

/* 
 * Read in file
 * Input : file path
 * Return : file text (noskipws)
 */
string readfile(string path){
    fstream file;
    string text = "";
    file.open(path, ios::in);
    if(!file){
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    else cout << "File open successfully!" << endl;
    cout << "Reading data from file..." << endl;
    char ch;
    while (file >> noskipws >> ch){
        text += ch;
    }
    file.close();
    return text;
}

/* 
 * Get each line in file to vector& data
 * Input : file path, vector& data, flg
 * flg == 1 -> gv_mode
 * flg == 0 -> sdf_mode
 */ 
void getfileline(string path, vector<string>& data, char del = '\n'){
    fstream file;
    file.open(path, ios::in);
    if (!file) {
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    else cout << "File open successfully!" << endl;
    cout << "Reading data from file..." << endl;
    string buf;
    while (!file.eof()) {
        if (del == '\n') getline(file, buf);
        else getline(file, buf, del);
        data.push_back(buf);
        //cout << buf << endl;
    }
    file.close();
}

/* 
 * Trim whitespace at begin and end
 * Input : string& s
 */ 
void trimws(string& s){
    size_t start = s.find_first_not_of(' ');
    if(start != string::npos) s = s.substr(start);
    size_t end = s.find_last_not_of(' ');
    if(end != string::npos) s = s.substr(0, end + 1);
}

/* 
 * Split string by delimiter and dump to a vector (ws trimed)
 * Input : string& s, char
 * Output : vector<string>
 */ 
vector<string> split(string& s, char delimiter){
    vector<string> tokens;
    string token;
    istringstream Stream(s);
    while(getline(Stream, token, delimiter)){
       trimws(token);
       tokens.push_back(token);
    }
    return tokens;
}

/* 
 * Parse .sdf file in to json format
 * Input : file path, vector& data
 * Reutrn : json object
 */
json parseSDF(string path, vector<string>& data){
    getfileline(path, data);
    json j;
    string type = "", instance = "";
    for(int i = 0;i < data.size();++i){
        size_t fcut = data[i].find_first_of('(');
        size_t lcut = data[i].find_last_of(')');
        if(fcut != string::npos && lcut != string::npos){
            data[i] = data[i].substr(fcut + 1, lcut - fcut - 1);
            // cout << data[i] << endl;

            /* parse timescale
             * ex. (TIMESCALE 1ns) => "timescale":"1ns" 
             */ 
            if(data[i].find("TIMESCALE") == 0){
                j["timescale"] = data[i].substr(10);
            }
            /* parse interconnect(undone)
             * ex. 
             */ 
            else if(data[i].find("INTERCONNECT") == 0){
                //j["interconnect"]
            }
            /* parse celltype & instance
             * ex. (CELLTYPE "GEN_FA_D1") 
             *     (INSTANCE x1111)
             *     => "cell":{"x1111":{"t":"GEN_FA_D1"}
             */ 
            else if(data[i].find("CELLTYPE") == 0){
                type = data[i].substr(10);
                type.pop_back();
            }
            else if(data[i].find("INSTANCE") == 0){
                if(data[i].size() == 8)
                    j["cell"][""]["t"] = type;
                else{
                    j["cell"][data[i].substr(9)]["t"] = type;
                    instance = data[i].substr(9);
                }
            }
            /* parse time delay
             * ex. iopath a co (0.066:0.066:0.066) (0.062:0.062:0.062)
             *     => "cell":{"x1111":{"d":[0.66, 0.62]}
             */ 
            else if (data[i].find("iopath") == 0){
                string io[2] = {};
                float delay[2] = {};
                // string delay[2] = {};
                string d = data[i].substr(7);
                // iopath
                for(int j = 0;j < 2;++j){
                    size_t par_pos_l = d.find_first_of(')');
                    size_t spa_pos = d.find_first_of(' ');
                    if(d[0] == '(' && par_pos_l != string::npos){
                        io[j] = d.substr(0, par_pos_l + 1);
                        d.erase(0, par_pos_l + 2);
                    }
                    else if(spa_pos != string::npos){
                        io[j] = d.substr(0, spa_pos);
                        d.erase(0, spa_pos + 1);
                    }
                    else{
                        cerr << "SDF Parsing error" << endl;
                        exit(1);
                    }
                }
                // delay time
                size_t pos = d.find_first_of(' ');
                string tmp[2] = {}; // ex. tmp[j] = (0.053:0.053:0.053)
                if(pos != string::npos){
                    tmp[0] = d.substr(0, pos);
                    tmp[1] = d.substr(pos + 1);
                }
                else{
                    tmp[0] = tmp[1] = d;
                }
                for(int j = 0;j < 2;++j){
                    size_t col_pos = tmp[j].find_first_of(':');
                    if(col_pos != string::npos){
                        delay[j] = stof(tmp[j].substr(1, col_pos - 1));
                        // delay[j] = tmp[j].substr(1, col_pos - 1);
                    }
                    else{
                        cerr << "SDF Parsing error" << endl;
                        exit(1);
                    }
                }
                j["cell"][instance]["d"][io[0] + ' ' + io[1]] = {delay[0], delay[1]};
                // j["cell"][instance]["d"][io[0] + ' ' + io[1]] = delay[0] + ' ' + delay[1];
            }
        }
    }
    // string prnt = j.dump(4);
    // cout << "################### IN JSONFILE ###################" << endl;
    // cout << prnt << endl;
    return j;
}

json parseGV(string path, vector<string>& data){
    getfileline(path, data, ';');
    json j;
    string module_name = "";
    for (int i = 0; i < data.size(); ++i) {
        size_t pos = 0;
        while ((pos = data[i].find("\r", pos)) != string::npos)
            data[i].erase(pos, 2);
        pos = 0;
        while ((pos = data[i].find("\n", pos)) != string::npos)
            data[i].erase(pos, 1);
        trimws(data[i]);
        // cout << data[i] << endl;

        if(data[i].find("module") != string::npos && i != data.size() - 1){
            module_name = data[i].substr(data[i].find("module") + 6);
            trimws(module_name);
            size_t ws_pos = module_name.find_first_of(' ');
            if(ws_pos == string::npos){
                cerr << "GV Parsing error" << endl;
                exit(1); 
            }
            module_name = module_name.substr(0, ws_pos);
            j["module_name"] = module_name;
            j["input"] = nullptr;
            j["input bitsize"] = nullptr;
            j["output"] = nullptr;
            j["output bitsize"] = nullptr;
            j["wire"] = nullptr;
            j["wire bitsize"] = nullptr;
            j["assign"] = nullptr;
            j["submodule"] = nullptr;
            j["submodule_names"] = nullptr;
        }
        else if(data[i].find("input") == 0){
            string str = data[i].substr(5);
            vector<string> tokens = split(str, ',');
            for(int k = 0;k < tokens.size();++k){
                if(tokens[k][0] == '['){
                    size_t col_pos = tokens[k].find_first_of(':');
                    size_t ws_pos = tokens[k].find_first_of(' ');
                    size_t bra_pos = tokens[k].find_first_of(']');
                    string head = tokens[k].substr(1, col_pos - 1);
                    string tail = tokens[k].substr(col_pos + 1, bra_pos - col_pos - 1);
                    string name = tokens[k].substr(ws_pos + 1);
                    string bits = "";
                    bits = (stoi(head) > stoi(tail))? (tail + ":" + head) : (head + ":" + tail);
                    j["input"] += name;
                    j["input bitsize"] += bits;
                }
                else{
                    j["input"] += tokens[k];
                    j["input bitsize"] += "1";
                }
            }
        }
        else if(data[i].find("output") == 0){
            string str = data[i].substr(6);
            vector<string> tokens = split(str, ',');
            for(int k = 0;k < tokens.size();++k){
                if(tokens[k][0] == '['){
                    size_t col_pos = tokens[k].find_first_of(':');
                    size_t ws_pos = tokens[k].find_first_of(' ');
                    size_t bra_pos = tokens[k].find_first_of(']');
                    string head = tokens[k].substr(1, col_pos - 1);
                    string tail = tokens[k].substr(col_pos + 1, bra_pos - col_pos - 1);
                    string name = tokens[k].substr(ws_pos + 1);
                    string bits = "";
                    bits = (stoi(head) > stoi(tail))? (tail + ":" + head) : (head + ":" + tail);
                    j["output"] += name;
                    j["output bitsize"] += bits;
                }
                else{
                    j["output"] += tokens[k];
                    j["output bitsize"] += "1";
                }
            }
        }
        else if(data[i].find("wire") == 0){
            string str = data[i].substr(4);
            vector<string> tokens = split(str, ',');
            for(int k = 0;k < tokens.size();++k){
                if(tokens[k][0] == '['){
                    size_t col_pos = tokens[k].find_first_of(':');
                    size_t ws_pos = tokens[k].find_first_of(' ');
                    size_t bra_pos = tokens[k].find_first_of(']');
                    string head = tokens[k].substr(1, col_pos - 1);
                    string tail = tokens[k].substr(col_pos + 1, bra_pos - col_pos - 1);
                    string name = tokens[k].substr(ws_pos + 1);
                    string bits = "";
                    bits = (stoi(head) > stoi(tail))? (tail + ":" + head) : (head + ":" + tail);
                    j["wire"] += name;
                    j["wire bitsize"] += bits;
                }
                else{
                    j["wire"] += tokens[k];
                    j["wire bitsize"] += "1";
                }
            }
        }
        else if(data[i].find("assign") == 0){
            string str = data[i].substr(6);
            vector<string> tokens = split(str, '=');
            string name = tokens[0], value = tokens[1], idx_str = "";
            size_t idx_f = name.find_first_of('[');
            size_t idx_l = name.find_first_of(']');
            if(idx_f != string::npos && idx_l != string::npos){
                idx_str = name.substr(idx_f + 1, idx_l - idx_f - 1);
                name = name.substr(0, idx_f);
                j["assign"][name + ' ' + idx_str] = value;
            }
            else j["assign"][name] = value; 
        }
        else if(data[i].find("endmodule") == string::npos && !data[i].empty()){
            size_t par_pos_f = data[i].find_first_of('(');
            size_t par_pos_l = data[i].find_last_of(')');
            if(par_pos_f == string::npos || par_pos_l == string::npos){
                cerr << "GV Parsing error" << endl;
                exit(1); 
            }
            string str = data[i].substr(par_pos_f + 1, par_pos_l - par_pos_f - 1);
            string type_inst = data[i].substr(0, par_pos_f); 
            string type = "", instance = "";
            size_t ws_pos = type_inst.find_first_of(' ');
            type = type_inst.substr(0, ws_pos);
            instance = type_inst.substr(ws_pos);
            trimws(instance);
            j["submodule"][instance]["t"] = type;
            j["submodule_names"] += instance;
            vector<string> tokens = split(str, '.');
            vector<string> parameters, names;
            for(int k = 0;k < tokens.size();++k){
                if(k == 0) continue;
                size_t p_pos_f = tokens[k].find_first_of('(');
                size_t p_pos_l = tokens[k].find_last_of(')');
                if(p_pos_f == string::npos || p_pos_l == string::npos){
                    cerr << "GV Parsing error" << endl;
                    exit(1); 
                }
                string parameter = tokens[k].substr(0, p_pos_f);
                string name = tokens[k].substr(p_pos_f + 1, p_pos_l - p_pos_f - 1);
                trimws(name);
                parameters.push_back(parameter);
                names.push_back(name);
            }
            for(int k = 0;k < names.size();++k){
                j["submodule"][instance]["para"][parameters[k]] = nullptr;
                string idx_str = "";
                if(names[k][0] == '{'){
                    string s = names[k].substr(1, names[k].size() - 2);
                    vector<string> vec = split(s, ',');
                    for(int l = 0;l < vec.size();++l){
                        size_t idx_f = vec[l].find_first_of('[');
                        size_t idx_l = vec[l].find_first_of(']');
                        if(idx_f != string::npos && idx_l != string::npos){
                            idx_str = vec[l].substr(idx_f + 1, idx_l - idx_f - 1);
                            vec[l] = vec[l].substr(0, idx_f);
                            j["submodule"][instance]["para"][parameters[k]] += vec[l] + ' ' + idx_str;
                        }
                        else j["submodule"][instance]["para"][parameters[k]] += vec[l];
                    }
                }
                else{
                    size_t idx_f = names[k].find_first_of('[');
                    size_t idx_l = names[k].find_first_of(']');
                    if(idx_f != string::npos && idx_l != string::npos){
                        idx_str = names[k].substr(idx_f + 1, idx_l - idx_f - 1);
                        names[k] = names[k].substr(0, idx_f);
                        j["submodule"][instance]["para"][parameters[k]] = names[k] + ' ' + idx_str;
                    }
                    else j["submodule"][instance]["para"][parameters[k]] = names[k];
                } 
            }
        }
    }
    // string prnt = j.dump(4);
    // cout << "################### IN JSONFILE ###################" << endl;
    // cout << prnt << endl;
    cout << "input size :" << j["input"].size() << endl;
    cout << "output size :" << j["output"].size() << endl;
    cout << "wire size :" << j["wire"].size() << endl;
    return j;
}
// json parseVlib()
// remember timescale = 1ps







