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
        // User Defined Primitives
        void _udp_xbuf(Wire* o, Wire* i, Wire* check_signal){}
        void _udp_dff(Wire* q, Wire* d, Wire* clk, Wire* clr, Wire* set, Wire* notifier){}
        void _udp_tlat(Wire* q, Wire* d, Wire* en, Wire* clr, Wire* set, Wire* notifier){}
        void _udp_mux2(Wire* z, Wire* i0, Wire* i1, Wire* s){
            /*/ 
             *    i0 i1 s :  z
             *    1  ?  0 :  1
             *    0  ?  0 :  0
             *    ?  1  1 :  1
             *    ?  0  1 :  0
             *    0  0  x :  0
             *    1  1  x :  1
            /*/
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
            // else z -> val = 1;
        }
        // Built-in Primitives
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
            o -> val = ~(i -> val) + 4;
            check2(o);
        }
        void _buf(Wire* o, Wire* i) {
            o -> val = i -> val;
        }
        void _xor(Wire* o, Wire* a, Wire* b) {
            if (a -> val == 1 && b -> val == 1) 
                o -> val = 1;
            else{
                o -> val = a -> val ^ b -> val;
                check2(o);
            }
        }
        void _xor(Wire* o, Wire* a, Wire* b, Wire* c) {
            _xor(o, a, b);
            check2(o);
            _xor(o, o, c);
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
