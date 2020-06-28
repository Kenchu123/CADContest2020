#ifndef WIRE
#define WIRE

#include <vector>
using namespace std;

class Wire;
class Bus;

class Wire {
    public:
        short val;
        Wire(short val = 1) : val(val) {}
        ~Wire() {}
    private:
        
};

class Bus {
    public:
        Wire** wires;
        int size;
        Bus(int size = 1) : size(size) {
            wires = new Wire*[size];
            for (int i = 0;i < size;++i)
                wires[i] = new Wire;
        }
        ~Bus() {}
        
        // overload []
        short &operator[](int);
        const short &operator[](int) const;


    private:
};

class Reg {
    public:
        short val;
        size_t size;
        Reg() {}
        Reg(int size): size(size), val(1) {}
        ~Reg() {}
    private:
};

#endif