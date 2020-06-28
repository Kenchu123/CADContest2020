#include <iostream>
#include "gate.h"
using namespace std;

int main() {
    cout << "HI, this is simulator" << endl;
    vector<string> v = {"a1", "a2", "b1", "b2", "z"};
    vector<int> s = {1, 1, 1, 1, 1};
    Gate* g = new Gate("GEN_AO22_D1", v, s);
    g->step();

    Gate* g2 = new Gate("GEN_AO22_D2", v, s);
    g2->step();

    Gate* g3 = new Gate("GEN_AND2_D1", v, s);
    g3->step();

    Gate* g4 = new Gate("GEN_RAMS_SP_WENABLE32_1024x32", v, s);
    g4->step();
}