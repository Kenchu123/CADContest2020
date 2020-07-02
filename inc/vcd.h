#ifndef VCD
#define VCD

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <utility>
#include <fstream>
#include "gate.h"
using namespace std;

class Event;
class GateMgr;

typedef unordered_map<string, pair<string, pair<unsigned, unsigned> > > in_strmap;
typedef map<string, pair<unsigned, string> > out_strmap;
// typedef map<pair<string, string>, map<unsigned long long, short> > myvcd;
typedef map<unsigned long long, map<string, short> > myvcd;

class Vcd {
    public:
        in_strmap symbols;
        out_strmap outsyms;
        myvcd data; // myvcd : map<ull, map<pair, short>>
                    // pair is like:
                    // single bit pair<"name", "">
                    // multi bit pair<"name", "idx">
        vector<string> scopes;
        string path; 
        string timescale = "1ps";
        ofstream outfile;
               
        Vcd() {}
        Vcd(string p, string o): path(p) {
            outfile.open(o);
        }
        ~Vcd() {
            outfile.close();
        }
        void print();
        void readvcd();
        void gensyms(string, GateMgr*);
        void writevcd(const Event*, GateMgr*);

    private:
        void trimws(string&);
        vector<string> split(string&, char);
        short convert_val(char);
        string convert_short(short);
        void getsyms(vector<string>&);
        string genAscii(int);
};
#endif