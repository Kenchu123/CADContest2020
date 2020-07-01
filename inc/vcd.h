#ifndef VCD
#define VCD

#include <vector>
#include <unordered_map>
#include <map>
#include <string>
#include <utility>
using namespace std;

typedef unordered_map<string, pair<string, pair<unsigned, unsigned> > > strmap;
// typedef map<pair<string, string>, map<unsigned long long, short> > myvcd;
typedef map<unsigned long long, map<string, short> > myvcd;

class Vcd {
    public:
        strmap symbols;
        myvcd data; // myvcd : map<ull, map<string, short>>
                    // single bit "name"
                    // multi bit "name idx"
        string path;
        string timescale = "1ps";
               
        Vcd() {}
        Vcd(string p): path(p) {}
        ~Vcd() {}
        void print();
        void readvcd();

    private:
        void trimws(string&);
        vector<string> split(string&, char);
        short convert_val(char);
        void getsyms(vector<string>&);
};
#endif