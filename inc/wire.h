#ifndef WIRE
#define WIRE

#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
using namespace std;

class Wire;
class Bus;

class Wire {
    public:
        short val;
        string name;
        size_t type; // 0 for wire, 1 for input, 2 for output
        Wire() {
            val = 1;
            name = "";
            type = 0;
        }
        Wire(string n, size_t t) {
            name = n;
            type = t;
            val = 1;
        }
        ~Wire() {}
        void print() {
            cout << "Wire: " << name << ", type:" << type << ", val: " << val << endl;
        }
    private:
        
};

class Bus {
    public:
        Wire** wires;
        int size;
        Bus() {}
        Bus(int size) : size(size) {
            wires = new Wire*[size];
        }
        ~Bus() {}
        
        // overload []
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