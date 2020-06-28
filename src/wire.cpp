#include "wire.h"
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
