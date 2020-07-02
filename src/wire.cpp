#include "wire.h"
#include "global.h"
#include "simulator.h"
#include <iostream>
using namespace std;

short &
Bus::operator[](int i)
{   
    if(i < 0 || i >= size){
        cout << "\nError: Index " << i << " out of range" << endl;
        exit(1);
    }
    return wires[i] -> val;
}

const short &
Bus::operator[](int i) const
{
    if(i < 0 || i >= size){
        cout << "\nError: Index " << i << " out of range" << endl;
        exit(1);
    }
    return wires[i] -> val;
}


void 
Wire::update(int delay) {
    // cout << "Wire update at time: " << global_time << ", delay" << (unsigned long long)delay << endl;
    time = global_time + (unsigned long long)delay;
    // create Event
    Simulator::createEvent(time, name, newVal);
}