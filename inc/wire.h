#ifndef WIRE
#define WIRE

#include <vector>
using namespace std;

class Wire {
    public:
        vector<short> val;
        size_t size;
        Wire() {}
        Wire(int size = 1): size(size) {
            val.push_back(1);
        }
        ~Wire() {}
        short getVal() {
            return val[0];
        }
    private:
        
};

class Reg {
    public:
        vector<short> val;
        size_t size;
        Reg() {}
        Reg(int size): size(size) {}
        ~Reg() {}
    private:
}

#endif