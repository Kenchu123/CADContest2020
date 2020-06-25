#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void findWire(string, string);
int main(int argc, char *argv[]){
    if(argc != 3){
        cerr << "Usage: ./vcdUtility <vcd_file> <wire_name>";
        exit(1);
    }
    string filepath = argv[1];
    string wirename = argv[2];
    findWire(filepath, wirename);
}

/* find wire
 * Input: string filepath, string wirename
 * Output: print line number and time and value change
 */ 
void findWire(string fp, string wn){
    fstream file;
    file.open(fp, ios::in);
    if (!file) {
        cerr << "Can't open file!" << endl;
        exit(1);  
    }
    else cout << "File open successfully!" << endl;
    cout << "Finding " << "\"" << wn << "\"" << "..." << endl;
    string buf;
    vector<string> lines;
    int wire_lineNo = -1;
    size_t wire_pos;
    while (!file.eof()) {
        getline(file, buf);
        lines.push_back(buf);
    }
    file.close();
    for(int i = 0;i < lines.size();++i){
        wire_pos = lines[i].find(wn);
        if(wire_pos != string::npos){
            wire_lineNo = i;
            cout << wire_lineNo + 1 << "  " << lines[i] << endl;
            break;
        }
    }
    // get token
    string token = "";
    if(wire_lineNo == -1){
       cout << "Not Found" << endl;
       return; 
    }
    else{
        string line = lines[wire_lineNo].substr(0, wire_pos - 1) ;
        size_t pos = line.find_last_of(' ');
        token = line.substr(pos + 1);
    }   
    // get time & value change
    unsigned long long time = 0;
    for(int i = 0;i < lines.size();++i){
        if(lines[i].find("#") == 0)
            time = stoull(lines[i].substr(1));
        else{
            if(lines[i][0] == 'b'){
                size_t a = lines[i].find("0 " + token);
                size_t b = lines[i].find("1 " + token);
                size_t c = lines[i].find("x " + token);
                size_t d = lines[i].find("z " + token);
                if(a != string::npos && lines[i].size() == a + 2 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(b != string::npos && lines[i].size() == b + 2 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(c != string::npos && lines[i].size() == c + 2 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(d != string::npos && lines[i].size() == d + 2 + token.size())
                    cout << time << " " << lines[i] << endl;
            } 
            else if(lines[i].find(token) != string::npos){
                size_t a = lines[i].find("0" + token);
                size_t b = lines[i].find("1" + token);
                size_t c = lines[i].find("x" + token);
                size_t d = lines[i].find("z" + token);
                if(a != string::npos && lines[i].size() == 1 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(b != string::npos && lines[i].size() == 1 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(c != string::npos && lines[i].size() == 1 + token.size())
                    cout << time << " " << lines[i] << endl;
                else if(d != string::npos && lines[i].size() == 1 + token.size())
                    cout << time << " " << lines[i] << endl;
            }
        }
    }
}

