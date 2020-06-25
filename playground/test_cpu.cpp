#include <bits/stdc++.h>
using namespace std;

class CirMgr;
class CirGate;
class TwoInputAndGate;

class CirMgr {
    public:
        CirMgr() {
            reset();
        }
        void DFS(CirGate*);
        void reset() {
            _dfslist.clear(); _dfsSet.clear();
            _pilist.clear(); _polist.clear();
        }
    private:
        vector<CirGate*> _pilist;
        vector<CirGate*> _polist;
        vector<CirGate*> _dfslist;
        set<CirGate*> _dfsSet;
};

void CirMgr::DFS(CirGate* root) {
    _dfslist.clear();
    _dfsSet.clear();
}

class CirGate {
    public:
        friend class CirMgr;
        friend class TwoInputAndGate;
        CirGate(): _delay(0), val(0), toStep(0) {
            _fanin.clear(); _fanout.clear();
        }
        virtual ~CirGate() {
            _fanin.clear(); _fanout.clear();
        };
        virtual void setInput() = 0;
        virtual void setOutput() = 0;
        virtual void setDelayTime() = 0;
        virtual void step() = 0;
        bool val;
        bool toStep;
    private:
        vector<CirGate*> _fanin;
        vector<CirGate*> _fanout;
        size_t _delay;
};

class TwoInputAndGate : public CirGate {
    public:
        friend class CirMgr;
        TwoInputAndGate() {}
        void setDelayTime(int delay) {
            _delay = delay;
        }
        void setInput(CirGate** gates, int n) {
            assert(n == 2);
            for (size_t i = 0; i < n; ++i) _fanin.push_back(gates[i]);
        }
        void setOutput(CirGate** gates, int n) {
            for (size_t i = 0; i < n; ++i) _fanout.push_back(gates[i]);
        }
        void step() {
            assert(_fanin.size() == 2);
            bool tmp = _fanin[0]->val & _fanin[1]->val;
            if (tmp != val) {
                // Event Driven
                // for (auto gate : _fanout) gate->toStep = 1;
            }
            val = tmp;
        }
};

int main() {

}