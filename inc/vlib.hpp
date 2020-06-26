#ifndef VLIB
#define VLIB
#include <string>
#include <unordered_map>
#include "wire.h"
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
           o = a & b;
       }
       void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
           o = a & b;
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
class GEN_AND2_D1 : public Cell {
    public:
        GEN_AND2_D1(){}
        ~GEN_AND2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D2 : public Cell {
    public:
        GEN_AND2_D2(){}
        ~GEN_AND2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D4 : public Cell {
    public:
        GEN_AND2_D4(){}
        ~GEN_AND2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND2_D8 : public Cell {
    public:
        GEN_AND2_D8(){}
        ~GEN_AND2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_AND3_D1 : public Cell {
    public:
        GEN_AND3_D1(){}
        ~GEN_AND3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D2 : public Cell {
    public:
        GEN_AND3_D2(){}
        ~GEN_AND3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D4 : public Cell {
    public:
        GEN_AND3_D4(){}
        ~GEN_AND3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND3_D8 : public Cell {
    public:
        GEN_AND3_D8(){}
        ~GEN_AND3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_AND4_D1 : public Cell {
    public:
        GEN_AND4_D1(){}
        ~GEN_AND4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D2 : public Cell {
    public:
        GEN_AND4_D2(){}
        ~GEN_AND4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D4 : public Cell {
    public:
        GEN_AND4_D4(){}
        ~GEN_AND4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AND4_D8 : public Cell {
    public:
        GEN_AND4_D8(){}
        ~GEN_AND4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _and(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_AO211_D1 : public Cell {
    public:
        GEN_AO211_D1(){}
        ~GEN_AO211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D2 : public Cell {
    public:
        GEN_BUF_D2(){}
        ~GEN_BUF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D4 : public Cell {
    public:
        GEN_BUF_D4(){}
        ~GEN_BUF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_BUF_D8 : public Cell {
    public:
        GEN_BUF_D8(){}
        ~GEN_BUF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _buf(wire["z"], wire["i"]);
        }
};
class GEN_FA_D1 : public Cell {
    public:
        GEN_FA_D1(){}
        ~GEN_FA_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_HA_D2 : public Cell {
    public:
        GEN_HA_D2(){}
        ~GEN_HA_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_HA_D4 : public Cell {
    public:
        GEN_HA_D4(){}
        ~GEN_HA_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["s"], wire["a"], wire["b"]);
            _and(wire["co"], wire["a"], wire["b"]);
        }
};
class GEN_INV_D1 : public Cell {
    public:
        GEN_INV_D1(){}
        ~GEN_INV_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D2 : public Cell {
    public:
        GEN_INV_D2(){}
        ~GEN_INV_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D4 : public Cell {
    public:
        GEN_INV_D4(){}
        ~GEN_INV_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_INV_D8 : public Cell {
    public:
        GEN_INV_D8(){}
        ~GEN_INV_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _not(wire["zn"], wire["i"]);
        }
};
class GEN_MAJORITYAOI222_D1 : public Cell {
    public:
        GEN_MAJORITYAOI222_D1(){}
        ~GEN_MAJORITYAOI222_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Reg* notifier;
            notifier = new Reg();
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_LATCH_D2 : public Cell {
    public:
        GEN_LATCH_D2(){}
        ~GEN_LATCH_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_LATCH_D4 : public Cell {
    public:
        GEN_LATCH_D4(){}
        ~GEN_LATCH_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_tlat(wire["q"], wire["d"], wire["e"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFCLR_D1 : public Cell {
    public:
        GEN_DFCLR_D1(){}
        ~GEN_DFCLR_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFCLR_D2 : public Cell {
    public:
        GEN_DFCLR_D2(){}
        ~GEN_DFCLR_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFCLR_D4 : public Cell {
    public:
        GEN_DFCLR_D4(){}
        ~GEN_DFCLR_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFCLR_D8 : public Cell {
    public:
        GEN_DFCLR_D8(){}
        ~GEN_DFCLR_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DF_D1 : public Cell {
    public:
        GEN_DF_D1(){}
        ~GEN_DF_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DF_D2 : public Cell {
    public:
        GEN_DF_D2(){}
        ~GEN_DF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DF_D4 : public Cell {
    public:
        GEN_DF_D4(){}
        ~GEN_DF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DF_D8 : public Cell {
    public:
        GEN_DF_D8(){}
        ~GEN_DF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFSET_D1 : public Cell {
    public:
        GEN_DFSET_D1(){}
        ~GEN_DFSET_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFSET_D2 : public Cell {
    public:
        GEN_DFSET_D2(){}
        ~GEN_DFSET_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFSET_D4 : public Cell {
    public:
        GEN_DFSET_D4(){}
        ~GEN_DFSET_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_DFSET_D8 : public Cell {
    public:
        GEN_DFSET_D8(){}
        ~GEN_DFSET_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* notifier;
            notifier = new Reg();
            _udp_dff(wire["q"], wire["d"], wire["cp"], wire["cdn"], wire["sdn"], notifier);
            delete notifier;
        }
};
class GEN_MUX2_D1 : public Cell {
    public:
        GEN_MUX2_D1(){}
        ~GEN_MUX2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2_D2 : public Cell {
    public:
        GEN_MUX2_D2(){}
        ~GEN_MUX2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2_D4 : public Cell {
    public:
        GEN_MUX2_D4(){}
        ~GEN_MUX2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _udp_mux2(wire["z"], wire["i0"], wire["i1"], wire["s"]);
        }
};
class GEN_MUX2N_D1 : public Cell {
    public:
        GEN_MUX2N_D1(){}
        ~GEN_MUX2N_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* z;
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
            Wire* z;
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
            Wire* z;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D2 : public Cell {
    public:
        GEN_NAND2_D2(){}
        ~GEN_NAND2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D4 : public Cell {
    public:
        GEN_NAND2_D4(){}
        ~GEN_NAND2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND2_D8 : public Cell {
    public:
        GEN_NAND2_D8(){}
        ~GEN_NAND2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NAND3_D1 : public Cell {
    public:
        GEN_NAND3_D1(){}
        ~GEN_NAND3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D2 : public Cell {
    public:
        GEN_NAND3_D2(){}
        ~GEN_NAND3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D4 : public Cell {
    public:
        GEN_NAND3_D4(){}
        ~GEN_NAND3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND3_D8 : public Cell {
    public:
        GEN_NAND3_D8(){}
        ~GEN_NAND3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NAND4_D1 : public Cell {
    public:
        GEN_NAND4_D1(){}
        ~GEN_NAND4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D2 : public Cell {
    public:
        GEN_NAND4_D2(){}
        ~GEN_NAND4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D4 : public Cell {
    public:
        GEN_NAND4_D4(){}
        ~GEN_NAND4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NAND4_D8 : public Cell {
    public:
        GEN_NAND4_D8(){}
        ~GEN_NAND4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nand(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR2_D1 : public Cell {
    public:
        GEN_NOR2_D1(){}
        ~GEN_NOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D2 : public Cell {
    public:
        GEN_NOR2_D2(){}
        ~GEN_NOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D4 : public Cell {
    public:
        GEN_NOR2_D4(){}
        ~GEN_NOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR2_D8 : public Cell {
    public:
        GEN_NOR2_D8(){}
        ~GEN_NOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_NOR3_D1 : public Cell {
    public:
        GEN_NOR3_D1(){}
        ~GEN_NOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D2 : public Cell {
    public:
        GEN_NOR3_D2(){}
        ~GEN_NOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D4 : public Cell {
    public:
        GEN_NOR3_D4(){}
        ~GEN_NOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR3_D8 : public Cell {
    public:
        GEN_NOR3_D8(){}
        ~GEN_NOR3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_NOR4_D1 : public Cell {
    public:
        GEN_NOR4_D1(){}
        ~GEN_NOR4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D2 : public Cell {
    public:
        GEN_NOR4_D2(){}
        ~GEN_NOR4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D4 : public Cell {
    public:
        GEN_NOR4_D4(){}
        ~GEN_NOR4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_NOR4_D8 : public Cell {
    public:
        GEN_NOR4_D8(){}
        ~GEN_NOR4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _nor(wire["zn"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OA211_D1 : public Cell {
    public:
        GEN_OA211_D1(){}
        ~GEN_OA211_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2,net3;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            Wire* net0,net1,net2;
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
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D2 : public Cell {
    public:
        GEN_OR2_D2(){}
        ~GEN_OR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D4 : public Cell {
    public:
        GEN_OR2_D4(){}
        ~GEN_OR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR2_D8 : public Cell {
    public:
        GEN_OR2_D8(){}
        ~GEN_OR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_OR3_D1 : public Cell {
    public:
        GEN_OR3_D1(){}
        ~GEN_OR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D2 : public Cell {
    public:
        GEN_OR3_D2(){}
        ~GEN_OR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D4 : public Cell {
    public:
        GEN_OR3_D4(){}
        ~GEN_OR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR3_D8 : public Cell {
    public:
        GEN_OR3_D8(){}
        ~GEN_OR3_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_OR4_D1 : public Cell {
    public:
        GEN_OR4_D1(){}
        ~GEN_OR4_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D2 : public Cell {
    public:
        GEN_OR4_D2(){}
        ~GEN_OR4_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D4 : public Cell {
    public:
        GEN_OR4_D4(){}
        ~GEN_OR4_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_OR4_D8 : public Cell {
    public:
        GEN_OR4_D8(){}
        ~GEN_OR4_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _or(wire["z"], wire["a1"], wire["a2"], wire["a3"], wire["a4"]);
        }
};
class GEN_SCAN_DFCLR_D1 : public Cell {
    public:
        GEN_SCAN_DFCLR_D1(){}
        ~GEN_SCAN_DFCLR_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* cdn_i,d_i,q_buf,sd,si_check,d_check,se1,se_check,xsi_check,xd_check,xcdn_i;
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
            Reg* notifier;
            notifier = new Reg();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFCLR_D2 : public Cell {
    public:
        GEN_SCAN_DFCLR_D2(){}
        ~GEN_SCAN_DFCLR_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* cdn_i,d_i,q_buf,sd,si_check,d_check,se1,se_check,xsi_check,xd_check,xcdn_i;
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
            Reg* notifier;
            notifier = new Reg();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFCLR_D4 : public Cell {
    public:
        GEN_SCAN_DFCLR_D4(){}
        ~GEN_SCAN_DFCLR_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* cdn_i,d_i,q_buf,sd,si_check,d_check,se1,se_check,xsi_check,xd_check,xcdn_i;
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
            Reg* notifier;
            notifier = new Reg();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFCLR_D8 : public Cell {
    public:
        GEN_SCAN_DFCLR_D8(){}
        ~GEN_SCAN_DFCLR_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* cdn_i,d_i,q_buf,sd,si_check,d_check,se1,se_check,xsi_check,xd_check,xcdn_i;
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
            Reg* notifier;
            notifier = new Reg();
            _buf(cdn_i, wire["cdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], cdn_i, wire["sdn"], notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DF_D1 : public Cell {
    public:
        GEN_SCAN_DF_D1(){}
        ~GEN_SCAN_DF_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* d_i,q_buf,sd,xse,xsd;
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            xse = new Wire();
            xsd = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], wire["sdn"], notifier);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _udp_xbuf(xse, wire["se"], wire["1'b1"]);
            _udp_xbuf(xsd, sd, wire["1'b1"]);
            delete d_i;
            delete q_buf;
            delete sd;
            delete xse;
            delete xsd;
            delete notifier;
        }
};
class GEN_SCAN_DF_D2 : public Cell {
    public:
        GEN_SCAN_DF_D2(){}
        ~GEN_SCAN_DF_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* d_i,q_buf,sd,xse,xsd;
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            xse = new Wire();
            xsd = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], wire["sdn"], notifier);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _udp_xbuf(xse, wire["se"], wire["1'b1"]);
            _udp_xbuf(xsd, sd, wire["1'b1"]);
            delete d_i;
            delete q_buf;
            delete sd;
            delete xse;
            delete xsd;
            delete notifier;
        }
};
class GEN_SCAN_DF_D4 : public Cell {
    public:
        GEN_SCAN_DF_D4(){}
        ~GEN_SCAN_DF_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* d_i,q_buf,sd,xse,xsd;
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            xse = new Wire();
            xsd = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], wire["sdn"], notifier);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _udp_xbuf(xse, wire["se"], wire["1'b1"]);
            _udp_xbuf(xsd, sd, wire["1'b1"]);
            delete d_i;
            delete q_buf;
            delete sd;
            delete xse;
            delete xsd;
            delete notifier;
        }
};
class GEN_SCAN_DF_D8 : public Cell {
    public:
        GEN_SCAN_DF_D8(){}
        ~GEN_SCAN_DF_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* d_i,q_buf,sd,xse,xsd;
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            xse = new Wire();
            xsd = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], wire["sdn"], notifier);
            _buf(wire["q"], q_buf);
            _not(sd, wire["se"]);
            _udp_xbuf(xse, wire["se"], wire["1'b1"]);
            _udp_xbuf(xsd, sd, wire["1'b1"]);
            delete d_i;
            delete q_buf;
            delete sd;
            delete xse;
            delete xsd;
            delete notifier;
        }
};
class GEN_SCAN_DFSET_D1 : public Cell {
    public:
        GEN_SCAN_DFSET_D1(){}
        ~GEN_SCAN_DFSET_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* sdn_i,d_i,q_buf,sd,si_check,d_check,xsi_check,xd_check,xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFSET_D2 : public Cell {
    public:
        GEN_SCAN_DFSET_D2(){}
        ~GEN_SCAN_DFSET_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* sdn_i,d_i,q_buf,sd,si_check,d_check,xsi_check,xd_check,xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFSET_D4 : public Cell {
    public:
        GEN_SCAN_DFSET_D4(){}
        ~GEN_SCAN_DFSET_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* sdn_i,d_i,q_buf,sd,si_check,d_check,xsi_check,xd_check,xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, notifier);
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
            delete notifier;
        }
};
class GEN_SCAN_DFSET_D8 : public Cell {
    public:
        GEN_SCAN_DFSET_D8(){}
        ~GEN_SCAN_DFSET_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* sdn_i,d_i,q_buf,sd,si_check,d_check,xsi_check,xd_check,xsdn_i;
            sdn_i = new Wire();
            d_i = new Wire();
            q_buf = new Wire();
            sd = new Wire();
            si_check = new Wire();
            d_check = new Wire();
            xsi_check = new Wire();
            xd_check = new Wire();
            xsdn_i = new Wire();
            Reg* notifier;
            notifier = new Reg();
            _buf(sdn_i, wire["sdn"]);
            _udp_mux2(d_i, wire["d"], wire["si"], wire["se"]);
            _udp_dff(q_buf, d_i, wire["cp"], wire["cdn"], sdn_i, notifier);
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
            delete notifier;
        }
};
class GEN_XNOR2_D1 : public Cell {
    public:
        GEN_XNOR2_D1(){}
        ~GEN_XNOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D2 : public Cell {
    public:
        GEN_XNOR2_D2(){}
        ~GEN_XNOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D4 : public Cell {
    public:
        GEN_XNOR2_D4(){}
        ~GEN_XNOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR2_D8 : public Cell {
    public:
        GEN_XNOR2_D8(){}
        ~GEN_XNOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"]);
        }
};
class GEN_XNOR3_D1 : public Cell {
    public:
        GEN_XNOR3_D1(){}
        ~GEN_XNOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XNOR3_D2 : public Cell {
    public:
        GEN_XNOR3_D2(){}
        ~GEN_XNOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XNOR3_D4 : public Cell {
    public:
        GEN_XNOR3_D4(){}
        ~GEN_XNOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xnor(wire["zn"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR2_D1 : public Cell {
    public:
        GEN_XOR2_D1(){}
        ~GEN_XOR2_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D2 : public Cell {
    public:
        GEN_XOR2_D2(){}
        ~GEN_XOR2_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D4 : public Cell {
    public:
        GEN_XOR2_D4(){}
        ~GEN_XOR2_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR2_D8 : public Cell {
    public:
        GEN_XOR2_D8(){}
        ~GEN_XOR2_D8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"]);
        }
};
class GEN_XOR3_D1 : public Cell {
    public:
        GEN_XOR3_D1(){}
        ~GEN_XOR3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR3_D2 : public Cell {
    public:
        GEN_XOR3_D2(){}
        ~GEN_XOR3_D2(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_XOR3_D4 : public Cell {
    public:
        GEN_XOR3_D4(){}
        ~GEN_XOR3_D4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            _xor(wire["z"], wire["a1"], wire["a2"], wire["a3"]);
        }
};
class GEN_CLKGATE_D1 : public Cell {
    public:
        GEN_CLKGATE_D1(){}
        ~GEN_CLKGATE_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* qd;
            qd = new Reg();
            delete qd;
        }
};
class GEN_SYNC2C_D1 : public Cell {
    public:
        GEN_SYNC2C_D1(){}
        ~GEN_SYNC2C_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* q,d0;
            q = new Reg();
            d0 = new Reg();
            delete q;
            delete d0;
        }
};
class GEN_SYNC3_D1 : public Cell {
    public:
        GEN_SYNC3_D1(){}
        ~GEN_SYNC3_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* q,d1,d0;
            q = new Reg();
            d1 = new Reg();
            d0 = new Reg();
            delete q;
            delete d1;
            delete d0;
        }
};
class GEN_SYNC3S_D1 : public Cell {
    public:
        GEN_SYNC3S_D1(){}
        ~GEN_SYNC3S_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* q,d1,d0;
            q = new Reg();
            d1 = new Reg();
            d0 = new Reg();
            delete q;
            delete d1;
            delete d0;
        }
};
class GEN_RAMS_16X272 : public Cell {
    public:
        GEN_RAMS_16X272(){}
        ~GEN_RAMS_16X272(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [3:0]ra_d;
            [3:0]ra_d = new Reg();
            Wire* [271:0]dout;
            [271:0]dout = new Wire();
            Reg* [271:0]M[15:0];
            [271:0]M[15:0] = new Reg();
            delete [3:0]ra_d;
            delete [271:0]dout;
            delete [271:0]M[15:0];
        }
};
class GEN_RAMS_16X256 : public Cell {
    public:
        GEN_RAMS_16X256(){}
        ~GEN_RAMS_16X256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [3:0]ra_d;
            [3:0]ra_d = new Reg();
            Wire* [255:0]dout;
            [255:0]dout = new Wire();
            Reg* [255:0]M[15:0];
            [255:0]M[15:0] = new Reg();
            delete [3:0]ra_d;
            delete [255:0]dout;
            delete [255:0]M[15:0];
        }
};
class GEN_RAMS_OLAT_80x14 : public Cell {
    public:
        GEN_RAMS_OLAT_80x14(){}
        ~GEN_RAMS_OLAT_80x14(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [13:0]dout;
            [13:0]dout = new Wire();
            Reg* [13:0]M[79:0];
            [13:0]M[79:0] = new Reg();
            Wire* [13:0]dout_ram=M[ra_d];
            [13:0]dout_ram=M[ra_d] = new Wire();
            Reg* [13:0]dout_r;
            [13:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [13:0]dout;
            delete [13:0]M[79:0];
            delete [13:0]dout_ram=M[ra_d];
            delete [13:0]dout_r;
        }
};
class GEN_RAMS_OLAT_80x65 : public Cell {
    public:
        GEN_RAMS_OLAT_80x65(){}
        ~GEN_RAMS_OLAT_80x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [64:0]dout;
            [64:0]dout = new Wire();
            Reg* [64:0]M[79:0];
            [64:0]M[79:0] = new Reg();
            Wire* [64:0]dout_ram=M[ra_d];
            [64:0]dout_ram=M[ra_d] = new Wire();
            Reg* [64:0]dout_r;
            [64:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [64:0]dout;
            delete [64:0]M[79:0];
            delete [64:0]dout_ram=M[ra_d];
            delete [64:0]dout_r;
        }
};
class GEN_RAMS_OLAT_160x16 : public Cell {
    public:
        GEN_RAMS_OLAT_160x16(){}
        ~GEN_RAMS_OLAT_160x16(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [15:0]dout;
            [15:0]dout = new Wire();
            Reg* [15:0]M[159:0];
            [15:0]M[159:0] = new Reg();
            Wire* [15:0]dout_ram=M[ra_d];
            [15:0]dout_ram=M[ra_d] = new Wire();
            Reg* [15:0]dout_r;
            [15:0]dout_r = new Reg();
            delete [7:0]ra_d;
            delete [15:0]dout;
            delete [15:0]M[159:0];
            delete [15:0]dout_ram=M[ra_d];
            delete [15:0]dout_r;
        }
};
class GEN_RAMS_OLAT_160x65 : public Cell {
    public:
        GEN_RAMS_OLAT_160x65(){}
        ~GEN_RAMS_OLAT_160x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [64:0]dout;
            [64:0]dout = new Wire();
            Reg* [64:0]M[159:0];
            [64:0]M[159:0] = new Reg();
            Wire* [64:0]dout_ram=M[ra_d];
            [64:0]dout_ram=M[ra_d] = new Wire();
            Reg* [64:0]dout_r;
            [64:0]dout_r = new Reg();
            delete [7:0]ra_d;
            delete [64:0]dout;
            delete [64:0]M[159:0];
            delete [64:0]dout_ram=M[ra_d];
            delete [64:0]dout_r;
        }
};
class GEN_RAMS_OLAT_8x65 : public Cell {
    public:
        GEN_RAMS_OLAT_8x65(){}
        ~GEN_RAMS_OLAT_8x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [2:0]ra_d;
            [2:0]ra_d = new Reg();
            Wire* [64:0]dout;
            [64:0]dout = new Wire();
            Reg* [64:0]M[7:0];
            [64:0]M[7:0] = new Reg();
            Wire* [64:0]dout_ram=M[ra_d];
            [64:0]dout_ram=M[ra_d] = new Wire();
            Reg* [64:0]dout_r;
            [64:0]dout_r = new Reg();
            delete [2:0]ra_d;
            delete [64:0]dout;
            delete [64:0]M[7:0];
            delete [64:0]dout_ram=M[ra_d];
            delete [64:0]dout_r;
        }
};
class GEN_RAMS_OLAT_128x6 : public Cell {
    public:
        GEN_RAMS_OLAT_128x6(){}
        ~GEN_RAMS_OLAT_128x6(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [5:0]dout;
            [5:0]dout = new Wire();
            Reg* [5:0]M[127:0];
            [5:0]M[127:0] = new Reg();
            Wire* [5:0]dout_ram=M[ra_d];
            [5:0]dout_ram=M[ra_d] = new Wire();
            Reg* [5:0]dout_r;
            [5:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [5:0]dout;
            delete [5:0]M[127:0];
            delete [5:0]dout_ram=M[ra_d];
            delete [5:0]dout_r;
        }
};
class GEN_RAMS_256x64 : public Cell {
    public:
        GEN_RAMS_256x64(){}
        ~GEN_RAMS_256x64(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [63:0]dout;
            [63:0]dout = new Wire();
            Reg* [63:0]M[255:0];
            [63:0]M[255:0] = new Reg();
            delete [7:0]ra_d;
            delete [63:0]dout;
            delete [63:0]M[255:0];
        }
};
class GEN_RAMS_16x64 : public Cell {
    public:
        GEN_RAMS_16x64(){}
        ~GEN_RAMS_16x64(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [3:0]ra_d;
            [3:0]ra_d = new Reg();
            Wire* [63:0]dout;
            [63:0]dout = new Wire();
            Reg* [63:0]M[15:0];
            [63:0]M[15:0] = new Reg();
            delete [3:0]ra_d;
            delete [63:0]dout;
            delete [63:0]M[15:0];
        }
};
class GEN_RAMS_OLAT_128x11 : public Cell {
    public:
        GEN_RAMS_OLAT_128x11(){}
        ~GEN_RAMS_OLAT_128x11(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [10:0]dout;
            [10:0]dout = new Wire();
            Reg* [10:0]M[127:0];
            [10:0]M[127:0] = new Reg();
            Wire* [10:0]dout_ram=M[ra_d];
            [10:0]dout_ram=M[ra_d] = new Wire();
            Reg* [10:0]dout_r;
            [10:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [10:0]dout;
            delete [10:0]M[127:0];
            delete [10:0]dout_ram=M[ra_d];
            delete [10:0]dout_r;
        }
};
class GEN_RAMS_OLAT_61x65 : public Cell {
    public:
        GEN_RAMS_OLAT_61x65(){}
        ~GEN_RAMS_OLAT_61x65(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [64:0]dout;
            [64:0]dout = new Wire();
            Reg* [64:0]M[60:0];
            [64:0]M[60:0] = new Reg();
            Wire* [64:0]dout_ram=M[ra_d];
            [64:0]dout_ram=M[ra_d] = new Wire();
            Reg* [64:0]dout_r;
            [64:0]dout_r = new Reg();
            delete [5:0]ra_d;
            delete [64:0]dout;
            delete [64:0]M[60:0];
            delete [64:0]dout_ram=M[ra_d];
            delete [64:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x9 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x9(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x9(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [8:0]dout;
            [8:0]dout = new Wire();
            Reg* [8:0]M[79:0];
            [8:0]M[79:0] = new Reg();
            Wire* [8:0]dout_ram=M[ra_d];
            [8:0]dout_ram=M[ra_d] = new Wire();
            Wire* [8:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [8:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [8:0]dout_r;
            [8:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [8:0]dout;
            delete [8:0]M[79:0];
            delete [8:0]dout_ram=M[ra_d];
            delete [8:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [8:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x15 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x15(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x15(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [14:0]dout;
            [14:0]dout = new Wire();
            Reg* [14:0]M[79:0];
            [14:0]M[79:0] = new Reg();
            Wire* [14:0]dout_ram=M[ra_d];
            [14:0]dout_ram=M[ra_d] = new Wire();
            Wire* [14:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [14:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [14:0]dout_r;
            [14:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [14:0]dout;
            delete [14:0]M[79:0];
            delete [14:0]dout_ram=M[ra_d];
            delete [14:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [14:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_60x21 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        ~GEN_RAMS_WT_IPASS_OLAT_60x21(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [20:0]dout;
            [20:0]dout = new Wire();
            Reg* [20:0]M[59:0];
            [20:0]M[59:0] = new Reg();
            Wire* [20:0]dout_ram=M[ra_d];
            [20:0]dout_ram=M[ra_d] = new Wire();
            Wire* [20:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [20:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [20:0]dout_r;
            [20:0]dout_r = new Reg();
            delete [5:0]ra_d;
            delete [20:0]dout;
            delete [20:0]M[59:0];
            delete [20:0]dout_ram=M[ra_d];
            delete [20:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [20:0]dout_r;
        }
};
class GEN_RAMS_WT_256x8 : public Cell {
    public:
        GEN_RAMS_WT_256x8(){}
        ~GEN_RAMS_WT_256x8(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [7:0]dout;
            [7:0]dout = new Wire();
            Reg* [7:0]M[255:0];
            [7:0]M[255:0] = new Reg();
            delete [7:0]ra_d;
            delete [7:0]dout;
            delete [7:0]M[255:0];
        }
};
class GEN_RAMS_256x7 : public Cell {
    public:
        GEN_RAMS_256x7(){}
        ~GEN_RAMS_256x7(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [6:0]dout;
            [6:0]dout = new Wire();
            Reg* [6:0]M[255:0];
            [6:0]M[255:0] = new Reg();
            delete [7:0]ra_d;
            delete [6:0]dout;
            delete [6:0]M[255:0];
        }
};
class GEN_RAMS_256x3 : public Cell {
    public:
        GEN_RAMS_256x3(){}
        ~GEN_RAMS_256x3(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [2:0]dout;
            [2:0]dout = new Wire();
            Reg* [2:0]M[255:0];
            [2:0]M[255:0] = new Reg();
            delete [7:0]ra_d;
            delete [2:0]dout;
            delete [2:0]M[255:0];
        }
};
class GEN_RAMS_WT_IPASS_OLAT_19x4 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_19x4(){}
        ~GEN_RAMS_WT_IPASS_OLAT_19x4(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [4:0]ra_d;
            [4:0]ra_d = new Reg();
            Wire* [3:0]dout;
            [3:0]dout = new Wire();
            Reg* [3:0]M[18:0];
            [3:0]M[18:0] = new Reg();
            Wire* [3:0]dout_ram=M[ra_d];
            [3:0]dout_ram=M[ra_d] = new Wire();
            Wire* [3:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [3:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [3:0]dout_r;
            [3:0]dout_r = new Reg();
            delete [4:0]ra_d;
            delete [3:0]dout;
            delete [3:0]M[18:0];
            delete [3:0]dout_ram=M[ra_d];
            delete [3:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [3:0]dout_r;
        }
};
class GEN_RAMS_128x18 : public Cell {
    public:
        GEN_RAMS_128x18(){}
        ~GEN_RAMS_128x18(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [17:0]dout;
            [17:0]dout = new Wire();
            Reg* [17:0]M[127:0];
            [17:0]M[127:0] = new Reg();
            delete [6:0]ra_d;
            delete [17:0]dout;
            delete [17:0]M[127:0];
        }
};
class GEN_SYNC3C_D1 : public Cell {
    public:
        GEN_SYNC3C_D1(){}
        ~GEN_SYNC3C_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* q,d1,d0;
            q = new Reg();
            d1 = new Reg();
            d0 = new Reg();
            delete q;
            delete d1;
            delete d0;
        }
};
class GEN_SYNC3C_STRICT_D1 : public Cell {
    public:
        GEN_SYNC3C_STRICT_D1(){}
        ~GEN_SYNC3C_STRICT_D1(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Wire* src_sel,dst_sel;
            src_sel = new Wire();
            dst_sel = new Wire();
            Reg* src_d_f;
            src_d_f = new Reg();
            delete src_sel;
            delete dst_sel;
            delete src_d_f;
        }
};
class GEN_RAMS_512x256 : public Cell {
    public:
        GEN_RAMS_512x256(){}
        ~GEN_RAMS_512x256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [8:0]ra_d;
            [8:0]ra_d = new Reg();
            Wire* [255:0]dout;
            [255:0]dout = new Wire();
            Reg* [255:0]M[511:0];
            [255:0]M[511:0] = new Reg();
            delete [8:0]ra_d;
            delete [255:0]dout;
            delete [255:0]M[511:0];
        }
};
class GEN_RAMS_64x116 : public Cell {
    public:
        GEN_RAMS_64x116(){}
        ~GEN_RAMS_64x116(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [115:0]dout;
            [115:0]dout = new Wire();
            Reg* [115:0]M[63:0];
            [115:0]M[63:0] = new Reg();
            delete [5:0]ra_d;
            delete [115:0]dout;
            delete [115:0]M[63:0];
        }
};
class GEN_RAMS_64x1088(clk,ra,re,dout,wa,we,di); : public Cell {
    public:
        GEN_RAMS_64x1088(clk,ra,re,dout,wa,we,di);(){}
        ~GEN_RAMS_64x1088(clk,ra,re,dout,wa,we,di);(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [1087:0]dout;
            [1087:0]dout = new Wire();
            Reg* [1087:0]M[63:0];
            [1087:0]M[63:0] = new Reg();
            delete [5:0]ra_d;
            delete [1087:0]dout;
            delete [1087:0]M[63:0];
        }
};
class GEN_RAMS_64x1024(clk,ra,re,dout,wa,we,di); : public Cell {
    public:
        GEN_RAMS_64x1024(clk,ra,re,dout,wa,we,di);(){}
        ~GEN_RAMS_64x1024(clk,ra,re,dout,wa,we,di);(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [1023:0]dout;
            [1023:0]dout = new Wire();
            Reg* [1023:0]M[63:0];
            [1023:0]M[63:0] = new Reg();
            delete [5:0]ra_d;
            delete [1023:0]dout;
            delete [1023:0]M[63:0];
        }
};
class GEN_RAMS_OLAT_256x14 : public Cell {
    public:
        GEN_RAMS_OLAT_256x14(){}
        ~GEN_RAMS_OLAT_256x14(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [13:0]dout;
            [13:0]dout = new Wire();
            Reg* [13:0]M[255:0];
            [13:0]M[255:0] = new Reg();
            Wire* [13:0]dout_ram=M[ra_d];
            [13:0]dout_ram=M[ra_d] = new Wire();
            Reg* [13:0]dout_r;
            [13:0]dout_r = new Reg();
            delete [7:0]ra_d;
            delete [13:0]dout;
            delete [13:0]M[255:0];
            delete [13:0]dout_ram=M[ra_d];
            delete [13:0]dout_r;
        }
};
class GEN_RAMS_OLAT_256x16 : public Cell {
    public:
        GEN_RAMS_OLAT_256x16(){}
        ~GEN_RAMS_OLAT_256x16(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [15:0]dout;
            [15:0]dout = new Wire();
            Reg* [15:0]M[255:0];
            [15:0]M[255:0] = new Reg();
            Wire* [15:0]dout_ram=M[ra_d];
            [15:0]dout_ram=M[ra_d] = new Wire();
            Reg* [15:0]dout_r;
            [15:0]dout_r = new Reg();
            delete [7:0]ra_d;
            delete [15:0]dout;
            delete [15:0]M[255:0];
            delete [15:0]dout_ram=M[ra_d];
            delete [15:0]dout_r;
        }
};
class GEN_RAMS_OLAT_256x257 : public Cell {
    public:
        GEN_RAMS_OLAT_256x257(){}
        ~GEN_RAMS_OLAT_256x257(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [7:0]ra_d;
            [7:0]ra_d = new Reg();
            Wire* [256:0]dout;
            [256:0]dout = new Wire();
            Reg* [256:0]M[255:0];
            [256:0]M[255:0] = new Reg();
            Wire* [256:0]dout_ram=M[ra_d];
            [256:0]dout_ram=M[ra_d] = new Wire();
            Reg* [256:0]dout_r;
            [256:0]dout_r = new Reg();
            delete [7:0]ra_d;
            delete [256:0]dout;
            delete [256:0]M[255:0];
            delete [256:0]dout_ram=M[ra_d];
            delete [256:0]dout_r;
        }
};
class GEN_RAMS_OLAT_8x257 : public Cell {
    public:
        GEN_RAMS_OLAT_8x257(){}
        ~GEN_RAMS_OLAT_8x257(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [2:0]ra_d;
            [2:0]ra_d = new Reg();
            Wire* [256:0]dout;
            [256:0]dout = new Wire();
            Reg* [256:0]M[7:0];
            [256:0]M[7:0] = new Reg();
            Wire* [256:0]dout_ram=M[ra_d];
            [256:0]dout_ram=M[ra_d] = new Wire();
            Reg* [256:0]dout_r;
            [256:0]dout_r = new Reg();
            delete [2:0]ra_d;
            delete [256:0]dout;
            delete [256:0]M[7:0];
            delete [256:0]dout_ram=M[ra_d];
            delete [256:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x72 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x72(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x72(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [71:0]dout;
            [71:0]dout = new Wire();
            Reg* [71:0]M[79:0];
            [71:0]M[79:0] = new Reg();
            Wire* [71:0]dout_ram=M[ra_d];
            [71:0]dout_ram=M[ra_d] = new Wire();
            Wire* [71:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [71:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [71:0]dout_r;
            [71:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [71:0]dout;
            delete [71:0]M[79:0];
            delete [71:0]dout_ram=M[ra_d];
            delete [71:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [71:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_80x17 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_80x17(){}
        ~GEN_RAMS_WT_IPASS_OLAT_80x17(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [6:0]ra_d;
            [6:0]ra_d = new Reg();
            Wire* [16:0]dout;
            [16:0]dout = new Wire();
            Reg* [16:0]M[79:0];
            [16:0]M[79:0] = new Reg();
            Wire* [16:0]dout_ram=M[ra_d];
            [16:0]dout_ram=M[ra_d] = new Wire();
            Wire* [16:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [16:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [16:0]dout_r;
            [16:0]dout_r = new Reg();
            delete [6:0]ra_d;
            delete [16:0]dout;
            delete [16:0]M[79:0];
            delete [16:0]dout_ram=M[ra_d];
            delete [16:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [16:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_60x168 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_60x168(){}
        ~GEN_RAMS_WT_IPASS_OLAT_60x168(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            Wire* [167:0]dout;
            [167:0]dout = new Wire();
            Reg* [167:0]M[59:0];
            [167:0]M[59:0] = new Reg();
            Wire* [167:0]dout_ram=M[ra_d];
            [167:0]dout_ram=M[ra_d] = new Wire();
            Wire* [167:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [167:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [167:0]dout_r;
            [167:0]dout_r = new Reg();
            delete [5:0]ra_d;
            delete [167:0]dout;
            delete [167:0]M[59:0];
            delete [167:0]dout_ram=M[ra_d];
            delete [167:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [167:0]dout_r;
        }
};
class GEN_RAMS_WT_IPASS_OLAT_20x32 : public Cell {
    public:
        GEN_RAMS_WT_IPASS_OLAT_20x32(){}
        ~GEN_RAMS_WT_IPASS_OLAT_20x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [4:0]ra_d;
            [4:0]ra_d = new Reg();
            Wire* [31:0]dout;
            [31:0]dout = new Wire();
            Reg* [31:0]M[19:0];
            [31:0]M[19:0] = new Reg();
            Wire* [31:0]dout_ram=M[ra_d];
            [31:0]dout_ram=M[ra_d] = new Wire();
            Wire* [31:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            [31:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram) = new Wire();
            Reg* [31:0]dout_r;
            [31:0]dout_r = new Reg();
            delete [4:0]ra_d;
            delete [31:0]dout;
            delete [31:0]M[19:0];
            delete [31:0]dout_ram=M[ra_d];
            delete [31:0]fbypass_dout_ram=(byp_sel?dbyp:dout_ram);
            delete [31:0]dout_r;
        }
};
class GEN_RAMS_SP_WENABLE21_64x21 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE21_64x21(){}
        ~GEN_RAMS_SP_WENABLE21_64x21(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [20:0]M[63:0];
            [20:0]M[63:0] = new Reg();
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            delete [20:0]M[63:0];
            delete [5:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE32_1024x32 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE32_1024x32(){}
        ~GEN_RAMS_SP_WENABLE32_1024x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [31:0]M[1023:0];
            [31:0]M[1023:0] = new Reg();
            Reg* [9:0]ra_d;
            [9:0]ra_d = new Reg();
            delete [31:0]M[1023:0];
            delete [9:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE8_4096x32 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE8_4096x32(){}
        ~GEN_RAMS_SP_WENABLE8_4096x32(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [31:0]M[4095:0];
            [31:0]M[4095:0] = new Reg();
            Reg* [11:0]ra_d;
            [11:0]ra_d = new Reg();
            delete [31:0]M[4095:0];
            delete [11:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE22_64x88 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE22_64x88(){}
        ~GEN_RAMS_SP_WENABLE22_64x88(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [87:0]M[63:0];
            [87:0]M[63:0] = new Reg();
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            delete [87:0]M[63:0];
            delete [5:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE8_512x256 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE8_512x256(){}
        ~GEN_RAMS_SP_WENABLE8_512x256(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [255:0]M[511:0];
            [255:0]M[511:0] = new Reg();
            Reg* [8:0]ra_d;
            [8:0]ra_d = new Reg();
            delete [255:0]M[511:0];
            delete [8:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE21_64x84 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE21_64x84(){}
        ~GEN_RAMS_SP_WENABLE21_64x84(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [83:0]M[63:0];
            [83:0]M[63:0] = new Reg();
            Reg* [5:0]ra_d;
            [5:0]ra_d = new Reg();
            delete [83:0]M[63:0];
            delete [5:0]ra_d;
        }
};
class GEN_RAMS_SP_WENABLE32_512x128 : public Cell {
    public:
        GEN_RAMS_SP_WENABLE32_512x128(){}
        ~GEN_RAMS_SP_WENABLE32_512x128(){}
        static void step(unordered_map<string, Wire*> &wire) {
            Reg* [127:0]M[511:0];
            [127:0]M[511:0] = new Reg();
            Reg* [8:0]ra_d;
            [8:0]ra_d = new Reg();
            delete [127:0]M[511:0];
            delete [8:0]ra_d;
        }
};
#endif