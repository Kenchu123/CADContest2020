#include "wire.h"

using namespace std;

class Cell {
    public:
        Cell() {}
        ~Cell() {} 
        void check2(Wire* w) {  // if '10', change to '01'
            if(w -> val == 2) w -> val = 1;
        }

    //    virtual void _step() = 0;
    // primitive
        void _and(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val & b -> val;
        }
        void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val & b -> val & c -> val;
        }
        void _and(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            o -> val = a -> val & b -> val & c -> val & d -> val;
        }
        void _or(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val | b -> val;
        }
        void _or(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val | b -> val | c -> val;
        }
        void _or(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            o -> val = a -> val | b -> val | c -> val | d -> val;
        }
        void _not(Wire* o, Wire* i) {
            o -> val = ~(i -> val);
            check2(o);
        }
        void _buf(Wire* o, Wire* i) {
            o -> val = i -> val;
        }
        void _xor(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val ^ b -> val;
            check2(o);
        }
        void _xor(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val ^ b -> val;
            check2(o);
            o -> val ^= c -> val;
            check2(o);
        }
        void _nand(Wire* o, Wire* a, Wire* b) {
            _and(o, a, b);
            _not(o, o);
        }
        void _nand(Wire* o, Wire* a, Wire* b, Wire* c) {
            _and(o, a, b, c);
            _not(o, o);
        }
        void _nand(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            _and(o, a, b, c, d);
            _not(o, o);
        }
        void _nor(Wire* o, Wire* a, Wire* b) {
            _or(o, a, b);
            _not(o, o);
        }
        void _nor(Wire* o, Wire* a, Wire* b, Wire* c) {
            _or(o, a, b, c);
            _not(o, o);
        }
        void _nor(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            _or(o, a, b, c, d);
            _not(o, o);
        }
        void _xnor(Wire* o, Wire* a, Wire* b) {
            _xor(o, a, b);
            _not(o, o);
        }
        void _xnor(Wire* o, Wire* a, Wire* b, Wire* c) {
            _xor(o, a, b, c);
            _not(o, o);
        }
    private:
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
