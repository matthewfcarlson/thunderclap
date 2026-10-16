#include "gen/hulkfight.h"

struct A_133f80 {
    A_133f80* First();
    A_133f80* Second();
    void Third(int);
};

bool hulkfight::motion::HoverAction::vfunc_5(int param, int unused) {
    if (param == 0) {
        A_133f80* p = ((A_133f80*)*(void**)((char*)this + 0x20))->First();
        p = p->Second();
        if (this->f_1c > 0)
            p->Third(1);
        else
            p->Third(3);
    }
    return true;
}
