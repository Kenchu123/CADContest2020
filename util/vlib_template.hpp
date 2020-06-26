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
