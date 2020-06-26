#ifndef VLIB
#define VLIB
#include <string>
#include <unordered_map>
#include "wire.h"
using namespace std;

class Cell {
    public:
        Cell() {}
        ~Cell() {}
    private:
    //    virtual void _step() = 0;
    // primitive
       void _and(Wire* o, Wire* a, Wire* b) {
        //    o = a & b;
       }
       void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
        //    o = a & b;
       }
       void _or() {};
};

// class Child: public Cell {
//     public:
//         Child() {}
//         ~Child() {}
//         static void step(unordered_map<string, Wire*> &wire) {
//             _and(wire["x"], wire["y"], wire["out"]);
//             _or(wire["x"], wire["y"], wire["out"]);
//         }
// };
class GEN_SCAN_DF_D2 : public Cell {
    public:
        GEN_SCAN_DF_D2(){}
        ~GEN_SCAN_DF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire *d_i, *q_buf, *sd, *xse, *xsd;
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            xse = new Wire();
            xsd = new Wire();
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _udp_xbuf(xse, wire["se"], wire["1'b1"]);
            _udp_xbuf(xsd, sd, wire["1'b1"]);
            delete d_i;
            delete q_buf;
            delete sd;
            delete xse;
            delete xsd;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_60x21 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        ~GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        static void step(unordered_map<string, Wire*> &wire) {
        }
};
#endif