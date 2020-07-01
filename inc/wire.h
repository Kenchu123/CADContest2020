#ifndef WIRE
#define WIRE

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

class Gate;
class Wire;
class Bus;

class Wire {
    public:
        short val;
        unsigned long long time;
        string name;
        size_t type; // 0 for wire, 1 for input, 2 for output
        vector<Gate*> fanouts;
        Wire() {
            val = 1;
            name = "";
            type = 0;
            time = 0;
        }
        Wire(string n, size_t t) {
            name = n;
            type = t;
            val = 1;
            time = 0;
        }
        ~Wire() {}
        void print() {
            cout << "Wire: " << name << ", type:" << type << ", val: " << val << endl;
        }
        void setVal(short v) {
            val = v;
        }
        void update(int t){
            time = t;
            // call undone
        }
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