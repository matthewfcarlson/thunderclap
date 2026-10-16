#include "gen/hulkfight.h"

struct A_15cbb0 {
    void* x;
    void* GetThing();
};
struct B_15cbb0 {
    void* GetNext();
};
struct C_15cbb0 {
    void DoThing(int);
};

void hulkfight::motion::LocomotingAction::vfunc_4() {
    A_15cbb0* p = (*(A_15cbb0 * *)&this->f_1c);
    if (p) {
        B_15cbb0* q = (B_15cbb0*)p->GetThing();
        if (q) {
            C_15cbb0* r = (C_15cbb0*)q->GetNext();
            if (r)
                r->DoThing(0);
        }
    }
}
