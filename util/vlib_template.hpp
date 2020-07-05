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
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            o -> val = a -> val & b -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            o -> val = a -> val & b -> val & c -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            if (!o || !a || !b || !c || !d) { return; }
            check2(a); check2(b); check2(c); check2(d);
            o -> val = a -> val & b -> val & c -> val & d -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b) {
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            o -> val = a -> val | b -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            o -> val = a -> val | b -> val | c -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            if (!o || !a || !b || !c || !d) { return; }
            check2(a); check2(b); check2(c); check2(d);
            o -> val = a -> val | b -> val | c -> val | d -> val;
        }
        static void _not(Wire* o, Wire* i) {
            if (!o || !i) { return; }
            check2(i);
            o -> val = ~(i -> val) + 4;
            check2(o);
        }
        static void _buf(Wire* o, Wire* i) {
            if (!o || !i) { return; }
            check2(i);
            o -> val = i -> val;
        }
        static void _xor(Wire* o, Wire* a, Wire* b) {
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            if (a -> val == 1 && b -> val == 1) 
                o -> val = 1;
            else{
                o -> val = a -> val ^ b -> val;
                check2(o);
            }
        }
        static void _xor(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            _xor(o, a, b);
            check2(o);
            _xor(o, o, c);
            check2(o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b) {
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            _and(o, a, b);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            _and(o, a, b, c);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            if (!o || !a || !b || !c || !d) { return; }
            check2(a); check2(b); check2(c); check2(d);
            _and(o, a, b, c, d);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b) {
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            _or(o, a, b);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            _or(o, a, b, c);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            if (!o || !a || !b || !c || !d) { return; }
            check2(a); check2(b); check2(c); check2(d);
            _or(o, a, b, c, d);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b) {
            if (!o || !a || !b) { return; }
            check2(a); check2(b);
            _xor(o, a, b);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b, Wire* c) {
            if (!o || !a || !b || !c) { return; }
            check2(a); check2(b); check2(c);
            _xor(o, a, b, c);
            _not(o, o);
        }

    private:
};