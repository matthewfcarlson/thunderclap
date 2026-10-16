#include "gen/hulkfight.h"

struct C_1725c0 {
    void* a;
    void* f592a0();
    void* f59a30();
    void f373e0(int);
};

void hulkfight::motion::MoveJointAction::vfunc_4() {
    C_1725c0* p = (C_1725c0*)(*(C_1725c0 * *)&this->f_20);
    p = (C_1725c0*)p->f592a0();
    p = (C_1725c0*)p->f59a30();
    p->f373e0(1);
}
