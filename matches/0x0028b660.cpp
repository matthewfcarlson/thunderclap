// Same code shape as 0x0028b4d0 (propagated; names are from that function)
#include "gen/pure3d.h"

struct Obj_28b660 {
    virtual void f0();
    virtual void f1();
};
void thunk(int*);

void pure3d::Vector3DOFChannel::vfunc_1() {
    if ((*(Obj_28b660 *volatile *)&this->f_0c) == 0)
        thunk((*(int * *)&this->f_18));
    (*(int * *)&this->f_18) = 0;
    if ((*(Obj_28b660 *volatile *)&this->f_0c) == 0) {
        thunk((*(int * *)&this->f_14));
        (*(int * *)&this->f_14) = 0;
        return;
    }
    Obj_28b660* p = (*(Obj_28b660 *volatile *)&this->f_0c);
    if (p) {
        p->f1();
        (*(Obj_28b660 *volatile *)&this->f_0c) = 0;
    }
    (*(int * *)&this->f_14) = 0;
}
