#include "gen/hulkfight.h"

struct A_15c460 {
    void* f592();
};
struct C_15c460 {
    void f22(void*, int, float);
};
struct D {
    void f359(int);
};
struct B_15c460 {
    C_15c460* f9a40();
    D* f9a30();
};

void hulkfight::motion::LocomotionStrafeAction::vfunc_4() {
    if ((*(void * *)&this->f_20)) {
        B_15c460* b = (B_15c460*)(*(A_15c460 * *)&this->f_1c)->f592();
        C_15c460* c = b->f9a40();
        if (c) {
            c->f22((*(void * *)&this->f_20), 0, -1.0f);
            D* d = b->f9a30();
            if (d)
                d->f359(0);
        }
    }
}
