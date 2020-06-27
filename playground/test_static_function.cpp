#include <bits/stdc++.h>
using namespace std;

class Cell {
    public:
        Cell() {}
        ~Cell() {}
        static void print() {
            cout << "This is Cell" << endl;
        }
    private:
};

class Child1 : public Cell {
    public:
        Child1() {}
        ~Child1() {}
        static void print() {
            cout << "This is Child1" << endl;
        }
        static void print(map<string, int>& mp) {
            cout << "This is Child1 with map" << mp["1"] << endl;
        }
    private:
};

class Child2 : public Cell {
    public:
        Child2() {}
        ~Child2() {}
        static void print() {
            cout << "This is Child2" << endl;
        }
        static void print(map<string, int>& mp) {
            cout << "This is Child2 with map" << mp["2"] << endl;
        }
    private:
};

typedef void (*func_ptr)(map<string, int>& mp);

int main() {
    cout << "This is test for static function pointer" << endl;
    // func_ptr child1 = &Child1::print;
    map<string, func_ptr> mp = {
        {"Child1", &Child1::print},
        {"Child2", &Child2::print}
    };

    map<string, int> string2int = {
        {"1", 1},
        {"2", 2}
    };
    mp["Child1"](string2int);
    mp["Child2"](string2int);

}