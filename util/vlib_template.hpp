using namespace std;

class Cell {
    public:
        Cell() {}
        ~Cell() {} 
        static void check2(Wire* w) {  // if '10', change to '01'
            if(w -> val == 2) w -> val = 1;
        }
        // primitive function
        static void _and(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val & b -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val & b -> val & c -> val;
        }
        static void _and(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            o -> val = a -> val & b -> val & c -> val & d -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val | b -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val | b -> val | c -> val;
        }
        static void _or(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            o -> val = a -> val | b -> val | c -> val | d -> val;
        }
        static void _not(Wire* o, Wire* i) {
            o -> val = ~(i -> val);
            check2(o);
        }
        static void _buf(Wire* o, Wire* i) {
            o -> val = i -> val;
        }
        static void _xor(Wire* o, Wire* a, Wire* b) {
            o -> val = a -> val ^ b -> val;
            check2(o);
        }
        static void _xor(Wire* o, Wire* a, Wire* b, Wire* c) {
            o -> val = a -> val ^ b -> val;
            check2(o);
            o -> val ^= c -> val;
            check2(o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b) {
            _and(o, a, b);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c) {
            _and(o, a, b, c);
            _not(o, o);
        }
        static void _nand(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            _and(o, a, b, c, d);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b) {
            _or(o, a, b);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c) {
            _or(o, a, b, c);
            _not(o, o);
        }
        static void _nor(Wire* o, Wire* a, Wire* b, Wire* c, Wire* d) {
            _or(o, a, b, c, d);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b) {
            _xor(o, a, b);
            _not(o, o);
        }
        static void _xnor(Wire* o, Wire* a, Wire* b, Wire* c) {
            _xor(o, a, b, c);
            _not(o, o);
        }
        static void _udp_xbuf(Wire* o, Wire* i, Wire* check_signal) {}
        static void _udp_dff(Wire* q, Wire* d, Wire* clk, Wire* clr, Wire* set, Wire* notifier) {}
        static void _udp_tlat(Wire* q, Wire* d, Wire* en, Wire* clr, Wire* set, Wire* notifier) {}
        static void _udp_mux2(Wire* z, Wire* i0, Wire* i1, Wire* s) {}

    private:
};