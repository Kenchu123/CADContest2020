#ifndef VLIB
#define VLIB
#include <string>
#include <iostream>
#include <unordered_map>
#include "wire.h"
using namespace std;

class Cell {
    public:
        Cell() {}
        ~Cell() {} 
        static void check2(Wire* w) {  // if '10', change to '01'
            if(w -> val == 2) w -> val = 1;
        }
        // User Defined Primitives
        static void _udp_xbuf(Wire* o, Wire* i, Wire* check_signal){}
        static void _udp_dff(Wire* q, Wire* d, Wire* clk, Wire* clr, Wire* set, Wire* notifier){}
        static void _udp_tlat(Wire* q, Wire* d, Wire* en, Wire* clr, Wire* set, Wire* notifier){}
        static void _udp_mux2(Wire* z, Wire* i0, Wire* i1, Wire* s){
            /*/ 
             *    i0 i1 s :  z
             *    1  ?  0 :  1
             *    0  ?  0 :  0
             *    ?  1  1 :  1
             *    ?  0  1 :  0
             *    0  0  x :  0
             *    1  1  x :  1
            /*/
            check2(i0); check2(i1); check2(s);
            if (s -> val == 0){
                if (i0 -> val == 3) z -> val = 3;
                else if (i0 -> val == 0) z -> val = 0;
                else z -> val = 1;
            }
            else if (s -> val == 3){
                if (i1 -> val == 3) z -> val = 3;
                else if (i1 -> val == 0) z -> val = 0;
                else z -> val = 1;
            }
            else if (s -> val == 1){
                if (i0 -> val == 3 && i1 -> val == 3) z -> val = 3;
                else if (i0 -> val == 0 && i1 -> val == 0) z -> val = 0;
                else z -> val = 1;
            }
        }
        // Built-in Primitives
        static void _and(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            o -> val = a -> val & b -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            o -> val = a -> val & b -> val & c -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            check2(a); check2(b); check2(c); check2(d);
            o -> val = a -> val & b -> val & c -> val & d -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            o -> val = a -> val | b -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            o -> val = a -> val | b -> val | c -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            check2(a); check2(b); check2(c); check2(d);
            o -> val = a -> val | b -> val | c -> val | d -> val;
        }
        static void _not(Wire* o, Wire* i) {
            check2(i);
            o -> val = ~(i -> val) + 4;
            check2(o);
        }
        static void _buf(Wire* o, Wire* i) {
            check2(i);
            o -> val = i -> val;
        }
        static void _xor(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            if (a -> val == 1 && b -> val == 1) 
                o -> val = 1;
            else{
                o -> val = a -> val ^ b -> val;
                check2(o);
            }
        }
        static void _xor(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            _xor(o, a, b);
            check2(o);
            _xor(o, o, c);
            check2(o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            _and(o, a, b);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            _and(o, a, b, c);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            check2(a); check2(b); check2(c); check2(d);
            _and(o, a, b, c, d);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            _or(o, a, b);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            _or(o, a, b, c);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            check2(a); check2(b); check2(c); check2(d);
            _or(o, a, b, c, d);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b) {
            check2(a); check2(b);
            _xor(o, a, b);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b, Wire* c) {
            check2(a); check2(b); check2(c);
            _xor(o, a, b, c);
            _not(o, o);
        }

    private:
};
class GEN_AND2_D1 : public Cell {
    public:
        GEN_AND2_D1(){}
        ~GEN_AND2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND2_D1 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D2 : public Cell {
    public:
        GEN_AND2_D2(){}
        ~GEN_AND2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND2_D2 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D4 : public Cell {
    public:
        GEN_AND2_D4(){}
        ~GEN_AND2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND2_D4 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D8 : public Cell {
    public:
        GEN_AND2_D8(){}
        ~GEN_AND2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND2_D8 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND3_D1 : public Cell {
    public:
        GEN_AND3_D1(){}
        ~GEN_AND3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND3_D1 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D2 : public Cell {
    public:
        GEN_AND3_D2(){}
        ~GEN_AND3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND3_D2 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D4 : public Cell {
    public:
        GEN_AND3_D4(){}
        ~GEN_AND3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND3_D4 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D8 : public Cell {
    public:
        GEN_AND3_D8(){}
        ~GEN_AND3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND3_D8 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND4_D1 : public Cell {
    public:
        GEN_AND4_D1(){}
        ~GEN_AND4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND4_D1 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D2 : public Cell {
    public:
        GEN_AND4_D2(){}
        ~GEN_AND4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND4_D2 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D4 : public Cell {
    public:
        GEN_AND4_D4(){}
        ~GEN_AND4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND4_D4 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D8 : public Cell {
    public:
        GEN_AND4_D8(){}
        ~GEN_AND4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AND4_D8 running ..." << endl;
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AO211_D1 : public Cell {
    public:
        GEN_AO211_D1(){}
        ~GEN_AO211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO211_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_AO211_D2 : public Cell {
    public:
        GEN_AO211_D2(){}
        ~GEN_AO211_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO211_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_AO211_D4 : public Cell {
    public:
        GEN_AO211_D4(){}
        ~GEN_AO211_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO211_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_AO21_D1 : public Cell {
    public:
        GEN_AO21_D1(){}
        ~GEN_AO21_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO21_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO21_D2 : public Cell {
    public:
        GEN_AO21_D2(){}
        ~GEN_AO21_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO21_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO21_D4 : public Cell {
    public:
        GEN_AO21_D4(){}
        ~GEN_AO21_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO21_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO221_D1 : public Cell {
    public:
        GEN_AO221_D1(){}
        ~GEN_AO221_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO221_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_AO221_D2 : public Cell {
    public:
        GEN_AO221_D2(){}
        ~GEN_AO221_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO221_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_AO221_D4 : public Cell {
    public:
        GEN_AO221_D4(){}
        ~GEN_AO221_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO221_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_AO222_D1 : public Cell {
    public:
        GEN_AO222_D1(){}
        ~GEN_AO222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO222_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AO222_D2 : public Cell {
    public:
        GEN_AO222_D2(){}
        ~GEN_AO222_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO222_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AO222_D4 : public Cell {
    public:
        GEN_AO222_D4(){}
        ~GEN_AO222_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO222_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AO22_D1 : public Cell {
    public:
        GEN_AO22_D1(){}
        ~GEN_AO22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO22_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO22_D2 : public Cell {
    public:
        GEN_AO22_D2(){}
        ~GEN_AO22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO22_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO22_D4 : public Cell {
    public:
        GEN_AO22_D4(){}
        ~GEN_AO22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO22_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO22_D8 : public Cell {
    public:
        GEN_AO22_D8(){}
        ~GEN_AO22_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO22_D8 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO31_D1 : public Cell {
    public:
        GEN_AO31_D1(){}
        ~GEN_AO31_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO31_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO31_D2 : public Cell {
    public:
        GEN_AO31_D2(){}
        ~GEN_AO31_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO31_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO31_D4 : public Cell {
    public:
        GEN_AO31_D4(){}
        ~GEN_AO31_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO31_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_AO32_D1 : public Cell {
    public:
        GEN_AO32_D1(){}
        ~GEN_AO32_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO32_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO32_D2 : public Cell {
    public:
        GEN_AO32_D2(){}
        ~GEN_AO32_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO32_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO32_D4 : public Cell {
    public:
        GEN_AO32_D4(){}
        ~GEN_AO32_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO32_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO33_D1 : public Cell {
    public:
        GEN_AO33_D1(){}
        ~GEN_AO33_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO33_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"], wire["b3"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO33_D2 : public Cell {
    public:
        GEN_AO33_D2(){}
        ~GEN_AO33_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO33_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"], wire["b3"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AO33_D4 : public Cell {
    public:
        GEN_AO33_D4(){}
        ~GEN_AO33_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AO33_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["b1"], wire["b2"], wire["b3"]);
            _and(net1, wire["a1"], wire["a2"], wire["a3"]);
            _or(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI211_D1 : public Cell {
    public:
        GEN_AOI211_D1(){}
        ~GEN_AOI211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI211_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI211_D2 : public Cell {
    public:
        GEN_AOI211_D2(){}
        ~GEN_AOI211_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI211_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI211_D4 : public Cell {
    public:
        GEN_AOI211_D4(){}
        ~GEN_AOI211_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI211_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI21_D1 : public Cell {
    public:
        GEN_AOI21_D1(){}
        ~GEN_AOI21_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI21_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI21_D2 : public Cell {
    public:
        GEN_AOI21_D2(){}
        ~GEN_AOI21_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI21_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI21_D4 : public Cell {
    public:
        GEN_AOI21_D4(){}
        ~GEN_AOI21_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI21_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI221_D1 : public Cell {
    public:
        GEN_AOI221_D1(){}
        ~GEN_AOI221_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI221_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI221_D2 : public Cell {
    public:
        GEN_AOI221_D2(){}
        ~GEN_AOI221_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI221_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI221_D4 : public Cell {
    public:
        GEN_AOI221_D4(){}
        ~GEN_AOI221_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI221_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI222_D1 : public Cell {
    public:
        GEN_AOI222_D1(){}
        ~GEN_AOI222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI222_D1 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_AOI222_D2 : public Cell {
    public:
        GEN_AOI222_D2(){}
        ~GEN_AOI222_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI222_D2 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_AOI222_D4 : public Cell {
    public:
        GEN_AOI222_D4(){}
        ~GEN_AOI222_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI222_D4 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["c1"], wire["c2"]);
            _and(net1, wire["a1"], wire["a2"]);
            _and(net2, wire["b1"], wire["b2"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_AOI22_D1 : public Cell {
    public:
        GEN_AOI22_D1(){}
        ~GEN_AOI22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI22_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI22_D2 : public Cell {
    public:
        GEN_AOI22_D2(){}
        ~GEN_AOI22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI22_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI22_D4 : public Cell {
    public:
        GEN_AOI22_D4(){}
        ~GEN_AOI22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI22_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI31_D1 : public Cell {
    public:
        GEN_AOI31_D1(){}
        ~GEN_AOI31_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI31_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI31_D2 : public Cell {
    public:
        GEN_AOI31_D2(){}
        ~GEN_AOI31_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI31_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI31_D4 : public Cell {
    public:
        GEN_AOI31_D4(){}
        ~GEN_AOI31_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI31_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_AOI32_D1 : public Cell {
    public:
        GEN_AOI32_D1(){}
        ~GEN_AOI32_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI32_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI32_D2 : public Cell {
    public:
        GEN_AOI32_D2(){}
        ~GEN_AOI32_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI32_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI32_D4 : public Cell {
    public:
        GEN_AOI32_D4(){}
        ~GEN_AOI32_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI32_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI33_D1 : public Cell {
    public:
        GEN_AOI33_D1(){}
        ~GEN_AOI33_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI33_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"], wire["b3"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI33_D2 : public Cell {
    public:
        GEN_AOI33_D2(){}
        ~GEN_AOI33_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI33_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"], wire["b3"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_AOI33_D4 : public Cell {
    public:
        GEN_AOI33_D4(){}
        ~GEN_AOI33_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_AOI33_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, wire["b1"], wire["b2"], wire["b3"]);
            _or(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_BUF_D1 : public Cell {
    public:
        GEN_BUF_D1(){}
        ~GEN_BUF_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_BUF_D1 running ..." << endl;
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D2 : public Cell {
    public:
        GEN_BUF_D2(){}
        ~GEN_BUF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_BUF_D2 running ..." << endl;
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D4 : public Cell {
    public:
        GEN_BUF_D4(){}
        ~GEN_BUF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_BUF_D4 running ..." << endl;
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D8 : public Cell {
    public:
        GEN_BUF_D8(){}
        ~GEN_BUF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_BUF_D8 running ..." << endl;
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_FA_D1 : public Cell {
    public:
        GEN_FA_D1(){}
        ~GEN_FA_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_FA_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _xor(wire["s"], wire["a"], wire["b"], wire["ci"]);
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["a"], wire["ci"]);
            _and(net2, wire["b"], wire["ci"]);
            _or(wire["co"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_FA_D2 : public Cell {
    public:
        GEN_FA_D2(){}
        ~GEN_FA_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_FA_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _xor(wire["s"], wire["a"], wire["b"], wire["ci"]);
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["a"], wire["ci"]);
            _and(net2, wire["b"], wire["ci"]);
            _or(wire["co"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_FA_D4 : public Cell {
    public:
        GEN_FA_D4(){}
        ~GEN_FA_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_FA_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _xor(wire["s"], wire["a"], wire["b"], wire["ci"]);
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["a"], wire["ci"]);
            _and(net2, wire["b"], wire["ci"]);
            _or(wire["co"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_HA_D1 : public Cell {
    public:
        GEN_HA_D1(){}
        ~GEN_HA_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_HA_D1 running ..." << endl;
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_HA_D2 : public Cell {
    public:
        GEN_HA_D2(){}
        ~GEN_HA_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_HA_D2 running ..." << endl;
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_HA_D4 : public Cell {
    public:
        GEN_HA_D4(){}
        ~GEN_HA_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_HA_D4 running ..." << endl;
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_INV_D1 : public Cell {
    public:
        GEN_INV_D1(){}
        ~GEN_INV_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_INV_D1 running ..." << endl;
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D2 : public Cell {
    public:
        GEN_INV_D2(){}
        ~GEN_INV_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_INV_D2 running ..." << endl;
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D4 : public Cell {
    public:
        GEN_INV_D4(){}
        ~GEN_INV_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_INV_D4 running ..." << endl;
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D8 : public Cell {
    public:
        GEN_INV_D8(){}
        ~GEN_INV_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_INV_D8 running ..." << endl;
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_MAJORITYAOI222_D1 : public Cell {
    public:
        GEN_MAJORITYAOI222_D1(){}
        ~GEN_MAJORITYAOI222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI222_D1 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["b"], wire["c"]);
            _and(net2, wire["c"], wire["a"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_MAJORITYAOI222_D2 : public Cell {
    public:
        GEN_MAJORITYAOI222_D2(){}
        ~GEN_MAJORITYAOI222_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI222_D2 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["b"], wire["c"]);
            _and(net2, wire["c"], wire["a"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_MAJORITYAOI222_D4 : public Cell {
    public:
        GEN_MAJORITYAOI222_D4(){}
        ~GEN_MAJORITYAOI222_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI222_D4 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _and(net0, wire["a"], wire["b"]);
            _and(net1, wire["b"], wire["c"]);
            _and(net2, wire["c"], wire["a"]);
            _or(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_MAJORITYAOI22_D1 : public Cell {
    public:
        GEN_MAJORITYAOI22_D1(){}
        ~GEN_MAJORITYAOI22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI22_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MAJORITYAOI22_D2 : public Cell {
    public:
        GEN_MAJORITYAOI22_D2(){}
        ~GEN_MAJORITYAOI22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI22_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MAJORITYAOI22_D4 : public Cell {
    public:
        GEN_MAJORITYAOI22_D4(){}
        ~GEN_MAJORITYAOI22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYAOI22_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _and(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MAJORITYOAI22_D1 : public Cell {
    public:
        GEN_MAJORITYOAI22_D1(){}
        ~GEN_MAJORITYOAI22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYOAI22_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MAJORITYOAI22_D2 : public Cell {
    public:
        GEN_MAJORITYOAI22_D2(){}
        ~GEN_MAJORITYOAI22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYOAI22_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MAJORITYOAI22_D4 : public Cell {
    public:
        GEN_MAJORITYOAI22_D4(){}
        ~GEN_MAJORITYOAI22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MAJORITYOAI22_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _not(net1, net0);
            _and(net2, wire["b1"], wire["b2"]);
            _or(wire["zn"], net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_LATCH_D1 : public Cell {
    public:
        GEN_LATCH_D1(){}
        ~GEN_LATCH_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_LATCH_D1 running ..." << endl;
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_LATCH_D2 : public Cell {
    public:
        GEN_LATCH_D2(){}
        ~GEN_LATCH_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_LATCH_D2 running ..." << endl;
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_LATCH_D4 : public Cell {
    public:
        GEN_LATCH_D4(){}
        ~GEN_LATCH_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_LATCH_D4 running ..." << endl;
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFCLR_D1 : public Cell {
    public:
        GEN_DFCLR_D1(){}
        ~GEN_DFCLR_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFCLR_D1 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFCLR_D2 : public Cell {
    public:
        GEN_DFCLR_D2(){}
        ~GEN_DFCLR_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFCLR_D2 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFCLR_D4 : public Cell {
    public:
        GEN_DFCLR_D4(){}
        ~GEN_DFCLR_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFCLR_D4 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFCLR_D8 : public Cell {
    public:
        GEN_DFCLR_D8(){}
        ~GEN_DFCLR_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFCLR_D8 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DF_D1 : public Cell {
    public:
        GEN_DF_D1(){}
        ~GEN_DF_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DF_D1 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DF_D2 : public Cell {
    public:
        GEN_DF_D2(){}
        ~GEN_DF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DF_D2 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DF_D4 : public Cell {
    public:
        GEN_DF_D4(){}
        ~GEN_DF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DF_D4 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DF_D8 : public Cell {
    public:
        GEN_DF_D8(){}
        ~GEN_DF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DF_D8 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFSET_D1 : public Cell {
    public:
        GEN_DFSET_D1(){}
        ~GEN_DFSET_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFSET_D1 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFSET_D2 : public Cell {
    public:
        GEN_DFSET_D2(){}
        ~GEN_DFSET_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFSET_D2 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFSET_D4 : public Cell {
    public:
        GEN_DFSET_D4(){}
        ~GEN_DFSET_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFSET_D4 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_DFSET_D8 : public Cell {
    public:
        GEN_DFSET_D8(){}
        ~GEN_DFSET_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_DFSET_D8 running ..." << endl;
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], wire["notifier"]);
        }
};
class GEN_MUX2_D1 : public Cell {
    public:
        GEN_MUX2_D1(){}
        ~GEN_MUX2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2_D1 running ..." << endl;
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2_D2 : public Cell {
    public:
        GEN_MUX2_D2(){}
        ~GEN_MUX2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2_D2 running ..." << endl;
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2_D4 : public Cell {
    public:
        GEN_MUX2_D4(){}
        ~GEN_MUX2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2_D4 running ..." << endl;
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2N_D1 : public Cell {
    public:
        GEN_MUX2N_D1(){}
        ~GEN_MUX2N_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2N_D1 running ..." << endl;
            Wire *z;
            z = new Wire();
            _udp_mux2(z, wire["i0"], wire["i1"], wire["s"]);
            _not(wire["zn"], z);
            delete z;
        }
};
class GEN_MUX2N_D2 : public Cell {
    public:
        GEN_MUX2N_D2(){}
        ~GEN_MUX2N_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2N_D2 running ..." << endl;
            Wire *z;
            z = new Wire();
            _udp_mux2(z, wire["i0"], wire["i1"], wire["s"]);
            _not(wire["zn"], z);
            delete z;
        }
};
class GEN_MUX2N_D4 : public Cell {
    public:
        GEN_MUX2N_D4(){}
        ~GEN_MUX2N_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX2N_D4 running ..." << endl;
            Wire *z;
            z = new Wire();
            _udp_mux2(z, wire["i0"], wire["i1"], wire["s"]);
            _not(wire["zn"], z);
            delete z;
        }
};
class GEN_MUX3_D1 : public Cell {
    public:
        GEN_MUX3_D1(){}
        ~GEN_MUX3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net0, wire["i2"], wire["s1"]);
            delete net0;
        }
};
class GEN_MUX3_D2 : public Cell {
    public:
        GEN_MUX3_D2(){}
        ~GEN_MUX3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net0, wire["i2"], wire["s1"]);
            delete net0;
        }
};
class GEN_MUX3_D4 : public Cell {
    public:
        GEN_MUX3_D4(){}
        ~GEN_MUX3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net0, wire["i2"], wire["s1"]);
            delete net0;
        }
};
class GEN_MUX3N_D1 : public Cell {
    public:
        GEN_MUX3N_D1(){}
        ~GEN_MUX3N_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3N_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net1, net0, wire["i2"], wire["s1"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_MUX3N_D2 : public Cell {
    public:
        GEN_MUX3N_D2(){}
        ~GEN_MUX3N_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3N_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net1, net0, wire["i2"], wire["s1"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_MUX3N_D4 : public Cell {
    public:
        GEN_MUX3N_D4(){}
        ~GEN_MUX3N_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX3N_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net1, net0, wire["i2"], wire["s1"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_MUX4_D1 : public Cell {
    public:
        GEN_MUX4_D1(){}
        ~GEN_MUX4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net1, net0, wire["s1"]);
            delete net0;
            delete net1;
        }
};
class GEN_MUX4_D2 : public Cell {
    public:
        GEN_MUX4_D2(){}
        ~GEN_MUX4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net1, net0, wire["s1"]);
            delete net0;
            delete net1;
        }
};
class GEN_MUX4_D4 : public Cell {
    public:
        GEN_MUX4_D4(){}
        ~GEN_MUX4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(wire["z"], net1, net0, wire["s1"]);
            delete net0;
            delete net1;
        }
};
class GEN_MUX4N_D1 : public Cell {
    public:
        GEN_MUX4N_D1(){}
        ~GEN_MUX4N_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4N_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net2, net1, net0, wire["s1"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MUX4N_D2 : public Cell {
    public:
        GEN_MUX4N_D2(){}
        ~GEN_MUX4N_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4N_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net2, net1, net0, wire["s1"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_MUX4N_D4 : public Cell {
    public:
        GEN_MUX4N_D4(){}
        ~GEN_MUX4N_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_MUX4N_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _udp_mux2(net0, wire["i2"], wire["i3"], wire["s0"]);
            _udp_mux2(net1, wire["i0"], wire["i1"], wire["s0"]);
            _udp_mux2(net2, net1, net0, wire["s1"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_NAND2_D1 : public Cell {
    public:
        GEN_NAND2_D1(){}
        ~GEN_NAND2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND2_D1 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D2 : public Cell {
    public:
        GEN_NAND2_D2(){}
        ~GEN_NAND2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND2_D2 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D4 : public Cell {
    public:
        GEN_NAND2_D4(){}
        ~GEN_NAND2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND2_D4 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D8 : public Cell {
    public:
        GEN_NAND2_D8(){}
        ~GEN_NAND2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND2_D8 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND3_D1 : public Cell {
    public:
        GEN_NAND3_D1(){}
        ~GEN_NAND3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND3_D1 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D2 : public Cell {
    public:
        GEN_NAND3_D2(){}
        ~GEN_NAND3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND3_D2 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D4 : public Cell {
    public:
        GEN_NAND3_D4(){}
        ~GEN_NAND3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND3_D4 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D8 : public Cell {
    public:
        GEN_NAND3_D8(){}
        ~GEN_NAND3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND3_D8 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND4_D1 : public Cell {
    public:
        GEN_NAND4_D1(){}
        ~GEN_NAND4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND4_D1 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D2 : public Cell {
    public:
        GEN_NAND4_D2(){}
        ~GEN_NAND4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND4_D2 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D4 : public Cell {
    public:
        GEN_NAND4_D4(){}
        ~GEN_NAND4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND4_D4 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D8 : public Cell {
    public:
        GEN_NAND4_D8(){}
        ~GEN_NAND4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NAND4_D8 running ..." << endl;
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR2_D1 : public Cell {
    public:
        GEN_NOR2_D1(){}
        ~GEN_NOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR2_D1 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D2 : public Cell {
    public:
        GEN_NOR2_D2(){}
        ~GEN_NOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR2_D2 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D4 : public Cell {
    public:
        GEN_NOR2_D4(){}
        ~GEN_NOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR2_D4 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D8 : public Cell {
    public:
        GEN_NOR2_D8(){}
        ~GEN_NOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR2_D8 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR3_D1 : public Cell {
    public:
        GEN_NOR3_D1(){}
        ~GEN_NOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR3_D1 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D2 : public Cell {
    public:
        GEN_NOR3_D2(){}
        ~GEN_NOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR3_D2 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D4 : public Cell {
    public:
        GEN_NOR3_D4(){}
        ~GEN_NOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR3_D4 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D8 : public Cell {
    public:
        GEN_NOR3_D8(){}
        ~GEN_NOR3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR3_D8 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR4_D1 : public Cell {
    public:
        GEN_NOR4_D1(){}
        ~GEN_NOR4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR4_D1 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D2 : public Cell {
    public:
        GEN_NOR4_D2(){}
        ~GEN_NOR4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR4_D2 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D4 : public Cell {
    public:
        GEN_NOR4_D4(){}
        ~GEN_NOR4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR4_D4 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D8 : public Cell {
    public:
        GEN_NOR4_D8(){}
        ~GEN_NOR4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_NOR4_D8 running ..." << endl;
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OA211_D1 : public Cell {
    public:
        GEN_OA211_D1(){}
        ~GEN_OA211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA211_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_OA211_D2 : public Cell {
    public:
        GEN_OA211_D2(){}
        ~GEN_OA211_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA211_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_OA211_D4 : public Cell {
    public:
        GEN_OA211_D4(){}
        ~GEN_OA211_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA211_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"], wire["c"]);
            delete net0;
        }
};
class GEN_OA21_D1 : public Cell {
    public:
        GEN_OA21_D1(){}
        ~GEN_OA21_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA21_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA21_D2 : public Cell {
    public:
        GEN_OA21_D2(){}
        ~GEN_OA21_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA21_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA21_D4 : public Cell {
    public:
        GEN_OA21_D4(){}
        ~GEN_OA21_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA21_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA221_D1 : public Cell {
    public:
        GEN_OA221_D1(){}
        ~GEN_OA221_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA221_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_OA221_D2 : public Cell {
    public:
        GEN_OA221_D2(){}
        ~GEN_OA221_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA221_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_OA221_D4 : public Cell {
    public:
        GEN_OA221_D4(){}
        ~GEN_OA221_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA221_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1, wire["c"]);
            delete net0;
            delete net1;
        }
};
class GEN_OA222_D1 : public Cell {
    public:
        GEN_OA222_D1(){}
        ~GEN_OA222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA222_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["c1"], wire["c2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OA222_D2 : public Cell {
    public:
        GEN_OA222_D2(){}
        ~GEN_OA222_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA222_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["c1"], wire["c2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OA222_D4 : public Cell {
    public:
        GEN_OA222_D4(){}
        ~GEN_OA222_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA222_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["c1"], wire["c2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(wire["z"], net0, net1, net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OA22_D1 : public Cell {
    public:
        GEN_OA22_D1(){}
        ~GEN_OA22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA22_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA22_D2 : public Cell {
    public:
        GEN_OA22_D2(){}
        ~GEN_OA22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA22_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA22_D4 : public Cell {
    public:
        GEN_OA22_D4(){}
        ~GEN_OA22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA22_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA31_D1 : public Cell {
    public:
        GEN_OA31_D1(){}
        ~GEN_OA31_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA31_D1 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA31_D2 : public Cell {
    public:
        GEN_OA31_D2(){}
        ~GEN_OA31_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA31_D2 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA31_D4 : public Cell {
    public:
        GEN_OA31_D4(){}
        ~GEN_OA31_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA31_D4 running ..." << endl;
            Wire *net0;
            net0 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, wire["b"]);
            delete net0;
        }
};
class GEN_OA32_D1 : public Cell {
    public:
        GEN_OA32_D1(){}
        ~GEN_OA32_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA32_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA32_D2 : public Cell {
    public:
        GEN_OA32_D2(){}
        ~GEN_OA32_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA32_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA32_D4 : public Cell {
    public:
        GEN_OA32_D4(){}
        ~GEN_OA32_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA32_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA33_D1 : public Cell {
    public:
        GEN_OA33_D1(){}
        ~GEN_OA33_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA33_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"], wire["b3"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA33_D2 : public Cell {
    public:
        GEN_OA33_D2(){}
        ~GEN_OA33_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA33_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"], wire["b3"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OA33_D4 : public Cell {
    public:
        GEN_OA33_D4(){}
        ~GEN_OA33_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OA33_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["b1"], wire["b2"], wire["b3"]);
            _or(net1, wire["a1"], wire["a2"], wire["a3"]);
            _and(wire["z"], net0, net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI211_D1 : public Cell {
    public:
        GEN_OAI211_D1(){}
        ~GEN_OAI211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI211_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI211_D2 : public Cell {
    public:
        GEN_OAI211_D2(){}
        ~GEN_OAI211_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI211_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI211_D4 : public Cell {
    public:
        GEN_OAI211_D4(){}
        ~GEN_OAI211_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI211_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"], wire["c"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI21_D1 : public Cell {
    public:
        GEN_OAI21_D1(){}
        ~GEN_OAI21_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI21_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI21_D2 : public Cell {
    public:
        GEN_OAI21_D2(){}
        ~GEN_OAI21_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI21_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI21_D4 : public Cell {
    public:
        GEN_OAI21_D4(){}
        ~GEN_OAI21_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI21_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI221_D1 : public Cell {
    public:
        GEN_OAI221_D1(){}
        ~GEN_OAI221_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI221_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI221_D2 : public Cell {
    public:
        GEN_OAI221_D2(){}
        ~GEN_OAI221_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI221_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI221_D4 : public Cell {
    public:
        GEN_OAI221_D4(){}
        ~GEN_OAI221_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI221_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1, wire["c"]);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI222_D1 : public Cell {
    public:
        GEN_OAI222_D1(){}
        ~GEN_OAI222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI222_D1 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _or(net0, wire["c1"], wire["c2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_OAI222_D2 : public Cell {
    public:
        GEN_OAI222_D2(){}
        ~GEN_OAI222_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI222_D2 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _or(net0, wire["c1"], wire["c2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_OAI222_D4 : public Cell {
    public:
        GEN_OAI222_D4(){}
        ~GEN_OAI222_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI222_D4 running ..." << endl;
            Wire *net0, *net1, *net2, *net3;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            net3 = new Wire();
            _or(net0, wire["c1"], wire["c2"]);
            _or(net1, wire["a1"], wire["a2"]);
            _or(net2, wire["b1"], wire["b2"]);
            _and(net3, net0, net1, net2);
            _not(wire["zn"], net3);
            delete net0;
            delete net1;
            delete net2;
            delete net3;
        }
};
class GEN_OAI22_D1 : public Cell {
    public:
        GEN_OAI22_D1(){}
        ~GEN_OAI22_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI22_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI22_D2 : public Cell {
    public:
        GEN_OAI22_D2(){}
        ~GEN_OAI22_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI22_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI22_D4 : public Cell {
    public:
        GEN_OAI22_D4(){}
        ~GEN_OAI22_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI22_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI31_D1 : public Cell {
    public:
        GEN_OAI31_D1(){}
        ~GEN_OAI31_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI31_D1 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI31_D2 : public Cell {
    public:
        GEN_OAI31_D2(){}
        ~GEN_OAI31_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI31_D2 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI31_D4 : public Cell {
    public:
        GEN_OAI31_D4(){}
        ~GEN_OAI31_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI31_D4 running ..." << endl;
            Wire *net0, *net1;
            net0 = new Wire();
            net1 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _and(net1, net0, wire["b"]);
            _not(wire["zn"], net1);
            delete net0;
            delete net1;
        }
};
class GEN_OAI32_D1 : public Cell {
    public:
        GEN_OAI32_D1(){}
        ~GEN_OAI32_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI32_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI32_D2 : public Cell {
    public:
        GEN_OAI32_D2(){}
        ~GEN_OAI32_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI32_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI32_D4 : public Cell {
    public:
        GEN_OAI32_D4(){}
        ~GEN_OAI32_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI32_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI33_D1 : public Cell {
    public:
        GEN_OAI33_D1(){}
        ~GEN_OAI33_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI33_D1 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"], wire["b3"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI33_D2 : public Cell {
    public:
        GEN_OAI33_D2(){}
        ~GEN_OAI33_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI33_D2 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"], wire["b3"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OAI33_D4 : public Cell {
    public:
        GEN_OAI33_D4(){}
        ~GEN_OAI33_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OAI33_D4 running ..." << endl;
            Wire *net0, *net1, *net2;
            net0 = new Wire();
            net1 = new Wire();
            net2 = new Wire();
            _or(net0, wire["a1"], wire["a2"], wire["a3"]);
            _or(net1, wire["b1"], wire["b2"], wire["b3"]);
            _and(net2, net0, net1);
            _not(wire["zn"], net2);
            delete net0;
            delete net1;
            delete net2;
        }
};
class GEN_OR2_D1 : public Cell {
    public:
        GEN_OR2_D1(){}
        ~GEN_OR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR2_D1 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D2 : public Cell {
    public:
        GEN_OR2_D2(){}
        ~GEN_OR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR2_D2 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D4 : public Cell {
    public:
        GEN_OR2_D4(){}
        ~GEN_OR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR2_D4 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D8 : public Cell {
    public:
        GEN_OR2_D8(){}
        ~GEN_OR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR2_D8 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR3_D1 : public Cell {
    public:
        GEN_OR3_D1(){}
        ~GEN_OR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR3_D1 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D2 : public Cell {
    public:
        GEN_OR3_D2(){}
        ~GEN_OR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR3_D2 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D4 : public Cell {
    public:
        GEN_OR3_D4(){}
        ~GEN_OR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR3_D4 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D8 : public Cell {
    public:
        GEN_OR3_D8(){}
        ~GEN_OR3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR3_D8 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR4_D1 : public Cell {
    public:
        GEN_OR4_D1(){}
        ~GEN_OR4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR4_D1 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D2 : public Cell {
    public:
        GEN_OR4_D2(){}
        ~GEN_OR4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR4_D2 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D4 : public Cell {
    public:
        GEN_OR4_D4(){}
        ~GEN_OR4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR4_D4 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D8 : public Cell {
    public:
        GEN_OR4_D8(){}
        ~GEN_OR4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_OR4_D8 running ..." << endl;
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_SCAN_DFCLR_D1 : public Cell {
    public:
        GEN_SCAN_DFCLR_D1(){}
        ~GEN_SCAN_DFCLR_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFCLR_D1 running ..." << endl;
            Wire *cdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *se1, *se_check, *xsi_check, *xd_check, *xcdn_i;
            cdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            se1 = new Wire();
            se_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xcdn_i = new Wire();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, cdn_i, wire["se"]);
            _and(d_check, cdn_i, sd);
            _xor(se1, wire["si"], wire["d"]);
            _and(se_check, se1, cdn_i);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xcdn_i, cdn_i, wire["1'b1"]);
            delete cdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete se1;
            delete se_check;
            delete xsi_check;
            delete xd_check;
            delete xcdn_i;
        }
};
class GEN_SCAN_DFCLR_D2 : public Cell {
    public:
        GEN_SCAN_DFCLR_D2(){}
        ~GEN_SCAN_DFCLR_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFCLR_D2 running ..." << endl;
            Wire *cdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *se1, *se_check, *xsi_check, *xd_check, *xcdn_i;
            cdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            se1 = new Wire();
            se_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xcdn_i = new Wire();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, cdn_i, wire["se"]);
            _and(d_check, cdn_i, sd);
            _xor(se1, wire["si"], wire["d"]);
            _and(se_check, se1, cdn_i);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xcdn_i, cdn_i, wire["1'b1"]);
            delete cdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete se1;
            delete se_check;
            delete xsi_check;
            delete xd_check;
            delete xcdn_i;
        }
};
class GEN_SCAN_DFCLR_D4 : public Cell {
    public:
        GEN_SCAN_DFCLR_D4(){}
        ~GEN_SCAN_DFCLR_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFCLR_D4 running ..." << endl;
            Wire *cdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *se1, *se_check, *xsi_check, *xd_check, *xcdn_i;
            cdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            se1 = new Wire();
            se_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xcdn_i = new Wire();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, cdn_i, wire["se"]);
            _and(d_check, cdn_i, sd);
            _xor(se1, wire["si"], wire["d"]);
            _and(se_check, se1, cdn_i);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xcdn_i, cdn_i, wire["1'b1"]);
            delete cdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete se1;
            delete se_check;
            delete xsi_check;
            delete xd_check;
            delete xcdn_i;
        }
};
class GEN_SCAN_DFCLR_D8 : public Cell {
    public:
        GEN_SCAN_DFCLR_D8(){}
        ~GEN_SCAN_DFCLR_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFCLR_D8 running ..." << endl;
            Wire *cdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *se1, *se_check, *xsi_check, *xd_check, *xcdn_i;
            cdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            se1 = new Wire();
            se_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xcdn_i = new Wire();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, cdn_i, wire["se"]);
            _and(d_check, cdn_i, sd);
            _xor(se1, wire["si"], wire["d"]);
            _and(se_check, se1, cdn_i);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xcdn_i, cdn_i, wire["1'b1"]);
            delete cdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete se1;
            delete se_check;
            delete xsi_check;
            delete xd_check;
            delete xcdn_i;
        }
};
class GEN_SCAN_DF_D1 : public Cell {
    public:
        GEN_SCAN_DF_D1(){}
        ~GEN_SCAN_DF_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DF_D1 running ..." << endl;
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
class GEN_SCAN_DF_D2 : public Cell {
    public:
        GEN_SCAN_DF_D2(){}
        ~GEN_SCAN_DF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DF_D2 running ..." << endl;
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
class GEN_SCAN_DF_D4 : public Cell {
    public:
        GEN_SCAN_DF_D4(){}
        ~GEN_SCAN_DF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DF_D4 running ..." << endl;
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
class GEN_SCAN_DF_D8 : public Cell {
    public:
        GEN_SCAN_DF_D8(){}
        ~GEN_SCAN_DF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DF_D8 running ..." << endl;
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
class GEN_SCAN_DFSET_D1 : public Cell {
    public:
        GEN_SCAN_DFSET_D1(){}
        ~GEN_SCAN_DFSET_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFSET_D1 running ..." << endl;
            Wire *sdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *xsi_check, *xd_check, *xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, sdn_i, wire["se"]);
            _and(d_check, sdn_i, sd);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xsdn_i, sdn_i, wire["1'b1"]);
            delete sdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete xsi_check;
            delete xd_check;
            delete xsdn_i;
        }
};
class GEN_SCAN_DFSET_D2 : public Cell {
    public:
        GEN_SCAN_DFSET_D2(){}
        ~GEN_SCAN_DFSET_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFSET_D2 running ..." << endl;
            Wire *sdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *xsi_check, *xd_check, *xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, sdn_i, wire["se"]);
            _and(d_check, sdn_i, sd);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xsdn_i, sdn_i, wire["1'b1"]);
            delete sdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete xsi_check;
            delete xd_check;
            delete xsdn_i;
        }
};
class GEN_SCAN_DFSET_D4 : public Cell {
    public:
        GEN_SCAN_DFSET_D4(){}
        ~GEN_SCAN_DFSET_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFSET_D4 running ..." << endl;
            Wire *sdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *xsi_check, *xd_check, *xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, sdn_i, wire["se"]);
            _and(d_check, sdn_i, sd);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xsdn_i, sdn_i, wire["1'b1"]);
            delete sdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete xsi_check;
            delete xd_check;
            delete xsdn_i;
        }
};
class GEN_SCAN_DFSET_D8 : public Cell {
    public:
        GEN_SCAN_DFSET_D8(){}
        ~GEN_SCAN_DFSET_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SCAN_DFSET_D8 running ..." << endl;
            Wire *sdn_i, *d_i, *q_buf, *sd, *si_check, *d_check, *xsi_check, *xd_check, *xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, wire["notifier"]);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _and(si_check, sdn_i, wire["se"]);
            _and(d_check, sdn_i, sd);
            _udp_xbuf(xsi_check, si_check, wire["1'b1"]);
            _udp_xbuf(xd_check, d_check, wire["1'b1"]);
            _udp_xbuf(xsdn_i, sdn_i, wire["1'b1"]);
            delete sdn_i;
            delete d_i;
            delete q_buf;
            delete sd;
            delete si_check;
            delete d_check;
            delete xsi_check;
            delete xd_check;
            delete xsdn_i;
        }
};
class GEN_XNOR2_D1 : public Cell {
    public:
        GEN_XNOR2_D1(){}
        ~GEN_XNOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR2_D1 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D2 : public Cell {
    public:
        GEN_XNOR2_D2(){}
        ~GEN_XNOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR2_D2 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D4 : public Cell {
    public:
        GEN_XNOR2_D4(){}
        ~GEN_XNOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR2_D4 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D8 : public Cell {
    public:
        GEN_XNOR2_D8(){}
        ~GEN_XNOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR2_D8 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR3_D1 : public Cell {
    public:
        GEN_XNOR3_D1(){}
        ~GEN_XNOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR3_D1 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XNOR3_D2 : public Cell {
    public:
        GEN_XNOR3_D2(){}
        ~GEN_XNOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR3_D2 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XNOR3_D4 : public Cell {
    public:
        GEN_XNOR3_D4(){}
        ~GEN_XNOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XNOR3_D4 running ..." << endl;
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR2_D1 : public Cell {
    public:
        GEN_XOR2_D1(){}
        ~GEN_XOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR2_D1 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D2 : public Cell {
    public:
        GEN_XOR2_D2(){}
        ~GEN_XOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR2_D2 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D4 : public Cell {
    public:
        GEN_XOR2_D4(){}
        ~GEN_XOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR2_D4 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D8 : public Cell {
    public:
        GEN_XOR2_D8(){}
        ~GEN_XOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR2_D8 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR3_D1 : public Cell {
    public:
        GEN_XOR3_D1(){}
        ~GEN_XOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR3_D1 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR3_D2 : public Cell {
    public:
        GEN_XOR3_D2(){}
        ~GEN_XOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR3_D2 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR3_D4 : public Cell {
    public:
        GEN_XOR3_D4(){}
        ~GEN_XOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_XOR3_D4 running ..." << endl;
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_CLKGATE_D1 : public Cell {
    public:
        GEN_CLKGATE_D1(){}
        ~GEN_CLKGATE_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_CLKGATE_D1 running ..." << endl;
        }
};
class GEN_SYNC2C_D1 : public Cell {
    public:
        GEN_SYNC2C_D1(){}
        ~GEN_SYNC2C_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SYNC2C_D1 running ..." << endl;
        }
};
class GEN_SYNC3_D1 : public Cell {
    public:
        GEN_SYNC3_D1(){}
        ~GEN_SYNC3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SYNC3_D1 running ..." << endl;
        }
};
class GEN_SYNC3S_D1 : public Cell {
    public:
        GEN_SYNC3S_D1(){}
        ~GEN_SYNC3S_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SYNC3S_D1 running ..." << endl;
        }
};
class GEN_RAMS_16X272 : public Cell {
    public:
        GEN_RAMS_16X272(){}
        ~GEN_RAMS_16X272(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_16X272 running ..." << endl;
        }
};
class GEN_RAMS_16X256 : public Cell {
    public:
        GEN_RAMS_16X256(){}
        ~GEN_RAMS_16X256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_16X256 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_80x14 : public Cell {
    public:
        GEN_RAMS_OLAT_80x14(){}
        ~GEN_RAMS_OLAT_80x14(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_80x14 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_80x65 : public Cell {
    public:
        GEN_RAMS_OLAT_80x65(){}
        ~GEN_RAMS_OLAT_80x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_80x65 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_160x16 : public Cell {
    public:
        GEN_RAMS_OLAT_160x16(){}
        ~GEN_RAMS_OLAT_160x16(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_160x16 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_160x65 : public Cell {
    public:
        GEN_RAMS_OLAT_160x65(){}
        ~GEN_RAMS_OLAT_160x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_160x65 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_8x65 : public Cell {
    public:
        GEN_RAMS_OLAT_8x65(){}
        ~GEN_RAMS_OLAT_8x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_8x65 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_128x6 : public Cell {
    public:
        GEN_RAMS_OLAT_128x6(){}
        ~GEN_RAMS_OLAT_128x6(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_128x6 running ..." << endl;
        }
};
class GEN_RAMS_256x64 : public Cell {
    public:
        GEN_RAMS_256x64(){}
        ~GEN_RAMS_256x64(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_256x64 running ..." << endl;
        }
};
class GEN_RAMS_16x64 : public Cell {
    public:
        GEN_RAMS_16x64(){}
        ~GEN_RAMS_16x64(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_16x64 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_128x11 : public Cell {
    public:
        GEN_RAMS_OLAT_128x11(){}
        ~GEN_RAMS_OLAT_128x11(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_128x11 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_61x65 : public Cell {
    public:
        GEN_RAMS_OLAT_61x65(){}
        ~GEN_RAMS_OLAT_61x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_61x65 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x9 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x9(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x9(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_80x9 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x15 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x15(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x15(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_80x15 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_60x21 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        ~GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_60x21 running ..." << endl;
        }
};
class GEN_RAMS_WT_256x8 : public Cell {
    public:
        GEN_RAMS_WT_256x8(){}
        ~GEN_RAMS_WT_256x8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_256x8 running ..." << endl;
        }
};
class GEN_RAMS_256x7 : public Cell {
    public:
        GEN_RAMS_256x7(){}
        ~GEN_RAMS_256x7(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_256x7 running ..." << endl;
        }
};
class GEN_RAMS_256x3 : public Cell {
    public:
        GEN_RAMS_256x3(){}
        ~GEN_RAMS_256x3(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_256x3 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_19x4 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_19x4(){}
        ~GEN_RAMS_WT_IPASS_OLAT_19x4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_19x4 running ..." << endl;
        }
};
class GEN_RAMS_128x18 : public Cell {
    public:
        GEN_RAMS_128x18(){}
        ~GEN_RAMS_128x18(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_128x18 running ..." << endl;
        }
};
class GEN_SYNC3C_D1 : public Cell {
    public:
        GEN_SYNC3C_D1(){}
        ~GEN_SYNC3C_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SYNC3C_D1 running ..." << endl;
        }
};
class GEN_SYNC3C_STRICT_D1 : public Cell {
    public:
        GEN_SYNC3C_STRICT_D1(){}
        ~GEN_SYNC3C_STRICT_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_SYNC3C_STRICT_D1 running ..." << endl;
            Wire *src_sel, *dst_sel;
            src_sel = new Wire();
            dst_sel = new Wire();
            delete src_sel;
            delete dst_sel;
        }
};
class GEN_RAMS_512x256 : public Cell {
    public:
        GEN_RAMS_512x256(){}
        ~GEN_RAMS_512x256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_512x256 running ..." << endl;
        }
};
class GEN_RAMS_64x116 : public Cell {
    public:
        GEN_RAMS_64x116(){}
        ~GEN_RAMS_64x116(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_64x116 running ..." << endl;
        }
};
class GEN_RAMS_64x1088 : public Cell {
    public:
        GEN_RAMS_64x1088(){}
        ~GEN_RAMS_64x1088(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_64x1088 running ..." << endl;
        }
};
class GEN_RAMS_64x1024 : public Cell {
    public:
        GEN_RAMS_64x1024(){}
        ~GEN_RAMS_64x1024(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_64x1024 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_256x14 : public Cell {
    public:
        GEN_RAMS_OLAT_256x14(){}
        ~GEN_RAMS_OLAT_256x14(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_256x14 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_256x16 : public Cell {
    public:
        GEN_RAMS_OLAT_256x16(){}
        ~GEN_RAMS_OLAT_256x16(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_256x16 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_256x257 : public Cell {
    public:
        GEN_RAMS_OLAT_256x257(){}
        ~GEN_RAMS_OLAT_256x257(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_256x257 running ..." << endl;
        }
};
class GEN_RAMS_OLAT_8x257 : public Cell {
    public:
        GEN_RAMS_OLAT_8x257(){}
        ~GEN_RAMS_OLAT_8x257(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_OLAT_8x257 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x72 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x72(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x72(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_80x72 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x17 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x17(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x17(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_80x17 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_60x168 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_60x168(){}
        ~GEN_RAMS_WT_IPASS_OLAT_60x168(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_60x168 running ..." << endl;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_20x32 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_20x32(){}
        ~GEN_RAMS_WT_IPASS_OLAT_20x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_WT_IPASS_OLAT_20x32 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE21_64x21 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE21_64x21(){}
        ~GEN_RAMS_SP_WENABLE21_64x21(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE21_64x21 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE32_1024x32 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE32_1024x32(){}
        ~GEN_RAMS_SP_WENABLE32_1024x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE32_1024x32 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE8_4096x32 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE8_4096x32(){}
        ~GEN_RAMS_SP_WENABLE8_4096x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE8_4096x32 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE22_64x88 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE22_64x88(){}
        ~GEN_RAMS_SP_WENABLE22_64x88(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE22_64x88 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE8_512x256 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE8_512x256(){}
        ~GEN_RAMS_SP_WENABLE8_512x256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE8_512x256 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE21_64x84 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE21_64x84(){}
        ~GEN_RAMS_SP_WENABLE21_64x84(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE21_64x84 running ..." << endl;
        }
};
class GEN_RAMS_SP_WENABLE32_512x128 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE32_512x128(){}
        ~GEN_RAMS_SP_WENABLE32_512x128(){}
        static void step(unordered_map<string, Wire*> &wire) {
            // cout << "This is GEN_RAMS_SP_WENABLE32_512x128 running ..." << endl;
        }
};
typedef void (*func_ptr)(unordered_map<string, Wire*>&);
extern unordered_map<string, func_ptr> vlib; 
#endif