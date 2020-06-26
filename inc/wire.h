#ifndef WIRE
#define WIRE

#include <vector>
using namespace std;

class Wire {
    public:
        Wire() {}
        ~Wire() {}
    private:
        
};

class Bus : public Wire {
    public:
        Bus(){}
        ~Bus(){}
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
};

#endif